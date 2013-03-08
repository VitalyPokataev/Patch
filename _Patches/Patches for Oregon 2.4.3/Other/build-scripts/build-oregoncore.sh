#!/bin/sh

echo "Building OregonCore..."

if [ -d oregoncore ]; then
  echo -ne "Pull current source tree (y/n)? "
  read CSINPUT

  CSINPUT=`echo $CSINPUT | tr '[:lower:]' '[:upper:]'`

  if [ $CSINPUT = "Y" ]; then
    cd oregoncore
    hg pull
    cd ..
  fi
else
  hg clone http://bitbucket.org/oregon/oregoncore
fi

cd oregoncore

echo -ne "\n\n*** Building OregonCore...\n\n\n"

if [ ! -d build ]; then
  mkdir build
fi

cd build

cmake ../ -DPREFIX=$HOME -DACE_LIBRARY=$HOME/lib/libACE.so -DACE_INCLUDE_DIR=$HOME/include -DOPENSSL_INCLUDE_DIR=$HOME/include/openssl -DOPENSSL_LIBRARIES=$HOME/lib/libssl.so && make -j2 && make install
RSLT=$?

if [ $RSLT != 0 ]; then
  echo " "
  echo "*** OregonCore Build Failed ***"
  echo " "
  exit 1
fi

cd ..

echo "Build complete!"

if [ ! -d ~/data ]; then
  mkdir -p ~/data/maps
  mkdir ~/data/vmaps
  mkdir ~/data/dbc
  cp contrib/extractor/ad.exe ~/data/
  cp contrib/vmap_extract_assembler_bin/*.exe ~/data/
  cp contrib/vmap_extract_assembler_bin/*SIMPLE*bat ~/data/
  echo "DBC/Map/VMap tools are in $HOME/data."
fi

exit 0

#EOF
