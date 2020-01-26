#!/bin/bash
for i in {0..5}
do
	echo test $i
	cd test_$i
	./../../../syko.exe
	cd ..
	echo "==================" 
done

