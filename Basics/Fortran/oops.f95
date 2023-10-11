program oops
implicit none

integer:: int_var, int_var2
real:: float_var01
real:: float_var

real:: function_01,function_02
integer:: function_03

int_var = 10

float_var = function_01(int_var)
float_var01 = function_02(int_var)
float_var = function_03(int_var)
call subr(float_var01,float_var,float_var,int_var,int_var2)
print*,float_var
end program






function function_01(y)
implicit none
real:: function_01

integer:: y

if(y > 20)then 
function_01 = 10.5
else
function_01 = 20.5
endif

end function 






real function function_02(y)
implicit none
integer:: y

function_02 = 100.5
end function function_02




integer function function_03(y)
implicit none
integer,intent(in):: y	!now editing y would result in error
function_03 = 99
print*,"FUNCTION 3 called"
end function function_03






subroutine subr(x1,x2,x3,a0,a1)
implicit none
real::x1,x2,x3
integer::a0,a1
a0 =  x1 + x2
a1 = x1 - x3
end subroutine



