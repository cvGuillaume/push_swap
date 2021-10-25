/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_less.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:28:32 by gcornet-          #+#    #+#             */
/*   Updated: 2021/10/19 19:28:33 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_data *data, int *stack)
{
	if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] < stack[2])
		sa(data, 1);
	else if (stack[0] > stack[1] && stack[1] > stack[2])
	{
		sa(data, 1);
		rra(data, 1);
	}
	else if (stack[0] > stack[1] && stack[1] < stack[2])
		ra(data, 1);
	else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[0] < stack[2])
	{
		sa(data, 1);
		ra(data, 1);
	}
	else
		rra(data, 1);
}

static void	sort_4(t_data *data)
{
	rotate_to_smallest(data);
	pb(data);
	sort_3(data, data->stack_a);
	pa(data);
}

static void	sort_5(t_data *data)
{
	rotate_to_smallest(data);
	pb(data);
	rotate_to_smallest(data);
	pb(data);
	if (!is_sorted(data->stack_a, data->sz_a))
		sort_3(data, data->stack_a);
	pa(data);
	pa(data);
}

void	sort_5_less(t_data *data)
{
	if (data->sz_a == 2)
		ra(data, 1);
	if (data->sz_a == 3)
		sort_3(data, data->stack_a);
	if (data->sz_a == 4)
		sort_4(data);
	if (data->sz_a == 5)
		sort_5(data);
}
