#pragma once
#include <vector>
#include "Colors.h"
#include "Graphics.h"
#include "Vector.h"
#include "Rectangle.h"

//PlaceHolder For Rectangle_
class Rectangle_;

class Draw
{
public:
	//Default Constructor is deleted so no draw object can exist without a graphics object..
	Draw() = delete;

	//Default Constructor For Draw Cannot Exist Without A Graphics object....
	Draw(Graphics* gfx);

private:
	Graphics *gfx;

public:
	/*MainDraw Routines*/

	void DrawLine(Vector<int> StartPoint, Vector<int> EndPoint,Color c);

	//Draw Rectangle_
	void DrawRectangle_Outline(Rectangle_* RectToDraw,Color c);
};