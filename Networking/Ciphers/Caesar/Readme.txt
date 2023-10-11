Caesar Cipher

+<number> Denotes Forward linking. Eg +5	A->E
-<number> Denotes Backward linking.Eg -1	A->Z

Also 
key = -1 = +25
	 -2 = +24

Generality
<positive_number>+|<negative_number>| = 26

Procedure: (Ascii code)

w	x	y	z	a	b	c	d	e	f	g	h	i	j	k	l	m	n	o	p	q	r	s	t	u	v

119	120	121	122	97	98	99	100	101	102	103	104	105	106	107	108	109	110	111	112	113	114	115	116	117	118

-97

22	23	24	25	0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	20	21

key = +5
	 +201(+19)	201%26=19

27	28	29	30	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	20	21	22	23	24	25	26
223	224	225	226	201	202	203	204	205	206	207	208	209	210	211	212	213	214	215	216	217	218	219	220	221	222

%26

1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	20	21	22	23	24	25	0	
15	16	17	18	19	20	21	22	23	24	25	0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	

+97

98	99	100	101	102	103	104	105	106	107	108	109	110	111	112	113	114	115	116	117	118	119	120	121	122	97
b	c	d	e	f	g	h	i	j	k	l	m	n	o	p	q	r	s	t	u	v	w	x	y	z	a

112	113	114	115	116	117	118	119	120	121	122	97	98	99	100	
p	q	r	s	t	u	v	w	x	y	z	a



Method 1
	Cipher text with spaces
