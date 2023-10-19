/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmejbar <mmejbar@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:41:25 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/15 23:33:37 by mmejbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ft.h"

int	main(int argc, char **argv)
{
	char	*dict_path;
	char	*nb;

	dict_path = "numbers.dict";
	if (check_arguments(argc, argv, &dict_path, &nb) == 0)
		write(1, "Error", 5);
	else
	{
		if (nb[0] == '+')
			nb += 1;
		get_dict(nb, dict_path);
	}
	write(1, "\n", 1);
}
