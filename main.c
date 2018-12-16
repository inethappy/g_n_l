#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fd = 0;
	int fd1 = 0;
    char *l;
	char *l1;
    int i = 1;
	int	ret = 0;
	int ret1 = 0;
    if (argc > 1)
    {
        fd = open(argv[1], O_RDONLY);
		fd1 = open(argv[2], O_RDONLY);
        while (i < 100)	
		{
			if ((ret = get_next_line(fd, &l)) == 1)
				printf("%d -> %s\n", i, l);
			if ((ret1 = get_next_line(fd1, &l1)) == 1)
				printf("%d -> %s\n", i, l1);
			free(l);
			free(l1);
			i++;
        }
		printf("%d\n",ret);
        close(fd);
		close(fd1);
    }
	system("leaks a.out");
    return 0;
}


