#include "XCanvas.h"
#include "XColor.h"

XCanvas::XCanvas(const size_t width, const size_t height)
{
	Width = width;
	Height = height;

	VecPixels.resize(Width * Height);
}

size_t XCanvas::GetWidth() const
{
	return Width;
}

size_t XCanvas::GetHeight() const
{
	return Height;
}

std::vector<XColor> XCanvas::GetPixels() const
{
	return VecPixels;
}

XColor XCanvas::GetPixel(const size_t x, const size_t y) const
{
	return VecPixels[x * Width + y];
}

void XCanvas::WriteToPixel(const size_t x, const size_t y, const XColor& value)
{
	VecPixels[x * Width + y] = value;
}

void XCanvas::SetWidth(const int width)
{
	Width = width;
}

void XCanvas::SetHeight(const int height)
{
	Height = height;
}
