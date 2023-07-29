#ifndef _EZBITMAP_H
#define _EZBITMAP_H

#include <stdint.h>

#pragma pack(push, 1)           /* pragma pack is to ensure all bitmap data is ordered corrently, pushing every variable one by one to the stack without padding */
typedef struct
{
  uint16_t bfType;
  uint32_t bfSize;              /* bitmap total file size defined as (((width * bitcount + 31) / 32) * 4) * height */
  uint16_t bfReserved1;
  uint16_t bfReserved2;
  uint32_t bfOffBits;           /* offbits typically defined as sizeof(file header) + sizeof(info header) which always results in 54 considering the sum of all the variable sizes in the two structures */
} BITMAPFILEHEADER;

typedef struct
{
  uint32_t biSize;              /* information buffer size, this contains the size of the information loaded at the beginning of each bitmap file. always size(BITMAPINFOHEADER) = 40 */
  int32_t  biWidth;             /* image width and height */
  int32_t  biHeight;
  uint16_t biPlanes;            /* number of colour planes (must be 1) */
  uint16_t biBitCount;          /* bitcount is almost always equal to 24, that's because there are three 8-bit channels for RGB, where 8*3 = 24, capable of representing about 16.7m colors */
  uint32_t biCompression;       /* usually bitmap files are uncompressed */
  uint32_t biSizeImage;         /* this is equal to the image's total size */
  int32_t  biXPelsPerMeter;
  int32_t  biYPelsPerMeter;
  uint32_t biClrUsed;
  uint32_t biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

#define OFFBITS sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)
#define BISIZE sizeof(BITMAPINFOHEADER)
#define BIPLANES 1              /* default 1 plane */
#define BITCOUNT 24             /* default 24-bit bitmap */

#define WIDTH_IN_BYTES(W) ((W * BITCOUNT + 31) / 32) * 4
#define IMAGESIZE(W, H) (((W * BITCOUNT + 31) / 32) * 4) * H

BITMAPINFOHEADER create_ezbitmap_info(int32_t, int32_t, uint16_t, uint32_t);
BITMAPFILEHEADER create_ezbitmap_file(uint32_t, uint32_t);

#endif
