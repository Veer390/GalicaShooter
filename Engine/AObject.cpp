#include "AObject.h"

AObject::AObject(Graphics & gfx, Rectangle_ RectBox)
	:
	gfx(&gfx),
	CollisionBox(RectBox)
{}

void AObject::DrawOnScreen()
{
	RendObj->DrawRectangle_Outline(&CollisionBox, { 255,255,255 });
}
