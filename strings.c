#include "monty.h"
#include <stdlib.h>

char **strtow(char *str, char *delims);
unsigned int token_arr(void);
char *g_int(int m);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		               char *buff, int buff_size);


/**
 * strtow - takes a string and seperates its words
 *
 * @str: string to seperate into words
 * @delims: delimitors to use to delimit words
 *
 * Return: 2D array of pointers to each word
 **/

char **strtow(char *str, char *delim)
{
	char **word = NULL;
	int wc, len, n, v = 0;
	
	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str, delim);
	
	if (wc == 0)
		return (NULL);
	word = malloc((wc + 1) * sizeof(char *));
	if (word == NULL)
		return (NULL);
	while (v < wc)
	{
		len = get_word_length(str, delim);
		if (is_delim(*str, delim))
		{
			str = get_next_word(str, delim);
		}
		word[v] = malloc((len + 1) * sizeof(char));
		
		if (word[v] == NULL)
		{
			while (v >= 0)
			{
				v--;
				free(word[v]);
			}
			free(word);
			return (NULL);
		}
		n = 0;
		
		while (n < len)
		{
			word[v][n] = *(str + n);
			n++;
		}
		word[v][n] = '\0';
		str = get_next_word(str, delim);
		v++;
	}
	word[v] = NULL;
	return (word);
}

/**
 * token_arr - Gets the length of current tok.
 *
 * Return: Length of current tok.
 **/

unsigned int token_arr(void)
{
	unsigned int tok_len = 0;
	
	while (tok[tok_len])
		tok_len++;
	return (tok_len);
}


/**
 * g_int - gets a character pointer to new string containing int
 * @m: number to be converted to string
 *
 * Return: character pointer. NULL if malloc fails.
 *
 **/

char *g_int(int m)
{
	unsigned int tmp;
	int len = 0;
	long num = 0;
	char *ret;
	
	tmp = _abs(m);
	len = get_numbase_len(tmp, 10);
	if (m < 0 || num < 0)
		len++;
	ret = malloc(len + 1);
	
	if (!ret)
		return (NULL);
	fill_numbase_buff(tmp, 10, ret, len);
	if (m < 0 || num < 0)
		ret[0] = '-';
	return (ret);
}

/**
 * get_numbase_len - gets the length of buffer.
 * @num: number 
 * @base: base of number representation used by buffer
 * Return: integer containing length of buffer needed
 **/

int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1;
	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - fills buffer with correct numbers up to base 36
 * @num: number to convert to string given base
 * @base: base of number used in conversion, only works up to base 36
 * @buff: buffer to fill with result of conversion
 * @buff_size: size of buffer in bytes
 *
 * Return: always void.
 *
 **/

void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size)
{
	int rem, i = buff_size - 1;
	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buff[i] = rem + 87;
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}
