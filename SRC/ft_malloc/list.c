/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:12:53 by rchavez           #+#    #+#             */
/*   Updated: 2024/07/05 11:31:09 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	link_append(t_link *new)
{
	t_link	*list;

	list = *get_head();
	if (!list)
	{
		*get_head() = new;
		return ;
	}
	else
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
}

void	link_free(void)
{
	t_link	*list;
	t_link	*temp;

	list = *get_head();
	if (!list)
		return ;
	while (list)
	{
		free(list->data);
		temp = list;
		list = list->next;
		free(temp);
	}
	*get_head() = NULL;
}

void	link_rm(void *ptr)
{
	t_link	*list;
	t_link	*prev;

	list = *get_head();
	if (!list)
		return ;
	if (list->data == ptr)
	{
		*get_head() = list->next;
		free(list);
		return ;
	}
	prev = list;
	list = list->next;
	while (list)
	{
		if (list->data == ptr)
		{
			prev->next = list->next;
			free(list);
			return ;
		}
		prev = list;
		list = list->next;
	}
}

int	leak_size(void)
{
	t_link	*list;
	int		ret;

	list = *get_head();
	if (!list)
		return (0);
	ret = 0;
	while (list)
	{
		ret++;
		list = list->next;
	}
	return (ret);
}
