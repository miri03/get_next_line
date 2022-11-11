/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:45:17 by meharit           #+#    #+#             */
/*   Updated: 2022/11/11 21:57:10 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ptr = NULL;
//	if (s1 == 0 || s2 == 0)
//		return (0);
	if (s1 == NULL)
		return (strdup(s2));
	if (s2 == NULL)
		return (strdup(s1));
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	new_line(char *str)
{
	while (*str != '\0' && *str != '\n')
		str++;
	if (*str == '\n')
		return (1);
	return (0);
}
