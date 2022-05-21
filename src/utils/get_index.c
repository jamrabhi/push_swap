/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 03:26:51 by jamrabhi          #+#    #+#             */
/*   Updated: 2022/05/21 03:26:54 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	get_index(t_data *data)
{
	int		i;
	t_stack	*stack;
	t_stack	*stack_cpy;

	stack = data->top_stack_a;
	while (stack)
	{
		i = 0;
		stack_cpy = data->top_stack_a;
		while (stack_cpy)
		{
			if (stack->nb > stack_cpy->nb)
				i++;
			stack_cpy = stack_cpy->next;
		}
		stack->index = i;
		stack = stack->next;
	}
}
