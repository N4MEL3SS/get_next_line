/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 00:19:51 by celadia           #+#    #+#             */
/*   Updated: 2021/12/05 00:19:51 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define FD_MAX 1024

char		*get_next_line(int fd);

ssize_t		ft_str_len(char *str);
int			ft_str_chr(char *str, ssize_t *len);
void		ft_str_cpy(char *str, ssize_t line_len);
char		*ft_str_join(char *dst, char *src, size_t line_len);

#endif //GET_NEXT_LINE_H