#include "headers.h"
/**
 * _strcpy - Entry to copy
 * Desc: _strcpy function
 * @dest: pointer to char type
 * @src: pointer to char type
 * Return: Return copy of src to dest
 **/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (src[i] != '\0')
	{
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			if (src[i + 1] == '\0')
				dest[i + 1] = src[i + 1];
			i++;
		}
	}
	return (dest);
}

/**
 * tok_count - Counts the amount of tokens
 * @in: struct input
 * @delims: delimiters
 * Return: Amount of tokens found
 */

size_t tok_count(input *in, const char *delims)
{
	char *buf_back, *tok;
	size_t counter = 0;

	buf_back = malloc(in->size);
	if (buf_back == NULL)
	{
		perror(in->sh_name);
		return (0);
	}
	_strcpy(buf_back, in->buffer);

	tok = strtok(buf_back, delims);
	while (tok != NULL)
	{
		counter++;
		tok = strtok(NULL, delims);
	}

	free(buf_back);
	return (counter);
}


/**
 * parser - Parses the input into something the executor can understand
 * Desc: parser function
 * @in: typedef struct
 * Return: An array of tokens ready to be used with execve
 */
char **parser(input *in)
{
	const char *delims = " \n\t\r";
	char **argv, *tok;
	size_t tok_amount = 0, tok_counter = 0;

	tok_amount = tok_count(in, delims);
	argv = malloc((tok_amount + 1) * sizeof(char *));
	if (argv == NULL)
	{
		perror(in->sh_name);
		return (NULL);
	}

	tok = strtok(in->buffer, delims);
	while (tok_counter < tok_amount)
	{
		argv[tok_counter] = tok;
		tok_counter++;
		tok = strtok(NULL, delims);
	}
	return (argv);
}
