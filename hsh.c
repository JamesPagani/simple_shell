#include "headers.h"
#include <string.h>
/**
 * parsing - Entry to strtok
 * Desc: parsing functions
 * @str: pointer to char
 * Return: Tokens
 **/
int parsing(char *str)
{
	char *tok[100];
	char chr[] = " ";
	int strtkn = 0, string = 0;

	tok[0] = strtok(str, chr);

	while (tok[strtkn] != '\0')
        {
                strtkn++;
                tok[strtkn] = strtok(NULL, " ");
        }
        for (; string <= (strtkn - 1); string++)
        {
                int kount = 0;
                while (tok[string][kount] != '\0')
                {
                        write(1, &tok[string][kount], 1);
                        kount++;
                }
		write(1, "\n", 1);
        }
        return (0);
}
/**
 * main - Entry point. Where the shell runs
 * Return: 0 on success, anything else on failure
 */

int main(void)
{
	char *argv[] = {NULL, NULL};
	ssize_t gl_check, wr_check;
	char *buf = NULL;
	size_t buf_size = 0;

	wr_check = write(STDOUT_FILENO, "$ ", 2);
	if (wr_check == -1)
	{
		write(STDOUT_FILENO, "Error\n", 6);
		exit(1);
	}

	while (getline(&buf, &buf_size, stdin) != -1)
	{
		parsing(buf);
		write(STDOUT_FILENO, "$ ", 2);
	}
	free(buf);
	write(STDOUT_FILENO, "Bye\n", 4);
	return (0);
}
