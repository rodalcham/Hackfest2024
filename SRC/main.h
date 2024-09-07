/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez@student.42heilbronn.de <rchavez    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 07:26:55 by rchavez@stu       #+#    #+#             */
/*   Updated: 2024/09/07 15:24:02 by rchavez@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# include "get_next_line/get_next_line.h"
# include "ft_malloc/ft_malloc.h"

# define malloc malloc_t
# define free free_t

# define OUTPUT tabloid

typedef struct s_emp
{
	char			id[42];
	char			name[42];
	char			lname[42];
	char			local[42];
	char			department[42];
	int				emmissions;
	struct s_emp	*next;
}					emp_t;

int		extract(char *dir, emp_t** head);
int		emp_add(emp_t **head, char *dir, char *str);
void	emp(emp_t *head, char *id, char *ammount);
void	emp_i(emp_t *head, char *id, int ammount);
void	ft_strlcpy(char *dst, char *src, size_t size, int param);

#endif