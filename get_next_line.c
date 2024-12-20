/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kentakato <kentakato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:59:06 by kentakato         #+#    #+#             */
/*   Updated: 2024/12/20 21:00:37 by kentakato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_getc(int fd)
{
	static t_buffer	buf;

	if (buf.bytes == 0)
	{
		buf.bytes = read(fd, buf.buf, BUFFER_SIZE);
		if (buf.bytes == -1)
		{
			buf.bytes = 0;
			return (READ_ERROR);
		}
		buf.bufp = buf.buf;
	}
	if (--buf.bytes >= 0)
	{
		return (*buf.bufp++);
	}
	buf.bytes = 0;
	return (EOF);
}

static int	ft_putc(t_string *line, char c)
{
	char	*tmp;
	size_t	i;

	if (line->capacity < line->length + 1)
	{
		tmp = line->str;
		line->str = (char *)malloc(sizeof(char) * (BLK_SIZE + line->capacity));
		if (!line->str)
		{
			free(tmp);
			return (1);
		}
		i = 0;
		while (i < line->length)
		{
			line->str[i] = tmp[i];
			i++;
		}
		free(tmp);
		line->capacity += BLK_SIZE;
	}
	line->str[line->length] = c;
	line->length++;
	return (0);
}

char	*get_next_line(int fd)
{
	char		c;
	t_string	line;

	line.str = NULL;
	line.length = 0;
	line.capacity = 0;
	while (1)
	{
		c = ft_getc(fd);
		if (c == READ_ERROR)
		{
			free(line.str);
			return (NULL);
		}
		if (c == EOF)
			break ;
		if (ft_putc(&line, c))
			return (NULL);
		if (c == '\n')
			break ;
	}
	if (line.length > 0)
		if (ft_putc(&line, '\0'))
			return (NULL);
	return (line.str);
}
