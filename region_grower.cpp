// implement your class here

#include "region_grower.h"
#include <utility>
#include <stdexcept>

RegionGrower::RegionGrower(): xPix(0), yPix(0),
rStart(0), gStart(0), bStart(0), rEnd(0), gEnd(0), bEnd(0)
{}

bool RegionGrower::SetImage(const char * imgFileName) {
	Input.ReadFromFile(imgFileName);
	if (Output.ReadFromFile(imgFileName)) return true;
	return false;
}

bool RegionGrower::SetSeed(int seedX, int seedY) {
	rStart = (int) Input(seedX, seedY)->Red;
	gStart = (int) Input(seedX, seedY)->Green;
	bStart = (int) Input(seedX, seedY)->Blue;
	xPix = seedX;
	yPix = seedY;
	if (seedX >= Input.TellWidth() || seedX < 0) return false;
	if (seedY >= Input.TellHeight() || seedY < 0) return false;
	return true;
}

bool RegionGrower::SetReplacement(int newRed, int newGreen, int newBlue) {
	rEnd = newRed;
	gEnd = newGreen;
	bEnd = newBlue;
	if (rEnd < 0 || rEnd > 255) return false;
	if (gEnd < 0 || gEnd > 255) return false;
	if (bEnd < 0 || bEnd > 255) return false;
	return true;
}

void RegionGrower::Update() {
	LinkedStack<int> Xs;
	LinkedStack<int> Ys;
	bool tryLeft = false;
	bool tryRight = false;
	int x;
	int y;
	Xs.push(xPix);
	Ys.push(yPix);
	while (Xs.isempty() == false) {
		tryLeft = false;
		tryRight = false;
		x = Xs.top();
		y = Ys.top();
		Xs.pop();
		Ys.pop();
		while (y >= 0 && Output(x, y)->Red == rStart && Output(x, y)->Green == gStart && Output(x, y)->Blue == bStart) {
			y--;
		}
		y++;
		while (y < Output.TellHeight() - 1 && Output(x, y)->Red == rStart && Output(x, y)->Green == gStart && Output(x, y)->Blue == bStart) {
			Output(x, y)->Red = rEnd;
			Output(x, y)->Green = gEnd;
			Output(x, y)->Blue = bEnd;
			if (x > 0) {
				if (Output(x - 1, y)->Red == rStart && Output(x - 1, y)->Green == gStart && Output(x - 1, y)->Blue == bStart) {
					if (!tryLeft) {
						Xs.push(x - 1);
						Ys.push(y);
						tryLeft = true;
					}
				}
				else if (tryLeft) {
					tryLeft = false;
				}
			}
			if (x < Output.TellWidth() - 1) {
				if (Output(x + 1, y)->Red == rStart && Output(x + 1, y)->Green == gStart && Output(x + 1, y)->Blue == bStart) {
					if (!tryRight) {
						Xs.push(x + 1);
						Ys.push(y);
						tryRight = true;
					}
				}
				else if (tryRight) {
					tryRight = false;
				}
			}
			y++;
		}
	}
}

bool RegionGrower::GetOutput(const char * outputFileName) {
	if (Output.WriteToFile(outputFileName)) return true;
	return false;
}