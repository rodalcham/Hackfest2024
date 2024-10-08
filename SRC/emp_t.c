/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emp_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez@student.42heilbronn.de <rchavez    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 08:06:22 by rchavez@stu       #+#    #+#             */
/*   Updated: 2024/09/07 17:22:50 by rchavez@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_strlcpy(char *dst, char *src, size_t size, int param)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!size)
		return ;
	while (param)
	{
		while (src[j] && src[j] != '\n' && src[j] != ':')
			j++;
		if (src[j] == ':')
			j++;
		if (src[j] == ':')
			j++;
		param--;
	}
	i = 0;
	while (src[i + j] && src[i + j] != ':' && src[i + j] != '\n' && src[i + j] != '\r' && i < size - 1)
	{
		dst[i] = src[i + j];
		i++;
	}
	while (i < size)
	{
		dst[i] = '\0';
		i++;
	}
}

int	emp_add(emp_t **head, char *dir, char *str)
{
	emp_t *new;

	new = (emp_t *)malloc(sizeof(emp_t));
	if (!new)
		return (1);
	new->emmissions[0] = 0;
	new->emmissions[1] = 0;
	new->emmissions[2] = 0;
	new->emmissions[3] = 0;
	new->emmissions[4] = 0;
	new->emmissions[5] = 0;
	new->emmissions[6] = 0;
	ft_strlcpy(new->id, str, 42, 0);
	ft_strlcpy(new->department, str, 42, 1);
	ft_strlcpy(new->name, str, 42, 2);
	ft_strlcpy(new->lname, str, 42, 3);
	ft_strlcpy(new->local, dir, 42, 0);
	if (*head)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		*head = new;
		new->next = NULL;
	}
	return (0);
}

void	emp(emp_t *head, char *id, char *ammount, int n)
{
	while (head)
	{
		if (!strcmp(id, head->id))
		{
			head->emmissions[n] += atof(ammount);
			return ;
		}
		else
			head = head->next;
	}
}

void	emp_i(emp_t *head, char *id, float ammount, int n)
{
	while (head)
	{
		if (!strcmp(id, head->id))
		{
			head->emmissions[n] += ammount;
			return ;
		}
		else
			head = head->next;
	}
}