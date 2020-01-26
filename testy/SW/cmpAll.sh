#!/bin/bash
for i in {0..9}
do
	echo test $i 
	cmp ./test_$i/file_data_in.bin ./test_$i/file_data_out.bin -l
	echo "============================="
done

