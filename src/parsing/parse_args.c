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

int	check_duplicate(t_stack *stack_a)
{
	int		i;
	int		j;
	t_stack	*stack_tmp;

	while (stack_a)
	{
		i = stack_a->nb;
		stack_tmp = stack_a;
		while (stack_tmp->next)
		{
			stack_tmp = stack_tmp->next;
			j = stack_tmp->nb;
			if (i == j)
				return (EXIT_FAILURE);
		}
		stack_a = stack_a->next;
	}
	return (EXIT_SUCCESS);
}

int	check_digit(char **str, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	(void)data;
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

int	into_stack(char **str, t_data *data)
{
	int		i;
	t_stack	*new_link;
	long	nb;

	i = 0;
	(void)data;
	while (str[i])
	{
		nb = ft_atol(str[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (EXIT_FAILURE);
		new_link = ft_stacknew(ft_atoi(str[i]));
		if (!new_link)
			return (EXIT_FAILURE);
		ft_stackadd_back(&data->top_stack_a, new_link);
		data->stack_a_size++;
		i++;
	}
	return (EXIT_SUCCESS);
}

void	parse_args(char *argv[], t_data *data)
{
	int		i;
	char	**args;

	i = 1;
	while (argv[i])
	{
		args = ft_split_whitespaces(argv[i]);
		if (check_digit(args, data) == EXIT_FAILURE || into_stack(args, data)
			== EXIT_FAILURE)
		{
			free_array(args);
			exit_free(data);
		}
		free_array(args);
		i++;
	}
	if (check_duplicate(data->top_stack_a) == EXIT_FAILURE)
		exit_free(data);
}
