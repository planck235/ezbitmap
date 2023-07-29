#include <stdio.h>

#include "ezbitmap.h"

BITMAPFILEHEADER create_ezbitmap_file(uint32_t offbits, uint32_t imagesize)
{
  BITMAPFILEHEADER filehdr = {0};

  filehdr.bfOffBits = offbits; /* sizeof(filehdr) + sizeof(infohdr) */
  filehdr.bfSize = offbits + imagesize; /* total filesize */

  return filehdr;
}

BITMAPINFOHEADER create_ezbitmap_info(int32_t width, int32_t height, uint16_t bitcount, uint32_t imagesize)
{
  BITMAPINFOHEADER infohdr = {0};

  infohdr.biSize = BISIZE;      /* sizeof(infohdr) */
  infohdr.biPlanes = BIPLANES;  /* 1 plane */
  infohdr.biWidth = width;
  infohdr.biHeight = height;
  infohdr.biBitCount = bitcount;
  infohdr.biSizeImage = imagesize;

  return infohdr;
}
