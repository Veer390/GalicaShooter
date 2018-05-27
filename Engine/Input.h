#pragma once
#include "Vector.h"
#include "Keyboard.h"
#include <vector>

enum class InputStructure
{
	RightArrow = 1,
	LeftArrow = -1,
	UpArrow = 2,
	DownArrow = -2,
	SpaceBar = 3,

	DKey = 10,
	AKey = -10,
	WKey = 20,
	SKey = -20,
	LeftShift = 30,

	Nothing = 99
};

class MainInput
{
public:
	//Default Constructor is deleted 
	MainInput() = default;

	//Use this as a default constructor
	MainInput(Keyboard& kbd);

private:
	//holds a reference to the keyboard so that functions can use it
	Keyboard * kbd;

public:
	//main functions for this class

	//Listen for the key press and returns which key is pressed uses priority order
	InputStructure ListenAndReturnInput();

	//Checks if a key is pressed and returns a boolean returns false if cant index...
	bool ListenForKeyPress(InputStructure KeyToListen);

	//Takes A std::vector and checks which key is pressed returns a std vector of bool with corresponding trues and falses
	std::vector<bool> ListenForMultipleKeyPresses(std::vector<InputStructure> StructureToWork);

};