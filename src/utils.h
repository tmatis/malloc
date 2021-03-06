/**
 * @file utils.h
 * @author tmatis (tmatis@student.42.fr)
 * @brief Header file for utils
 * @date 2022-06-06
 * 
 */
# ifndef UTILS_H
# define UTILS_H

#include <unistd.h>

void ft_putstr(char *str);
void ft_putnbr(size_t n);
void error_write(char *str);
void ft_memcpy(void *dst, void *src, size_t n);
size_t ft_strlen(char const *str);
int ft_strcmp(char *s1, char *s2);
void size_to_string(char *str, size_t size);
void ptr_to_string(char *str, void *ptr);
void ft_memset(void *dst, int c, size_t n);

#endif