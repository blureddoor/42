#include "cub.h"

void    game_init(t_game *game)
{
    const int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    memcpy(game->map, map, sizeof(const int) * MAP_NUM_ROWS * MAP_NUM_COLS);
}
/*
 typedef struct s_player {
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

typedef struct  s_ray {
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

*/
int close(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win_ptr);
    exit(0);
}

int init(t_game *game)
{
    game->mlx = mlx_init();
    game->win_ptr = mlx_new_window(game->mlx, game->loop.w, game->loop.h, "===pikuma===");
    game->img.img_ptr = mlx_new_image(game->mlx, game->loop.w, game->loop.h);
    game->img.data = (unsigned int *)mlx_get_data_addr(game->img.img_ptr, &game->img.bpp,
    &game->img.size_l, &game->img.endian);
    return (0);
}
/*
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
int isGameRunning = FALSE;
int ticksLastFrame;

int initializeWindow() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error initializing SDL.\n");
        return FALSE;
    }
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_BORDERLESS
    );
    if (!window) {
        fprintf(stderr, "Error creating SDL window.\n");
        return FALSE;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        fprintf(stderr, "Error creating SDL renderer.\n");
        return FALSE;
    }
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    return TRUE;
}

void destroyWindow() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
*/


void setup(t_game *game) {
    game->player.x = WINDOW_WIDTH / 2;
    game->player.y = WINDOW_HEIGHT / 2;
    game->player.width = 1;
    game->player.height = 1;
    game->player.turnDirection = 0;
    game->player.walkDirection = 0;
    game->player.rotationAngle = PI / 2;
    game->player.walkSpeed = 100;
    game->player.turnSpeed = 45 * (PI / 180);
}

int mapHasWallAt(float x, float y) {
    if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
        return TRUE;
    int mapGridIndexX = floor(x / TILE_SIZE);
    int mapGridIndexY = floor(y / TILE_SIZE);
    return (game->map[mapGridIndexY][mapGridIndexX] != 0);
}

void movePlayer(t_game *game) 
{
    game->player.rotationAngle += game->player.turnDirection *
    game->player.turnSpeed * deltaTime;
    float moveStep = game->player.walkDirection *
    game->player.walkSpeed * deltaTime;

    float newPlayerX = game->player.x + cos(game->player.rotationAngle) * 
    moveStep;
    float newPlayerY = game->player.y + sin(game->player.rotationAngle) * 
    moveStep;

    if (!mapHasWallAt(newPlayerX, newPlayerY)) 
    {
        game->player.x = newPlayerX;
        game->player.y = newPlayerY;
    }
}

void    draw_player(t_game *game, int x, int y)
{
    int i;
    int j;

    game->player.x *= 10;
    game->player.y *= 10;
    i = 0;
    while (i < TILE_SIZE / 8)   // cambia size player
    {
        j = 0;
        while (j < TILE_SIZE / 8) // cambia size player
        {
            game->img.data[(game->player.y + i) * WINDOW_WIDTH + game->player.x + j] = 0xFF0000;
            j++;
        }
        i++;
    }
}

void    draw_players(t_game *game)
{
    int i;
    int j;
    
    i = 0;
    while (i < MAP_NUM_ROWS)
    {
        j = 0;
        while (j < MAP_NUM_COLS)
        {
            if (game->map[i][j] == 2) // posicion inicial player //guard
                draw_player(game, j + game->player.y, i + game->player.x); //posicion dibujo pla
                j++;
        }
        i++;
    }
    //  printf("break point\n");
}

