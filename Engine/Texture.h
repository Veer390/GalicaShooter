#pragma once
#include <fstream>
#include <string>
#include "ChiliWin.h"
#include "Colors.h"
#include "Graphics.h"
#include "Vector.h"

namespace Surface
{
	class Texture
	{
	public:
		//Default constructor
		Texture();

		//Constructor Which Loads Texture Data From BMP
		Texture(const std::string FileName);

		//Main Constructor Which Should Be Used..
		Texture(int width, int height);

	private:
		//main pixels pointer
		Color * Pixels = nullptr;
		//width of the texture
		int Width = 0;
		//height of the texture
		int Height = 0;

		//Main Functions For the Class
		void PutPixel(int x, int y, Color c);
		Color GetPixel(int x, int y) const;


	public:
		void Draw(Vector<int> Point, Graphics& gfx);


	public:
		~Texture();
		Texture& operator=(const Texture& rhs);

	};
}