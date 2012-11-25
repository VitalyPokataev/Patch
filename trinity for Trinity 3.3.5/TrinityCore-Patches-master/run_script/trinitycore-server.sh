#!/bin/bash
### TrinityCore server management script by Kline.
## vers: 2012-02-11 - Initial release.
# Permission is granted to modify and distribute this file freely. I only ask that you
# do not claim it as your own work and give credit where due.
#
# https://github.com/Kline-

### START: CONFIG VALUES
## The name of the server. Second argument passed to the script. Shouldn't need to modify this.
# Default: SRVNAME="$2"
SRVNAME="$2"

## List of servers to control. Must be delimited with | between each elemnt.
## 'all' will poll all servers with the specified command and must be first in the list.
# Default: SERVERS="authserver|worldserver"
SERVERS="all|authserver|worldserver"

## Root path to your servers, ie, the home dir of the user they run as.
# Default: SRVROOT="/home/trinity"
SRVROOT="/home/trinity"

## The of each server executable based upon the root path. Must include $SRVNAME.
# Default: SRVBIN="$SRVROOT/bin/$SRVNAME"
SRVBIN="$SRVROOT/bin/$SRVNAME"

## The pid file location of each server based upon the root path.
# Default: SRVPFL="$SRVROOT/pid/$SRVNAME.pid"
SRVPFL="$SRVROOT/pid/$SRVNAME.pid"
### END: CONFIG VALUES

### START: OUTPUT MESSAGES
## The following variables are available for use:
# %cmds%     List of accepted commands.
# %pid%      PID of the requested server.
# %script%   Name of this script.
# %servers%  List of servers to control.
# %srvname%  Name of the requested server.
# %srvpfl%   PID file of the requested server.
M_NOT_RUN="%script%: %srvname% is not running."
M_NOT_RUN_FOUND_PID="%script%: %srvname% is not running but %srvpfl% exists."
M_RESTART_FAIL="%script%: Unknown error occured while attempting restart."
M_RUNNING="%script%: %srvname% is running as PID %pid%."
M_START_BEGIN="%script%: Starting %srvname% ..."
M_START_FAIL="%script%: %srvname% failed to start. Verify file path and permissions."
M_STOP_BEGIN="%script%: Stopping %srvname% ..."
M_STOP_FAIL="%script: %srvname% did not respond to SIG_TERM. Use force-stop to send SIG_KILL."
M_STOP_OK="%script%: %srvname% stopped."
M_STOP9_FAIL="%script%: %srvname% did not respond to SIG_KILL. Investigate manually (running as proper user?)."
M_USAGE="%script%: {%cmds%} {%servers%}"
### END: OUTPUT MESSAGES

#####                          #####
##### NO FURTHER CONFIGURATION #####
#####                          #####

## wrapper for echo to do replacement with sed.
secho()
{
    _cmds="start|stop|force-stop|restart|status"
    _pid=$(get_pid -v)
    _script=$(basename $0)
    _servers=$SERVERS
    _srvname=$SRVNAME
    _srvpfl=$SRVPFL
    echo "$1" | sed -e "s#%cmds%#$_cmds#g" \
                    -e "s#%pid%#$_pid#g" \
                    -e "s#%script%#$_script#g" \
                    -e "s#%servers%#$_servers#g" \
                    -e "s#%srvname%#$_srvname#g" \
                    -e "s#%srvpfl%#$_srvpfl#g"
}

## redundantly poll all servers for a command.
get_all()
{
    if [ $SRVNAME == "all" ]; then
        for opt in $(echo $SERVERS | cut -d"|" --output-delimiter=" " -f2-); do
            $0 "$1" $opt
        done
        exit 0
    fi
}

## display usage and exit.
get_help()
{
    secho "$M_USAGE"
    exit 0
}

## verify first argument is a known server.
get_valid()
{
    for opt in $(echo $SERVERS | cut -d"|" --output-delimiter=" " -f1-); do
        if [ $opt == "$1" ]; then VALID=1; break; fi
    done
    if [ -z $VALID ]; then get_help; fi
}

## retrieve pid from pid file. single arg -v is for echo output.
get_pid()
{
    if [ -r $SRVPFL ]; then SRVPID=$(cat $SRVPFL); else SRVPID=-1; fi
    if [ -z $SRVPID ]; then SRVPID=-1; fi
    [ "$1" == -v ] && echo "$SRVPID"
}

## generate status code, optionally output. single arg is -v for messages, -q for none.
get_status()
{
    if [ $SRVPID -lt 0 ]; then
        [ "$1" == -v ] && secho "$M_NOT_RUN"
        STATUS=2
    else if [ ! $(ls /proc | grep -w $SRVPID) > /dev/null 2>&1 ]; then
        [ "$1" == -v ] && secho "$M_NOT_RUN_FOUND_PID"
        STATUS=1
    else
        [ "$1" == -v ] && secho "$M_RUNNING"
        STATUS=0
    fi fi
}

[ ! -z $SRVNAME ] && get_all "$1"
get_valid "$2"
get_pid
get_status -q

case "$1" in
    start)
        if [ $STATUS -gt 0 ]; then
            secho "$M_START_BEGIN"
            screen -dmS $SRVNAME $SRVBIN
        else
            secho "$M_RUNNING"
            exit 1
        fi
        sleep 2
        get_pid
        get_status -q
        if [ $STATUS -gt 0 ]; then
            secho "$M_START_FAIL"
        else
            get_status -v
        fi
    ;;
    stop)
        if [ $STATUS -gt 0 ]; then
            secho "$M_NOT_RUN"
            exit 1
        fi
        secho "$M_STOP_BEGIN"
        kill $SRVPID > /dev/null 2>&1
        sleep 2
        if [ $(ls /proc | grep $SRVPID) > /dev/null 2>&1 ]; then
            secho "$M_STOP_FAIL"
            exit 1
        else
            secho "$M_STOP_OK"
            rm -f "$SRVPFL"
            exit 0
        fi
    ;;
    force-stop)
        if [ $STATUS -gt 0 ]; then
            secho "$M_NOT_RUN"
            exit 1
        fi
        secho "$M_STOP_START"
        kill -9 $SRVPID > /dev/null 2>&1
        sleep 2
        if [ $(ls /proc | grep $SRVPID) > /dev/null 2>&1 ]; then
            secho "$M_STOP9_FAIL"
            exit 1
        else
            secho "$M_STOP_OK"
            rm -f "$SRVPFL"
            exit 0
        fi
    ;;
    restart)
        get_pid
        get_status -q
        if [ $STATUS -eq 0 ]; then
            $0 stop $SRVNAME
            sleep 2
        fi
        $0 start $SRVNAME
        get_pid
        get_status -q
        if [ $STATUS -gt 0 ]; then
            secho "$M_RESTART_FAIL"
            exit 1
        fi
    ;;
    status)
        get_status -v
        exit 0
    ;;
    *)
        get_help
        exit 1
esac

exit 0
