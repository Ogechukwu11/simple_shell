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
char *_strtok(const char *str, const char *delimiter);
int check_script(const char *file_name);
void is_interactive(void);
int _minenv(void);
void cmd_parse(char *cmd, char **av);
int cmd_execute(char **argv);
int execve_cmd(char *total_path, char **argv);
char *search_cmd(char *input);
char *_getminenv(const char *name);


#endif
