/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 00:14:41 by celadia           #+#    #+#             */
/*   Updated: 2021/12/05 09:04:31 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "stdio.h"

//char	**get_stat_init(int fd)
//{
//	char		**stat_str;
//	ssize_t		fd_count;
//
//	fd_count = ft_fd_count(fd);
//	stat_str = malloc(sizeof(char *) * fd_count);
//	if (!stat_str)
//		return (NULL);
//	stat_str[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
//	stat_str[fd_count] = NULL;
//	return (stat_str);
//}
//
//char	**get_stat_unit(int fd, char **stat_str)
//{
//	ssize_t		fd_count;
//	ssize_t		i;
//	ssize_t		n;
//
//	i = 0;
//	n = 0;
//	fd_count = ft_fd_count(fd);
//	stat_str[0] = ft_free_ptr(stat_str[0]);
//	stat_str[1] = ft_free_ptr(stat_str[1]);
//	stat_str[2] = ft_free_ptr(stat_str[2]);
//	while (i < fd_count)
//	{
//		if (stat_str[i] == NULL)
//			n++;
//		i++;
//	}
//	if (n == fd_count)
//		stat_str = ft_free_ptr(stat_str);
//	return (stat_str);
//}

//char	*get_next_line(int fd)
//{
//	static char		**stat_str;
//	char			*line_str;
//
//	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > SSIZE_MAX - 1)
//		return (NULL);
//	if (!stat_str)
//		stat_str = get_stat_init(fd);
//	if (!stat_str[fd])
//		stat_str[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
//	line_str = get_read_file(fd, stat_str[fd]);
//	if (*line_str == '\0')
//	{
//		stat_str[fd] = ft_free_ptr(stat_str[fd]);
//		line_str = ft_free_ptr(line_str);
//		//stat_str = ft_free_ptr(stat_str);
//		stat_str = get_stat_unit(fd, stat_str);
//	}
//	return (line_str);
//}

char	*get_read_file(int fd, char *stat_str)
{
	char		*line_str;
	ssize_t		line_len;
	ssize_t		stat_len;
	ssize_t		full_len;

	line_str = malloc(sizeof(char) * 1);
	*line_str = '\0';
	full_len = 0;
	if (!ft_str_chr(stat_str, &line_len))
	{
		stat_len = 1;
		while (stat_len > 0 && !ft_str_chr(stat_str, &line_len))
		{
			full_len += line_len;
			line_str = ft_str_join(line_str, stat_str, full_len);
			stat_len = read(fd, stat_str, BUFFER_SIZE);
			if (stat_len == -1 || !line_str)
				return (line_str);
			*(stat_str + stat_len) = '\0';
		}
	}
	line_str = ft_str_join(line_str, stat_str, full_len + line_len);
	ft_str_cpy(stat_str, line_len);
	return (line_str);
}

char	*get_next_line(int fd)
{
	static char		*stat_str[FD_SIZE];
	char			*line_str;

	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > SSIZE_MAX - 1)
		return (NULL);
	if (!stat_str[fd])
		stat_str[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	line_str = get_read_file(fd, stat_str[fd]);
	if (*line_str == '\0')
	{
		stat_str[fd] = ft_free_ptr(stat_str[fd]);
		line_str = ft_free_ptr(line_str);
	}
	return (line_str);
}
