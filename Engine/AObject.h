#pragma once
#include "Graphics.h"
#include "Vector.h"
#include "Rectangle.h"
#include "Draw.h"

class AObject
{
public:
	//Constructors

	AObject() = delete;

	AObject(Graphics &gfx,Rectangle_ RectBox);

private:
	Graphics* gfx;
	Rectangle_ CollisionBox;
	Draw *RendObj = new Draw(gfx);

public:
	void DrawOnScreen();

};
