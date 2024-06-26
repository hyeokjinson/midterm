#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include "ppm_io.h"

void grayscale(Image * img);
void binarize(int threshold,const Image *im );


#endif