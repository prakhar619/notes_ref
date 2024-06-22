//missing continue for here//
#include <iostream>

using namespace std;

#define DIM 1024
#define PI 3.1415
#define MAX_TEMP 1.0f
#define MIN_TEMP 0.00001f
#define SPEED 0.25f

struct DataBlock
{
    unsigned char* output_bitmap;
    float *dev_inSrc;
    float *dev_outSrc;
    float *dev_constSrc;
    CPUAnimBitmap *bitmap;
    cudaEvent_t start,stop;
    float totalTime;
    float frames;
}

//cptr is heater locations
__global__ void copy_const_kernel(float * iptr, const float *cptr)
{
    int x = threadIdx.x + blockIdx.x * blockDim.x;
    int y = threadIdx.y + blockIdx.y * blockDim.y;
    int offset = x + y * gridDim.x + blockDim.x;

    if(cptr[offset] != 0)
    {
        iptr[offset] = cptr[offset];
    }

}

__global__ void blend_kernel(float *outSrc, const float* inSrc)
{
    int x = threadIdx.x + blockIdx.x * blockDim.x;
    int y = threadIdx.y + blockIdx.y * blockDim.y;
    int offset = x + y * gridDim.x + blockDim.x;

    int left = offset - 1;
    int right = offset + 1;
    if(x == 0)
    {
        left++;
    }
    if(x == DIM -1)
    {
        right--;
    }

    int top = offset - DIM;
    int bottom = offset + DIM;

    if(y == 0)
    {
        top+= DIM;
    }
    if(y == DIM-1)
    {
        bottom -= DIM;
    }

    outSrc[offset] = inSrc[offset] + SPEED * (inSrc[top] + inSrc[bottom] + inSrc[left] + inSrc[right] - inSrc[offset] * 4);

}

void anim_gpu( uchar4* outputBitmap, DataBlock *d, int ticks ) {
      cudaEventRecord( d->start, 0 ) );
    dim3    blocks(DIM/16,DIM/16);
    dim3    threads(16,16);

    // since tex is global and bound, we have to use a flag to
    // select which is in/out per iteration
    volatile bool dstOut = true;
    for (int i=0; i<90; i++) {
        float   *in, *out;
        if (dstOut) {
            in  = d->dev_inSrc;
            out = d->dev_outSrc;
        } else {
            out = d->dev_inSrc;
            in  = d->dev_outSrc;
        }
        copy_const_kernel<<<blocks,threads>>>( in );
        blend_kernel<<<blocks,threads>>>( out, dstOut );
        dstOut = !dstOut;
    }

    float_to_color<<<blocks,threads>>>( outputBitmap,d->dev_inSrc );

    cudaEventRecord( d->stop, 0 );
    cudaEventSynchronize( d->stop );
    float   elapsedTime;
    cudaEventElapsedTime( &elapsedTime,d->start, d->stop );
    d->totalTime += elapsedTime;
    ++d->frames;
    printf( "Average Time per frame:  %3.1f ms\n",d->totalTime/d->frames  );
}

// clean up memory allocated on the GPU
void anim_exit( DataBlock *d )
{
      cudaUnbindTexture( texIn );
      cudaUnbindTexture( texOut );
      cudaUnbindTexture( texConstSrc );
      cudaFree( d->dev_inSrc );
      cudaFree( d->dev_outSrc );
      cudaFree( d->dev_constSrc );

      cudaEventDestroy( d->start );
      cudaEventDestroy( d->stop );
}

int main(void)
{
    Data

}
