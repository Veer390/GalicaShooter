#include "Texture.h"
#include <cassert>

Surface::Texture::Texture()
	:
	Width(0),
	Height(0),
	Pixels(new Color[Width*Height])
{}

Surface::Texture::Texture(const std::string FileName)
{
	std::ifstream file(FileName, std::ios::binary);

	BITMAPFILEHEADER bmfileheader;
	file.read(reinterpret_cast<char*>(&bmfileheader), sizeof(bmfileheader));

	BITMAPINFOHEADER bmInfoHeader;
	file.read(reinterpret_cast<char*>(&bmInfoHeader), sizeof(bmInfoHeader));

	assert(bmInfoHeader.biBitCount == 24);
	assert(bmInfoHeader.biCompression == BI_RGB);

	Width = bmInfoHeader.biWidth;
	Height = bmInfoHeader.biHeight;

	Pixels = new Color[Width*Height];

	file.seekg(bmfileheader.bfOffBits);
	const int padding = (4 - (Width * 3) % 4) % 4;

	for (int y = Height-1; y >= 0; y--)
	{
		for (int x = 0; x < Width; x++)
		{
			PutPixel(x, y, Color(file.get(), file.get(), file.get()));
		}
		file.seekg(padding, std::ios::cur);
	}
	
}

Surface::Texture::Texture(int width, int height)
	:
	Width(width),
	Height(height),
	Pixels(new Color[Width*Height])
{}

void Surface::Texture::PutPixel(int x, int y, Color c)
{
	Pixels[y*Width + x] = c;
}

Color Surface::Texture::GetPixel(int x, int y) const
{
	return Pixels[y*Width+x];
}

void Surface::Texture::Texture::Draw(Vector<int> Point, Graphics & gfx)
{
	int x = Point.x;
	int y = Point.y;

	for (int sx = 0; sx < Width; sx++)
	{
		for (int sy = 0; sy < Height; sy++)
		{
			if(x+sx <=Graphics::ScreenWidth&&y+sy<=Graphics::ScreenHeight)
			gfx.PutPixel(x + sx, y + sy, GetPixel(sx, sy));
		}
	}
}

Surface::Texture::~Texture()
{
	delete[] Pixels;
	Pixels = nullptr;
}

Surface::Texture & Surface::Texture::operator=(const Texture & rhs)
{
	//NOT YET IMPLEMNTED WORK IN PROGRESS
	return *this;
}

