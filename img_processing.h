#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include "ppm_io.h"

Image grayscale( const Image in );

Image binarize( const Image in );


Image crop( const Image in );

Image transpose( const Image in );

Image gradient( const Image in );

Image seam( const Image in );

#endif