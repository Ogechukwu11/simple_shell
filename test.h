#ifndef TEST_H
#define TEST_H

#define SPACE 130
#define MAX_INPUT_LENGTH 1024

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

const char *str_chr(const char *sequence, char ch);
char *str_cat(char *to, char *from);
char *_sdup(const char *source);
int str_cmp(const char *seq1, const char *seq2, int len);
char *_cpy(char *destination, const char *source);
size_t _len(const char *str);
void _OA_printer(const char *letters);

#endif