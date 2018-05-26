#include "Draw.h"
#include <algorithm>
#include <functional>
#include <cmath>

Draw::Draw(Graphics *gfx)
	:
	gfx(gfx)
{}

// draw Line Algorithm   /* Note Improve Here Implement Bresenham's line algorithm For Faster Computation...*/
void Draw::DrawLine(Vector<int> StartPoint, Vector<int> EndPoint,Color c)
{
	float m = 0.0f;
	if (EndPoint.x != StartPoint.x)
	{
		m = (float)(EndPoint.y - StartPoint.y) / (EndPoint.x - StartPoint.x);

	}
	if (EndPoint.x != StartPoint.x&&std::abs( m) <= 1.0f)
	{
		if (StartPoint.x > EndPoint.x)
		{
			std::swap(StartPoint, EndPoint);
		}

		const float b = StartPoint.y - m * StartPoint.x;

		for (int x = StartPoint.x; x <= EndPoint.x; x++)
		{
			const float y = m * (float)x + b;
			gfx->PutPixel(x, (int)y, c);
		}
	}
	else
	{
		if (StartPoint.y > EndPoint.y)
		{
			std::swap(StartPoint, EndPoint);
		}

		const float w = (EndPoint.x - StartPoint.x) / (EndPoint.y - StartPoint.y);
		const float p = StartPoint.x - w * StartPoint.y;
		for (int y = (int)StartPoint.y; y <= (int)EndPoint.y; y++)
		{
			const float x = w * (float)y + p;
			gfx->PutPixel((int)x, y, c);
		}
	}
}

void Draw::DrawRectangle_Outline(Rectangle_* RectToDraw, Color c)
{
	for (int i = 0; i < 3; i++)
	{
		DrawLine((RectToDraw->GetEndPoints())[i], (RectToDraw->GetEndPoints())[i + 1],c);
		
	}
	DrawLine((RectToDraw->GetEndPoints())[3], (RectToDraw->GetEndPoints())[0], c);
}
