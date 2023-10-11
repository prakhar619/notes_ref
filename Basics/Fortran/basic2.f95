program fill_tub
implicit none
real,parameter:: pi =3.1415
real::height,flow,diameter,time,init_Height
read*,init_Height,flow,time,diameter
height = init_height + (4.0*flow * time)/(pi*diameter*diameter)
print*,"Height After", time, "Height", height
end program fill_tub
