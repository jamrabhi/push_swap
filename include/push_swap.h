/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:41:49 by jamrabhi          #+#    #+#             */
/*   Updated: 2022/03/30 17:41:53 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <unistd.h>

typedef struct s_stack
{
	int	nb;
	struct s_stack	*element;
}				t_stack;


void	parse_args(char *argv[]);
void	exit_error(void);
void	free_array(char **str);
char	**ft_split_whitespaces(char *s);
#endif
