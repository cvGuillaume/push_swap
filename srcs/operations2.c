/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:27:52 by gcornet-          #+#    #+#             */
/*   Updated: 2021/10/19 19:27:53 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_data *data, int r)
{
	ft_rev_int_tab(data->stack_a, data->sz_a);
	ra(data, 0);
	ft_rev_int_tab(data->stack_a, data->sz_a);
	if (r)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_data *data, int r)
{
	ft_rev_int_tab(data->stack_b, data->sz_b);
	rb(data, 0);
	ft_rev_int_tab(data->stack_b, data->sz_b);
	if (r)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_data *data)
{
	rra(data, 0);
	rrb(data, 0);
	ft_putendl_fd("rrr", 1);
}

void	ra(t_data *data, int r)
{
	int	i;
	int	tmp;

	if (data->sz_a < 2)
		return ;
	i = 0;
	tmp = data->stack_a[0];
	while (i + 1 < data->sz_a)
	{
		data->stack_a[i] = data->stack_a[i + 1];
		i++;
	}
	data->stack_a[data->sz_a - 1] = tmp;
	if (r)
		ft_putendl_fd("ra", 1);
}

void	rb(t_data *data, int r)
{
	int	i;
	int	tmp;

	if (data->sz_b < 2)
		return ;
	i = 0;
	tmp = data->stack_b[0];
	while (i + 1 < data->sz_b)
	{
		data->stack_b[i] = data->stack_b[i + 1];
		i++;
	}
	data->stack_b[data->sz_b - 1] = tmp;
	if (r)
		ft_putendl_fd("rb", 1);
}
