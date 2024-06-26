//Host -> CPU AND RAM
//DEVICE -> GPU and its internal memory


#include <stdio.h>
__global__ void kernel( void )	//alerts the compiler that a function should run on a device instead of the host
{
}
//nvcc gives kernel() to compiler that handles device code
int main(void) 
{
	kernel<<<1,1>>>();	//gives parameter to compiler during runtime
	printf( "Hello, World!\n" );
	return 0;
}
