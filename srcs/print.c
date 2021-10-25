/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:28:04 by gcornet-          #+#    #+#             */
/*   Updated: 2021/10/19 19:28:06 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_stacks(t_data *data)
{
	int	i;

	i = 0;
	ft_putendl_fd("a	b", 1);
	ft_putendl_fd("_	_", 1);
	while (i < data->sz_a || i < data->sz_b)
	{
		if (i < data->sz_a)
			ft_putnbr_fd(data->stack_a[i], 1);
		else
			ft_putchar_fd('	', 1);
		ft_putstr_fd("	", 1);
		if (i < data->sz_b)
			ft_putnbr_fd(data->stack_b[i], 1);
		else
			ft_putchar_fd('	', 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putendl_fd("_	_", 1);
	ft_putendl_fd("a	b", 1);
}

void	ft_print_bin_1byte_stacks(t_data *data)
{
	int	i;

	i = 0;
	ft_putendl_fd("a		b", 1);
	ft_putendl_fd("_		_", 1);
	while (i < data->sz_a || i < data->sz_b)
	{
		if (i < data->sz_a)
			print_bin_1byte(data->stack_a[i]);
		else
			ft_putstr_fd("0	", 1);
		ft_putstr_fd("	", 1);
		if (i < data->sz_b)
			print_bin_1byte(data->stack_b[i]);
		else
			ft_putstr_fd("0	", 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putendl_fd("_		_", 1);
	ft_putendl_fd("a		b", 1);
}

void	print_bin_1byte(int nbr)
{
	int		j;
	int		i;
	char	byte;
	int		bits[8];

	j = 0;
	i = 7;
	byte = ((char *)&nbr)[0];
	while (j < 8)
	{
		bits[j] = byte & 1;
		byte >>= 1;
	}
	while (i > -1)
	{
		ft_putchar_fd(bits[i] + '0', 1);
		i--;
	}
}
