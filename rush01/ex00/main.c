/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnickl <pnickl@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:36:21 by pnickl            #+#    #+#             */
/*   Updated: 2023/10/07 13:16:56 by pnickl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rush01(char *argv);

int	ft_check_arg(char *argv)
{
	int	count;

	count = 0;
	while (argv[count])
		count++;

	if (count != 31)
		return (0);
	
	count = 0;
	while (argv[count])
	{
		if (count % 2 == 0)
		{
			if (!(argv[count] >= '1' && argv[count] <= '4'))
				return (0);
		}
		else if (argv[count] != ' ')
			return (0);
		count++;
	}
	return (1);

}
#include <unistd.h>
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_check_arg(argv[1]) == 0)
			write(1, "Error\n", 6);
		else
			rush01(argv[1]);
	}
	else
		write(1, "Error\n", 6);
}	

