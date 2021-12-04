/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 00:14:41 by celadia           #+#    #+#             */
/*   Updated: 2021/12/05 00:14:41 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_read_file(int fd, char **stat_str)
{
	char		*line;
	ssize_t		line_len;
	ssize_t		stat_len;
	ssize_t		full_len;

	line = malloc(sizeof(char) * 1);
	*line = '\0';
	full_len = 0;
	if (!ft_str_chr(*stat_str, &line_len))
	{
		full_len = ft_str_len(*stat_str);
		line = ft_str_join(line, *stat_str, full_len);
		stat_len = read(fd, *stat_str, BUFFER_SIZE);
		*(*stat_str + stat_len) = '\0';
		while (stat_len > 0 && !ft_str_chr(*stat_str, &line_len))
		{
			full_len += stat_len;
			line = ft_str_join(line, *stat_str, full_len);
			stat_len = read(fd, *stat_str, BUFFER_SIZE);
			*(*stat_str + stat_len) = '\0';
		}
	}
	line = ft_str_join(line, *stat_str, full_len + line_len);
	ft_str_cpy(*stat_str, line_len);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		**stat_str;
	char			*line_str;

	if (!stat_str)
	{
		stat_str = malloc(sizeof(char *) * 1);
		*stat_str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		**stat_str = '\0';
	}
	line_str = get_read_file(fd, stat_str);
	if (*line_str == '\0')
	{
		free(*stat_str);
		stat_str = NULL;
		line_str = NULL;
	}
	return (line_str);
}
