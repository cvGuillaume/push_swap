/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:29:04 by gcornet-          #+#    #+#             */
/*   Updated: 2021/10/19 19:29:05 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_to_smallest(t_data *data)
{
	int	small;
	int	i;
	int	r;

	i = 0;
	small = get_smallest(data->stack_a, data->sz_a);
	r = 0;
	while (i < data->sz_a)
	{
		if (small == data->stack_a[i])
			break ;
		i++;
	}
	if (i > data->sz_a / 2)
		r = 1;
	while (small != data->stack_a[0])
	{
		if (r)
			rra(data, 1);
		else
			ra(data, 1);
	}
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	ft_check_signs(char *str, int i)
{
	if (str[i] == '-' && (str[i + 1] == ' ' || str[i + 1] == '-'
			|| str[i + 1] == '+'))
		return (1);
	if (str[i] == '+' && (str[i + 1] == ' ' || str[i + 1] == '-'
			|| str[i + 1] == '+'))
		return (1);
	return (0);
}

void	ft_check_args(t_data *data, char *full_str)
{
	int	i;

	i = 0;
	while (full_str[i + 1])
	{
		if ((!ft_isdigit(full_str[i]) && (full_str[i] != ' ')
				&& full_str[i] != '-' && full_str[i] != '+')
			|| ft_check_signs(full_str, i))
		{
			free(full_str);
			ft_free(data, -1);
			ft_error_msg();
		}
		i++;
	}
	if (!ft_isdigit(full_str[i]) && full_str[i] != ' ')
	{
		free(full_str);
		ft_free(data, -1);
		ft_error_msg();
	}
	ft_check_duplicate(data, full_str);
}

void	ft_check_duplicate(t_data *data, char *full_str)
{
	int	i;
	int	j;
	int	tmp;

	j = 0;
	while (j < data->sz_a)
	{
		tmp = data->stack_a[j];
		i = j + 1;
		while (i < data->sz_a)
		{
			if (data->stack_a[i] == tmp)
			{
				free(full_str);
				ft_free(data, -1);
				ft_error_msg();
			}
			i++;
		}
		j++;
	}	
}
