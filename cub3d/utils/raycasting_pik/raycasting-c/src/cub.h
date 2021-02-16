#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>

# define KEY_EXIT   17
# define KEY_ESC    53
# define KEY_W      13
# define KEY_A      0
# define KEY_S      1
# define KEY_D      2
# define KEY_IZQ    123
# define KEY_DCH    124

# define FALSE 0
# define TRUE 1

# define PI 3.14159265
# define TWO_PI 6.28318530

# define TILE_SIZE 64
# define MAP_NUM_ROWS 13
# define MAP_NUM_COLS 20

# define MINIMAP_SCALE_FACTOR 1.0 

# define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
# define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

# define FOV_ANGLE (60 * (PI / 180))

# define NUM_RAYS WINDOW_WIDTH

# define FPS 30
# define FRAME_TIME_LENGTH (1000 / FPS)

typedef struct  s_img
{
    void            *img_ptr;
    unsigned int    *data;
    int             size_l;
    int             bpp;
    int             endian;
}               t_img;

typedef struct  s_main_loop
{
    void        *mlx;
    void        *mlx_win;
    int         x;
    int         w;
    int         h;
    double      pos_x;
    double      pos_y;
    double      dir_x;
    double      dir_y;
}               t_main_loop;

typedef struct  s_player
{
    float x;
    float y;
    float width;
    float height;
    int turnDirection; // -1 for left, +1 for right
    int walkDirection; // -1 for back, +1 for front
    float rotationAngle;
    float walkSpeed;
    float turnSpeed;
}               t_player;

typedef struct  s_ray
{
    float rayAngle;
    float wallHitX;
    float wallHitY;
    float distance;
    int wasHitVertical;
    int isRayFacingUp;
    int isRayFacingDown;
    int isRayFacingLeft;
    int isRayFacingRight;
    int wallHitContent;
}               t_ray[NUM_RAYS];

typedef struct  s_game
{
    void        *mlx;
    void        *win_ptr;
    t_img       img;
    t_main_loop loop;
    t_player    player;
    t_ray       ray;
    float       deltaTime;
    const int   map[MAP_NUM_ROWS][MAP_NUM_COLS];
}               t_game;

#endif
