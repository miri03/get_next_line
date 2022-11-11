/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:22:15 by meharit           #+#    #+#             */
/*   Updated: 2022/11/11 18:11:27 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GNL_H_
# define GNL_H_

#define BUFFER_SIZE 2

#include<strings.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<stdlib.h>

char	*get_next_line(int fd);

# endif
