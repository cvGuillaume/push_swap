/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:28:11 by gcornet-          #+#    #+#             */
/*   Updated: 2021/10/19 19:28:12 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_init_data(argv, argc);
	data = ft_parse_data(data, argv, argc);
	if (is_sorted(data->stack_a, data->sz_a))
		ft_free(data, 0);
	if (data->sz_a <= 5)
		sort_5_less(data);
	else if (data->sz_a < 75)
		sort_5_75(data);
	else
		radix_stack(data, 0, 0);
	ft_free(data, 0);
	return (0);
}
