/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_75.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:28:23 by gcornet-          #+#    #+#             */
/*   Updated: 2021/10/19 19:28:25 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_5_75(t_data *data)
{
	int	i;
	int	sz;

	i = 0;
	sz = data->sz_a - 3;
	rotate_to_smallest(data);
	while (i < sz)
	{
		rotate_to_smallest(data);
		pb(data);
		i++;
	}
	sort_3(data, data->stack_a);
	while (i)
	{
		pa(data);
		i--;
	}
}

void	ft_check_split(t_data *data, char **split_data, int sz, char *str)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (split_data[i])
	{
		if (ft_strlen(split_data[i]) > 1)
		{
			while (split_data[i][j])
			{
				if (split_data[i][j] == '-' || split_data[i][j] == '+')
				{
					free_mat2(split_data, sz);
					free(str);
					ft_free(data, -1);
					ft_error_msg();
				}
				j++;
			}
		}
		j = 1;
		i++;
	}
}
