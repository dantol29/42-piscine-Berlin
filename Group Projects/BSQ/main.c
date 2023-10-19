/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:57:07 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/18 13:51:34 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	int		i;
	char	*str;
	char	**map;
	int	lcount;
	int	k;

	if (argc > 1)
	{
		k = 1;
		while (k < argc)
		{
			str = ft_read_map(argv[k]);
			//printf("%s\n", str);
			map = map_memory(str);
			fill_map(str, map);
			i = 0;
			while (map[0][i])
				i++;
			lcount = ft_linecount(str) - 1;
			solve(map, i, lcount);
			free(str);
			i = 0;
			while (i < lcount + 1)
			{
				free(map[i]);
				i++;
			}
			free(map);
			write(1, "\n", 1);
			k++;
		}
	}
}
