/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 20:02:02 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/07 18:40:47 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			add_arg(t_arg **head, char *str)
{
	t_arg	*new;
	t_arg	*ptr;

	if (!(new = malloc(sizeof(t_arg))))
		exit(EXIT_FAILURE);
	new->name = ft_strdup(str);
	new->size = ft_strlen(str);
	new->select = 0;
	new->cursor = 0;
	new->next = NULL;
	new->prev = NULL;
	ptr = *head;
	if (ptr == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
	}
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
		new->prev = ptr;
	}
}

void			linkfrontend(t_arg **head)
{
	t_arg	*ptr;

	ptr = *head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = *head;
	(*head)->prev = ptr;
}

char			**arg_sort(char **argv)
{
	int		i;
	int		j;
	int		max;
	char	*tmp;

	max = 1;
	while (argv[max])
		max++;
	i = 1;
	while (i < max - 1)
	{
		j = i + 1;
		while (j < max)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[j];
				argv[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (argv);
}

void			init_arg(t_slc *slc, char **argv)
{
	int		i;
	t_arg	*head;

	head = NULL;
	argv = arg_sort(argv);
	i = 1;
	while (argv[i])
	{
		add_arg(&head, argv[i]);
		i++;
	}
	slc->nb_arg = i - 1;
	slc->row = slc->nb_arg - 1;
	linkfrontend(&head);
	slc->arg = head;
	slc->arg->cursor = 1;
}
