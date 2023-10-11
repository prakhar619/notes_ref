No of indepentent variable involved
2 prime no : p q
1 constant prime no: e = 65,537
1 random integer: k

No of dependent variable involved
n = p*q
@(n) Carmichael's totient function: @(n) = LCM(p-1,q-1)
d = 1/e mod @(n)


Public Key
 n    and e(constant)         //cipher_text = (plain_text^e) mod n
Private Key
d and n         			//plain_text = (cipher_text^d) mod n






Plain Text file --> To upper case  --> To ascii(1 char=> 2 digit) -->Plain Numeric file
Plain Numeric file --> RSA encrypt --> Cipher Text
Cipher Text --> RSA Decrypt --> Plain Numeric file
Plain Numeric file --> To ascii(2 digit => 1 char) --> Plain Text file

[Problem]
RSA can take no. upto n and any no. greater than n will not be encrypted in a mapped way (wrong decryption).
So the question arises how many numeric integers should be encrypted at once and how to identify such each blocks during decryption.

Eg 
n = 701111
plain text: AAAAA A
plain numeric file: 65656565653265
thus how to select each block + a marker for block during decryption.
A marker for block during decryption is necessary as during encryption 65-> 453243 (6 digit) while 32-> 12343(5 digit)

Else we can increase the value of n
Usually 4026 bit n is used.
Meaning 2^4026 can be the value of n.

<space>   32
<new line, line feed, end of line> 10
A     65
Z     90
,     44
'     39


88823
