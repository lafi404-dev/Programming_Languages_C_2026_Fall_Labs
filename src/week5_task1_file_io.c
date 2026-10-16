// week5_task1_file_io.c
// Name: Lafi Haneef  Surname: Mulakkal  Student ID: 251ADB120
//
// Write two lines to a text file, then read and display them.

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_FILENAME "data.txt"
#define LINE_LEN 256

int main(int argc, char* argv[]) {
  const char* filename = DEFAULT_FILENAME;
  char line[LINE_LEN];
  int line_count = 0;

  if (argc > 1) {
    filename = argv[1];
  }

  printf("Writing lines to %s...\n", filename);

  FILE* fp = fopen(filename, "w");
  if (fp == NULL) {
    perror(filename);
    return EXIT_FAILURE;
  }

  /* Check writes and closing because either can report a failure. */
  int write_failed = 0;
  if (fprintf(fp,
              "Hello, file I/O in C!\n"
              "This is another line.\n") < 0) {
    write_failed = 1;
  }

  if (fclose(fp) == EOF) {
    write_failed = 1;
  }

  if (write_failed) {
    fprintf(stderr, "Failed to write file.\n");
    return EXIT_FAILURE;
  }

  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror(filename);
    return EXIT_FAILURE;
  }

  printf("Reading contents:\n");

  while (fgets(line, sizeof(line), fp) != NULL) {
    printf("%s", line);
    line_count++;
  }

  /* Distinguish a read error from reaching the end of the file. */
  int read_failed = ferror(fp);
  if (fclose(fp) == EOF) {
    read_failed = 1;
  }

  if (read_failed) {
    fprintf(stderr, "Failed to read file.\n");
    return EXIT_FAILURE;
  }

  printf("Lines read: %d\n", line_count);
  return EXIT_SUCCESS;
}