/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 04:40:33 by jamrabhi          #+#    #+#             */
/*   Updated: 2022/05/08 04:40:35 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	exit_success(t_data *data)
{
	// printf("SUCCESS\n");
	free_stack(&data->top_stack_a);
	free_stack(&data->top_stack_b);
	exit(EXIT_SUCCESS);
}

void	exit_free(t_data *data)
{
	free_stack(&data->top_stack_a);
	free_stack(&data->top_stack_b);
	exit_error();
}

void	exit_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	free_stack(t_stack **astack)
{
	t_stack	*stack;
	t_stack	*tmp;

	if (astack)
	{
		stack = *astack;
		while (stack)
		{
			if (stack->next)
				tmp = stack->next;
			else
				tmp = NULL;
			free(stack);
			stack = tmp;
		}
		*astack = NULL;
	}
}

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	*str = NULL;
	if (str)
		free(str);
}
