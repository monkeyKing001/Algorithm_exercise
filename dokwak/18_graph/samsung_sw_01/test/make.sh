#!/bin/bash
a=1
b=2
one=1
for (( i = 1; i < 101; i++ )); do
	echo "$a $b $a" >> ./3.txt
	a=$(( $a + $one ))
	b=$(( $b + $one ))
done
