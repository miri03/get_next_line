/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:22:03 by meharit           #+#    #+#             */
/*   Updated: 2022/11/11 23:51:58 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_line(char *s)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n') // '\0'
		i++;
	if (s[i] == 0)
		return (NULL);
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	while (i > j)
	{
		line[j] = s[j];
		j++;
	}

	line[j] = '\n';
	line[j + 1] = '\0';
//	free(s);
	return (line);
}

char	*ft_remain(char *s)
{
	int	i;
	char	*remain;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	remain = strdup(&s[i]);
	
	return (remain);
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
	static char	*string = NULL;
	int			rd;
	char		*line;

	rd = 1;
	if (fd < 0)
		return (NULL);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	while (rd > 0 && new_line(buff) == 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd <= 0)
		{
			free (buff);
			return (NULL);
		}
		buff[rd] = '\0';
		string = ft_strjoin(string, buff); //freed string
	}
	line = ft_line(string); //freed string = error
	string = ft_remain(string); // free? 
	free(buff);
	return(line);
}

int main()
{
	char *str;
	char *s;
	int fd = open("test.txt",O_RDWR);
	int i = 0;

	while (str)
	{
		str = get_next_line(fd);
	//	free(str);
		printf("%s",str);
	}

/*
	while (1)
	{
		;
	}
*/
}

/*
int main()
{
//	char *str = "hello\n123";
	char *remain = ft_remain("hello\n123");
	printf("%s\n", remain);
}
*/
