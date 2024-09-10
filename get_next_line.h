/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kentakato <kentakato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:59:08 by kentakato         #+#    #+#             */
/*   Updated: 2024/09/10 21:43:50 by kentakato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#define BUF_SIZE 1
#define READ_ERROR -1

#include <stdio.h> // 課題終わったら消す
#include <unistd.h>
#include <fcntl.h> // 課題終わったら消す
#include <stdlib.h>

typedef struct s_string
{
    char *str;
    size_t len;
    size_t capacity;
} t_string;


#endif 