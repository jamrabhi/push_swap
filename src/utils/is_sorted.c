/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 03:30:31 by jamrabhi          #+#    #+#             */
/*   Updated: 2022/05/21 03:30:51 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_sorted(t_data *data)
{
	t_stack	*stack;
	int		nb;

	stack = data->top_stack_a;
	while (stack)
	{
		nb = stack->nb;
		stack = stack->next;
		if (stack && nb > stack->nb)
			return (EXIT_FAILURE);
	}
	if (data->top_stack_b)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
