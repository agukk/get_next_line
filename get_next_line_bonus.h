/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kentakato <kentakato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:13:45 by kentakato         #+#    #+#             */
/*   Updated: 2024/09/22 16:17:19 by kentakato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define READ_ERROR -1
# define READ_FAIL -11

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_string
{
	char					*str;
	size_t					len;
	size_t					capacity;
}							t_string;

typedef struct s_buffer
{
	static ssize_t			n;
	static unsigned char	buf[BUFFER_SIZE];
	static unsigned char	*bufp;
}							t_buffer;

char						*get_next_line(int fd);

#endif