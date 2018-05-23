#pragma once
#include "Graphics.h"
#include "Vector.h"
#include <vector>

class Rectangle
{
public:
	//Constructors
	Rectangle()=delete;

	//standrad constructor constructs a rectangle with width and height and center
	Rectangle(int width, int height,Vector<int> Centre,Graphics& gfx);

	Rectangle(std::vector<Vector<int>> EndPoints,Graphics& gfx);

	
private:
	//stores the centre of the given rectangle
	Vector<int> Centre;

	//stores all the endpoints of a given rectangle                        0 means top right goes Anti Clockwise from there
	std::vector<Vector<int>> EndPoints;
    //Stores Width of the rectangle
	int width;
	//Stores height if the rectangle
	int height;

	bool DebugDrawFlag = false;

	//Stores a reference to the Graphics object
	Graphics* gfx;
	
	//helper Functions
public:
	//gets width of the rectangle
	int GetWidth();
	//gets height of the rectangle
	int GetHeight();

	//gets the centre of the rectangle
	Vector<int> GetCentre();

	//sets the debug draw flag of the rectangle...... if SetDebugDrawFlag is set to true the physics must draw outline of the rectangle...
	void SetDebugDrawFlag(bool newval);

	//Computes End Points using data from the centre and height and width and then proceeds to set the end points of the rectangle...
	void RComputeEndPoints();

	//Set Width of the rectangle
	void SetWidth(int NewWidth);

	//Set Height of the rectangle
	void SetHeight(int NewHeight);

	         //Main Functional Functions for the outside world....
public:
	//This Function Must Be Wired Up To The Class Which Has A Rectangle Object embedded inside it is vital to run on every frame of the program execution...
	void RMain(Graphics& gfx);


	//used By the external program to move the rectangle around If the center is Moved immediately new values are computed for end points and stored in the endpoints vector..
	void MoveCentre(Vector<int> NewLoc);

	



};