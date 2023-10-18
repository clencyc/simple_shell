#include "execute.h"
#include "builtin.h"

#define MAX_TOKENS 512
/**
 * handle_terminalinp - process and execute commands entered into the shell,
 * @trim_inp: pointer advanced to remove whitespace
 * @inp_len: calculates length of input string
 * @token: holds user's input while parsing it
 * @tokens: stores extracted okens as they await execution
 *
 * Return: void
 */

void handle_terminalinp(char *input)
{
char *trim_inp *token;
int inp_len *tokens[MAX_TOKENS]
int i = 0;

trim_inp = input;

while (*trim_inp == ' ' || *trim_inp == '\t' || *trim_inp == '\n')
{
	trim_inp++;
}
inp_len = strlen(trim_inp);
while (inp_len > 0 && (trim_inp[inp_len - 1] == ' ' || trim_inp[inp_len - 1] == ' ' || trim_inp[inp_len - 1] == '\n'))
{
	trim_inp[inp_len - 1] = '\0';
	inp_len--;
}
if (strcmp(trim_inp, "exit") == 0)
{
	exit_builtin();
}
else if (strcmp(trim_inp, "env") == 0)
{
	environ_builtin();
}
else if (inp_len > 0)
{
	token = strtok(trim_inp, " ");
	while (token != NULL && i < MAX_TOKENS)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	execute_command(tokens);
}
}
