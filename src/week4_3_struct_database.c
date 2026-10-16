/*
 * week4_3_struct_database.c
 * Author: Lafi Haneef Mulakkal
 * Student ID: 251ADB120
 * Description: Allocate student records, read and display them,
 * then release the allocated memory.
 */

#include <stdio.h>
#include <stdlib.h>

struct Student {
  char name[50];
  int id;
  float grade;
};

int main(void) {
  int n;
  struct Student* students = NULL;

  printf("Enter number of students: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid number.\n");
    return 1;
  }

  /* Prevent overflow when calculating the allocation size. */
  if ((size_t)n > (size_t)-1 / sizeof(struct Student)) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  students = malloc((size_t)n * sizeof(struct Student));
  if (students == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    printf("Enter data for student %d: ", i + 1);

    /* Limit names to 49 characters to leave space for '\0'. */
    if (scanf("%49s %d %f", students[i].name, &students[i].id,
              &students[i].grade) != 3) {
      free(students);
      printf("Invalid input.\n");
      return 1;
    }
  }

  printf("\n");
  printf("%-6s %-11s %s\n", "ID", "Name", "Grade");

  for (int i = 0; i < n; i++) {
    printf("%-6d %-11s %.1f\n", students[i].id, students[i].name,
           students[i].grade);
  }

  /* The records are no longer needed after printing. */
  free(students);
  return 0;
}