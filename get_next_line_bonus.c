/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:16:10 by meharit           #+#    #+#             */
/*   Updated: 2022/11/18 09:10:23 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(char *string, int fd)
{
	int			rd;
	char		*buff;

	rd = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	while (rd > 0 && new_line(string) == 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(string);
			free (buff);
			return (NULL);
		}
		buff[rd] = '\0';
		string = ft_strjoin(string, buff);
	}
	free(buff);
	return (string);
}

char	*ft_line(char *s)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s[i] == 0)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i = i + 1;
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	while (s[j] && s[j] != '\n')
	{
		line[j] = s[j];
		j++;
	}
	if (s[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*ft_remain(char *s)
{
	int		i;
	char	*remain;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	if (s[i] == '\n')
		i++;
	remain = ft_strdup(&s[i]);
	free(s);
	return (remain);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*string[OPEN_MAX];
	int			rd;

	rd = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	string[fd] = ft_read(string[fd], fd);
	if (string[fd] == NULL)
		return (NULL);
	line = ft_line(string[fd]);
	string[fd] = ft_remain(string[fd]);
	return (line);
}