/*

void renderPlayer() 
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect playerRect = 
    {
        game->player.x * MINIMAP_SCALE_FACTOR,
        game->player.y * MINIMAP_SCALE_FACTOR,
        game->player.width * MINIMAP_SCALE_FACTOR,
        game->player.height * MINIMAP_SCALE_FACTOR
    };
    SDL_RenderFillRect(renderer, &playerRect);

    SDL_RenderDrawLine(
        renderer,
        MINIMAP_SCALE_FACTOR * game->player.x,
        MINIMAP_SCALE_FACTOR * game->player.y,
        MINIMAP_SCALE_FACTOR * (game->player.x + cos(game->player.rotationAngle) * 40),
        MINIMAP_SCALE_FACTOR * (game->player.y + sin(game->player.rotationAngle) * 40)
    );
}

*/

void castRay(float rayAngle, int stripId) 
{
    // TODO: All that crazy logic for horz, vert, ...
    // ...
}

void castAllRays() 
{
    float rayAngle = game->player.rotationAngle - (FOV_ANGLE / 2);

    for (int stripId = 0; stripId < NUM_RAYS; stripId++) 
    {
        castRay(rayAngle, stripId);
        rayAngle += FOV_ANGLE / NUM_RAYS;
    }
}
/*
void renderMap() 
{
    for (int i = 0; i < MAP_NUM_ROWS; i++) 
    {
        for (int j = 0; j < MAP_NUM_COLS; j++) 
        {
            int tileX = j * TILE_SIZE;
            int tileY = i * TILE_SIZE;
            int tileColor = map[i][j] != 0 ? 255 : 0;

            SDL_SetRenderDrawColor(renderer, tileColor, tileColor, tileColor, 255);
            SDL_Rect mapTileRect = 
            {
                tileX * MINIMAP_SCALE_FACTOR,
                tileY * MINIMAP_SCALE_FACTOR,
                TILE_SIZE * MINIMAP_SCALE_FACTOR,
                TILE_SIZE * MINIMAP_SCALE_FACTOR
            };
            SDL_RenderFillRect(renderer, &mapTileRect);
        }
    }
}
*/

int     imput_key(int key, t_game *game)
{
    if (key == KEY_ESC)
    {
        system ("leak a.out");
        exit(0);
    }
    //move forward if no wall in front of you
    else if (key == (KEY_W))
    {
        if (game->map[(int)(game->loop.pos_x + game->loop.dir_x * 
            MOVE_SPEED)][(int)(game->loop.pos_y)] == FALSE)
            game->loop.pos_x += game->loop.dor_x * MOVE_SPEED;
        if (game->map[(int)(game->loop.pos_x)][(int)(game->loop.pos_y + 
            game->loop.dir_y * MOVE_SPEED)] == FALSE)
            game->loop.pos_y += game->loop.dir_y * MOVE_SPEED;
    }
    // move bacwards if no wall in front of you
    else if (key == (KEY_S))
    {
        if (game->map[(int)(game->loop.pos_x - game->loop.dir_x *
            MOVE_SPEED)][(int)(game->loop.pos_y)] == FALSE)
            game->loop.pos_x -= game->loop.dir_x * MOVE_SPEED;
        if (game->map[(int)(game->loop.pos_x)][(int)(game->loop.pos_y - 
            game->loop.dir_y * MOVE_SPEED)] == FALSE)
            game->loop.pos_y -= game->loop.dir_y * MOVE_SPEED;
    }
    // rotate to the right
    else if (key == (KEY_D))
    {
        //both camera direction and camera plane must be rotated
        game->loop.old_dir_x1 = game->loop.dir_x;
        game->loop.dir_x = game->loop.dir_x * cos(-ROT_SPEED) - game->loop.dir_y *
        sin(-ROT_SPEED);
        game->loop.dir_y = game->loop.old_dir_x1 * sin(-ROT_SPEED) + game->loop.dir_y *
        cos(-ROT_SPEED);
        game->loop.old_plane_x1 = game->loop.plane_x;
        game->loop.plane_x = game->loop.plane_x * cos(-ROT_SPEED) - game->loop.plane_y
        sin(-ROT_SPEED);
        game->loop.plane_y = game->loop.old_plane_x1 * sin(-ROT_SPEED) + game->loop.plane_y
        * cos(-ROT_SPEED);
    }
    else if (key == (KEY_A))
    {
        //both camera direction and camera plane must be rotated
        game->loop.old_dir_x2 = game->loop.dir_x;
        game->loop.dir_x = game->loop.dir_x * cos(ROT_SPEED) - game->loop.dir_y *
        sin(ROT_SPEED);
        game->loop.dir_y = game->loop.old_dir_x2 * sin(ROT_SPEED) + game->loop.dir_y *
        cos(ROT_SPEED);
        game->loop.old_plane_x2 = game->loop.plane_x;
        game->loop.plane_x = game->loop.plane_x * cos(ROT_SPEED) - game->loop.plane_y *
        sin(ROT_SPEED);
        game->loop.plane_y = game->loop.old_plane_x2 * sin(ROT_SPEED) + game->loop.plane_y *
        cos(ROT_SPEED);
    }
    return (0);
}
/*
void processInput() //int imput_key();
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) 
    {
        case SDL_QUIT: 
        {
            isGameRunning = FALSE;
            break;
        }
        case SDL_KEYDOWN: 
        {
            if (event.key.keysym.sym == SDLK_ESCAPE)
                isGameRunning = FALSE;
            if (event.key.keysym.sym == SDLK_UP)
                player.walkDirection = +1;
            if (event.key.keysym.sym == SDLK_DOWN)
                player.walkDirection = -1;
            if (event.key.keysym.sym == SDLK_RIGHT)
                player.turnDirection = +1;
            if (event.key.keysym.sym == SDLK_LEFT)
                player.turnDirection = -1;
            break;
        }
        case SDL_KEYUP: 
        {
            if (event.key.keysym.sym == SDLK_UP)
                player.walkDirection = 0;
            if (event.key.keysym.sym == SDLK_DOWN)
                player.walkDirection = 0;
            if (event.key.keysym.sym == SDLK_RIGHT)
                player.turnDirection = 0;
            if (event.key.keysym.sym == SDLK_LEFT)
                player.turnDirection = 0;
            break;
        }
    }
}
*/

