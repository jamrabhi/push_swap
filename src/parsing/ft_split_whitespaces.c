/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 22:00:11 by jamrabhi          #+#    #+#             */
/*   Updated: 2022/05/08 22:00:13 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_count_words(char *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s || !s[0])
		exit_error();
	while (s && s[i])
	{
		if (ft_isspace(s[i]))
			i++;
		else
		{
			j++;
			while (!ft_isspace(s[i]) && s[i])
				i++;
		}
	}
	return (j);
}

char	**ft_split_whitespaces(char *s)
{
	size_t	i;
	char	**rt;
	size_t	index;
	size_t	start;

	i = 0;
	index = 0;
	rt = (char **)malloc(sizeof(*rt) * (ft_count_words(s) + 1));
	if (!s || !rt)
		return (NULL);
	while (s[i])
	{
		if (!ft_isspace(s[i]))
		{
			start = i;
			while (!ft_isspace(s[i]) && s[i])
				i++;
			rt[index++] = ft_substr(s, start, (i - start));
		}
		else
			i++;
	}
	rt[index] = NULL;
	return (rt);
}
