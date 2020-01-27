#!/bin/bash
for i in {0..3}
do
	echo test $i 
	cmp ./test_$i/file_reg_in.bin ./test_$i/file_reg_out.bin -l
	echo "============================="
done
read -p "czekam..."
