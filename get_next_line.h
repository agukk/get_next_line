/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenkato <kenkato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:59:08 by kentakato         #+#    #+#             */
/*   Updated: 2024/09/20 19:30:44 by kenkato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define READ_ERROR -1

# include <fcntl.h> // for open
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_string
{
	char	*str;
	size_t	len;
	size_t	capacity;
}			t_string;

char		*get_next_line(int fd);
int			ft_putc(t_string *str, char c);
int			ft_getc(int fd);

#endif