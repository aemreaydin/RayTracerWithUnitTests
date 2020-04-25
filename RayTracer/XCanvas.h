#pragma once
#include <vector>

struct XVector;

class XCanvas
{
public:
	explicit XCanvas(int width = 256, int height = 256);

	int GetWidth() const;
	int GetHeight() const;
	std::vector<std::vector<XVector>> GetPixels() const;
	XVector GetPixel(size_t x, size_t y) const;
	void WriteToPixel(size_t x, size_t y, const XVector& value);

	void SetWidth(int width);
	void SetHeight(int height);
private:

	int Width;
	int Height;
	std::vector<std::vector<XVector>> VecPixels;
};
