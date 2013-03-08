#!/bin/sh

echo "Building ACE..."

rm -rf ACE_wrappers
if [ ! -e download/ACE-5.8.1.tar.gz ]; then
  if [ ! -d download ]; then
    mkdir download
  fi
  cd download
  wget http://download.dre.vanderbilt.edu/previous_versions/ACE-5.8.1.tar.gz
  cd ..
fi
tar -xzf download/ACE-5.8.1.tar.gz

cd ACE_wrappers
rm -rf build
mkdir build
cd build
../configure --prefix=$HOME --with-openssl=$HOME --disable-ace-tests --disable-ace-examples && \
make install
RSLT=$?

if [ $RSLT != 0 ]; then
  echo "*** ACE Build Failed : Exit Code=$RSLT ***"
  exit 1
else
  echo " "
  echo "*** ACE Build Complete ***"
  exit 0
fi

#EOF
