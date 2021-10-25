/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:28:38 by gcornet-          #+#    #+#             */
/*   Updated: 2021/10/19 19:28:39 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_error_msg(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	ft_free(t_data *data, int exit_code)
{
	free(data->stack_a);
	free(data->stack_b);
	free(data->sorted_a);
	free(data->pos_sorted);
	free(data);
	if (exit_code != -1)
		exit(exit_code);
}

int	ft_get_pos(t_data *data, int nbr)
{
	int	i;

	i = 0;
	while (i < data->sz_a + data->sz_b)
	{
		if (data->sorted_a[i] == nbr)
			return (i);
		i++;
	}
	return (0);
}

void	ft_arrcpy(int *dest, int *src, int sz)
{
	int	i;

	i = 0;
	while (i < sz)
	{
		dest[i] = src[i];
		i++;
	}
}

int	ft_isspace(char c)
{
	return (c == '\f' || c == '\t' || c == ' '
		|| c == '\v' || c == '\n' || c == '\r');
}
