#include "AObject.h"

AObject::AObject(Graphics & gfx, Rectangle_ RectBox)
	:
	gfx(&gfx),
	CollisionBox(RectBox)
{}

AObject::AObject(Graphics & gfx, Rectangle_ Rectbox, bool SimulatePhysics, bool DrawObject, bool DrawCollisionBox)
	:
	gfx(&gfx),
	CollisionBox(Rectbox),
	SimulatePhysics(SimulatePhysics),
	DrawObject(DrawObject),
	DrawCollisionBox(DrawCollisionBox)
{}

void AObject::DrawRectangle_CollisionMesh(Color c)
{
	RendObj->DrawRectangle_Outline(&CollisionBox, c);
}
