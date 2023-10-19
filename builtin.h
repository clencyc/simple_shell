#ifndef BUILTINS_H
#define BUILTINS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void exit_builtin();
void environ_builtin();

void helpCommand();
void cdCommand(char *directory);

#endif  
