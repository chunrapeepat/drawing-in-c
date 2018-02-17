#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void rgb(int r, int g, int b, FILE *fp) {
    static unsigned char color[3];
    color[0] = r;  /* red */
    color[1] = g;  /* green */
    color[2] = b;  /* blue */
    (void) fwrite(color, 1, 3, fp);
}

int main(void)
{
  const int dimx = 1000, dimy = 1000;
  const int circle_d = 300;
  int i, j;

  FILE *fp = fopen("image.ppm", "wb");
  (void) fprintf(fp, "P6\n%d %d\n255\n", dimx, dimy);

  // start drawing
  for (j = 0; j < dimy; ++j)
  {
    for (i = 0; i < dimx; ++i)
    {
        if (pow(i - dimx / 2, 2) + pow(j - dimy / 2, 2) <= pow(circle_d, 2)) {
            rgb(255, 0, 0, fp);
        } else {
            rgb(255, 255, 255, fp);
        }
    }
  }

  (void) fclose(fp);
  return EXIT_SUCCESS;
}