/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:22:15 by meharit           #+#    #+#             */
/*   Updated: 2022/11/11 22:01:19 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3 
# endif

# include<strings.h>
# include<string.h>
# include<stdio.h>
# include<unistd.h>
# include <fcntl.h>
# include<stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int		new_line(char *str);
size_t	ft_strlen(const char *s);
char	*ft_remain(char *s);
char	*ft_line(char *s, char *remain);

#endif
