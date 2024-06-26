#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "img_processing.h"
#include "ppm_io.h"


Image grayscale( FILE *fp,const Image *im ){
    assert(im);
    int imgDataSize = im->rows * im->cols;
    unsigned char buffer[imgDataSize][3]; 
        // Loop through rows
    for (int i = 0; i < imgDataSize; i++){
        int y = 0;
        buffer[i][2] = getc(fp);					//blue
        buffer[i][1] = getc(fp);					//green
        buffer[i][0] = getc(fp);					//red
		
        y = (buffer[i][0]*0.3) + (buffer[i][1]*0.59) + (buffer[i][2]*0.11); //conversion formula of rgb to gray

        putc(y,fp);
        putc(y,fp);
        putc(y,fp);
    }
    return;
}

Image binarize( FILE *fp,const Image *im );


Image crop( FILE *fp,const Image *im );

Image transpose( FILE *fp,const Image *im );

Image gradient( FILE *fp,const Image *im );

Image seam(FILE *fp,const Image *im );