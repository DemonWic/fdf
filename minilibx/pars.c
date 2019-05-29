#include <stdio.h>
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>


typedef struct t3_coor 
{
    int x;
    int y;
    int z;

} s3_coor;

void    ft_free_str(char **s)
{
    int i;

    i = 0;
    while (s[i] != 0)
        ft_memdel((void **)(s + i++));
    ft_memdel((void **)(s + i));
    ft_memdel((void **)&s);   
}

int main(int argc, char **argv)
{
    int fd;
    int ret;
    int count_X;
    int count_Y;
    char *line;
    char **str;
    s3_coor *map;

    count_X = -1;
    count_Y = 0;
    if (argc != 2)
     return (1);
    fd = open(argv[1], O_RDONLY, 0);
    while((ret = get_next_line(fd, &line) > 0))
    {
        if (count_Y == 0)
        {
            str = ft_strsplit(line, ' ');
            while (str[++count_X] != 0)
                ;
            ft_free_str(str);
        }
        if (line != NULL)
            free(line);
        count_Y++;
    }
    close(fd);
    printf("X =%i, Y=%i\n", count_X, count_Y);

    int i = -1;
    int j = 0;
    int p = 0;
    map = (s3_coor *)malloc(sizeof(s3_coor) * (count_X * count_Y));
    fd = open(argv[1], O_RDONLY, 0);
   while((ret = get_next_line(fd, &line) > 0))
    {
        str = ft_strsplit(line, ' ');
        while (str[++i] != 0)
        {
            map[j].z = ft_atoi(str[i]);
            map[j].x = i;
            map[j].y = p;
            j++;
        }
        i = -1;
        ft_free_str(str);
        free(line);
        p++;
    }
    printf("Size map = %i\n Size all = %i\n", j, (count_X * count_Y));
    j = 0;
    while(j < (count_X * count_Y))
    {
        printf("x = %i y = %i z = %i\n", map[j].x, map[j].y, map[j].z);
        j++;
    }
    free(map);
    return (0);
}


