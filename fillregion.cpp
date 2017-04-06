// implement your program here

#include "region_grower.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	RegionGrower mainClass;
	int seedArgX = atoi(argv[2]);
	int seedArgY = atoi(argv[3]);
	int redArg = atoi(argv[4]);
	int greenArg = atoi(argv[5]);
	int blueArg = atoi(argv[6]);
	// Test for valid input file
	if (!mainClass.SetImage(argv[1])) {
		std::cout << "Input File Name is Invalid" << std::endl;
		return 0;
	}
	// Test for valid seed position
	if (!mainClass.SetSeed(seedArgX, seedArgY)) {
		std::cout << "Invalid Seed Position" << std::endl;
		return 0;
	}
	// Test for valid color integers
	if (!mainClass.SetReplacement(redArg, greenArg, blueArg)) {
		std::cout << "Invalid Color Range" << std::endl;
		return 0;
	}
	// Processes image
	mainClass.Update();
	// Test for valid output file
	if (!mainClass.GetOutput(argv[7])) {
		std::cout << "Output File Name is Invalid" << std::endl;
		return 0;
	}
	return 0;
}