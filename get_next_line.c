/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:22:03 by meharit           #+#    #+#             */
/*   Updated: 2022/11/11 22:02:36 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_line(char *s, char *remain)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (remain == NULL)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == 0)
		return (NULL);
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	while (i > j)
	{
		line[j] = s[j];
		j++;
	}
	line[j] = '\n';
	return (line);
}

char	*ft_remain(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
	{
		i++;
		return (&s[i]);
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*remain = NULL;
	int			rd;
	char		*line;
	char		*str;

	line = NULL;
	str = NULL;
	rd = 1;
	if (remain)
		line = ft_strjoin(remain, line);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1); // ?
	if (buff == NULL)
		return (NULL);
	while (rd > 0 && new_line(buff) == 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		str = ft_strjoin(str, buff);
	}
	remain = ft_remain(str);
	if (remain == NULL)
		line = NULL;
	else
		line = ft_strjoin(line, ft_line(str, remain));
	free(buff);
	bzero(buff, BUFFER_SIZE + 1);
	return (line);
}


int main()
{
	char *str;
	char *s;
	int fd = open("test.txt",O_RDWR);
	int i = 0;
/*	while (str)
	{
		str = get_next_line(fd);
		printf("[result] %s",str);
	}
	*/
	str = get_next_line(fd);
	while (1)
	{
		;
	}
}

