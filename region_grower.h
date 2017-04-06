// define your class here

#ifndef _REGION_GROWER_H_
#define _REGION_GROWER_H_

#include "abstract_stack.h"
#include "EasyBMP.h"
#include "linked_stack.h"
#include <iostream>

class RegionGrower {
public:

	// Constructor
	RegionGrower();
	
	// Set the input BMP image to use
	// Returns false on invalid filename
	bool SetImage(const char * imgFileName);
	
	// Set the seed pixel indices
	// Returns false on invalid seed position
	bool SetSeed(int seedX, int seedY);
	
	// Set the pixel color (RGB) to set the region to
	// Returns false on invalid color integers
	bool SetReplacement(int newRed, int newGreen, int newBlue);
	
	// Replace the color in a region defined by seed with new color
	void Update();
	
	// Get the new BMP image
	// Returns false if unable to write to output file
	bool GetOutput(const char * outputFileName);
	
private:

	BMP Input;		// Input image
	BMP Output;		// Processed output image
	int xPix;		// X coordinate of seed
	int yPix;		// Y coordinate of seed
	int rStart;		// Seed colors
	int gStart;
	int bStart;
	int rEnd;		// Colors to change to
	int gEnd;
	int bEnd;
	
};

#endif // _REGION_GROWER_H_