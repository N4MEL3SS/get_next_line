#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

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
		printf("fd_%i: %02d ", fd, i);
		ft_line = get_next_line(fd);
		check_gnl(ft_line);
	}
	printf("\n");
}

int	main(void)
{
	int		fd[2];

	fd[0] = open("/Users/celadia/school21/GNL/TakeOnMe.txt", O_RDONLY);
	fd[1] = open("/Users/celadia/school21/GNL/RickRoll.txt", O_RDONLY);
	printf("fd1: %i\n", fd[0]);
	printf("fd2: %i\n", fd[1]);
	start_gnl(fd[0], 7);
	start_gnl(fd[1], 5);
	start_gnl(fd[0], 5);
	start_gnl(fd[1], 3);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
