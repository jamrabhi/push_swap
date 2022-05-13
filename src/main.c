/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:37:55 by jamrabhi          #+#    #+#             */
/*   Updated: 2022/03/30 17:37:58 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

void print_list_elt(void *content) {
	printf("%d\n", content);
}



int	main(int argc, char *argv[])
{
	t_list *stack_a;
	// t_list	**stack_a = &first_element;
	// t_list *second;

	if (argc == 1)
		exit_error();
	// int p = 42;
	// first_element = ft_lstnew(&p);
	// second = ft_lstnew((int *)212);
	// stack_a = &first_element;
	// ft_lstadd_back(&first_element, second);
	// ft_lstadd_back(stack_a, ft_lstnew((int *)98	));
	// free(first_element);
	// free(second);
	stack_a = parse_args(argv, &stack_a);
	ft_lstiter(stack_a, &print_list_elt);
	return (0);
}
