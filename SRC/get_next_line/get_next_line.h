/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez@student.42heilbronn.de <rchavez    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:01:11 by rchavez@stu       #+#    #+#             */
/*   Updated: 2024/09/07 19:03:38 by rchavez@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../ft_malloc/ft_malloc.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define FD_NUM 10240

int		ft_strlen(char *str);
int		search_nl(char str[]);

char	*get_next_line(int fd);
char	*ft_join(char *str, char *buffer);

void	ft_clean(char *buffer);
void	ft_cpy(char *src, char *dst);

#endif