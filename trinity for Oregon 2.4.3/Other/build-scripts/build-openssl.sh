#!/bin/sh

echo "Building OpenSSL..."

if [ ! -d download ]; then
  mkdir download
fi
cd download
if [ ! -e openssl-0.9.8n.tar.gz ]; then
  wget http://www.openssl.org/source/openssl-0.9.8n.tar.gz
fi
cd ..
tar -xzf download/openssl-0.9.8n.tar.gz

cd openssl-0.9.8n

./config --prefix=$HOME shared --openssldir=$HOME/etc/ssl && make install
RSLT=$?

if [ $RSLT != 0 ]; then
  echo "*** OpenSSL Build Failed : Exit Code=$RSLT ***"
  exit 1
else
  echo " "
  echo "*** OpenSSL Build Complete ***"
  exit 0
fi

#EOF
