        program A2
        implicit none 
        ! environment variables
        double precision, parameter:: viscos_mu=1.48E-5,R=100E-6
        real, parameter:: g=9.8,dt=1E-4,pi=3.1415
        real ::lambda,mass_m,time_T, x, y, z, V_x, V_y, V_z
        time_T = 0.0;x = 0.0;y = 0.0;z = 2.0;V_x = 25.0;V_y = 0.0
        V_z = 0.0 
        lambda=6*pi*viscos_mu*R
        mass_m=1000.0*4*pi*(R**3)/3

        open(1,file="Vx_VS_T.csv")
        open(2,file="Vz_VS_T.csv")
        open(3,file="x_VS_T.csv")
        open(4,file="z_VS_T.csv")
        do while(z >=0)
                time_T=time_T+dt 
                x= x+V_x*dt 
                y= y+V_y*dt 
                z= z+V_z*dt 
                V_x = V_x - (lambda/mass_m)*V_x*dt
                V_y = V_y - (lambda/mass_m)*V_y*dt
                V_z = V_z- (lambda/mass_m)*V_z*dt - g*dt
                write(1,*)time_T,",",V_x
                write(2,*)time_T,",",V_z
                write(3,*)time_T,",",x
                write(4,*)time_T,",",z
        end do 
        end program A2
