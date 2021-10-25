/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:27:44 by gcornet-          #+#    #+#             */
/*   Updated: 2021/10/19 19:27:46 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_data *data, int r)
{
	if (data->sz_a > 1)
	{
		ft_swap(&(data->stack_a[0]), &(data->stack_a[1]));
		if (r)
			ft_putendl_fd("sa", 1);
	}
}

void	sb(t_data *data, int r)
{
	if (data->sz_b > 1)
	{
		ft_swap(&(data->stack_b[0]), &(data->stack_b[1]));
		if (r)
			ft_putendl_fd("sb", 1);
	}
}

void	ss(t_data *data)
{
	sa(data, 0);
	sb(data, 0);
	ft_putendl_fd("ss", 1);
}

void	pa(t_data *data)
{
	if (data->sz_b)
	{	
		ft_push(data, data->stack_b[0], 'a');
		ft_del_1st(data, 'b');
		ft_putendl_fd("pa", 1);
	}
}

void	pb(t_data *data)
{
	if (data->sz_a)
	{	
		ft_push(data, data->stack_a[0], 'b');
		ft_del_1st(data, 'a');
		ft_putendl_fd("pb", 1);
	}
}
