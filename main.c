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
	int		fd;
	size_t	i;
	char	*ft_line;

	fd = open("/Users/celadia/school21/GNL/TakeOnMe.txt", O_RDONLY);
	printf("fd: %i\n", fd);
	i = 0;
	while (++i <= 42)
	{
		printf("fd1 %02lu ", i);
		ft_line = get_next_line(fd);
		check_gnl(ft_line);
	}
	close(fd);
	return (0);
}
