#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ezbitmap.h"

void write_bitmap(char* filepath, BITMAPFILEHEADER filehdr, BITMAPINFOHEADER infohdr)
{
  int width_in_bytes = WIDTH_IN_BYTES(infohdr.biWidth);

  memcpy(&filehdr, "BM", 2);    /* bitmap signature */

  srand(time(NULL));

  /* pixel data preparation */
  unsigned char* buf = malloc(infohdr.biSizeImage);
  for(int row = infohdr.biHeight - 1; row >= 0; row--) {
    for(int col = 0; col < infohdr.biWidth; col++) {
      buf[row * width_in_bytes + col * 3 + 0] = rand()%255; /* blue */
      buf[row * width_in_bytes + col * 3 + 1] = rand()%255; /* red */
      buf[row * width_in_bytes + col * 3 + 2] = rand()%255; /* green */
    }
  }
  
  FILE* fout = fopen(filepath, "wb");
  fwrite(&filehdr, sizeof(filehdr), 1, fout);
  fwrite(&infohdr, sizeof(infohdr), 1, fout);
  fwrite((char*)buf, 1, infohdr.biSizeImage, fout);
  fclose(fout);
  free(buf);
}

int main()
{
  int width = 800, height = 600, imagesize = IMAGESIZE(width, height);

  BITMAPFILEHEADER filehdr = create_ezbitmap_file(OFFBITS, imagesize);
  BITMAPINFOHEADER infohdr = create_ezbitmap_info(width, height, BITCOUNT, imagesize);

  write_bitmap("test.bmp", filehdr, infohdr);

  return 0;
}
