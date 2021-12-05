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

int	main(void)
{
	int		fd1;
	int		fd2;
	size_t	i;
	char	*ft_line;

	i = 0;
	fd1 = open("/Users/celadia/school21/GNL/RickRoll.txt", O_RDONLY);
	fd2 = open("/Users/celadia/school21/GNL/RickRol.txt", O_RDONLY);
	if (fd1 == -1)
		printf("File open error!\n");
	if (fd2 == -1)
		printf("File open error!\n");
	while (i < 60)
	{
		printf("fd1 %02lu ", i + 1);
		ft_line = get_next_line(fd1);
		check_gnl(ft_line);
//		printf("fd2 %02lu ", i + 1);
//		ft_line = get_next_line(fd2);
//		check_gnl(ft_line);
		i++;
	}
	close(fd1);
	close(fd2);
	return (0);
}
