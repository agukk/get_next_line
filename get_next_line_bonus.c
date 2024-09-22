/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kentakato <kentakato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:13:30 by kentakato         #+#    #+#             */
/*   Updated: 2024/09/22 18:04:14 by kentakato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_getc(int fd)
{
	static t_buffer	buf;

	if (buf.n == 0)
	{
		buf.n = read(fd, buf.buf, BUFFER_SIZE);
		if (buf.n == READ_ERROR)
		{
			buf.n = 0;
			return (READ_FAIL);
		}
		buf.bufp = buf.buf;
	}
	if (--buf.n >= 0)
		return (*buf.bufp++);
	buf.n = 0;
	return (EOF);
}

static int	ft_putc(t_string *str, char c)
{
	char	*tmp;
	size_t	i;

	if (str->capacity < str->len + 1)
	{
		tmp = str->str;
		str->str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + str->capacity));
		if (!str->str)
		{
			free(tmp);
			return (1);
		}
		i = 0;
		while (i < str->len)
		{
			str->str[i] = tmp[i];
			i++;
		}
		free(tmp);
		str->capacity += BUFFER_SIZE;
	}
	str->str[str->len] = c;
	str->len++;
	return (0);
}

char	*get_next_line(int fd)
{
	t_string ret;
	char c;

	ret.str = NULL;
	ret.len = 0;
	ret.capacity = 0;
	while (1)
	{
		c = ft_getc(fd);
		if (c == READ_FAIL)
		{
			free(ret.str);
			return (NULL);
		}
		if (c == EOF)
			break ;
		if (ft_putc(&ret, c))
			return (NULL);
		if (c == '\n')
			break ;
	}
	if (ret.len > 0)
	{
		if (ft_putc(&ret, '\0'))
			return (NULL);
	}
	return (ret.str);
}