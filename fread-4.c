/* Reader program.
  Read the contents of STUDENTS.BIN file.
*/
#include <stdio.h>
#include "grado.h"

int Read_Binary_File(char* filename, struct studentTag S[]) {
  FILE* fp;
  // int retval;
  int ctr = 0;
  struct studentTag temp;

  fp = fopen(filename, "rb");  // read binary file
  if (fp != NULL) {            // file exists
    while (fread(&temp, sizeof(struct studentTag), 1, fp) == 1) {
      S[ctr] = temp;  // structure-to-structure assignment
      ctr++;
    }

    fclose(fp);
    return ctr;
  } else {  // file does not exist
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

int main() {
  struct studentTag S[MAXNUM_STUDENTS];
  int nStudents;

  nStudents = Read_Binary_File("STUDENTS.BIN", S);
  Print_Student_Data(S, nStudents);

  return 0;
}
