/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:45:45 by jamrabhi          #+#    #+#             */
/*   Updated: 2022/05/14 18:45:47 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ra(t_data *data, int i)
{
	t_stack	*stack;
	t_stack	*new_link;
	t_stack	*tmp;

	print_stack_a_b(data->top_stack_a, data->top_stack_b);

	if (data->stack_a_size > 1)
	{
		stack = data->top_stack_a;
		tmp = stack->next;
		new_link = ft_stacknew_index(stack->nb, stack->index);
		if (!new_link)
			exit_free(data);
		ft_stackadd_back(&tmp, new_link);
		data->top_stack_a = tmp;
		free(stack);
		if (i == 1)
			ft_putstr_fd("ra\n", 1);
	}
	print_stack_a_b(data->top_stack_a, data->top_stack_b);

}

void	rb(t_data *data, int i)
{
	t_stack	*stack;
	t_stack	*new_link;
	t_stack	*tmp;

	print_stack_a_b(data->top_stack_a, data->top_stack_b);

	if (data->stack_b_size > 1)
	{
		stack = data->top_stack_b;
		tmp = stack->next;
		new_link = ft_stacknew_index(stack->nb, stack->index);
		if (!new_link)
			exit_free(data);
		ft_stackadd_back(&tmp, new_link);
		data->top_stack_b = tmp;
		free(stack);
		if (i == 1)
			ft_putstr_fd("rb\n", 1);
	}
	print_stack_a_b(data->top_stack_a, data->top_stack_b);

}

void	rr(t_data *data)
{
	ra(data, 0);
	rb(data, 0);
	ft_putstr_fd("rr\n", 1);
}
