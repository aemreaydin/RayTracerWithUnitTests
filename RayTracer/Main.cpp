#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>


#include "XColor.h"
#include "XCanvas.h"
#include "XImageManager.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	

	const auto nx = 4096;
	const auto ny = 4096;
	XCanvas canvas(nx, ny);
	for (auto j = ny - 1; j >= 0; j--)
	{
		for (auto i = 0; i != nx; i++)
		{
			XColor color(static_cast<float>(i) / nx, static_cast<float>(j) / ny, 0.2f);
			color *= 255.0f;

			canvas.WriteToPixel(i, j, color);
		}
	}
	XImageManager::SaveCanvasAsPpm("color.ppm", canvas);

	return 0;
}
