/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:22:03 by meharit           #+#    #+#             */
/*   Updated: 2022/11/13 17:57:33 by meharit          ###   ########.fr       */
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
	if (s == NULL || *s == 0)
	   return (NULL);	
	while (s[i] && s[i] != '\n')
		i++;
//	if (s[i] == 0)
//		return (NULL);
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
	{
		line[j] = '\n';
		j++;
	}
	line[j] = '\0';
	free(s);
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
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	while (rd > 0 && new_line(string) == 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd < 0) // =
		{
			free (buff);
			return (NULL);
		}
		buff[rd] = '\0';
		if (rd == 0)
		{
		//	return (buff);
			free (buff);
		}
		string = ft_strjoin(string, buff);
	}
	line = ft_line(string);
	string = ft_remain(string);
//	printf("%d\n", *string);
	free(buff);
	return(line);
}

/*
int main()
{
	char *str;
	char *s;
	char *a;
	int fd = open("tt.txt",O_RDWR);
	int i = 0;

	while (str)
	{
		str = get_next_line(fd);
		printf("%s",str);
	}

//	printf("%s",ft_line("helloi"));

	while (1)
	{
		;
	}
}
*/


/*
int main()
{
//	char *str = "hello\n123";
	char *remain = ft_remain("hello\n123");
	printf("%s\n", remain);
}
*/
