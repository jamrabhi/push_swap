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

// void print_list_elt(void *content) {
// 	printf("%d\n", content);
// }

t_list	*into_stack(char **str, int arg, t_list *stack_a)
{
	int		i;
	int		tmp;
	t_list	*new_link;

	i = 0;
	while (str[i])
	{
		tmp = ft_atoi(str[i]);
		if (i == 0 && arg == 1)
		{
			stack_a = ft_lstnew(tmp);
		}
		else
		{
			new_link = ft_lstnew((int *)tmp);
			ft_lstadd_back(&stack_a, new_link);
		}
		// ft_lstadd_back(&stack_a, ft_lstnew(&tmp));
		i++;
	}
	// ft_lstiter(stack_a, &print_list_elt);
	return (stack_a);
}

t_list	*parse_args(char *argv[], t_list *stack_a)
{
	int		i;
	char	**args;
	t_list	*new_link;
	int		tmp;

	i = 1;
	args = NULL;
	// stack_a = NULL;
	while (argv[i])
	{
		args = ft_split_whitespaces(argv[i]);
		check_digit(args);
		tmp = ft_atoi(argv[i]);
		stack_a = into_stack(args, i, stack_a);
		// if (i == 1)
		// 	stack_a = ft_lstnew(&tmp);
		// else
		// {
		// 	new_link = ft_lstnew(&tmp);
		// 	ft_lstadd_front(&stack_a, new_link);
		// }
		// printf("argv[%d]\n", i);
		// show_array(args);
		// free_array(args);
		i++;
	}
	return (stack_a);
	// printf("STaCK = %d\n", *(int *)stack_a->content);
	// ft_lstiter(stack_a, &print_list_elt);
}
