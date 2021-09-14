/*
        Reader program.

        Example program that will read integer data from a named binary file
        using fread().  Integer values will be read one at time.
*/
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "array.dat"

void PrintArray(int L[], int n) {
  int i;

  for (i = 0; i < n; i++)
    printf("%d\n", L[i]);
}

/*
        This function will read one integer at a time from a binary file
        and store it into an array.  The function returns the number
        of integers that were read from the binary file.
*/
int Read_Binary_File(char* filename, int A[]) {
  FILE* fp;
  int i;
  int data;

  fp = fopen(filename, "rb");  // read binary mode
  if (fp != NULL) {            // file exists
    for (i = 0; i < 5; i++) {
      fread(&data, sizeof(int), 1, fp);  // read the data from the file
      A[i] = data;                       // store the data into the array
    }
    fclose(fp);
    return 5;
  } else {  // file does not exist
    fprintf(stderr, "%s does not exist.\n", FILENAME);
    // exit(1); // terminate immediately -- abnormal program termination.
    return 0;
  }
}

int main() {
  int A[5];  // with garbage value as default value
  int B[5];
  int nA;
  int nB;

  nA = Read_Binary_File(FILENAME, A);
  PrintArray(A, nA);

  nB = Read_Binary_File("myarray.bin", B);
  PrintArray(B, nB);

  return 0;
}
