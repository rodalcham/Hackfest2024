/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:07:33 by rchavez           #+#    #+#             */
/*   Updated: 2024/07/05 11:29:28 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*malloc_t(size_t size)
{
	t_link	*new;

	new = (t_link *)malloc(sizeof(t_link));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->data = malloc(size);
	if (!new->data)
		return (free(new), NULL);
	link_append(new);
	return (new->data);
}

void	free_t(void *ptr)
{
	link_rm(ptr);
	free(ptr);
}
