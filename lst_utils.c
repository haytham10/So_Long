/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:54:00 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/18 23:07:48 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_coord	*lst_last(t_coord *coord)
{
	if (!coord)
		return (0);
	while (coord->next)
		coord = coord->next;
	return (coord);
}

static void	lst_add_back(t_coord **lst, t_coord *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lst_last(*lst)->next = new;
}

int	lst_add(t_coord **lst, int x, int y)
{
	t_coord	*new;

	new = (t_coord *)malloc(sizeof(t_coord));
	if (!new)
		return (0);
	new->x = x;
	new->y = y;
	new->next = NULL;
	lst_add_back(lst, new);
	return (1);
}

void	lst_delete(t_coord **lst, int x, int y)
{
	t_coord	*tmp;
	t_coord	*dst;

	tmp = *lst;
	if (tmp && tmp->x == x && tmp->y == y)
	{
		*lst = tmp->next;
		free(tmp);
		tmp = NULL;
		return ;
	}
	while (tmp && tmp->next)
	{
		if (tmp->next->x == x && tmp->next->y == y)
		{
			dst = tmp->next;
			tmp->next = tmp->next->next;
			free(dst);
			dst = NULL;
		}
		tmp = tmp->next;
	}
}