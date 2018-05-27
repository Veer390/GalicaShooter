#pragma once
#include "Colors.h"
#include "Graphics.h"
#include "Texture.h"
#include "Vector.h"
#include "Rectangle.h"
#include "AObject.h"
#include <string>

class Ship:protected AObject /*Aobjected is inherited as protected... so that this can be drawn to the screen at will A ship can have input too and fire projectiles too...*/
{
public:
	//Default constructor is deleted cannot exist without gfx,health and sprite
	Ship() = delete;

	//Constructor To Be Used As Default
	Ship(float health, Graphics& gfx, std::string SpriteName,Vector<int> SpawnLoc);


protected:
	//vector to hold location of the player ship
	Vector<int> Loc = { 600,600 };

	//health that this ship has....
	float Health = 100.0f;
	
	//Texture for this ship
	Surface::Texture Sprite;
	
public:
	void ShipDraw(Graphics& gfx);
	
	

};