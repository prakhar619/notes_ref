program array
implicit none

integer:: ar1(5)		!indexing start from 1 in fortran
integer,dimension(5)::ar2

integer:: ar3(-3,5)		!here indexing starts from -3  !user controlled
integer,dimension(-3,5):: ar4
integer:: i,j,c

!2d array
integer:: two_d(6,5)	!6 row 5 column
integer:: two_d01(-3:5,5:12)	!user controlled 2d array

!multidimesion array
integer:: mult(6,5,4)		!shape = (6,5,4)
				!rank = 3
				!size = 6*5*4

integer:: ar5(20)

!extensible array
real,allocatable,dimension(:)::arr,arr01
real,allocatable::arr02(:),arr03(:)

	read*,n
	allocate(arr(n),arr01(n))
	! allocate(arr(n),arr01(n),stat = ok)	ok = 0 allocation successful; != 0  allocation failed

	deallocate(x(n),y(n))

do c = 1,5
read*,ar1(c)
end do

read*,(ar2(i), i=1,5)

read*,ar3

read*,(two_d01(i,j),i = -3,5),j = 5,12)

ar5 = (|4,5,8,7,6|)
ar5 = (|(i,i = 1,10)|)
ar5 = (|5,6,2,(2*i,i = 1,10),9,10|)
ar5 = (|(2*i,i = 1,10),(3*i,i = 1,10)|)


mult = reshape((|10,0,10,9,10,20,12,10,0,8,5|),(6,5,4))	
	! 6 row, 5 column
	! first row change then column
	! 1,1,1		2,1,1		3,1,1		4,1,1
	
!intrinsic function
! matmul(ar,ar)	VECTOR MULTIPLICATION
! dot_product(ar,ar)
! transpose(ar)
! maxval(ar)
! minval(ar)
! product(ar)
! sum(ar)

! whole array operation z(i) = x(i) + y(i)	=> z = x+y




 

