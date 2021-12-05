#include <stdio.h>
#include <fcntl.h>
//#include "get_next_line.h"
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

int	main(void)
{
	int		fd1;
	int		fd2;
	size_t	i;
	char	*ft_line;

	fd1 = open("/Users/celadia/school21/GNL/RickRoll.txt", O_RDONLY);
	fd2 = open("/Users/celadia/school21/GNL/TakeOnMe.txt", O_RDONLY);
	printf("fd1: %i\n", fd1);
	printf("fd2: %i\n", fd2);
	i = 0;
	while (i < 5)
	{
		printf("fd1 %02lu ", i + 1);
		ft_line = get_next_line(fd1);
		check_gnl(ft_line);
		i++;
	}
	i = 0;
	printf("\n");
	while (i < 7)
	{
		printf("fd2 %02lu ", i + 1);
		ft_line = get_next_line(fd2);
		check_gnl(ft_line);
		i++;
	}
	i = 0;
	printf("\n");
	while (i < 3)
	{
		printf("fd1 %02lu ", i + 1);
		ft_line = get_next_line(fd1);
		check_gnl(ft_line);
		i++;
	}
	i = 0;
	printf("\n");
	while (i < 5)
	{
		printf("fd2 %02lu ", i + 1);
		ft_line = get_next_line(fd2);
		check_gnl(ft_line);
		i++;
	}
	close(fd1);
	close(fd2);
	return (0);
}
