#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct t3_coor
{
    int x;
    int y;
    int z;
} s3_coor;

typedef struct t2_coor
{
    int x;
    int y;
} s2_coor;

//struct for all shit, maybe color

typedef struct t_all
{
    s3_coor *map;
    int coor_X;       
    int coor_Y;
    void *winptr;
    void *mlxptr;
    int color;
} s_all;

s2_coor *ft_isometric(s3_coor * map, long int size)
{
    int i;
    s2_coor *put_map;

    i = 0;
    put_map = (s2_coor *)malloc(sizeof(s2_coor) * size);
    while (i < size)
    {
        put_map[i].x = (int)(map[i].x * cos(30 * M_PI / 180) - map[i].y * cos(30 * M_PI / 180));
        put_map[i].y = (int)(map[i].x * sin(30 * M_PI / 180) + map[i].y * sin(30 * M_PI / 180) - map[i].z);
        i++;
    }
    return (put_map);
}

s3_coor *ft_rotate_z(s3_coor *map, long int size, int angle)
{
    int i;
    s3_coor *rot_map;
    
    i = 0;
    rot_map = (s3_coor *)malloc(sizeof(s3_coor) * size);
    while(i < size)
    {
       rot_map[i].x = map[i].x * cos(angle * M_PI / 180) + (map[i].y * (-sin(angle * M_PI / 180)));
       rot_map[i].y = map[i].x * sin(angle * M_PI / 180) + (map[i].y * cos(angle * M_PI / 180));
       rot_map[i].z = map[i].z * 1;
       i++;
    }
    return (rot_map);
}

s3_coor *ft_rotate_y(s3_coor *map, long int size, int angle)
{
    int i;
    s3_coor *rot_map;
    
    i = 0;
    rot_map = (s3_coor *)malloc(sizeof(s3_coor) * size);
    while(i < size)
    {
       rot_map[i].x = map[i].x * cos(angle * M_PI / 180) + (map[i].z * sin(angle * M_PI / 180));
       rot_map[i].y = map[i].y * 1;
       rot_map[i].z = map[i].x * (-sin(angle * M_PI / 180)) + (map[i].z * cos(angle * M_PI / 180));
       i++;
    }
    return (rot_map);
}

s3_coor *ft_rotate_x(s3_coor *map, long int size, int angle)
{
    int i;
    s3_coor *rot_map;
    
    i = 0;
    rot_map = (s3_coor *)malloc(sizeof(s3_coor) * size);
    while(i < size)
    {
       rot_map[i].x = map[i].x * 1;
       rot_map[i].y = map[i].y * cos(angle * M_PI / 180) + (map[i].z * (-sin(angle * M_PI / 180)));
       rot_map[i].z = map[i].y * sin(angle * M_PI / 180) + (map[i].z * cos(angle * M_PI / 180));
       i++;
    }
    return (rot_map);
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

void    ft_draw_to_map(s2_coor *map, int coor_X, int coor_Y, void *mlx_ptr, void *win_ptr, int color)
{
    int i;
    int size;

    i = 0;
    size = coor_X * coor_Y;
    while(i < size - 1)
    {
        if((i + 1) / coor_X != 0)
            ft_draw(map[i].x, map[i].y, map[i + 1].x, map[i + 1].y, mlx_ptr, win_ptr, color);
        if ((i + coor_X) < size)
            ft_draw(map[i].x, map[i].y, map[i + coor_X].x, map[i + coor_X].y, mlx_ptr, win_ptr, color);
        i++;
    }
}


// add point to function rotate

void    ft_paint_rot(s3_coor *map, long int size, int sign, int coor_X, int coor_Y, void *mlx_ptr, void *win_ptr, int color) //s_all *cur_state
{
    s2_coor *cur;
    s3_coor *buf;
    int angle;
    int max_angle;

    angle = 1;
    max_angle = 360;
    while (angle < max_angle)
    {
        buf = ft_rotate_z(map, size, (angle * sign)); // change function for other behaviors
        cur = ft_isometric(buf, size);
        free(buf);
        mlx_clear_window(mlx_ptr, win_ptr);
        ft_draw_to_map(cur, coor_X, coor_Y, mlx_ptr, win_ptr, color);
        free(cur);
        angle++;
        if (angle == (max_angle - 1))
            angle = 0;
    }
}

int main()
{
    printf("Hello");
    return (0);
}