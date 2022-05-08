/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 04:32:15 by jamrabhi          #+#    #+#             */
/*   Updated: 2022/05/08 04:32:19 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
// A SUPPRIMER !
#include <stdio.h>

void	show_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("str[%d] = '%s'\n", i, str[i]);
		i++;
	}
	printf("\n");
}

void	check_digit(char **str)
{
	int	i;
	int	j;

	i = 0;
	if (!str || !str[0])
	{
		free_array(str);
		exit_error();
	}
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '+')
			j++;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
			{
				free_array(str);
				exit_error();
			}
			j++;
		}
		i++;
	}
}

void	parse_args(char *argv[])
{
	int		i;
	char	**tmp;

	i = 1;
	tmp = NULL;
	while (argv[i])
	{
		tmp = ft_split_whitespaces(argv[i]);
		check_digit(tmp);
		printf("argv[%d]\n", i);
		show_array(tmp);
		free_array(tmp);
		i++;
	}
}
