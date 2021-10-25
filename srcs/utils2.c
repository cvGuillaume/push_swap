/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:28:48 by gcornet-          #+#    #+#             */
/*   Updated: 2021/10/19 19:28:50 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	permut;

	permut = *a;
	*a = *b;
	*b = permut;
}

void	ft_push(t_data *data, int value, char c)
{
	int	i;
	int	*stack;

	i = 0;
	if (c == 'a')
	{
		stack = data->stack_a;
		i = data->sz_a - 1;
		data->sz_a++;
	}
	else
	{
		stack = data->stack_b;
		i = data->sz_b - 1;
		data->sz_b++;
	}
	while (i + 1)
	{
		stack[i + 1] = stack[i];
		i--;
	}
	stack[0] = value;
}

void	ft_del_1st(t_data *data, char c)
{
	int	i;
	int	sz;
	int	*stack;

	i = 0;
	if (c == 'a')
	{
		stack = data->stack_a;
		sz = data->sz_a - 1;
		data->sz_a--;
	}
	else
	{
		stack = data->stack_b;
		sz = data->sz_b - 1;
		data->sz_b--;
	}
	while (i < sz)
	{
		stack[i] = stack[i + 1];
		i++;
	}
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	permut;

	i = 0;
	permut = 0;
	size--;
	while (i < size)
	{
		permut = tab[i];
		tab[i] = tab[size];
		tab[size] = permut;
		i++;
		size--;
	}
}

int	is_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i + 1 < size)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}
