#include <stdlib.h>
#include "main.h"
#include "builtin.h"
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

void helpCommand() {
    printf("Simple Shell Help:\n");
    printf("  help - Display this help message\n");
    printf("  cd   - Change the current directory\n");
    printf("  exit - Exit the shell\n");
}

void cdCommand(char *directory) {
    if (directory == NULL) {
        printf("Usage: cd [directory]\n");
    } else {
        if (chdir(directory) == 0) {
            printf("Changed directory to %s\n", directory);
        } else {
            perror("cd");
        }
    }
}

