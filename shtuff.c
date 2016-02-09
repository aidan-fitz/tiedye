#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include <math.h>

void mkimg() {
  int newfile = creat("image.ppm", 0644);
  dup2(newfile, STDOUT_FILENO);
  // Is this legal?
  close(newfile);
}

int main() {
  mkimg();

  const int width = 300, height = 300, maxval = 255;
  
  // Header
  printf("P3\n%d %d\n%d\n", width, height, maxval);

  float x, y;

  for (x = 0; x < width; x++) {
    for (y = 0; y < height; y++) {
      int r, g, b;
      r = maxval;
      g = (int) (maxval/2 * (1 + cos(x / width * 2 * M_PI)) );
      b = (int) (maxval/3 * (2 + cos(y / height * 4 * M_PI)) );

      printf("%d %d %d ", r, g, b);
    }
  }
}
