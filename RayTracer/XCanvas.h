#pragma once
#include <vector>

struct XVec3;

class XCanvas
{
public:
	explicit XCanvas(int width = 256, int height = 256);

	int GetWidth() const;
	int GetHeight() const;
	std::vector<std::vector<XVec3>> GetPixels() const;
	XVec3 GetPixel(size_t x, size_t y) const;
	void WritePixel(size_t x, size_t y, const XVec3& value);
	//std::vector<XVec3> GetPixels() const;
	//XVec3 GetPixelAtIndex(int x, int y) const;

	void SetWidth(int width);
	void SetHeight(int height);
private:
	
	int mWidth;
	int mHeight;
	//std::vector<XVec3> mVecPixels;
	std::vector<std::vector<XVec3>> mVecPixels;
	//XVec3* pixels;
};