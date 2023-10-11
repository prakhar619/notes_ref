	program A1_A1
        implicit none
        ! No of particles
        integer, parameter :: N = 100000

	! box size
        real, parameter :: min_size = -2.0
        real, parameter :: max_size = 2.0

	! 3 arrays to store x,y,z coordinates of all the particles 
        real :: x(N)
        real :: y(N)
        real :: z(N)

        integer :: i, j
        
        ! Variables for histogram
        integer, parameter :: N_bins = 100
        real :: width_bin, min_bin, max_bin
        integer :: value_bin_x(N_bins)
        integer:: value_bin_y(N_bins)
        integer:: value_bin_z(N_bins) 
        real:: temp

        ! Alloting x,y,z coordinates to particles randomly;
        call random_seed()
        do i = 1, N
                call random_number(x(i))
                call random_number(y(i))
                call random_number(z(i))
        	x(i) = min_size + (max_size - min_size) * x(i)
        	y(i) = min_size + (max_size - min_size) * y(i)
        	z(i) = min_size + (max_size - min_size) * z(i)
        end do

        ! Probability of particle on  x axis
        width_bin = (max_size - min_size) / N_bins
        min_bin = min_size - width_bin / 2.0
        max_bin = max_size + width_bin / 2.0
        value_bin_x = 0
        do i = 1, N
                j = int((x(i) - min_bin) / width_bin) + 1
        	if (j >= 1 .and. j <= N_bins) then
        		value_bin_x(j) = value_bin_x(j) + 1
        	end if
        end do

        open(unit=1,file='bin_value_x.csv')
        write(*,*) 'Value of Random Number','  Number of Particles'
        do i = 1, N_bins
        	temp  = real(value_bin_x(i))/N
        	write(1,*) min_bin + (i-0.5)*width_bin,",",temp
        end do


	value_bin_y = 0
        do i = 1, N
                j = int((y(i) - min_bin) / width_bin) + 1
        	if (j >= 1 .and. j <= N_bins) then
        		value_bin_y(j) = value_bin_y(j) + 1
        	end if
        end do
        close(1)

        open(unit=2,file='bin_value_y.csv')
        write(*,*) 'Value of Random Number','  Number of Particles'
        do i = 1, N_bins
        	temp = real(value_bin_y(i))/N
        	write(2,*) min_bin + (i-0.5)*width_bin,",",temp
        end do

	value_bin_z = 0
        do i = 1, N
                j = int((y(i) - min_bin) / width_bin) + 1
        	if (j >= 1 .and. j <= N_bins) then
        		value_bin_z(j) = value_bin_z(j) + 1
        	end if
        end do
	close(2)
        open(unit=3,file='bin_value_z.csv')
        write(*,*) 'Value of Random Number','  Number of Particles'
        do i = 1, N_bins
        	temp =  real(value_bin_z(i))/N
        	write(3,*) min_bin + (i-0.5)*width_bin,",", temp
        end do
	close(3)
	end program A1_A1






