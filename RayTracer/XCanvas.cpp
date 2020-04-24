#include "XCanvas.h"
#include "XVector.h"

XCanvas::XCanvas(const int width, const int height)  {
	mWidth = width;
	mHeight = height;

	// TODO: Either use 1D Vector with indexing or C 1D Array
	mVecPixels.resize(mWidth, std::vector<XVector>(mHeight));

	//auto** pixels = new XVec3*[mWidth];
	//for(auto row = 0; row != mWidth; ++row) {
	//	pixels[row] = new XVec3[mHeight];
	//}
	//
	//mVecPixels.resize(static_cast<size_t>(mWidth) * static_cast<size_t>(mHeight));
	
	//pixels = new XVec3[mWidth * mHeight];
}

//XCanvas::~XCanvas() {
//	delete[] pixels;
//}

int XCanvas::GetWidth() const {
	return mWidth;
}
int XCanvas::GetHeight() const {
	return mHeight;
}

std::vector<std::vector<XVector>> XCanvas::GetPixels() const {
	return mVecPixels;
}

XVector XCanvas::GetPixel(const size_t x, const size_t y) const {
	return mVecPixels[x][y];
}
void XCanvas::WritePixel(const size_t x, const size_t y, const XVector& value) {
	mVecPixels[x][y] = value;
}

//XVec3 XCanvas::GetPixelAtIndex(const int x, const int y) const {
//	return pixels[x + mWidth * y];
//}

void XCanvas::SetWidth(const int width) {
	mWidth = width;
}
void XCanvas::SetHeight(const int height) {
	mHeight = height;
}
