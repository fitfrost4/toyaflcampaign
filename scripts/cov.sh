#!/bin/sh

dir="$1"

# generate cov data for all files in dir
for file in "$1"; do
  if [ -f "$file" ]; then
	./toyparser/toyparser "$file"
  fi
done

mkdir -p cov

#parse coverage
cd cov && gcov ../toyparser/parser.c 

#create info
geninfo ../toyparser/ -b ../toyparser/ -o cov.info

#export to html
genhtml cov.info -o cov/html
