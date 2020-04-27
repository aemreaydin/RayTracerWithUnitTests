#pragma once
#include <vector>

struct XColor;

class XCanvas
{
public:
	explicit XCanvas(size_t width = 256, size_t height = 256);

	size_t GetWidth() const;
	size_t GetHeight() const;
	std::vector<XColor> GetPixels() const;
	XColor GetPixel(size_t x, size_t y) const;
	void WriteToPixel(size_t x, size_t y, const XColor& value);

	void SetWidth(int width);
	void SetHeight(int height);
	
private:
	size_t Width;
	size_t Height;
	std::vector<XColor> VecPixels;
};
