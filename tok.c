#include "main.h"
/**
* _token - the fonction
* @sent: the message the we want to tokenize
* Return: the tokinezed message
*/
char **_token(char *sent)
{
	char *tok = NULL, *tmp = NULL;
	char **command = NULL;
	int count = 0, i = 0;

	if (!sent)
	return (NULL);
	tmp = _strdup(sent);
	if (!tmp)
	{
	free(sent);
	return (NULL);
	}
	tok = strtok(tmp, SEP);

	if (tok == NULL)
	{
		free(sent);
		free(tmp);
		return (NULL); }
	while (tok)
	{
		count++;
		tok = strtok(NULL, SEP);  }
	free(tmp), tmp = NULL;
	command = malloc(sizeof(char *) * (count + 1));
	if (!command)
	{
		free(sent), sent = NULL;
		free(tmp), tmp = NULL;
		return (NULL); }
	tok = strtok(sent, SEP);

	for (i = 0; tok; i++)
	{
		command[i] = tok;
		tok = strtok(NULL, SEP);
		}
	free(sent), sent = NULL;
	free(tmp), tmp = NULL;
	command[i] = NULL;
	return (command);  }
