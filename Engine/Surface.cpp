#include "Surface.h"
#include <assert.h>
#include"ChiliWin.h"
#include<fstream>

Surface::Surface(const std::string & filename)
{
	std::ifstream file(filename, std::ios::binary);
	BITMAPFILEHEADER bmf;
	file.read(reinterpret_cast<char*>(&bmf),sizeof(bmf));
	BITMAPINFOHEADER bmifh;
	file.read(reinterpret_cast<char*>(&bmifh), sizeof(bmifh));
	assert(bmifh.biBitCount == 24|| bmifh.biBitCount == 32);
	const bool is32b = bmifh.biBitCount == 32;
	assert(bmifh.biCompression == BI_RGB);
	width = bmifh.biWidth;
	height = bmifh.biHeight;
	file.seekg(bmf.bfOffBits);
	
	int yStart = height - 1;
	int yEnd = -1;
	int dy = -1;
	if (bmifh.biHeight < 0)
	{
		height = -bmifh.biHeight;
		yStart = 0;
		yEnd = height;
		dy = 1;
	}
	else {
		height = bmifh.biHeight;
		yStart = height - 1;
		yEnd = -1;
		dy = -1;
	}
	ppixels = new Color[width*height];
	const int padding = (4 - (width * 3) % 4) % 4;
	for (int y = yStart; y != yEnd; y+=dy) {
		for (int x = 0; x < width; x++) {
			const unsigned char b = file.get();
			const unsigned char g = file.get();
			const unsigned char r = file.get();
			PutPixel(x, y, { r,g,b });
			if (is32b) {
				file.seekg(1, std::ios::cur);
			}
		}
		if (!is32b) {
			file.seekg(padding, std::ios::cur);
		}
	}
}

Surface::Surface(int in_width, int in_height)
	:
	width(in_width),
	height(in_height),
	ppixels(new Color[in_width*in_height])
{
}

Surface::Surface(const Surface & rhs)
	:
	Surface(rhs.width,rhs.height)

{
	const int nPixels = width * height;
	for (int i = 0; i < nPixels; i++) {
		ppixels[i] = rhs.ppixels[i];
	}
}

Surface::~Surface()
{
	delete[] ppixels;
	ppixels = nullptr;
}

Surface & Surface::operator=(const Surface & rhs)
{
	width = rhs.width;
	height = rhs.height;
	delete[] ppixels;
	ppixels = new Color[width*height];
	const int nPixels = width * height;
	for (int i = 0; i < nPixels; i++) {
		ppixels[i] = rhs.ppixels[i];
	}
	return *this;
}

void Surface::PutPixel(int x, int y, Color c)
{
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);
	ppixels[y*width + x] = c;
}

Color Surface::GetPixel(int x, int y) const
{
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);
	return ppixels[y*width + x];
}

int Surface::GetWidth() const
{
	return width;
}

int Surface::Getheight() const
{
	return height;
}

RectI Surface::GetRect() const
{
	return {0,width,0,height};
}
