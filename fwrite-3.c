/*
WRITER program.
  1. Read the contents of an input text file which represent student.
  2. Store the data into an array of structures.
  3. Write the array of structures into a binary file.
*/
#include <stdio.h>
#include <stdlib.h>

#include "grado.h"

/*
  1. Read the contents of an input text file which represent student data.
  2. Store the data into an array of structures.
*/

int Read_Text_File(char* filename, struct studentTag S[]) {
  FILE* fp_txt;  // file pointer for the text file
  struct studentTag temp;
  int ctr = 0;

  fp_txt = fopen(filename, "r");  // read text file

  printf("fp_txt = %p\n", fp_txt);

  if (fp_txt != NULL) {  // file exists
    // read data from the input text file
    while (fscanf(fp_txt, "%s %s %d %d", temp.name.last, temp.name.first,
                  &temp.practice_score, &temp.midterm_score) == 4) {
      S[ctr] = temp;  // structure-to-structure assignment
      ctr++;
    }
    fclose(fp_txt);
    return ctr;
  } else {
    fprintf(stderr, "%s does not exist.\n", filename);
    return 0;
  }
}

void Print_Student_Data(struct studentTag S[], int n) {
  int i;

  for (i = 0; i < n; i++)
    printf("%s %s %d %d\n", S[i].name.last, S[i].name.first,
           S[i].practice_score, S[i].midterm_score);
}

/* 3. Write the array of structures into a binary file */
void Write_Binary_File(char* filename, struct studentTag S[], int n) {
  FILE* fp_bin;
  fp_bin = fopen(filename, "wb");                   // write binary
  fwrite(S, sizeof(struct studentTag), n, fp_bin);  // BLOCK WRITE
  fclose(fp_bin);
}

int main() {
  struct studentTag S[MAXNUM_STUDENTS];
  int nStudents;

  nStudents = Read_Text_File("TESTDATA.TXT", S);
  printf("nStudents = %d\n", nStudents);

  Print_Student_Data(S, nStudents);

  Write_Binary_File("STUDENTS.BIN", S, nStudents);

  return 0;
}
