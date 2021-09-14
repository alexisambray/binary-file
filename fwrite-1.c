/*
    Writer program.

        Example program that writes the contents of an integer array
        one element at a time using fwrite().
*/
#include <stdio.h>

int main() {
  FILE* fp;

  int A[5] = {-100, -200, -300, -400, -500};
  int i;

  // fp = fopen("array.dat", "wb"); // write binary mode

  fp = fopen("myarray.bin", "wb");  // write binary mode

  for (i = 0; i < 5; i++)
    fwrite(&A[i], sizeof(int), 1, fp);

  fclose(fp);
  return 0;
}
