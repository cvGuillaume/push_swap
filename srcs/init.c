/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:27:37 by gcornet-          #+#    #+#             */
/*   Updated: 2021/10/19 19:27:40 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_get_pos_sorted(t_data *data, int sz)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < sz)
	{
		while (j < sz)
		{
			if (data->stack_a[i] == data->sorted_a[j])
			{
				data->pos_sorted[i] = j;
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	ft_arrcpy(data->stack_a, data->pos_sorted, data->sz_a);
}

void	ft_get_full_str_size(t_data *data, char **argv, int argc)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	data->sz_a = 0;
	while (i < argc)
	{
		count += ft_strlen(argv[i]);
		data->sz_a += ft_wordcount2(argv[i], ' ');
		count++;
		i++;
	}
	data->count = count;
}

char	*ft_get_all_args(t_data *data, char **argv, int argc)
{
	char	*str = "";
	int		i;

	str = malloc(sizeof(char) * (data->count + 1));
	if (!str)
		ft_error_msg();
	ft_bzero(str, data->count + 1);
	i = 1;
	while (i < argc)
	{
		ft_strcat(str, argv[i]);
		if (i + 1 < argc)
			str = ft_strcat(str, " ");
		i++;
	}
	return (str);
}

t_data	*ft_parse_data(t_data *data, char **argv, int argc)
{
	char	**split_data;
	char	*full_str;
	int		i;
	int		sz;

	i = 0;
	full_str = ft_get_all_args(data, argv, argc);
	split_data = ft_split(full_str, ' ');
	sz = 0;
	while (split_data[sz])
		sz++;
	ft_check_split(data, split_data, sz, full_str);
	while (i < sz)
	{
		data->stack_a[i] = ft_atoi_check(split_data[i]);
		i++;
	}
	ft_get_a_sorted(data);
	ft_get_pos_sorted(data, sz);
	free_mat2(split_data, sz);
	if (ft_strlen(full_str))
		ft_check_args(data, full_str);
	free(full_str);
	return (data);
}

t_data	*ft_init_data(char **argv, int argc)
{
	int		sz;
	t_data	*data;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		ft_error_msg();
	ft_get_full_str_size(data, argv, argc);
	sz = data->sz_a;
	data->stack_a = (int *)malloc(sizeof(int) * (sz));
	data->stack_b = (int *)malloc(sizeof(int) * (sz));
	data->sorted_a = (int *)malloc(sizeof(int) * (sz));
	data->pos_sorted = (int *)malloc(sizeof(int) * (sz));
	if (!data->stack_a || !data->stack_b
		|| !data->sorted_a || !data->pos_sorted)
		ft_error_msg();
	data->sz_a = sz;
	data->sz_b = 0;
	return (data);
}
