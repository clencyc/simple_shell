#include <stdlib.h>
#include "main.h"

/**
 * exit_builtin - to exit the current environment
 *
 * Return: void
 */

void exit_builtin(void)
{
exit(0);
}

/**
 * environ_builtin - that prints the current environment;
 * @env_when: pointer to a pointer
 * Return: void
 */

void environ_builtin(void)
{
extern char **environ;
char **env_when = environ;

while (*env_when)
{
	printf("%s\n", *env_when);
	env_when++;
}
}
