/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez@student.42heilbronn.de <rchavez    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 07:37:13 by rchavez@stu       #+#    #+#             */
/*   Updated: 2024/09/07 15:57:54 by rchavez@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_role(char *dir, emp_t **head)
{
	int	fd;
	char *str;

	fd = open("Role.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	str = get_next_line(fd);
	while (str)
	{
		if (emp_add(head, dir, str))
		{
			close(fd);
			return (1);
		}
		free_t(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	fromKey(emp_t *head, char *file, char *key)
{
	int		fd;
	int		fdKey;
	char	*str;
	char	*str2;
	char	id[42];
	char	item[42];
	char	temp[42];

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	str = get_next_line(fd);
	while (str)
	{
		fdKey = open(key, O_RDONLY);
		if (fdKey < 0)
		{
			close(fd);
			return (1);
		}
		ft_strlcpy(id, str, 42, 2);
		ft_strlcpy(item, str, 42, 3);
		str2 = get_next_line(fdKey);
		while (str2)
		{
			ft_strlcpy(temp, str2, 42, 0);
			if (!strcmp(item, temp))
			{
				ft_strlcpy(temp, str2, 42, 1);
				emp(head, id, temp);
			}
			free_t(str2);
			str2 = get_next_line(fdKey);
		}
		free_t(str);
		str = get_next_line(fd);
		close(fdKey);
	}
	close(fd);
	return (0);
}

int	Parking(emp_t *head, char *file)
{
	char	id[42];
	char	*str;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	str = get_next_line(fd);
	while (str)
	{
		ft_strlcpy(id, str, 42, 2);
		emp(head, id, "17");
		free_t(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	Travel(emp_t *head, char *file)
{
	char	id[42];
	char	km[42];
	char	method[42];
	char	*str;
	int		fd;
	int		delta;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	str = get_next_line(fd);
	while (str)
	{
		ft_strlcpy(id, str, 42, 1);
		ft_strlcpy(method, str, 42, 2);
		ft_strlcpy(km, str, 42, 3);
		if (!strcmp(method, "Bus"))
			delta = 36;
		else if (!strcmp(method, "Train"))
			delta = 4;
		else if (!strcmp(method, "Plane"))
			delta = 101;
		emp_i(head, id, (atoi(km) * delta / 1000));
		free_t(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	Emails(emp_t *head, char *file)
{
	int		fd;
	char	id[42];
	char	num[42];
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	str = get_next_line(fd);
	while (str)
	{
		ft_strlcpy(id, str, 42, 0);
		ft_strlcpy(num, str, 42, 1);
		emp_i(head, id, atoi(num) / 30000);
		free_t(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	Energy(emp_t *head,  char *dir, char *file)
{
	emp_t	*temp;
	char	dpt[42];
	char	amt[42];
	char	unit[42];
	int		delta;
	char	*str;
	int		fd;
	int		num;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	str = get_next_line(fd);
	while (str)
	{
		num = 0;
		ft_strlcpy(dpt, str, 42, 0);
		ft_strlcpy(unit, str, 42, 1);
		ft_strlcpy(amt, str, 42, 2);
		temp = head;
		if (!strcmp(unit, "KWH"))
			delta = 35;
		else if (!strcmp(unit, "KL"))
			delta = 35;
		else if (!strcmp(unit, "KCAL"))
			delta = 210;
		while (temp)
		{
			if (!strcmp(dpt, temp->department) && !strcmp(temp->local, dir))
				num++;
			temp = temp->next;
		}
		temp = head;
		while (temp)
		{
			if (!strcmp(dpt, temp->department) && !strcmp(temp->local, dir))
				temp->emmissions += (atoi(amt) * delta / 1000 ) / num;
			temp = temp->next;
		}
		free_t(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	extract(char *dir, emp_t** head)
{
	if (chdir(dir) < 0)
		return (1);
	if	(get_role(dir, head))
		return (1);
	if (fromKey(*head, "Vending Machine.txt", "Vending Machine Key.txt"))
		return (1);
	if (fromKey(*head, "Mensa.txt", "Mensa Key.txt"))
		return (1);
	if (fromKey(*head, "Office Supplies.txt", "Office Supplies Key.txt"))
		return (1);
	if (Parking(*head, "Parking.txt"))
		return (1);
	if (Travel(*head, "Travel.txt"))
		return (1);
	if (Emails(*head, "Emails.txt"))
		return (1);
	if (Energy(*head, dir, "Energy.txt"))
		return (1);
	return (0);
}
