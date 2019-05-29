/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahintz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:29:13 by ahintz            #+#    #+#             */
/*   Updated: 2019/05/24 16:37:10 by ahintz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ABS(x) (x < 0) ? -x : x
/*
int deal_key(int key, void *param)
{
	printf("%i\n", key);
	return (0);
}
*/

int mouse_key(int button, int x, int y, void *param)
{
	printf("button %i\n", button);
	printf("x= %i y = %i\n", x, y);
	return (0);
}

void plot_circle(int x, int y, int x_center, int  y_center, void *mlx_ptr, void *win_ptr)
{
	mlx_pixel_put(mlx_ptr, win_ptr, x_center+x, y_center+y, 0xFFFFFF);
	mlx_pixel_put(mlx_ptr, win_ptr, x_center+x, y_center-y, 0xFFFFFF);
	mlx_pixel_put(mlx_ptr, win_ptr, x_center-x, y_center+y, 0xFFFFFF);
	mlx_pixel_put(mlx_ptr, win_ptr, x_center-x, y_center-y, 0xFFFFFF);

}

/* Вычерчивание окружности с использованием алгоритма Мичнера */
void circle(int x_center, int y_center, int radius, void *mlx_ptr, void *win_ptr)
{
    int x,y,delta;
    x = 0;
    y = radius;
    delta=3-2*radius;
    while(x<y) {
        plot_circle(x,y,x_center,y_center, mlx_ptr, win_ptr);
        plot_circle(y,x,x_center,y_center, mlx_ptr, win_ptr);
        if (delta<0)
            delta+=4*x+6;
        else 
		{
            delta+=4*(x-y)+10;
            y--;
        }
        x++;
    }

    if(x==y) plot_circle(x,y,x_center,y_center, mlx_ptr, win_ptr);
}

void	ft_draw(int x1, int y1, int x2, int y2, void *mlx_ptr, void *win_ptr, int color)
{
	const int dX = ABS((x2 - x1));
	const int dY = ABS((y2 - y1));
	const int sX = x1 < x2 ? 1 : -1;
	const int sY = y1 < y2 ? 1 : -1;

	int error = dX - dY;
	mlx_pixel_put(mlx_ptr, win_ptr, x2, y2, color);
	while (x1 != x2 || y1 != y2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, color);
		const int error2 = error * 2;

		if (error2 > -dY)
		{
			error -= dY;
			x1 += sX;
		}
		if (error2 < dX)
		{
			error += dX;
			y1 += sY;
		}
	}
}	
int		*ft_isometric(int x, int y, int z)
{
	int *r;

	r = (int *)malloc(sizeof(int) * 2);

	r[0] = (int)((1 / sqrt(6)) * (sqrt(3) * x + 0 * y + (-sqrt(3)) * z));
	r[1] = (int)((1 / sqrt(6)) * (1 * x + 2 * y + 1 * z));
	return (r);
}

int		*ft_isometric2(int x, int y, int z)
{
	int *r;

	r = (int *)malloc(sizeof(int) * 2);

	r[0] = (int)((1 / sqrt(6)) * (sqrt(2) * x + 1 * y + (sqrt(3)) * z));
	r[1] = (int)((1 / sqrt(6)) * ((-sqrt(2)) * x + 2 * y + 0 * z));
	return (r);
}

int		*ft_isometric3(int x, int y, int z)
{
	int *r;

	r = (int *)malloc(sizeof(int) * 2);
	r[0] = (int)(x * cos((30 * M_PI) / 180) - y * cos((30 * M_PI) / 180));
	r[1] = (int)(x * sin((30 * M_PI) / 180) + y * sin((30 * M_PI) / 180)) - z;

	return (r);
}




int		main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	int *p0;
	int *p1;
	int *p2;
	int *p3;
	int *p4;
	int *p5;
	int *p6;
	int *p7;


	p0 = ft_isometric3(900, 400, 0);
	p1 = ft_isometric3(1200, 400, 0);
	p2 = ft_isometric3(900, 700, 0);
	p3 = ft_isometric3(1200, 700, 0);
	p4 = ft_isometric3(900, 400, 200);
	p5 = ft_isometric3(1200, 400, 200);
	p6 = ft_isometric3(900, 700, 200);
	p7 = ft_isometric3(1200, 700, 200);

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2400, 2400, "mlx 42");

	ft_draw(p0[0], p0[1], p1[0], p1[1], mlx_ptr, win_ptr, 0xFFFFFF);
	ft_draw(p0[0], p0[1], p2[0], p2[1], mlx_ptr, win_ptr, 0xFFFFFF);
	ft_draw(p2[0], p2[1], p3[0], p3[1], mlx_ptr, win_ptr, 0xFFFFFF);
	ft_draw(p1[0], p1[1], p3[0], p3[1], mlx_ptr, win_ptr, 0xFFFFFF);

	ft_draw(p4[0], p4[1], p5[0], p5[1], mlx_ptr, win_ptr, 0xFF0000);
	ft_draw(p4[0], p4[1], p6[0], p6[1], mlx_ptr, win_ptr, 0xFF0000);
	ft_draw(p6[0], p6[1], p7[0], p7[1], mlx_ptr, win_ptr, 0xFF0000);
	ft_draw(p5[0], p5[1], p7[0], p7[1], mlx_ptr, win_ptr, 0xFF0000);


	ft_draw(p0[0], p0[1], p4[0], p4[1], mlx_ptr, win_ptr, 0xFFF000);
	ft_draw(p1[0], p1[1], p5[0], p5[1], mlx_ptr, win_ptr, 0xFFF000);
	ft_draw(p2[0], p2[1], p6[0], p6[1], mlx_ptr, win_ptr, 0xFFF000);
	ft_draw(p3[0], p3[1], p7[0], p7[1], mlx_ptr, win_ptr, 0xFFF000);


/*	circle(500, 500, 400, mlx_ptr, win_ptr);

	int x =(int)(500 + (400 * cos((45 * M_PI) / 180))); 
	int y =(int)(500 + (400 * sin((45 * M_PI) / 180)));
	ft_draw(500, 500, x, y, mlx_ptr, win_ptr);
	x =(int)(500 + (400 * cos((135 * M_PI) / 180))); 
	y =(int)(500 + (400 * sin((135 * M_PI) / 180)));
	ft_draw(500, 500, x, y, mlx_ptr, win_ptr);
	x =(int)(500 + (400 * cos((225 * M_PI) / 180))); 
	y =(int)(500 + (400 * sin((225 * M_PI) / 180)));
	ft_draw(500, 500, x, y, mlx_ptr, win_ptr);
	x =(int)(500 + (400 * cos((-45 * M_PI) / 180))); 
	y =(int)(500 + (400 * sin((-45 * M_PI) / 180)));
	ft_draw(500, 500, x, y, mlx_ptr, win_ptr);*/
//	mlx_string_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF, "Hello, world!");
//	ft_draw(200, 200, 200, 800, mlx_ptr, win_ptr);
//	ft_draw(200, 200, 800, 200, mlx_ptr, win_ptr);
//	ft_draw(200, 800, 800, 800, mlx_ptr, win_ptr);
//	ft_draw(800, 200, 800, 800, mlx_ptr, win_ptr);
//	mlx_key_hook(win_ptr, deal_key, (void *)0);	
	mlx_mouse_hook(win_ptr, mouse_key, (void *)0);	
	mlx_loop(mlx_ptr);
	return (0);
}
