#pragma once
#include "Colors.h"
#include <string>
#include "RectI.h"
class Surface {
public:
	Surface(const std::string& filename);
	Surface(int in_width, int in_height);
	Surface(const Surface& rhs);
	~Surface();
	Surface& operator=(const Surface& rhs);
	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;
	int GetWidth() const;
	int Getheight() const;
	RectI GetRect() const;
private:
	Color* ppixels = nullptr;//pointer to pixel array
	int width;
	int height;
};