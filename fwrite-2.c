/*
    Writer program.

        Example program that writes the contents of an integer array
        with just ONE fwrite() -- block write.
*/
#include <stdio.h>

int main() {
  FILE* fp;

  int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // int i;

  fp = fopen("array.dat", "wb");  // write binary mode

#if 0
	for (i = 0; i < 5; i++)
		fwrite(&A[i], sizeof(int), 1, fp);
#endif

  fwrite(A, sizeof(int), 10, fp);  // BLOCK WRITE - faster, more efficient!

  fclose(fp);
  return 0;
}
