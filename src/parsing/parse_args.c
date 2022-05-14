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

void	check_digit(char **str, t_stack *stack_a)
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
		{
			j++;
			if (!str[i][j])
			{
				free_array(str);
				free_stack(&stack_a);
				exit_error();
			}
		}
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

t_stack	*into_stack(char **str, int arg, t_stack *stack_a)
{
	int		i;
	int		tmp;
	t_stack	*new_link;

	i = 0;
	while (str[i])
	{
		tmp = ft_atoi(str[i]);
		if (i == 0 && arg == 1)
			stack_a = ft_stacknew(tmp);
		else
		{
			new_link = ft_stacknew(tmp);
			ft_stackadd_back(&stack_a, new_link);
		}
		i++;
	}
	return (stack_a);
}

t_stack	*parse_args(char *argv[], t_stack *stack_a)
{
	int		i;
	char	**args;

	i = 1;
	while (argv[i])
	{
		args = ft_split_whitespaces(argv[i]);
		check_digit(args, stack_a);
		stack_a = into_stack(args, i, stack_a);
		i++;
		free_array(args);
	}
	return (stack_a);
}
