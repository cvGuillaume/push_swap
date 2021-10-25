/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:28:59 by gcornet-          #+#    #+#             */
/*   Updated: 2021/10/19 19:29:00 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_arr(int *arr, int sz)
{
	int	i;
	int	j;

	i = 0;
	while (i < sz)
	{
		j = 0;
		while (j < sz)
		{
			if (arr[i] < arr[j])
				ft_swap(&(arr[i]), &(arr[j]));
			j++;
		}
		i++;
	}
}

void	ft_get_a_sorted(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->sz_a)
	{
		data->sorted_a[i] = data->stack_a[i];
		i++;
	}
	ft_sort_arr(data->sorted_a, data->sz_a);
}

char	**free_mat2(char **mat, int sz)
{
	int	i;

	i = 0;
	while (i < sz)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
	return (NULL);
}

int	ft_wordcount2(char const *str, char sep)
{
	int	i;
	int	count;

	if (str == 0 || str[0] == 0)
		return (0);
	i = 1;
	count = 0;
	if (str[0] != sep)
		count++;
	while (str[i] != '\0')
	{
		if ((str[i] != sep && str[i - 1] == sep))
			count++;
		i++;
	}
	return (count);
}

int	ft_atoi_check(char const *str)
{
	long long	final;
	int			sign;

	final = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (ft_isdigit(*str))
	{
		final = final * 10 + *str - '0';
		str++;
	}
	if (final * sign > 2147483647LL || final * sign < -2147483648LL)
		ft_error_msg();
	return (sign * final);
}
