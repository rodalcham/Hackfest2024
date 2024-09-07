/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez@student.42heilbronn.de <rchavez    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:59:09 by rchavez@stu       #+#    #+#             */
/*   Updated: 2024/09/07 22:07:20 by rchavez@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	dbprint(emp_t *head, int argc, char **argv)
{
	int 	i;
	int 	fd;
	int 	j;
	emp_t	*temp;

	char Departments[5][42] = {"Management", "Marketing", "Manufacturing", "Research", "HR"};
	if (chdir("..") < 0)
		return ;
	fd = open(OUTPUT, O_WRONLY | O_CREAT | O_TRUNC);
	if (fd < 0)
		return ;
	if (dup2(fd, 1) < 0)
		return ;
	close(fd);
	i = 0;
	while (i < argc)
	{
		printf("{\n\t\"name\": \"%s\",\n\t\"department\": [\n", argv[i]);
		j = 0;
		while (j < 5)
		{
			temp = head;
			printf("\t\t{\n\t\t\t\"name\": \"%s\",\n\t\t\t\"staff\": [\n", Departments[j]);
			while (temp)
			{
				if (!strcmp(temp->local, argv[i]) && !strcmp(temp->department, Departments[j]))
				{
					printf("\t\t\t\t{\n");
					printf("\t\t\t\t\t\"name\": \"%s\",\n", temp->name);
					printf("\t\t\t\t\t\"lname\": \"%s\",\n", temp->lname);
					printf("\t\t\t\t\t\"VM\": %f,\n", temp->emmissions[0]);
					printf("\t\t\t\t\t\"Mensa\": %f,\n", temp->emmissions[1]);
					printf("\t\t\t\t\t\"OfficeSupplies\": %f,\n", temp->emmissions[2]);
					printf("\t\t\t\t\t\"Parking\": %f,\n", temp->emmissions[3]);
					printf("\t\t\t\t\t\"Travel\": %f,\n", temp->emmissions[4]);
					printf("\t\t\t\t\t\"Emails\": %f,\n", temp->emmissions[5]);
					printf("\t\t\t\t\t\"Energy\": %f,\n", temp->emmissions[6]);
					printf("\t\t\t\t},\n");
				}
				temp = temp->next;
			}
			j++;
			printf("\t\t\t],\n\t\t},\n");
		}
		printf("\t],\n");
		printf("},\n");
		i++;
	}
}
