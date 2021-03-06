/**
 * @file utils.c
 * @author tmatis (tmatis@student.42.fr)
 * @brief This file contains various utilities
 * @date 2022-06-06
 * 
 */

#include <unistd.h>

/**
 * @brief write error message to stderr
 * 
 * @param str error message
 */
void error_write(char *str)
{
	size_t len = 0;
	while (str[len] != '\0')
		len++;
	write(STDERR_FILENO, str, len);
	write(STDERR_FILENO, "\n", 1);
}

/**
 * @brief write a message to STDOUT
 * 
 * @param str message to write
 */
void ft_putstr(char *str)
{
	size_t i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

/**
 * @brief Put a nbr to STDOUT
 * 
 * @param n nbr to print
 */
void ft_putnbr(size_t n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	char c;
	c = n % 10 + '0';
	write(1, &c, 1);
}

/**
 * @brief copy the content of src to dst
 * 
 * @param dst destination
 * @param src source
 * @param n number of bytes to copy
 */
void ft_memcpy(void *dst, void *src, size_t n)
{
	size_t i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
}

/**
 * @brief set the content of the memory to c
 * 
 * @param dst destination
 * @param c value to set
 * @param n number of bytes to set
 */
void ft_memset(void *dst, int c, size_t n)
{
	size_t i = 0;
	while (i < n)
	{
		((char *)dst)[i] = c;
		i++;
	}
}

/**
 * @brief count the number of characters in a string
 * 
 * @param str string to count
 * @return size_t number of characters
 */
size_t ft_strlen(const char *str)
{
	size_t i = 0;
	while (str[i])
		i++;
	return i;
}

/**
 * @brief compare two strings
 * 
 * @param s1 first string
 * @param s2 second string
 * @return int 0 if equal, the difference between the first different character otherwise
 */
int ft_strcmp(char const * const s1, char const * const s2)
{
	size_t i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return s1[i] - s2[i];
}

void size_to_string(char *str, size_t size)
{
	size_t nbr_size = 0;
	size_t nbr = size;
	while (nbr > 0)
	{
		nbr /= 10;
		nbr_size++;
	}
	if (nbr_size == 0)
		nbr_size = 1;
	str[nbr_size] = '\0';
	while (nbr_size > 0)
	{
		str[nbr_size - 1] = '0' + (size % 10);
		size /= 10;
		nbr_size--;
	}
}

void ptr_to_string(char *str, void *ptr)
{
	static char const hex[] = "0123456789ABCDEF";
	size_t size = (size_t)ptr;

	str[0] = '0';
	str[1] = 'x';
	for (int i = sizeof(size_t) * 2 - 1; i >= 2; i--)
	{
		str[i] = hex[size & 0xF];
		size >>= 4;
	}
	str[sizeof(size_t) * 2] = '\0';
}