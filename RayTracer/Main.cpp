#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include "XMatrix.h"
#include "XColor.h"
#include "XCanvas.h"
#include "XImageManager.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	const auto nx = 256;
	const auto ny = 256;

	const auto midX = nx / 2;
	const auto midY = ny / 2;
	const auto radius = 25.0f;
	
	XCanvas canvas(nx, ny);

	for(auto i = 0; i != nx; ++i)
	{
		for(auto j = 0; j != ny; ++j)
		{
			canvas.WriteToPixel(i, j, XColor(255.0f, 0.0f, 0.0f));
		}
	}

	for(auto i = 0; i != 12; i++)
	{
		auto point = XVector4();
		auto mat = XMatrix::Identity();
		XMatrix::Translate(mat, XVector4(radius, 0.0f, 0.0f), point);
		XMatrix::RotateZ(mat, i * (PI / 6.0f), point);

		canvas.WriteToPixel(midX + static_cast<size_t>(point.X), midY + static_cast<size_t>(point.Y), XColor(255.0f, 255.0f, 1.0f));
	}
		
	XImageManager::SaveCanvasAsPpm("color.ppm", canvas);

	return 0;
}
