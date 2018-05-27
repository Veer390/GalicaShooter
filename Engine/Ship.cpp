#include "Ship.h"

Ship::Ship(float health, Graphics & gfx, std::string SpriteName, Vector<int> SpawnLoc)
	:
	Health(health),
	Sprite(SpriteName),
	AObject(gfx,Rectangle_(Sprite.GetWidth(),Sprite.GetWidth(),SpawnLoc))
{}

void Ship::ShipDraw(Graphics& gfx)
{
	Sprite.Draw((CollisionBox.GetEndPoints())[1], gfx);
}
