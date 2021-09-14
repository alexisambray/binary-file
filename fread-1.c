/*
        Reader program.

        Example program that will read integer data from a named binary file
        using fread().  Integer values will be read one at time.
*/
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "array.dat"

int main() {
  FILE* fp;
  int i;
  int data;

  fp = fopen(FILENAME, "rb");  // read binary mode
  if (fp != NULL) {            // file exists
    for (i = 0; i < 5; i++) {
      fread(&data, sizeof(int), 1, fp);
      printf("%d %d\n", i, data);
    }
    fclose(fp);
  } else {  // file does not exist
    fprintf(stderr, "%s does not exist.\n", FILENAME);
    exit(1);  // terminate immediately -- abnormal program termination.
  }

  return 0;
}
