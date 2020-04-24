#include "XCanvas.h"
#include "XVector.h"

XCanvas::XCanvas(const int width, const int height)  {
	Width = width;
	Height = height;

	// TODO: Either use 1D Vector with indexing or C 1D Array
	VecPixels.resize(Width, std::vector<XVector>(Height));

	//auto** pixels = new XVec3*[Width];
	//for(auto row = 0; row != Width; ++row) {
	//	pixels[row] = new XVec3[Height];
	//}
	//
	//VecPixels.resize(static_cast<size_t>(Width) * static_cast<size_t>(Height));
	
	//pixels = new XVec3[Width * Height];
}

//XCanvas::~XCanvas() {
//	delete[] pixels;
//}

int XCanvas::GetWidth() const {
	return Width;
}
int XCanvas::GetHeight() const {
	return Height;
}

std::vector<std::vector<XVector>> XCanvas::GetPixels() const {
	return VecPixels;
}

XVector XCanvas::GetPixel(const size_t x, const size_t y) const {
	return VecPixels[x][y];
}
void XCanvas::WriteToPixel(const size_t x, const size_t y, const XVector& value) {
	VecPixels[x][y] = value;
}

//XVec3 XCanvas::GetPixelAtIndex(const int x, const int y) const {
//	return pixels[x + Width * y];
//}

void XCanvas::SetWidth(const int width) {
	Width = width;
}
void XCanvas::SetHeight(const int height) {
	Height = height;
}
