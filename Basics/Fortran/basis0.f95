program Program_name

integer:: int_variable
integer,Parameter:: int_const

real:: float_variable
real, Parameter:: real_const

character(len = 10):: string_10
character:: string_10_01(10)
character(10):: string_alt_10
character:: string_alt * 10
character*10 :: string_alt_01			

	! if string smaller then space appended
	! if len smaller store only part of string

read*,string_10
print*,string_10,"Hello","World"

end program

