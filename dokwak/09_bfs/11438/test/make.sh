#!/bin/bash
a=1
b=2
one=1
echo "100000" >> ./5.txt
for (( i = 1; i < 100000; i++ )); do
	echo "$a $b" >> ./5.txt
	a=$(( $a + $one ))
	b=$(( $b + $one ))
done
echo "1 99999" >> ./5.txt
