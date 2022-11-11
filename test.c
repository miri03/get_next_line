#include"get_next_line.h"

int main()
{
	char buff[BUFFER_SIZE + 1];
	int fd = open("test.txt",O_RDWR);
	int rd = read(fd, buff, BUFFER_SIZE);
	printf("%s %d\n", buff, rd);
	int r =  read(fd, buff, BUFFER_SIZE);
	printf("%s %d", buff, r);
}
