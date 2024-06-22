#include <iostream>
using namespace std;

int main()
{
    cudaDeviceProp prop;
    int dev;

    //cudaGetDevice(&dev);

    //memset(&prop,0,sizeof(cudaDeviceProp));
    prop.major = 1;
    prop.minor = 3;

    cudaChooseDevice(&dev,&prop);

    printf("ID of CUDA device closed to revision 1.3:%d\n",dev);

    cudaSetDevice(dev);
}
