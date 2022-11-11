
#include"get_next_line.h"

#include<fcntl.h>

#include<stdio.h>

char *get_next_line(int fd)
{
	char *buf;
	static char *txt;
	int rd;

	buf = malloc(sizeof(char) * BUFFER_SIZE);
	rd = read(fd, buf, BUFFER_SIZE);
	printf("%s\n", buf);
	printf("%d\n", rd);
	return ("hi");
}
int main()
{
	int fd = open("test.txt",O_RDWR);
	get_next_line(fd);
	printf("\n\n\n\n");
	get_next_line(fd);
}
