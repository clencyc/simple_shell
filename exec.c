#include "execute.h"

/**
 * execute_command - to execute command passed by user.
 * @*path: stores value of the PATH env variable
 * @*path_tk: iterates through each dir in the PATH
 * @find: tracks whther command is found
 * @args: argument contains command from user
 * Return: void
 */

void execute_command(char *args[])
{
char *path, *path_tk;
int find;
path = getenv("PATH");

for (path_tk = strtok(path, ":"); path_tk; path_tk = strtok(NULL, ":"))
{
	char file_path[1024];
	snprintf(file_path, sizeof(file_path), "%s/%s", path_tk, args[0]);

	if (access(file_path, X_OK) == 0)
	{
		find = 1;
		break;
	}
}
if (find)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror(args[0]);
			exit(1);
		}
	} else if (pid < 0)
	{
		perror("fork");
	} else
	{
		wait(NULL);
	}
} else
{
	printf("Command not found: %s\n", args[0]);
}
}
