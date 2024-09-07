/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez@student.42heilbronn.de <rchavez    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:01:08 by rchavez@stu       #+#    #+#             */
/*   Updated: 2024/09/07 19:04:28 by rchavez@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	search_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_join(char *str, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = ft_strlen(str);
	j = ft_strlen(&buffer[0]);
	p = (char *)malloc_t((i + j + 1) * sizeof(char));
	if (!p)
	{
		free_t(str);
		return (NULL);
	}
	ft_cpy(str, p);
	ft_cpy(&buffer[0], &p[i]);
	free_t(str);
	ft_clean(buffer);
	if (!p[0])
	{
		free_t(p);
		return (NULL);
	}
	return (p);
}

void	ft_cpy(char *src, char *dst)
{
	int	a;

	a = 0;
	if (!src)
		return ;
	while (src[a] && src[a] != '\n')
	{
		dst[a] = src[a];
		a++;
	}
	if (src[a] == '\n')
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = '\0';
}

void	ft_clean(char *buffer)
{
	int		i;
	int		j;
	char	temp[BUFFER_SIZE + 1];

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		buffer[0] = '\0';
	else
	{
		i++;
		while (buffer[i])
			temp[j++] = buffer[i++];
		temp[j] = '\0';
		i = 0;
		while (temp[i])
		{
			buffer[i] = temp[i];
			i++;
		}
		buffer[i] = '\0';
	}
}
