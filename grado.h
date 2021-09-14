/*
  grado.h

  DO NOT CHANGE THE CONTENTS OF THIS HEADER FILE.
*/

// maximum number of students
#define MAXNUM_STUDENTS 100

typedef char String[51];

/*
   This is the structure data type for a structure variable that will store
   data about a student.
*/
struct nameTag {
  String last;   // 51 bytes   sizeof(char) = 1
  String first;  // 51 bytes
};

struct studentTag {
  struct nameTag name;  // nested structure
  int practice_score;   // Practice Quiz score   4 bytes  sizeof(int) = 4
  int midterm_score;    // Midterm Exam score    4
};

// Q: How many bytes will be allocated for a variable whose of type struct
// studentTag? A: 51 + 51 + 4 + 4 = 110 bytes
