/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:07:29 by rchavez           #+#    #+#             */
/*   Updated: 2024/07/05 11:30:45 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_link	**get_head(void)
{
	static t_link	*head = NULL;

	return (&head);
}

int	*get_bad(void)
{
	static int	bad = -1;

	return (&bad);
}
