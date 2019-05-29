#include <stdio.h>
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ABS(x) (x < 0) ? -x : x


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
} s_all;