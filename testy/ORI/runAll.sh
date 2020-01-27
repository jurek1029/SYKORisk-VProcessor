#!/bin/bash
for i in {0..2}
do
	echo test $i
	cd test_$i
	./../../../syko.exe
	cd ..
	echo "==================" 
done
read -p "czekam..."
