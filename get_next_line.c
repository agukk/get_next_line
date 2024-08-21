/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kentakato <kentakato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:59:06 by kentakato         #+#    #+#             */
/*   Updated: 2024/08/21 21:31:31 by kentakato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUF_SIZE 512

char *get_next_line(int fd)
{
    static char buf[BUF_SIZE];
    size_t i = 0;
    char c;
    ssize_t byte;
    
    while (i < BUF_SIZE - 1)
    {
        byte = read(fd, &c, 1);
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