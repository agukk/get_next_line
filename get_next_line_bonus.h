/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenkato <kenkato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:13:45 by kentakato         #+#    #+#             */
/*   Updated: 2024/12/20 20:08:21 by kenkato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// # include <fcntl.h>  // for open
# include <stdio.h>  // for EOF
# include <stdlib.h> // for malloc
# include <unistd.h> // for read

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef BLK_SIZE
#  define BLK_SIZE 4096
# endif

# define READ_ERROR -2

typedef struct s_string
{
	char			*str;
	size_t			length;
	size_t			capacity;
}					t_string;

typedef struct s_buffer
{
	ssize_t			bytes;
	unsigned char	buf[BUFFER_SIZE];
	unsigned char	*bufp;
}					t_buffer;

char				*get_next_line(int fd);

#endif
