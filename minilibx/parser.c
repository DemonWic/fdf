#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUF_SIZE 1

typedef struct t_coor 
{
    char x;
    char y;
    char z;

} s_coor;

int main(int argc, char **argv)
{
    int fd;
    int count_X;
    int count_Y;
    char buf[BUF_SIZE + 1];
    int k;
    s_coor *map;

    count_X = 0;
    count_Y = 0;
    k = 0;
    if (argc != 2)
    return (1);
    fd = open(argv[1], O_RDONLY, 0);
    while((read(fd, buf, BUF_SIZE)))
    {
        if(buf[0] == ' ' && k == 0)
            count_X++;
        else if(buf[0] == '\n')
        {
            count_Y++;
            if (k == 0)
                count_X++;
            k = 1;
        }
    }
    count_X = (count_X + 1) / 2;
    close(fd);
    printf("X =%i, Y=%i\n", count_X, count_Y);
    char s[3];
    int i = 0;
    int j = 0;
    k = 0;
    int p = 0;
    map = (s_coor *)malloc(sizeof(s_coor) * (count_X * count_Y));
    printf("SIZE S_COOR = %li\n", sizeof(s_coor));
    printf("SIZE MAP = %li\n", sizeof(map));
    fd = open(argv[1], O_RDONLY, 0);
    while((read(fd, buf, BUF_SIZE)))
    {
        if (buf[0] != ' ' && buf[0] != '\n')
            s[i++] = buf[0];
        if ((buf[0] == ' ' || buf[0] == '\n') && i != 0)
        {
            s[i] = '\0';
            i = 0;
            map[j].z = (char)atoi(s);
            map[j].x = (char)p;
            map[j].y = (char)k;
            p++;
            j++;
            printf("%i ", j);
            if (p == count_X)
                p = 0;
        }
        if (buf[0] == '\n')
            k++;

    }
    printf("Size map = %i\n Size all = %i\n", j, (count_X * count_Y));
    j = 0;
    while(j < (23200))
    {
        // printf("x = %i y = %i z = %i\n", (int)map[j].x, (int)map[j].y, (int)map[j].z);
        // printf("y = %i\n",(int)map[j].y);
        j++;
    }
    return (0);
}