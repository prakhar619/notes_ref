#include <iostream>
using namespace std;

int main()
{
    int count;
    cudaGetDeviceCount(&count);
    printf("No of Devices:%d\n",count);
    printf("\n");
    cudaDeviceProp prop;

    for(int i=0; i < count; i++)
    {
        cudaGetDeviceProperties(&prop,i);

        printf("General Info for device %d\n",i);
        printf("Name:%s\n",prop.name);
        printf("Compute Capabilities:%d.%d\n",prop.major,prop.minor);
        printf("Clock Rate:%d\n",prop.clockRate);
        printf("Total Global Memory:%ld\n",prop.totalGlobalMem);
        printf("Total Constant Memory:%ld\n",prop.totalConstMem);
        printf("Texture Alignment:%ld\n",prop.textureAlignment);
        printf("Multiprocessor count:%d\n",prop.multiProcessorCount);
        printf("Shared Mem per mp:%ld\n",prop.sharedMemPerBlock);
        printf("Registers per mp:%ld\n",prop.regsPerBlock);
        printf("Threads in warp:%d\n",prop.warpSize);
        printf("Max Threads per block:%d\n",prop.maxThreadsPerBlock);
        printf("Max Thread dimensions:(%d,%d,%d)\n",prop.maxThreadsDim[0],prop.maxThreadsDim[1],prop.maxThreadsDim[2]);
        printf("Max Grid Dimensions:(%d,%d,%d)\n",prop.maxGridSize[0],prop.maxGridSize[1],prop.maxGridSize[2]);
        printf("\n");
    }
    return 1;
}
