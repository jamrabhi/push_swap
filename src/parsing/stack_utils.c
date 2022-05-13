/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:49:08 by jamrabhi          #+#    #+#             */
/*   Updated: 2022/05/13 17:49:09 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*ft_stacknew(int nb)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		return (NULL);
	tmp->nb = nb;
	tmp->next = NULL;
	return (tmp);
}

void	ft_stackadd_front(t_stack **astack, t_stack *new)
{
	if (astack && new)
	{
		new->next = *astack;
		*astack = new;
	}
}

void	ft_stackadd_back(t_stack **astack, t_stack *new)
{
	t_stack	*tmp;

	tmp = *astack;
	if (!tmp)
		*astack = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_stackiter(t_stack *stack, void (*f)(int))
{
	if (stack && f)
	{
		while (stack)
		{
			f(stack->nb);
			stack = stack->next;
		}
	}
}

void	ft_stackdelone(t_stack *stack, void (*del)(int))
{
	if (stack && del)
	{
		del(stack->nb);
		free(stack);
	}
}
