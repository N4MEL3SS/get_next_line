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

	i = 0;
	fd = open("/Users/celadia/school21/GNL/RickRoll.txt", O_RDONLY);
	if (fd == -1)
		printf("File open error!\n");
	while (i < 56)
	{
		printf("%02lu ", i + 1);
		ft_line = get_next_line(fd);
		check_gnl(ft_line);
		i++;
	}
	close(fd);
	return (0);
}
