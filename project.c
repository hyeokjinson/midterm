// <your name> and <your JHED>
// __Add your name and JHED above__
/*****************************************************************************
 * Midterm Project - A program to run the image processing operations
 * Note: for naming convention, we try to follow Google C++ style guide:
 *       https://google.github.io/styleguide/cppguide.html
 * It is not compulsory, but you are highly encouraged to follow a convention.
 *
 * Summary: This file implements a program for image processing operations.
 *          Different operations take different input arguments. In general,
 *            ./project <input> <output> <operation name> [operation params]
 *          The program will return 0 and write an output file if successful.
 *          Otherwise, the below error codes should be returned:
 *            1: Wrong usage (i.e. mandatory arguments are not provided)
 *            2: Input file I/O error
 *            3: Output file I/O error
 *            4: The Input file cannot be read as a PPM file
 *            5: Unsupported image processing operations
 *            6: Incorrect number of arguments for the specified operation
 *            7: Invalid arguments for the specified operation
 *            8: Other errors 
 *****************************************************************************/
#include "ppm_io.h" // PPM I/O header
#include <stdlib.h> // c functions: atio
// TODO: include requried headers for your projects.  
// We recommend to put your image processing operations in 
//  img_processing.h for decleartions and
//  img_processing.c for their defintions
// Then you should include the below header:
#include "img_processing.h" // Image processing header
#include <string.h>

int main(int argc, char **argv) {
	// TODO: write your codes here
  int threshold;
  	// parsing command line arguments
  if (argc < 3) {
    fprintf(stderr, "No input and output filename.\n");
    return 1; // not enough filenames
  }
	
  if (argc < 4) {
    fprintf(stderr, "No operation name.\n");
    return 4; // input and output files were given but no operation
  }

  FILE *fp = fopen(argv[1], "rb");
  if (fp == NULL) {
		printf("Couldn't open output file: %s\n", argv[1]);
		return 2; // return 2 for other errors
  }

 // allocate space for an Image
  Image * im = ReadPPM(fp);
  if (im == NULL) {
    fprintf(stderr, "Read ppm failed.\n");
    return 3; // read function failed beceause ppm was incorrectly formatted
  }
  //operate 
  if (strcmp(argv[3], "grayscale") == 0) {
    grayscale(im); // grayscale image produced
    printf("%s Complete !!\n",argv[3]);    /*for debug*/
  }
  /*TODO Write Function*/

  else if(strcmp(argv[3], "binarize") == 0){
    threshold=atoi(argv[4]);
    if((threshold < 0) || (threshold > 255)){
      fprintf(stderr, "\nError! The threshold value of %d is not in the range 0->255.\n\n",threshold);
    }
    grayscale(im); // grayscale image produced
    binarize(threshold,im );
    printf("%s Complete !!\n",argv[3]);    /*for debug*/

  }

/*
  else if(strcmp(argv[3], "crop") == 0){
  }
  */
  else {
    fprintf(stderr, "Invalid operation name.\n");
    return 4; // no valid operation was given
  }

  
  FILE* write_to = fopen(argv[2], "wb");
  if (write_to == NULL) {
    fprintf(stderr, "Cannot open output file.\n");
    return 7; // cannot open Image
  }
  // write image to output file
  int num_pixels_written = WritePPM(write_to, im);
  
  printf("Image created with %d pixels.\n", num_pixels_written);

  // clean up!
  free(im->data);  // releases the pixel array
  free(im);        // releases the image itself

  fclose(fp);
  fclose(write_to);

	return 0;
  return 0;
}
