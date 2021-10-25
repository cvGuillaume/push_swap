/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:59:47 by gcornet-          #+#    #+#             */
/*   Updated: 2020/11/24 14:59:49 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**free_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
	return (NULL);
}

static int	spot_charset(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

int	ft_wordcount(char const *str, char sep)
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

static char	**sep(char **mat, const char *str, char charset, int len)
{
	int	y;
	int	x;
	int	z;

	y = 0;
	z = 0;
	x = 0;
	while (y < ft_wordcount(str, charset))
	{
		len = 0;
		while (str[z] && spot_charset(str[z], charset) == 1)
			z++;
		while (str[z++] && spot_charset(str[z], charset) == 0)
			len++;
		mat[y] = (char *)malloc(len + 2 * sizeof(char));
		if (!(mat[y]))
			return (free_mat(mat));
		x = -1;
		while (++x <= len)
			mat[y][x] = str[x + z - len - 1];
		mat[y][x] = '\0';
		y++;
	}
	mat[y] = NULL;
	return (mat);
}

char	**ft_split(char const *s, char c)
{
	char	**mat;
	int		len;

	len = 0;
	mat = (char **)malloc((ft_wordcount((char *)s, c) + 1) * sizeof(char *));
	if (!(mat))
		return (NULL);
	sep(mat, s, c, len);
	return (mat);
}
