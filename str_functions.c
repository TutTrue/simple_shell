#include "shell.h"

/**
 * _strcpy -  copies the string pointed to by src,
 * @dest: pointer.
 * @src:copy str.
 * Return: The pointer's dest.
 */
char *_strcpy(char *dest, char *src)
{
	int len = _strlen(src);
	int i;

	for (i = 0; i < len; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - The strcat function returns a pointer to s1
 * @dest: A pointer to a string that will be modified. s2 will be copied..
 * @src: A pointer to a string that will be appended to the end of s1.
 * Return:The strcat function returns a pointer to s1
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}

/**
 * _strdup - returns a pointer to a newly allocated
 * @str: string variable
 * Return: ptr or null if was failed
 */
char *_strdup(char *str)
{
	int i;
	char *ptr;

	if (str == NULL)
		return (NULL);
	ptr = malloc(sizeof(char) * _strlen(str) + 1);
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < (int)_strlen(str); i++)
		ptr[i] = str[i];
	ptr[i] = '\0';
	return (ptr);
}

/**
 * _strncmp - compare with two string
 * @s1: string 1
 * @s2: string 2
 * @count:the number of compare string
 * Return: 15 or -15 or -1
 */
int _strncmp(char *s1, char *s2, int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
/**
 * _strcmp - Compare two strings.
 * @s1: first string
 * @s2: second string
 * Return: 0 if equal 0 > if s1 > s2 , 0 < if s2 > s1
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	return (0);
}
