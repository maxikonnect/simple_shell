#include "simple_shell.h"

/**
 * cmp_env_name - compares env variables names
 * with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int n;

	for (n = 0; nenv[n] != '='; n++)
	{
		if (nenv[n] != name[n])
		{
			return (0);
		}
	}

	return (n + 1);
}

/**
 * _getenv - get an environment variable
 * @name: name of the environment variable
 * @_environ: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int n, movp;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	movp = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (n = 0; _environ[n]; n++)
	{
		/* If name and env are equal */
		movp = cmp_env_name(_environ[n], name);
		if (movp)
		{
			ptr_env = _environ[n];
			break;
		}
	}

	return (ptr_env + movp);
}

/**
 * _env - prints the evironment variables
 *
 * @datash: data relevant.
 * Return: 1 on success.
 */
int _env(data_shell *datash)
{
	int n, m;

	for (n = 0; datash->_environ[n]; n++)
	{

		for (m = 0; datash->_environ[n][m]; m++)
			;

		write(STDOUT_FILENO, datash->_environ[n], m);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
