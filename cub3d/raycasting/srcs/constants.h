#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


/* #define mapX 8 */
/* #define mapY 8 */
/* #define mapS 64 */

#define FALSE	0
#define TRUE	1

#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)

#define KEY_PRESS   2
#define KEY_RELEASE 3

#define KEY_EXIT    17

#define KEY_ESC     53
#define KEY_W       13
#define KEY_A       0
#define KEY_S       1
#define KEY_D       2
#define KEY_IZQ     123
#define KEY_DCH     124

#define TILE_SIZE   64
#define ROWS        12
#define COLS        16
#define WIDTHS      COLS * TILE_SIZE
#define HEIGHTS     ROWS * TILE_SIZE

#define TO_COORD(X, Y)  ((int)floor(Y) * WIDTHS + (int)floor(X))

#define PI          3.141592653589793238
#define P2          PI / 2
#define P3          3 * PI / 2
#define DR          0.0174533 // un grado en radians
