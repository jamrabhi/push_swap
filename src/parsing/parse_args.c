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

int	check_digit(char **str, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (!str || !str[0])
		return (EXIT_FAILURE);
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '+')
		{
			j++;
			if (!str[i][j])
				return (EXIT_FAILURE);
		}
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

void	into_stack(char **str, int arg, t_data *data)
{
	int		i;
	int		tmp;
	t_stack	*new_link;

	i = 0;
	while (str[i])
	{
		new_link = ft_stacknew(ft_atoi(str[i]));
		if (!new_link)
			exit_free(data);
		ft_stackadd_back(&data->top_stack_a, new_link);
		data->stack_a_size++;
		i++;
	}
}

void	parse_args(char *argv[], t_data *data)
{
	int		i;
	char	**args;

	i = 1;
	while (argv[i])
	{
		args = ft_split_whitespaces(argv[i]);
		if (check_digit(args, data) == EXIT_FAILURE)
		{
			free_array(args);
			exit_free(data);
		}
		into_stack(args, i, data);
		free_array(args);
		i++;
	}
}
