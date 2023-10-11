#include "stdio.h"
__global__ void add(int a, int b, int *c)
{
*c = a + b;
}
int main()
{
	int a,b,c;
	int *dev_c;
	a=3;
	b=4;
	cudaMalloc((void**)&dev_c, sizeof(int));	//create malloc space in device; passed pointer (address of pointer in sent); address in gpu created will be pointed address
	//		dev_c        -|->               created_var
	//		121					155
	//	we are passing addr of pointer 121 but device creates memory with 155
	add<<<1,1>>>(a,b,dev_c);
	cudaMemcpy(&c, dev_c, sizeof(int), cudaMemcpyDeviceToHost);
	printf("%d + %d is %d\n", a, b, c);
	cudaFree(dev_c);
	
	//ERROR DETECTION CODE
	cudaDeviceSynchronize();
	cudaError_t error = cudaGetLastError();
	if(error!=cudaSuccess)
	{
	   fprintf(stderr,"ERROR: %s\n", cudaGetErrorString(error) );
	   exit(-1);
	}
	return 0;
}
