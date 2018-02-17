#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  const int dimx = 800, dimy = 800;
  int i, j;
  FILE *fp = fopen("image.ppm", "wb");
  (void) fprintf(fp, "P6\n%d %d\n255\n", dimx, dimy);
  for (j = 0; j < dimy; ++j)
  {
    for (i = 0; i < dimx; ++i)
    {
      static unsigned char color[3];
      color[0] = 0;  /* red */
      color[1] = 255;  /* green */
      color[2] = 255;  /* blue */
      (void) fwrite(color, 1, 3, fp);
    }
  }
  (void) fclose(fp);
  return EXIT_SUCCESS;
}