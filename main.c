#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "term.h"
#include "builtin.h"

#define BUFFER_SIZE 1024

/**
 * main - entry point
 *
 *
 * Return 0
 */
int main() {
    char input[BUFFER_SIZE];

    while (1) {
        const char *prompt = "#cisfun$ ";
        write(1, prompt, strlen(prompt));

        if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
            write(1, "\n", 1);
            break;
        }

        handle_terminalinp(input);
    }

    return 0;
}
