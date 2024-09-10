/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kentakato <kentakato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:59:06 by kentakato         #+#    #+#             */
/*   Updated: 2024/09/10 18:48:28 by kentakato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *line;
    ssize_t byte;
    size_t i = 0;
    static char buf[BUF_SIZE];

    if (fd < 0 || BUF_SIZE <= 0)
        return NULL;

    line = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
    if (!line)
        return NULL;

    byte = read(fd, line, BUF_SIZE);
    buf[byte] = '\0';
    
    return line;
}


int main()
{
    int fd = open("example.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));
    close(fd);
}