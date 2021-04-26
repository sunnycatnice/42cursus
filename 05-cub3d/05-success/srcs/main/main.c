/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:31:49 by dmangola          #+#    #+#             */
/*   Updated: 2021/04/26 17:31:51 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_parse	config;

	config.save = 0;
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save"))
			config.save = 1;
		else
			ft_perror("Error\n*1* Unknown Command");
	}
	if (argc < 2)
		ft_perror("Error\n*2* No Config File Specified");
	if (argc > 3)
		ft_perror("Error\n*3* Too Many Arguments");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_perror("Error\n*4* Invalid Config File");
	ft_print_start();
	parse_main(fd, &config);
	window_main(&config);
	close(fd);
	return (0);
}
