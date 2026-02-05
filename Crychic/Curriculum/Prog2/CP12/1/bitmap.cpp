#include "bitmap.h"
#include <iostream>
#include <cstring>
#include <cstdio>

CBitmap::CBitmap()
{
    Bits = nullptr;
}

CBitmap::CBitmap(int width, int height)
{
    Bits = nullptr;
    Create(width, height);
}

CBitmap::CBitmap(const CBitmap &x)
{
    Bits = nullptr;
    BITMAPINFOREHEADER info = x.GetInfo();
    BYTE* xbits = x.GetBits(0, info.biHeight - 1);
    if(xbits != NULL)
    {
        Create(info.biWidth, info.biHeight);
        std::memcpy(Bits, xbits, info.biSizeImage);
    }
}

CBitmap& CBitmap::operator=(const CBitmap &x)
{
    Release();

    BITMAPINFOREHEADER info = x.GetInfo();
    BYTE* xbits = x.GetBits(0, info.biHeight - 1);
    if(xbits != NULL)
    {
        BITMAPINFOREHEADER info = x.GetInfo();
        Create(info.biWidth, info.biHeight);
        std::memcpy(Bits, xbits, info.biSizeImage);
    }
    return *this;
}

CBitmap::~CBitmap()
{
    Release();
}

void CBitmap::Create(int width, int height)
{
    Release();

    Info.biSize = sizeof(BITMAPINFOREHEADER);
    Info.biWidth = width;
    Info.biHeight = height;
    Info.biPlanes = 1;
    Info.biBitCount = 24;
    Info.biCompression = 0;
    Info.biSizeImage = width * height * 3;
    Info.biXPelsPerMeter = 0;
    Info.biYPelsPerMeter = 0;
    Info.biClrUsed = 0;
    Info.biClrImportant = 0;

    Bits = new BYTE[Info.biSizeImage];
}

void CBitmap::Release()
{
    if(Bits != nullptr)
    {
        delete[] Bits;
        Bits = nullptr;
    }
}

bool CBitmap::SaveBmp(string path) const
{
    FILE* fp ;
    if(NULL==(fp = fopen(path.c_str(), "wb")))
        return false;

    DWORD bfType = (WORD)('M'<<8)|'B';
    DWORD bfSize = 14+ Info.biSize + Info.biSizeImage;
    DWORD bfReserved1 = 0;
    DWORD bfReserved2 = 0;
    DWORD bfOffBits = 14 + Info.biSize;

    fwrite(&bfType, 2, 1, fp);
    fwrite(&bfSize, 4, 1, fp);
    fwrite(&bfReserved1, 2, 1, fp);
    fwrite(&bfReserved2, 2, 1, fp);
    fwrite(&bfOffBits, 4, 1, fp);
    fwrite(&Info, Info.biSize, 1, fp);
    fwrite(Bits, sizeof(BYTE), Info.biSizeImage, fp);

    fclose(fp);
    return true;
}

BYTE* CBitmap::GetBits(int x, int y) const
{
    int w=Info.biWidth;
    int h=Info.biHeight;
    if(x<0 || x>=w || y<0 || y>=h )
        return nullptr;
    return Bits + (h - 1 - y) * (w * 3) + x * 3;
}

void CBitmap::SetPixel(int x, int y, COLORREF color)
{
    BYTE* p = GetBits(x, y);
    if(p)
    {
        p[0] = GetBValue(color);
        p[1] = GetGValue(color);
        p[2] = GetRValue(color);
    }
}

void CBitmap::DrawFunctionImage(COLORREF (*F)(int x, int y))
{
    int w = Info.biWidth;
    int h = Info.biHeight;
    for(int y=0; y<h; y++)
    {
        BYTE* p = GetBits(0, y);
        for(int x=0; x<w; x++)
        {
            COLORREF color =F(x,y);
            p[0] = GetBValue(color);
            p[1] = GetGValue(color);
            p[2] = GetRValue(color);
            p += 3;
        }
    }
}