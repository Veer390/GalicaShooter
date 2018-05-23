#include "Rectangle.h"
#include<cmath>

Rectangle::Rectangle(int width, int height, Vector<int> Centre, Graphics & gfx)
	:
	width(width),
	height(height),
	Centre(Centre),
	gfx(&gfx)
{
	RComputeEndPoints();
}

Rectangle::Rectangle(std::vector<Vector<int>> EndPoints, Graphics & gfx)
	:
	gfx(&gfx),
	EndPoints(EndPoints)
{
	//Compute height and width of the rectangle...
	width = EndPoints[0].x - EndPoints[1].x;
	height = EndPoints[3].y - EndPoints[0].y;

	//Compute Centre of the rectangle...
	Centre.x = EndPoints[0].x - floor(width / 2);
	Centre.y = EndPoints[0].y + floor(height / 2);
}

int Rectangle::GetWidth()
{
	return width;
}

int Rectangle::GetHeight()
{
	return height;
}

Vector<int> Rectangle::GetCentre()
{
	return Centre;
}

void Rectangle::SetDebugDrawFlag(bool newval)
{
	DebugDrawFlag = newval;
}

void Rectangle::RComputeEndPoints()
{
	EndPoints[0] = { Centre.x + floor(width / 2),Centre.y - floor(height / 2) };
	EndPoints[1] = { Centre.x - floor(width / 2),Centre.y - floor(height / 2) };
	EndPoints[2] = { Centre.x - floor(width / 2),Centre.y + floor(height / 2) };
	EndPoints[3] = { Centre.x + floor(width / 2),Centre.y + floor(height / 2) };
}

void Rectangle::SetWidth(int NewWidth)
{
	width = NewWidth;
}

void Rectangle::SetHeight(int NewHeight)
{
	height = NewHeight;
}

void Rectangle::RMain(Graphics & gfx)
{
	RComputeEndPoints();
	if (DebugDrawFlag)
	{
		//need to be filled out with drawing routine which draws the outline of the rectangle taking four end points or the centre and width, height
	}
}

//Sets the New Location of the Rectangle By Changing its centre i.e Moving its Centre...
void Rectangle::MoveCentre(Vector<int> NewLoc)
{
	Centre.x = NewLoc.x;
	Centre.y = NewLoc.y;
}




