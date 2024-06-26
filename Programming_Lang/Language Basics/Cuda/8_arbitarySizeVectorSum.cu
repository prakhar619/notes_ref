#include <stdio.h>

#define  N 100000

__global__ void add(int* a,int *b,int *c)
{
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    while(tid < N)
    {
        c[tid] = a[tid] + b[tid];
        tid += blockDim.x * gridDim.x;
    }
}
int main()
{
    int threadPerBlock = 1000;
    int blockCount = 10;


    int a[N], b[N], c[N];
    int* dev_a, *dev_b, *dev_c;

    cudaMalloc(&dev_a,sizeof(int)*N);
    cudaMalloc(&dev_b,sizeof(int)*N);
    cudaMalloc(&dev_c,sizeof(int)*N);

    for(int i = 0; i < N; i++)
    {
        a[i] = -i;
        b[i] = 3*i -1;
    }

    cudaMemcpy(dev_a,a,sizeof(int)*N,cudaMemcpyHostToDevice);
    cudaMemcpy(dev_b,b,sizeof(int)*N,cudaMemcpyHostToDevice);

    add<<<blockCount,threadPerBlock>>>(dev_a,dev_b,dev_c);

    cudaMemcpy(c,dev_c,sizeof(int)*N,cudaMemcpyDeviceToHost);

    for(int i = 0; i < N; i++)
    {
        if(a[i] + b[i] != c[i])
            printf("ERROR");
        else
        printf("%d + %d = %d\n",a[i],b[i],c[i]);
    }
    return 1;
}
