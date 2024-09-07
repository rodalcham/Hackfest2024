/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez@student.42heilbronn.de <rchavez    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:59:09 by rchavez@stu       #+#    #+#             */
/*   Updated: 2024/09/07 21:19:49 by rchavez@stu      ###   ########.fr       */
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
		printf("{\n\tname: \"%s\",\n\tdepartment: [\n", argv[i]);
		j = 0;
		while (j < 5)
		{
			temp = head;
			printf("\t\t{\n\t\t\tname: \"%s\",\n\t\t\tstaff: [\n", Departments[j]);
			while (temp)
			{
				if (!strcmp(temp->local, argv[i]) && !strcmp(temp->department, Departments[j]))
				{
					printf("\t\t\t\t{\n");
					printf("\t\t\t\t\tname: \"%s\",\n", temp->name);
					printf("\t\t\t\t\tlname: \"%s\",\n", temp->lname);
					printf("\t\t\t\t\tVM: %f,\n", temp->emmissions[0]);
					printf("\t\t\t\t\tMensa: %f,\n", temp->emmissions[1]);
					printf("\t\t\t\t\tOfficeSupplies: %f,\n", temp->emmissions[2]);
					printf("\t\t\t\t\tParking: %f,\n", temp->emmissions[3]);
					printf("\t\t\t\t\tTravel: %f,\n", temp->emmissions[4]);
					printf("\t\t\t\t\tEmails: %f,\n", temp->emmissions[5]);
					printf("\t\t\t\t\tEnergy: %f,\n", temp->emmissions[6]);
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
