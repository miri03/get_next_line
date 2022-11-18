/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:33:09 by meharit           #+#    #+#             */
/*   Updated: 2022/11/18 09:10:33 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define  GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include<stdlib.h>
# include<limits.h>
# include<unistd.h>

char	*ft_read(char *string, int fd);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		new_line(char *str);
size_t	ft_strlen(const char *s);
char	*ft_remain(char *s);
char	*ft_line(char *s);
char	*ft_strdup(const char *s1);

#endif
