#!/bin/bash

echo "Use echo to print any statement"
echo Printing without quotes
echo Use read to enter value
read INP

#Commenting 

#VARIABLE MANIPULATION
var=1	#always avoid extra space like var = 1
#var=1/2*5	will print:1/2*5 and not 2.5
echo Value of variable:$var
echo Value of variable_2ndMethod:${var}
var=$var+1
echo Value of Incremented variable:$var #output is 1+1 and not 2
#var=(var+1)   result in:var+1
var=1
var=$((var+1))
echo "Value of Incremented variable(correct way)":$var
var=$((20/5+4-1*200))
echo "Mathematical Calculation:$var"
var="$(expr $var + 10)"
echo "Mathematical Calcution using expr:$var"

#STRING MANIPULATION
echo -e	"Escape Sequenece Activated: \\ \a \b \c \f \n \r \t \v"
echo Special Character Print: \;, \$, \', \", \\, Grouping All: '<-$500/-'
var="The fox in the wood"
echo "Length of string:${#var}"
echo Substring:${var:1:8}		#substring
echo Replace:${var/"fox"/"dog"} #replace
echo Replace_2ndMethod:${var/fox/dog} 	#replace
#${var//fox/dog} replaces all fox with dog

#CMD STORING IN VARIABLE
CMD=$(ls)
echo Using Commands:$CMD

#EXTRA VARIABLE INFO
echo "Const or final in c++ and java, Here readonly."
readonly var		#var or $var both valid
echo "Deleting a variable. unset."
unset INP		#INP or $INP both valid

I=101
J=99
#DECISION MAKING STATEMENT
if [ $I -gt 100 -a $J -gt 100 ]
then
echo "I is greater than 100 and J is greater than 100: I=$I,J=$J"
elif [ $I -gt 100 -a $J -lt 100 ]
then
echo "I is greater than 100 and J is less than 100: I=$I,J=$J"
elif [ $I -lt 100 -a $J -gt 100 ]
then
echo "I is less than 100 and J is greater than 100: I=$I,J=$J"
else
echo "I is less than 100 and J is less than 100: I=$I,J=$J"
fi

#-eq,-gt,-lt,-ge,-le,-ne
#-o (or) -a(and) !(not)
#break, continue, break <n>, continue <n>

STR="HELLO"
if [ $STR = "HELLO" ]
then 
echo "String is HELLO"
else
echo "String is not HELLO"
fi

#=,!=,-z(size == zero),-n(size != zero)

#ARRAY
AR=(1 2 4)
echo Array 2nd Element:${AR[1]}
ARR[2]=5
echo Array 3rd Element:${ARR[2]}

Str_Ar=("Helo" "world" "to" "u")
new_str_ar=${Str_Ar[@]}
echo "Assigning full new Arry:$new_str_ar"

new_sub_ar=${Str_Ar[@]:1:3}		#${Str_Ar:1:3] result in substring of first element
echo "SubArray:$new_sub_ar"

len=${#Str_Ar}
echo "Len of first element:$len"
len_ar=${#Str_Ar[@]}
echo "Len of array:$len_ar"

#LOOPING
for c in $var
do
echo "Word of string:$c"
done

for I in {1..5..2}
do
echo "Value of I:$I"
done


for I in 0 1 2 3 4
do
echo "MII Value of I:$I"
done

for (( c=1; c<=5; c++ ))
do 
   echo "Welcome $c times"
done


#IO Operation #Reading and outputing file

# >	(new file)
# >>	(existing file)(append)
# <	(input to cmd;  cmd < file)
# |	(pipling sending output from one cmd to other cmd)

# cmd > /dev/null	(discarding output)
# cmd > /dev/null 2>&1  (discarding output and error)

#Reading file line by line
	#file='test-01.csv'
	#while read line
	#do
	# echo "Line is:$line	
	#done <$file

#FUNCTIONS

hello()
{
echo "ARGS:$1"
return 60
}

hello 1000	#numeric args only
echo "Return of function:$?"




