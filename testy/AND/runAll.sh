#!/bin/bash
for i in {0..4}
do
	echo test $i
	cd test_$i
	./../../../syko.exe
	cd ..
	echo "==================" 
done
read -p "czekam..."
