#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "term.h"
#include "builtin.h"
#include "execute.h"

#define BUFFER_SIZE 1024

/**
 * main - entry point
 *
 *
 * Return 0
 */
int main()
{
char *args[] = {"/bin/ls", NULL};
char input[BUFFER_SIZE];
char *line = NULL;
size_t len = 0;
ssize_t n = getline(&line, &len, stdin);
int interactive = isatty(STDIN_FILENO);

while (1)
{
	if (interactive)
	{
            printf("($) ");
            n = getline(&line, &len, stdin);

            if (n == -1)
	    {
                break;
            }
            line[n - 1] = '\0';
            strcpy(input, line);
        }
	else
	{
            n = getline(&line, &len, stdin);
            if (n == -1)
	    {
                break;
            }
            line[n - 1] = '\0';
            strcpy(input, line);
        }
        execute_command(args);
}

free(line);
return (0);
}
