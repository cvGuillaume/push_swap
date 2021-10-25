/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:27:25 by gcornet-          #+#    #+#             */
/*   Updated: 2021/10/19 19:27:26 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_data
{
	int		*sorted_a;
	int		*pos_sorted;
	int		*stack_a;
	int		*stack_b;
	int		count;
	int		sz_a;
	int		sz_b;
}			t_data;

int		ft_error_msg(void);
void	ft_free(t_data *data, int exit_code);
void	ft_swap(int *a, int *b);
t_data	*ft_init_data(char **argv, int argc);
void	ft_push(t_data *data, int value, char c);
void	ft_del_1st(t_data *data, char c);
void	ft_rev_int_tab(int *tab, int size);
int		is_sorted(int *stack, int size);
void	ft_sort_arr(int *arr, int sz);
void	ft_print_stacks(t_data *data);
void	ft_print_bin_1byte_stacks(t_data *data);
int		ft_get_pos(t_data *data, int nbr);
void	ft_get_a_sorted(t_data *data);
int		get_max_bits(t_data *data);
void	print_bin_1byte(int nbr);
int		ft_wordcount2(char const *str, char sep);
char	**free_mat2(char **mat, int sz);
t_data	*ft_parse_data(t_data *data, char **argv, int argc);
void	ft_arrcpy(int *dest, int *src, int sz);
int		ft_atoi_check(char const *str);
int		ft_isspace(char c);
int		get_smallest(int *arr, int sz);
void	rotate_to_smallest(t_data *data);
void	sort_3(t_data *data, int *stack);
char	*ft_strcat(char *dest, char *src);
void	ft_check_args(t_data *data, char *full_str);
void	ft_check_duplicate(t_data *data, char *full_str);
void	ft_check_split(t_data *data, char **split_data, int sz, char *str);

void	sort_5_less(t_data *data);
void	sort_5_75(t_data *data);
void	radix_stack(t_data *data, int i, int j);

void	sa(t_data *data, int r);
void	sb(t_data *data, int r);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data, int r);
void	rb(t_data *data, int r);
void	rr(t_data *data);
void	rra(t_data *data, int r);
void	rrb(t_data *data, int r);
void	rrr(t_data *data);

#endif
