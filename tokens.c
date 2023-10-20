#include <stdlib.h>

int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);
unsigned int _abs(int n);

/**
 * is_delim - checks if stream has delimitor char
 * @ch: character in stream
 * @delims: Pointer to null terminated array of delimitors
 *
 * Return: 1 (success) 0 (failure)
 **/

int is_delim(char ch, char *delims)
{
	int v = 0;
	
	while (delims[v])
	{
		if (delims[v] == ch)
			return (1);
		v++;
	}
	return (0);
}


/**
 * get_word_length - gets the word length
 * @str: string to get word length from current word
 * @delims: delimitors to use to delimit words
 * Return: word length of current word
 **/


int get_word_length(char *str, char *delims)
{
	int wLen = 0, pending = 1, i = 0;
	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(str[i], delims))
			break;
		i++;
	}
	return (wLen);
}


/**
 * get_word_count - gets the word count of a string
 *
 * @str: string to get word count from
 * @delims: delimitors to use to delimit words
 * Return: the word count of the string
 **/

int get_word_count(char *str, char *delims)
{
	int wc = 0, pending = 1, i = 0;
	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}


/**
 * get_next_word - gets the next word in a string
 *
 * @str: string to get next word from
 * @delims: delimitors to use to delimit words
 *
 * Return: pointer to first char of next word
 **/

char *get_next_word(char *str, char *delims)
{
	int pending = 0;
	int i = 0;
	
	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}


/**
 * _abs - gets the absolute value of an integer
 * @n: integer to get absolute value of
 *
 * Return: unsigned integer abs rep of i
 **/

unsigned int _abs(int n)
{
	if (n < 0)
		return (-(unsigned int)n);
	return ((unsigned int)n);
}
