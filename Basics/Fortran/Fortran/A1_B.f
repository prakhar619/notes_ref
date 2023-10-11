        program A1_B
            implicit none
            ! No of Particles
            integer, parameter :: N = 100000   
            ! loop variable
            integer :: i
            ! environment variables
            real(kind=8) :: p, f_p,Engy, avg_Engy
            real(kind=8), parameter :: c = 1.0d0, k = 1.0d0, T = 0.2d0
            real, dimension(N) :: randm
            real(kind = 8) :: dp = 15.0d0 / N
            Engy = 0.0d0
            call random_number(randm)
            randm = randm * 15.0
            open(1, file='Numerical_distribution.csv')
            do i = 1, N
                p = randm(i)
                f_p = exp(-p*c/(k*T))
                write(1,*) p,",", f_p
            end do
            close(1)

            open(2, file='Analytical_distribution.csv')
            do i = 1, N
            	p = (i - 0.5d0) * dp
                f_p = exp(-p/(k*T)) / (k*T)
                write(2,*) p,",", f_p
            end do
            close(2)
            
            do i = 1, N
                p = (i - 0.5d0) * dp
                f_p = exp(-c*p/(k*T))
                Engy = Engy + p*f_p*dp
            end do

            avg_Engy = Engy /N
            print*,"Average energy of particles = ", avg_Engy

        end program A1_B
