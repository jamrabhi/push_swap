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

void	print_list_elt(int nb)
{
	printf("%d\n", nb);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	if (argc == 1)
		exit_error();
	stack_a = parse_args(argv, stack_a);
	ft_stackiter(stack_a, &print_list_elt);
	free_stack(&stack_a);
	return (0);
}
