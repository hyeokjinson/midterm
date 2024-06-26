#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "img_processing.h"
#include "ppm_io.h"


void grayscale(Image * img){
  // determine total number of pixels of the image
  int num_pixels = img->rows * img->cols;

  for (int i = 0; i < num_pixels; i++) {
    // calculate grayscale value based on rgb values for a pixel
    int red = (int) (img->data)[i].r;
    int green = (int) (img->data)[i].g;
    int blue = (int) (img->data)[i].b;
    double intensity = 0.30*red + 0.59*green + 0.11*blue;

    //cast value back to unsigned char
    unsigned char g_value = (unsigned char) intensity;

    // assign value to each rbg channel
    (img->data)[i].r = (img->data)[i].g = (img->data)[i].b = g_value;
  }
}
void binarize(int threshold,const Image *im ){
  int num_pixels = im->rows * im->cols;

	for(int i=0;i<num_pixels;i++)
	{
		
		if((im->data)[i].r<threshold){
				(im->data)[i].r=0;
		}
    else if((im->data)[i].g<threshold){
        (im->data)[i].g=0;
    }
    else if((im->data)[i].b<threshold){
        (im->data)[i].b=0;
    }
		else
			{
				(im->data)[i].r=(im->data)[i].g=(im->data)[i].b=255;
			}
	
	}
}


// void crop( const Image *im );

// void transpose( const Image *im );

// void gradient( const Image *im );

// void seam(const Image *im );