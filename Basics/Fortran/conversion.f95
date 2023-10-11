! fortran do both conversion int->real and real->int(truncation) and same with double precision
program conversion
implicit none
integer:: int = 10
double precision:: dou = 20.54
real:: re = 23.35

integer:: converted_double
double precision :: converted_int
integer:: converted_real

converted_double = 20.54
converted_int = int
converted_real = re

print*,int,converted_int,dou,converted_double, re, converted_real

end program
