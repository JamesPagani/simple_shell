#include "headers.h"
/**
 * _strcat - Entry
 * Desc: _strcat function
 * @dest: char type pointer where src will concatenate
 * @src: char pointer type to add to dest
 * Return: concatenate two strings
 **/
char *_strcat(char *dest, char *src)
{
	int i = 0, e = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[e] != '\0')
	{
		dest[i] = src[e];
		e++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - Entry
 * Desc: _strlen function
 * @s: length of input
 * Return: Length of name
 **/
int _strlen(const char *s)
{
	int x = 0;

	while (*s != 0)
	{
		s++;
		x++;
	}
	return (x);
}

/**
 * _strncmp - Entry
 * Desc: _strncmp function
 * @s1: environ[i]
 * @s2: name
 * @n: _strlen(name)
 * Return: characters compared
 **/
int _strncmp(const char *s1, const char *s2, size_t n)
{
	int i = 0;
	size_t run = 0;

	while ((s1[i] != '\0' && s2[i] != '\0') && run < n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
		run++;
	}
	return (0);
}

/**
 * _getenv - Entry
 * Desc: _getenv function
 * @argv: pointer to char const
 * @env: env variable
 * Return: pointer
 **/
char *_getenv(char *argv, char **env)
{
	int i = 0, j = 0;
	char *tok, *tmp, *toki;
	const char *delims = ":";
	const char *d = "=";
	char *path;
	struct stat st;

	while (env[i] != NULL)
	{
		if ((_strncmp(env[i], "PATH=", 5) == 0))
		{
			path = malloc(_strlen(env[i]) + 1);
			_strcpy(path, env[i]);
			toki = strtok(path, d);
			toki = strtok(NULL, "=");
			i++;
		}
		tok = strtok(toki, delims);
		while (tok != '\0')
		{
			tmp = malloc(_strlen(tok) + _strlen(argv));
			_strcat(tmp, tok);
			_strcat(tmp, "/");
			_strcat(tmp, argv);
			if (stat(tmp, &st) == 0)
				return (tmp);
			free(tmp);
			tok = strtok(NULL, delims);
			j++;
		}
		i++;
	}
	free(path);
	putchar('\n');
	return (argv);
}
