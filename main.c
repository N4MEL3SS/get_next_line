#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

void	check_gnl(char *str)
{
	char	*temp;

	temp = str;
	if (str)
	{
		while (*str && *str != '\n')
			str++;
		if (*str == '\n')
			*str = '@';
	}
	printf("Line texts: |%s|\n", temp);
	free(temp);
	temp = NULL;
}

void	start_gnl(int fd, int n)
{
	char	*ft_line;
	int		i;

	i = 0;
	while (++i <= n)
	{
		printf("fd1 %02d ", i);
		ft_line = get_next_line(fd);
		check_gnl(ft_line);
	}
	printf("\n");
}

int	main(void)
{
	int		fd;

	fd = open("/Users/celadia/school21/GNL/RickRoll.txt", O_RDONLY);
	printf("fd: %i\n", fd);
	start_gnl(fd, 69);
	close(fd);
	return (0);
}
