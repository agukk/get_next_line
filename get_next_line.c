/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kentakato <kentakato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:59:06 by kentakato         #+#    #+#             */
/*   Updated: 2024/09/03 18:45:48 by kentakato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char c;
    ssize_t byte;
    size_t i = 0;
    static char buf[BUF_SIZE];

    if (fd < 0 || BUF_SIZE <= 0)
        return NULL;

    while(1)
    {
        byte = read(fd, &c, BUF_SIZE);
        if (byte == 0)
        {
            buf[i] = '\0';
            break;
        }
        buf[i] = c;
        i++;
    }
    
    return buf;
}


int main()
{
    int fd = open("example.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));
    close(fd);
}