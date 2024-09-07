/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez@student.42heilbronn.de <rchavez    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:01:09 by rchavez@stu       #+#    #+#             */
/*   Updated: 2024/09/07 19:05:57 by rchavez@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[FD_NUM][BUFFER_SIZE + 1];
	char		*str;
	int			chars_read;

	str = NULL;
	if (BUFFER_SIZE < 1 || fd < 0 || fd >= FD_NUM)
		return (NULL);
	chars_read = 1;
	if (buffer[fd][0])
		str = ft_join(str, buffer[fd]);
	while (chars_read)
	{
		if (search_nl(str))
			return (str);
		chars_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (chars_read == -1)
		{
			if (str)
				free_t(str);
			return (NULL);
		}
		buffer[fd][chars_read] = '\0';
		str = ft_join(str, &buffer[fd][0]);
	}
	return (ft_join(str, &buffer[fd][0]));
}