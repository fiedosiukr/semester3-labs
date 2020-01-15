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

struct Color
{
    unsigned int r;
    unsigned int g;
    unsigned int b;

    Color(int r, int g, int b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }

    struct Color operator=(struct Color& rhs)
    {
        r = rhs.r;
        g = rhs.g;
        b = rhs.b;
    
        return *this;
    }

    struct Color operator-(const struct Color& rhs)
    {
        return Color((int) r - rhs.r, (int) g - rhs.g, (int) b - rhs.b);
    }

    struct Color operator*(float rhs)
    {
        return Color((int) r * rhs, (int) g * rhs, (int) b * rhs);
    }

    ALLEGRO_COLOR to_al_color()
    {
        return al_map_rgb(r, g, b);
    }
    
};

struct Point
{
    int x;
    int y;

    bool operator==(const struct Point& rhs)
    {
        return (x == rhs.x && y == rhs.y);
    }

    bool operator!=(const struct Point& rhs)
    {
        return (x != rhs.x || y != rhs.y);
    }

    void operator-(const struct Point& rhs)
    {
        x = x - rhs.x;
        y = y - rhs.y;
    }

    void operator*(float rhs)
    {
        x = (int) (x * rhs);
        y = (int) (y * rhs);
    }

};

static Color BUTTON_COLOR = {140, 45, 0};
static Color BUTTON_HOVER_COLOR = {241, 106, 0};
static Color BUTTON_DISABLED_COLOR = {88, 37, 14};
static Color TEXT_COLOR = {230, 230, 230};
static Color CORRECT_COLOR = {34, 151, 34};
static Color WRONG_COLOR = {200, 0, 30};
static Color BACKGROUND_COLOR {25, 25, 25};

#endif