int raycast(t_game *game)
{
    int x;

    x = 0;
    while (x < game->loop.w)
    {
        //camera_calc(game, x); //o camera_calc
        //steps_initial_dist(game);
        //perform_dda(game);
        //calc_pixel(game, x);
        //color_rgb(game);
        //draw2(game, x);
        x++;
    }
    return (0);
}


void update(t_game *game) 
{
/*    // waste some time until we reach the target frame time length
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame + FRAME_TIME_LENGTH));

    float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

    ticksLastFrame = SDL_GetTicks();

    movePlayer(deltaTime);
    castAllRays();*/
    // Leo->refresh();
    mlx_destroy_image(game->mlx, game->img.img_ptr);
    game->img.img_ptr = mlx_new_image(game->mlx, game->loop.w, game->loop-h);
    game->img.data = (unsigned int*)mlx_get_data_addr(game->img.img_ptr,
    &game->img.endian, &game->img.size_l);
}
/*
void render() // int raycast();
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    renderMap();
    //renderRays();
    renderPlayer();

    SDL_RenderPresent(renderer);
}
*/
int loop(t_game *game)
{
    raycast(game);
    mlx_put_image_to_window(game->mlx, game->win_ptr, game->img.img_ptr, 0, 0);
    update(game);
    return (0);
}

int main() 
{
    t_game *game;
//  isGameRunning = initializeWindow();
    setup();// init_vars
    game_init(&game);
    init(&game);
    mlx_hook(game.win_ptr, KEY_PRESS, 0, imput_key, &game);
    mlx_hook(game.win_ptr, KEY_EXIT, 0, close, &game);
    mlx_loop_hook(game.mlx, loop, &game);
    mlx_loop(game.mlx);
/*
    while (isGameRunning) { //int loop(t_game *game);
        processInput();
        update();
        render();
    }

    destroyWindow();
*/
    return 0;
}
