/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:42:40 by dmangola          #+#    #+#             */
/*   Updated: 2021/04/13 18:42:51 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_check_flags(t_all *all)
{
	if (I_FINISH_FLAG == 1)
	{
		I_ENDIAN = mlx_png_file_to_image(VP_MLX, "textures/THE_END.png",
					&I_RES_WIDTH, &I_RES_HEIGHT);
		mlx_put_image_to_window(VP_MLX, VP_WIN, I_ENDIAN, 0, 0);
		return 0;
	}
	if (I_SAVE_FLAG == 1)
	{
		UCP_SCREEN = malloc(sizeof(unsigned char) * I_RES_HEIGHT * I_RES_WIDTH
						* 4);
		if (!UCP_SCREEN)
			ft_print_error(all, 0);
	}
}