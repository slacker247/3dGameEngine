#include "LoadBMP.h"

namespace loaders
{
    typedef struct tagBITMAPFILEHEADER { 
      unsigned short   bfType; 
      unsigned long    bfSize; 
      unsigned short   bfReserved1; 
      unsigned short   bfReserved2; 
      unsigned long   bfOffBits; 
    } BITMAPFILEHEADER; 

    typedef struct tagBITMAPINFOHEADER{
      unsigned long  biSize; 
      long   biWidth; 
      long   biHeight; 
      unsigned short   biPlanes; 
      unsigned short   biBitCount; 
      unsigned long  biCompression; 
      unsigned long  biSizeImage; 
      long   biXPelsPerMeter; 
      long   biYPelsPerMeter; 
      unsigned long  biClrUsed; 
      unsigned long  biClrImportant;  
    } BITMAPINFOHEADER;

	String LoadBMP::STR_RB = newString("rb");
    int LoadBMP::height = 0;
    int LoadBMP::width = 0;
    int LoadBMP::size = 0;

    LoadBMP::LoadBMP()
    {
    }

    LoadBMP::~LoadBMP()
    {
    }

    //BYTE& BMPClass::pixel(int x,int y,int c)
    //{
    //	return bytes[(y * width + x) * 3 + c];
    //}

    String LoadBMP::TranslateBMPError(BMPError err)
    {
	    switch(err)
	    {
	    case(BMPNOTABITMAP):
		    return newString("This file is not a bitmap, specifically it doesn't start 'BM'");
	    case(BMPNOOPEN):
		    return newString("Failed to open the file, suspect it doesn't exist");
	    case(BMPFILEERROR):
		    return newString("ferror said we had an error. This error seems to not always mean anything, try ignoring it");
	    case(BMPBADINT):
		    return newString("sizeof(int)!=4 quite a lot of rewriting probably needs to be done on the code");
	    case(BMPNOERROR):
		    return newString("No errors detected");
	    case(BMPUNKNOWNFORMAT):
		    return newString("Unknown bmp format, ie not 24bit, 256,16 or 2 colour");
	    default:
		    return newString("Not a valid error code");
	    }
    }

