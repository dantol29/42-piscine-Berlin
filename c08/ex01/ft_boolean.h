/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:43:27 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/10 12:00:29 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define TRUE	1
# define FALSE	0
# define SUCCESS	0
# define EVEN(nbr)	((nbr % 2) == 0)
# define EVEN_MSG	"I have an even number of arguments.\n"
# define ODD_MSG	"I have an odd number of arguments.\n"

typedef int	t_bool;
void	ft_putstr(char *str);
t_bool	ft_is_even(int nbr);

#endif
