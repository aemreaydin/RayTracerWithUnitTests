#include <iostream>

#include "XVector.h"
#include "XCanvas.h"
#include "XMath.h"
#include "XImageManager.h"


int main() {

	XCanvas canvas;

	const auto nx = 256;
	const auto ny = 256;
	for(auto j = ny - 1; j >= 0; j--)
	{
		for(auto i = 0; i != nx; i++) {
			XVector vec(static_cast<float>(i) / nx, static_cast<float>(j) / ny, 0.2f);
			vec *= 255.0f;

			canvas.WritePixel(i, j, vec);
		}
	}
	XImageManager::SaveCanvasAsPpm("color.ppm", canvas);

	return 0;
}