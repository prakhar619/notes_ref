#!/bin/bash

#prints all line 	#default
echo 'Print all lines'
awk '{print}' pattern_search.txt

echo 'Pattern Search'
awk '/manager/{print}' pattern_search.txt

echo 'Splitting Line into Fields'
awk '{print $1,$4}' pattern_search.txt


echo '$0 represent whole line'
echo 'Built in variables NR,NF,FS,RS,OFS,ORS'
awk '{print NR,$0}' pattern_search.txt		#NR for line counter in output

awk '{print $1,$NF}' pattern_search.txt		#NF for last field number

echo 'Line control'
awk 'NR==3, NR==6 {print NR,$0}' pattern_search.txt


echo 'GREP USAGE'
grep -i 'SUNIL' pattern_search.txt	#case insensitive search
grep -ci 'SUNIL' pattern_search.txt	#line count of matching lines with case insensitive
grep 'accou' pattern_search.txt
grep -wc 'accou' pattern_search.txt	#full word match

