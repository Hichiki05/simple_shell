#include "main.h"
/**
* _token - the fonction
* @sent: the message the we want to tokenize
* Return: the tokinezed message
*/
char **_token(char *sent)
{
	char *tok = NULL,  *toktmp = NULL, *tmp = NULL;
	char **command = NULL;
	int count = 0, i = 0;

	if (!sent)
	return (NULL);

	tmp = strdup(sent);
	if (!tmp)
	{
	free(sent);
	return (NULL);
	}
	toktmp = strtok(tmp, " \t");

	while (toktmp)
	{
		count++;
		toktmp = strtok(NULL, " \t");  }
	free(tmp), tmp = NULL;

	if (count == 0)
		{free(sent);
		return (NULL); }

	command = (char **)malloc(sizeof(char *) * (count + 1));
	if (!command)
	{
		free(sent), sent = NULL;
		return (NULL); }

	tok = strtok(sent, " \t");
	for (i = 0; tok; i++)
	{
		command[i] = tok;
	tok = strtok(NULL, " \t");  }
	
	command[i] = NULL;
	return (command); }
