#include <iostream>
#include "bmp.h"
#include "3.h"
#include "4.h"
#include "5-6.h"
#include "7.h"
#include "8-11.h"
#include "12-13.h"
#include "14-16.h"
#include "dop.h"

using namespace std;

int main() {
	BITMAPFILEHEADER bfh;
	BITMAPINFOHEADER bih;
	FILE* f1;
	f1 = fopen("Original.bmp", "rb");
	if (f1 == NULL)
	{
		cout << "ERROR";
		return 0;
	}
	RGB** rgb = read_bmp(f1, &bfh, &bih);
	fclose(f1);
	int height = bih.biHeight;
	int width = bih.biWidth;

	/*
	set style data histograms
	plot 'dopFreqY_00.txt' using 2:xtic(1)
	*/

	/*
 width=5
bin(x, s) = s*int(x/s) + width/2
set boxwidth width
plot 'histogramRed.txt' u (bin($1,width)):(1.0) s f w boxes fs solid 0.5 
	*/

	Get_color get_color(&bfh, &bih, rgb, height, width);
	//Corelation correlaion(height, width, rgb);
	Direct_conversion direct_conversion(&bfh, &bih, rgb, height, width);	
	Reverse_conversion reverse_conversion(&bfh, &bih, direct_conversion.get_YCbCr(), height, width, rgb);
	Decimation decimation(direct_conversion.get_YCbCr(), height, width, &bfh, &bih, rgb);
	Frequency frequency(rgb, height, width, direct_conversion.get_YCbCr());
	DPCM dpcm(height, width, rgb, direct_conversion.get_YCbCr());
	Subframes(height, width, direct_conversion.get_YCbCr(), &bfh, &bih);

	return 0;
}