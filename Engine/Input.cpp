#include "Input.h"
#include "ChiliWin.h"

MainInput::MainInput(Keyboard & kbd)
	:
	kbd(&kbd)
{}

//Garbage Function Sub optimal And Never should be used 
//PROBLEM------- Down Centric.....
InputStructure MainInput::ListenAndReturnInput()
{
	InputStructure Inp = InputStructure::Nothing;

	if (kbd->KeyIsPressed(0x27))
	{
		Inp = InputStructure::RightArrow;
	}
	if (kbd->KeyIsPressed(0x25))
	{
		Inp = InputStructure::LeftArrow;
	}
	if (kbd->KeyIsPressed(0x26))
	{
		Inp = InputStructure::UpArrow;
	}
	if (kbd->KeyIsPressed(0x28))
	{
		Inp = InputStructure::DownArrow;
	}
	if (kbd->KeyIsPressed(0x44))
	{
		Inp = InputStructure::DKey;
	}
	if (kbd->KeyIsPressed(0x41))
	{
		Inp = InputStructure::AKey;
	}
	if (kbd->KeyIsPressed(0x57))
	{
		Inp = InputStructure::WKey;
	}
	if (kbd->KeyIsPressed(0x53))
	{
		Inp = InputStructure::SKey;
	}
	if (kbd->KeyIsPressed(0x20))
	{
		Inp = InputStructure::SpaceBar;
	}
	if (kbd->KeyIsPressed(0x10))
	{
		Inp = InputStructure::LeftShift;
	}
	return Inp;
}

bool MainInput::ListenForKeyPress(InputStructure KeyToListen)
{
	if (KeyToListen == InputStructure::RightArrow)
	{
		if (kbd->KeyIsPressed(0x27))
		{
			return true;
		}
	}
	if (KeyToListen == InputStructure::LeftArrow)
	{
		if (kbd->KeyIsPressed(0x25))
		{
			return true;
		}
	}
	if (KeyToListen == InputStructure::UpArrow)
	{
		if (kbd->KeyIsPressed(0x26))
		{
			return true;
		}
	}
	if (KeyToListen == InputStructure::DownArrow)
	{
		if (kbd->KeyIsPressed(0x28))
		{
			return true;
		}
	}
	if (KeyToListen == InputStructure::SpaceBar)
	{
		if (kbd->KeyIsPressed(0x20))
		{
			return true;
		}
	}
	if (KeyToListen == InputStructure::DKey)
	{
		if (kbd->KeyIsPressed(0x44))
		{
			return true;
		}
	}
	if (KeyToListen == InputStructure::AKey)
	{
		if (kbd->KeyIsPressed(0x41))
		{
			return true;
		}
	}
	if (KeyToListen == InputStructure::WKey)
	{
		if (kbd->KeyIsPressed(0x57))
		{
			return true;
		}
	}
	if (KeyToListen == InputStructure::SKey)
	{
		if (kbd->KeyIsPressed(0x53))
		{
			return true;
		}
	}
	if (KeyToListen == InputStructure::LeftShift)
	{
		if (kbd->KeyIsPressed(0x10))
		{
			return true;
		}
	}
	return false;
}

std::vector<bool> MainInput::ListenForMultipleKeyPresses(std::vector<InputStructure> StructureToWork)
{
	std::vector<bool> ReturnVec;
	for (auto i : StructureToWork)
	{
		ReturnVec.emplace_back(ListenForKeyPress(i));
	}
	return ReturnVec;
}
