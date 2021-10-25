/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:28:17 by gcornet-          #+#    #+#             */
/*   Updated: 2021/10/19 19:28:18 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_biggest(int *arr, int sz)
{
	int	i;
	int	max;

	i = 0;
	max = -(0x80000000);
	while (i < sz)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

int	get_smallest(int *arr, int sz)
{
	int			i;
	long long	min;

	i = 0;
	min = 0x7FFFFFFF;
	while (i < sz)
	{
		if ((long long)arr[i] < min)
			min = (long long)arr[i];
		i++;
	}
	return ((int)min);
}

int	get_max_bits(t_data *data)
{
	int	max_bits;
	int	max_num;

	max_bits = 0;
	max_num = get_biggest(data->pos_sorted, data->sz_a);
	while ((max_num >> max_bits) != 0)
		++max_bits;
	return (max_bits);
}

void	radix_stack(t_data *data, int i, int j)
{
	int	sz;
	int	top;

	sz = data->sz_a;
	while (i < get_max_bits(data))
	{
		while (j < sz)
		{
			top = data->stack_a[0];
			if ((top >> i) & 1)
				ra(data, 1);
			else
				pb(data);
			j++;
		}
		j = 0;
		i++;
		while (data->sz_b)
			pa(data);
		if (is_sorted(data->stack_a, data->sz_a))
			break ;
	}
}
