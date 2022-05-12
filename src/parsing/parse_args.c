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

void print_list_elt(void *content) {
	printf("%d\n", *(int*)content);
}

void	into_stack(char **str)
{
	t_list	*first_element;
	t_list	**stack_a;
	int		i;
	int		tmp;

	i = 1;
	tmp = ft_atoi(str[0]);
	first_element = ft_lstnew(&tmp);
	stack_a = &first_element;
	while (str[i])
	{
		tmp = ft_atoi(str[i]);
		ft_lstadd_back(stack_a, ft_lstnew(&tmp));
		i++;
	}
	ft_lstiter(first_element, &print_list_elt);
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
		// into_stack(str[i]);
		i++;
	}
}

void	parse_args(char *argv[], t_stack stack_a)
{
	int		i;
	char	**args;

	i = 1;
	args = NULL;
	while (argv[i])
	{
		args = ft_split_whitespaces(argv[i]);
		check_digit(args);
		// printf("argv[%d]\n", i);
		// show_array(args);
		// free_array(args);
		show_array(args);
		i++;
	}
}
