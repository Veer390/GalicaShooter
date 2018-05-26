#include "Rectangle.h"
#include<cmath>

Rectangle_::Rectangle_(int width, int height, Vector<int> Centre)
	:
	EndPoints(4),
	width(width),
	height(height),
	Centre(Centre)
{
	//rendobj = new Draw(this->gfx);
	RComputeEndPoints();
}

Rectangle_::Rectangle_(std::vector<Vector<int>> EndPoints)
	:
	EndPoints(EndPoints)
{
	//rendobj = new Draw(this->gfx);
	//Compute height and width of the Rectangle_...
	width = EndPoints[0].x - EndPoints[1].x;
	height = EndPoints[3].y - EndPoints[0].y;

	//Compute Centre of the Rectangle_...
	Centre.x = EndPoints[0].x - (int)floor(width / 2);
	Centre.y = EndPoints[0].y + (int)floor(height / 2);
}

int Rectangle_::GetWidth()
{
	return width;
}

int Rectangle_::GetHeight()
{
	return height;
}

Vector<int> Rectangle_::GetCentre()
{
	return Centre;
}

std::vector<Vector<int>> Rectangle_::GetEndPoints()
{
	return EndPoints;
}

void Rectangle_::SetDebugDrawFlag(bool newval)
{
	DebugDrawFlag = newval;
}

void Rectangle_::RComputeEndPoints()
{
	EndPoints[0] = { Centre.x + (int)floor(width / 2),Centre.y - (int)floor(height / 2) };
	EndPoints[1] = { Centre.x - (int)floor(width / 2),Centre.y - (int)floor(height / 2) };
	EndPoints[2] = { Centre.x - (int)floor(width / 2),Centre.y + (int)floor(height / 2) };
	EndPoints[3] = { Centre.x + (int)floor(width / 2),Centre.y + (int)floor(height / 2) };
}

void Rectangle_::SetWidth(int NewWidth)
{
	width = NewWidth;
}

void Rectangle_::SetHeight(int NewHeight)
{
	height = NewHeight;
}

void Rectangle_::RMain()
{
	RComputeEndPoints();
}

//Sets the New Location of the Rectangle_ By Changing its centre i.e Moving its Centre...
void Rectangle_::MoveCentre(Vector<int> NewLoc)
{
	Centre.x = NewLoc.x;
	Centre.y = NewLoc.y;
	RComputeEndPoints();
}




