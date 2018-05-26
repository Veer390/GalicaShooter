#pragma once
#include <vector>
#include "Vector.h"

class Rectangle_
{
public:
	//Constructors
	Rectangle_()=delete;

	//standrad constructor constructs a Rectangle_ with width and height and center
	Rectangle_(int width, int height,Vector<int> Centre);

	Rectangle_(std::vector<Vector<int>> EndPoints);

	
private:
	//stores the centre of the given Rectangle_
	Vector<int> Centre;

	//stores all the endpoints of a given Rectangle_                        0 means top right goes Anti Clockwise from there
	std::vector<Vector<int>> EndPoints;
    //Stores Width of the Rectangle_
	int width;
	//Stores height if the Rectangle_
	int height;

	bool DebugDrawFlag = false;
		
	//helper Functions
public:
	//gets width of the Rectangle_
	int GetWidth();
	//gets height of the Rectangle_
	int GetHeight();

	//gets the centre of the Rectangle_
	Vector<int> GetCentre();

	//gets end Points of the rectangle..
	std::vector<Vector<int>> GetEndPoints();

	//sets the debug draw flag of the Rectangle_...... if SetDebugDrawFlag is set to true the physics must draw outline of the Rectangle_...
	void SetDebugDrawFlag(bool newval);

	//Computes End Points using data from the centre and height and width and then proceeds to set the end points of the Rectangle_...
	void RComputeEndPoints();

	//Set Width of the Rectangle_
	void SetWidth(int NewWidth);

	//Set Height of the Rectangle_
	void SetHeight(int NewHeight);

	         //Main Functional Functions for the outside world....
public:
	//This Function Must Be Wired Up To The Class Which Has A Rectangle_ Object embedded inside it is vital to run on every frame of the program execution...
	void RMain();


	//used By the external program to move the Rectangle_ around If the center is Moved immediately new values are computed for end points and stored in the endpoints vector..
	void MoveCentre(Vector<int> NewLoc);

	



};