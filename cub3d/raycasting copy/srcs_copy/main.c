
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>


#include "constants.h"

int player_x, player_y;


float px = 0;
float py = 0;
float pviewx = 0;
float pviewy = 0;
float pa;
float camarax = 1;
float camaray = 0;

typedef struct s_img
{
    void    *img_ptr;
    int     *data;
    int     size_l;
    int     bpp;
    int     endian;
}               t_img;
typedef struct s_game
{
    void *mlx;
    void *win_ptr;
    t_img img;

    int map[ROWS][COLS];
}           t_game;

typedef struct s_player
{
	float x;
	float y;
	float width;
	float height;
	int turn_dir; // -1 for left, +1 or right
	int walk_dir; // -1 for back, +1 for front
	float rotation_angle;
	float walk_speed;
	float turn_speed;
}				t_player;

void    draw_back(t_game *game, int x, int y)
{
    int     i;
    int     j;

    x *= TILE_SIZE;
    y *= TILE_SIZE;
    i = 0;
    while (i < TILE_SIZE - 1)
    {
        j = 0;
        while (j < TILE_SIZE - 1)
        {
            game->img.data[(y + i) * WIDTHS + x + j] = 0xC0C0C0;
            j++;
        }
        i++;
    }
}

void    draw_backgrounds(t_game *game)
{
    int         i;
    int         j;

    i = 0;
    while (i < ROWS)
    {
        j = 0;
        while (j < COLS)
        {
            if (game->map[i][j] == 0 || game->map[i][j] == 2)
                draw_back(game, j , i);
            j++;
        }
        i++;
    }
}

/****************************************
 * 										*
 * 										*
 *  parte comun - map - minilibx - loop	*
 * 										*
 * 										*
 * 										*
 ***************************************/



void     game_init(t_game *game)
{
    int map[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };
    memcpy(game->map, map, sizeof(int) * ROWS * COLS);
}


// ventana

void window_init(t_game *game)
{
    if (mlx_init() == 0)
		fprintf(stderr, "Error initializing mlx.\n");
	game->mlx = mlx_init();
    game->win_ptr = mlx_new_window(game->mlx, WIDTHS, HEIGHTS, "=== // -game CUB3D- \\\\ ===");
	if (!game->win_ptr)
		fprintf(stderr, "Error creating mlx_new_window..\n");
}


// inicia dibujo

void img_init(t_game *game)
{
    game->img.img_ptr = mlx_new_image(game->mlx, WIDTHS, HEIGHTS);
    game->img.data = (int*)mlx_get_data_addr(game->img.img_ptr, &game->img.bpp, &game->img.size_l, &game->img.endian);
};

//cierra ventana con boton rojo

int close(t_game *game)
{
    exit(0);
}


void setup_player(t_player *player)
{
	player->x = WIDTHS / 2;
	player->y = HEIGHTS / 2;
	player->width = 5;
	player->height = 5;
	player->turn_dir = 0;
	player->walk_dir = 0;
	player->rotation_angle = P2;
	player->walk_speed = 100;
	player->turn_speed = 45 * DR;
}

void    draw_rectangle(t_game *game, int x, int y)
{
    int     i;
    int     j;

    x *= TILE_SIZE;
    y *= TILE_SIZE;
    i = 0;
    while (i < TILE_SIZE - 1)
    {
        j = 0;
        while (j < TILE_SIZE - 1)
        {
            game->img.data[(y + i) * (WIDTHS) + x + j] = 0x00FF00;
            j++;
        }
        i++;
    }
}

void    draw_rectangles(t_game *game)
{
    int     i;
    int     j;

    i = 0;
    while (i < ROWS)
    {
        j = 0;
        while (j < COLS)
        {
            if (game->map[i][j] == 1)
                draw_rectangle(game, j, i);
            j++;
        }
        i++;
    }
}


void update()
{
	// waste some time
	while (!difftime(getTicks(), (time + FRAME_TIME_LENGTH)));
	
	delta_time = (time - old_time) / 1000.0f;
/*	old_time = time;*/
	time = getTicks();
	player_x += 1;
	player_y += 1;
}
int main_loop(t_game *game)
{
	draw_backgrounds(game);
	draw_rectangles(game);
	update();
/*	draw_players(game);
    draw_pviews(game);
    draw_lines(game);*/
    mlx_put_image_to_window(game->mlx, game->win_ptr, game->img.img_ptr, 0, 0);
    return (0);
}

int main(void)
{
    t_game game;
	t_player player;
	setup_player(&player);
    game_init(&game);
    window_init(&game);
    img_init(&game);
    mlx_hook(game.win_ptr, KEY_PRESS, 0, /*&imputkey*/0, &game);
    mlx_hook(game.win_ptr, KEY_EXIT, 0, &close, &game);

    mlx_loop_hook(game.mlx, &main_loop, &game);
    mlx_loop(game.mlx);
}
