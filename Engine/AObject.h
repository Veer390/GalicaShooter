#pragma once
#include "Colors.h"
#include "Graphics.h"
#include "Vector.h"
#include "Rectangle.h"
#include "Draw.h"

class AObject
{
protected:
	//Constructors
	AObject() = delete;
	//An Aobject Can Exist Without a gfx object and rectbox this rectbox can be used for collision..
	AObject(Graphics &gfx,Rectangle_ RectBox);

	//to set Custom flag Values
	AObject(Graphics &gfx, Rectangle_ Rectbox, bool SimulatePhysics, bool DrawObject, bool DrawCollisionBox);

protected:
	//Main Graphics object for the object used for drawing stuff to the screen
	Graphics* gfx;
	//Rectangle Box Holds the Rectangle Collision Box.. Must For any Object..
	Rectangle_ CollisionBox;
	//Draw Object Used Draw The Object To The Screen
	Draw *RendObj = new Draw(gfx);

protected:
	//flag Variables:
	
	//Simulates Physics Either True Or false
	bool SimulatePhysics=true;
	//Draws The Entire Object
	bool DrawObject=true;
	//Draws the Collision Boxx only
	bool DrawCollisionBox = false;
	
public:
	void DrawRectangle_CollisionMesh(Color c);

};
