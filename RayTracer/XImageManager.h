#pragma once

#include "XCanvas.h"
#include "XColor.h"
#include "XMath.h"

#include <fstream>

class XImageManager
{
public:
	static void SaveCanvasAsPpm(const char* filename, const XCanvas& canvas)
	{
		std::ofstream file(filename);
		if (!file.is_open())
			throw std::runtime_error("Failed to open the image.");

		WritePpmHeader(canvas, file);
		WritePpmBody(canvas, file);
	}

private:
	enum class EImageType
	{
		Ppm
	};

	static void WriteHeader(const EImageType imageType, const XCanvas& canvas, std::ofstream& output)
	{
		switch (imageType)
		{
		case EImageType::Ppm:
			WritePpmHeader(canvas, output);
			break;
		default: ;
			throw std::runtime_error("Failed to obtain the type.");
		}
	}

	static void WritePpmHeader(const XCanvas& canvas, std::ofstream& output)
	{
		output << "P3\n";
		output << canvas.GetWidth() << " " << canvas.GetHeight() << '\n';
		output << 255 << '\n';
	}

	static void WritePpmBody(const XCanvas& canvas, std::ofstream& output)
	{
		for (size_t i = 0; i != canvas.GetHeight(); i++)
		{
			for (size_t j = 0; j != canvas.GetWidth(); j++)
			{
				output << static_cast<int>(XMath::Clamp(canvas.GetPixel(i, j).Color.X, 0.0F, 255.0F)) << " "
					<< static_cast<int>(XMath::Clamp(canvas.GetPixel(i, j).Color.Y, 0.0F, 255.0F)) << " "
					<< static_cast<int>(XMath::Clamp(canvas.GetPixel(i, j).Color.Z, 0.0F, 255.0F)) << " ";
			}
			output << '\n';
		}
	}
};
