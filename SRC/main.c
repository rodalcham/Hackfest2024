/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez@student.42heilbronn.de <rchavez    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 07:23:31 by rchavez@stu       #+#    #+#             */
/*   Updated: 2024/09/07 11:01:28 by rchavez@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	int	locals;
	int	i;
	emp_t	*head;

	head = NULL;
	if (argc < 3)
	{
		fprintf(stderr, "Too few argunents in call\n");
		return (1);
	}
	if (chdir(argv[1]) < 0)
	{
		fprintf(stderr, "Invalid Directory\n");
		return (1);
	}
	locals = argc - 2;
	i = 0;
	while (i < locals)
	{
		if (extract(argv[i + 2], &head))
		{
			fprintf(stderr, "Error while extracting ");
			fprintf(stderr, "%s", argv[i + 2]);
			fprintf(stderr, "\n");
			return (1);
		}
		i++;
	}
	// if (put_emp()) 
	while (head)
	{
		printf("%s, id %s produced %i Kg of CO2.\n", head->name, head->id, head->emmissions);
		head = head->next;
	}
	link_free();
	return (0);
}
