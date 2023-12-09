#include "main.h"

/*
 * main: This is the main function of the code
 *
 *
 */

int main()
{
        char *input = NULL;
        int status;
        pid_t child_pid;
        size_t len = 0;
        ssize_t n;
        int interactive = isatty(STDIN_FILENO);

        while (1)
	{
		if (interactive)
		{
			printf("($) ");
			setbuf(stdout, NULL);
		}
                n = getline(&input, &len, stdin);

                if (n == -1)
                {
                        break;
                }
                input[n - 1] = '\0';

                child_pid = fork();

                if (child_pid == -1)
                {
                        perror("Fork failed");
                        exit(EXIT_FAILURE);
                }
                if (child_pid == 0)
                {
                        if (execlp(input, input, (char *)NULL) == -1)
                        {
                                perror("./shell ");
                                exit(EXIT_FAILURE);
                        }
                        exit(EXIT_SUCCESS);
                }
                else
                {
                        pid_t terminated_pid = waitpid(child_pid, &status, 0);

                        if (terminated_pid == -1)
                        {
                                perror("Waitpid failed");
                                exit(EXIT_FAILURE);
                        }
                }
        }

        free(input);
        return (0);
}
