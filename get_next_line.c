/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kentakato <kentakato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:59:06 by kentakato         #+#    #+#             */
/*   Updated: 2024/09/10 21:57:25 by kentakato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_getc(int fd)
{
    ssize_t n = 0; 
    unsigned char buf[BUF_SIZE];
    unsigned char *bufp;
    
    if (n == 0)
    {
        n = read(fd, buf, BUF_SIZE);
        if (n == READ_ERROR)
        {
            return READ_ERROR;
        }
        bufp = buf;
    }
    
    return (--n >= 0) ? *bufp++ : EOF;
}

int ft_putc(t_string *str, char c)
{
    if (str->capacity < str->len + 1)
    {
        str->str = (char *)malloc(sizeof(char) * ());
    }
    str->str[str->len] = c;
    str->len++;
    return 0;
}

char *get_next_line(int fd)
{
    t_string ret;
    char c;

    ret.str = NULL;
    ret.len = 0;
    ret.capacity = 0;
    
    while (1)
    {
        c = ft_getc(fd);
        if (c == EOF)
            break;
        ft_putc(&ret, c);
        if (c == '\n')
            break;
    }
    if (ret.len > 0)
    {
        ft_putc(&ret, '\0');
    }
    return ret.str;
}


int main()
{
    int fd = open("example.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));
    close(fd);
}