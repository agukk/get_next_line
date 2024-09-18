/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kentakato <kentakato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:59:06 by kentakato         #+#    #+#             */
/*   Updated: 2024/09/18 22:11:02 by kentakato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_getc(int fd)
{
    static ssize_t n = 0; 
    static unsigned char buf[BUFFER_SIZE];
    static unsigned char *bufp;
    
    if (n == 0)
    {
        n = read(fd, buf, BUFFER_SIZE);
        if (n == READ_ERROR)
        {
            return READ_ERROR;
        }
        bufp = buf;
    }
    
    return (--n >= 0) ? *bufp++ : EOF;
}

// ここの挙動確認する
int ft_putc(t_string *str, char c)
{
    size_t i = 0;
    
    if (str->capacity < str->len + 1)
    {
        str->str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + str->capacity));
        if (!str->str)
        {
            return 1;
        }
        str->capacity += BUFFER_SIZE;
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
        if (c == READ_ERROR)
        {
            return NULL;
        }
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
    // for (size_t i = 0; i < 5; i++)
    // {
    //     printf("%c\n", ft_getc(fd));
    // }
    
    // printf("%s\n", get_next_line(fd));
    close(fd);
}