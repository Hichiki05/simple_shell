#ifndef MAIN_H
#define MAIN_H

/**
*the header file
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

void prompt(void);
void print(const char *string);
void read(char *command, size_t size);
void execute(const char *command);

#endif