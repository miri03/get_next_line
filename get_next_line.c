
#include"get_next_line.h"

#include<stdio.h>

char *get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	static int	ret;
	static char	*txt;
	char	*line;
	int i = 0;
	int j = 0;
	
	if (ret <= 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		txt = malloc(sizeof(char) * ret);
		txt = buff;
	}
	printf("{%s}\n",txt);
	while (txt[i] && txt[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	printf("[i]%d\n\n", i);
	while (i > j)
	{
		line[j] = txt[j];
		j++;
	}
	line[j] = 0;
	return (line);
}

int main()
{
	int fd = open("test.txt", O_RDWR);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
}
