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
	tok = strtok(tmp, SEP);

	if (tok == NULL)
	{
		free(sent), sent = NULL;
		free(tmp), tmp = NULL;
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
		return (NULL); }
	tok = strtok(sent, SEP);

	while (tok)
	{
		command[i] = _strdup(tok);
		tok = strtok(NULL, SEP);
		i++;  }
	free(sent), sent = NULL;
	command[i] = NULL;
	return (command);  }