    unsigned char* LoadBMP::loadBMP(String& fname)
    {
	    if(sizeof(int) != 4)
		    return NULL;
    //		return BMPBADINT;
    		
		// TODO : Abstract fopen
		FILE* f = _wfopen(fname.c_str(), STR_RB.c_str());		//open for reading in binary mode
	    if(!f)
		    return NULL;
    //		return BMPNOOPEN;

		
	    BITMAPFILEHEADER *bfh = new tagBITMAPFILEHEADER;
	    fread(&bfh->bfType, 2, 1, f);
	    fread(&bfh->bfSize, 4, 1, f);
	    fread(&bfh->bfReserved1, 2, 1, f);
	    fread(&bfh->bfReserved2, 2, 1, f);
	    fread(&bfh->bfOffBits, 4, 1, f);

	    unsigned short* t = &(bfh->bfType);
	    char* type = reinterpret_cast<char*>(t);
	    if(type[0] != 'B' || type[1] != 'M') 
	    {
		    fclose(f);
		    return NULL;
    //		return BMPNOTABITMAP;		//all bitmaps should start "BM"
	    }

		
	    BITMAPINFOHEADER *bih = new tagBITMAPINFOHEADER;
	    fread(bih, sizeof(BITMAPINFOHEADER), 1, f);

	    int bits = bih->biBitCount;		//colourdepth

	    // Dynamically create enough memory for the image.
	    unsigned char *bitmap = new unsigned char[bih->biSizeImage];

	    // Error checking.  Make sure the memory was allocated.
	    if(!bitmap)
	    {
		    delete bitmap;
		    fclose(f);
		    return NULL;
    //		return 0;
	    }

	    // Read in the image.
	    //fread(bitmap, 1, bih->biSizeImage, f);
	    fseek(f, bfh->bfOffBits, SEEK_SET);
	    int x = 0, h = 0;
	    while(!feof(f) && x+2 < bih->biSizeImage)
	    {
		    BYTE byte;
		    fread((BYTE *)&byte, sizeof(byte), 1, f);	//24bit is easy
		    bitmap[x+2] = byte; // BLUE
		    fread((BYTE *)&byte, sizeof(byte), 1, f);	//24bit is easy
		    bitmap[x+1] = byte; // GREEN
		    fread((BYTE *)&byte, sizeof(byte), 1, f);	//24bit is easy
		    bitmap[x] = byte; // RED
		    byte = bitmap[x+2];
		    x += 3;
	    }

	    // Error checking.  Make sure an image was loaded.
	    if(bitmap == 0)
	    {
		    fclose(f);
		    return NULL;
    //		return 0;
	    }

	    // This will be used to swap the image colors from BGR to RGB.
	    //unsigned char textureColors = 0;

	    //unsigned char ch = bitmap[328];

	    //// Bitmaps are saved in BGR format so we will make the image RGB by...
	    //for(int index = 0; index < (int)bih->biSizeImage; index+=3)
	    //{
	    //	textureColors = bitmap[index];
	    //	bitmap[index] = bitmap[index + 2];
	    //	bitmap[index + 2] = textureColors;
	    //}


	    //int x, y, c;
	    //BYTE cols[256*4];				//colourtable
	    //switch(bits)
	    //{
	    //case(24):
	    //	//fseek(f,offset,SEEK_SET);
	    //	//fread(bytes, sizeof(bytes), 1, f);	//24bit is easy
	    //	//for(x = 0; x < sizeof(bytes); x += 3)			//except the format is BGR, grr
	    //	//{
	    //	//	BYTE temp = bytes[x];
	    //	//	bytes[x]=bytes[x+2];
	    //	//	bytes[x+2]=temp;
	    //	//}
	    //	fseek(f,offset,SEEK_SET);
	    //	x = 0;
	    //	while(!feof(f))
	    //	{
	    //		BYTE byte;
	    //		fread((BYTE *)&byte, sizeof(byte), 1, f);	//24bit is easy
	    //		bytes[x+2] = byte; // BLUE
	    //		fread((BYTE *)&byte, sizeof(byte), 1, f);	//24bit is easy
	    //		bytes[x+1] = byte; // GREEN
	    //		fread((BYTE *)&byte, sizeof(byte), 1, f);	//24bit is easy
	    //		bytes[x] = byte; // RED
	    //		x += 3;
	    //		byte = bytes[x];
	    //	}
	    //	break;

	    //case(8):
	    //	fread(cols,256*4,1,f);							//read colortable
	    //	fseek(f,offset,SEEK_SET);
	    //	for(y = 0; y < height; ++y)						//(Notice 4bytes/col for some reason)
	    //		for(x = 0; x < width; ++x)
	    //		{
	    //			BYTE byte;			
	    //			fread(&byte, 1, 1, f);						//just read byte					
	    //			for(int c = 0; c < 3; ++c)
	    //				pixel(x, y, c) = cols[byte * 4 + 2 - c];	//and look up in the table
	    //		}
	    //	break;

	    //case(4):
	    //	fread(cols, 16 * 4, 1, f);
	    //	fseek(f, offset, SEEK_SET);
	    //	for(y = 0; y < 256; ++y)
	    //		for(x = 0; x < 256; x += 2)
	    //		{
	    //			BYTE byte;
	    //			fread(&byte, 1, 1, f);						//as above, but need to exract two
	    //			for(c = 0; c < 3; ++c)						//pixels from each byte
	    //				pixel(x, y, c) = cols[byte/16 * 4 + 2 - c];
	    //			for(c = 0; c < 3; ++c)
	    //				pixel(x + 1, y, c) = cols[byte%16 * 4 + 2 - c];
	    //		}
	    //	break;

	    //case(1):
	    //	fread(cols, 8, 1, f);
	    //	fseek(f, offset, SEEK_SET);
	    //	for(y = 0; y < height; ++y)
	    //		for(x = 0; x < width; x += 8)
	    //		{
	    //			BYTE byte;
	    //			fread(&byte, 1, 1, f);
	    //			//Every byte is eight pixels
	    //			//so I'm shifting the byte to the relevant position, then masking out
	    //			//all but the lowest bit in order to get the index into the colourtable.
	    //			for(int x2 = 0; x2 < 8; ++x2)
	    //				for(int c = 0; c < 3; ++c)
	    //					pixel(x + x2, y, c) = cols[((byte>>(7 - x2))&1)* 4 + 2 - c];
	    //		}
	    //	break;

	    //default:
	    //	fclose(f);
	    //	return BMPUNKNOWNFORMAT;
	    //}

	    if(ferror(f))
	    {
		    fclose(f);
		    return NULL;
    //		return BMPFILEERROR;
	    }
    	
	    fclose(f);

	    LoadBMP::width = bih->biWidth;
	    LoadBMP::height = bih->biHeight;
	    LoadBMP::size = bih->biSizeImage;

	    return bitmap;
	    //return BMPNOERROR;
    }
}