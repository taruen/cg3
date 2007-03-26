#!/bin/bash

rm -rf dist
mkdir -p dist

. chapterize.sh
mkdir -p dist/chunked
mv *.html dist/chunked/

. singlefile.sh
mkdir -p dist/single
mv *.html dist/single/

rm -f manual-combined.xml
mkdir -p dist/source
cp *.xml dist/source

cd dist

tar -zcvf chunked.tar.gz chunked
tar -zcvf single.tar.gz single
tar -zcvf source.tar.gz source
zip -r9 chunked.zip chunked
zip -r9 single.zip single
zip -r9 source.zip source
