#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <allegro5/allegro.h>


#define WIDTH 800
#define HEIGHT 600

#define TPS 60

#define HOVER_DURATION 0.2

#define MENU_FONT_SIZE 28
#define PLAY_FONT_SIZE 22

#define BUTTON_WIDTH 250
#define BUTTON_HEIGHT 60
#define BUTTON_OFFSET 4
#define BUTTON_AMOUNT 3

#define INITIAL_WIDTH 3
#define INITIAL_HEIGHT 3

#define INITIAL_BOARD_OFFSET_X 10
#define INITIAL_BOARD_OFFSET_Y 10

#define MINIMUM_BOARD_OFFSET_X 4
#define MINIMUM_BOARD_OFFSET_Y 4

#define BOARD_WIDTH 600
#define BOARD_HEIGHT 600

#define BLINKING_DELAY 0.5
#define LEVEL_DELAY 2.0

#define TIME_PER_TILE 0.3
#define SCORE_PER_TILE 10
#define MAX_SCORE_DECREMENT 6
#define SCORE_DECREMENT_TIME 0.05

#define DIFFICULTY_INCREMENT_PER_LEVEL 2

const ALLEGRO_COLOR BUTTON_COLOR = {140, 45, 0};
const ALLEGRO_COLOR BUTTON_HOVER_COLOR = {241, 106, 0};
const ALLEGRO_COLOR BUTTON_DISABLED_COLOR = {88, 37, 14};
const ALLEGRO_COLOR TEXT_COLOR = {230, 230, 230};
const ALLEGRO_COLOR CORRECT_COLOR = {34, 151, 34};
const ALLEGRO_COLOR WRONG_COLOR = {200, 0, 30};
const ALLEGRO_COLOR BACKGROUND_COLOR {25, 25, 25};

typedef struct point {
    int x;
    int y;

    bool operator==(const struct point& rhs)
    {
        return (x == rhs.x && y == rhs.y);
    }

    bool operator!=(const struct point& rhs)
    {
        return (x != rhs.x || y != rhs.y);
    }

} Point;

#endif