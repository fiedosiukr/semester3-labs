#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <allegro5/allegro.h>
#include <iostream>


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
#define MAX_TEXT_LENGTH 12
#define TEXTBOX_OFFSET 23
#define FOCUS_LINE_WIDTH 2
#define FILENAME "../scores.txt"
#define MAX_SCORES 5

extern std::string USERNAME;

struct Color
{
    unsigned int r;
    unsigned int g;
    unsigned int b;

    Color()
    {
        r = g = b = 0;
    }

    Color(int r, int g, int b)
    {
        this->r = r;
        this->g = g;
        this->b = b;
    }

    struct Color& operator=(const struct Color& rhs)
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
    
    struct Color operator+(const struct Color& rhs)
    {
        return Color(r + rhs.r, g + rhs.g, b + rhs.b);
    }

    struct Color operator*(float rhs)
    {
        return Color((int) r * rhs, (int) g * rhs, (int) b * rhs);
    }

    friend std::ostream& operator<<(std::ostream& os, const Color& rhs)
    {
        os << "(" << rhs.r << ", " << rhs.g << ", " << rhs.b << ")";
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

    Point()
    {
        x = y = 0;
    }

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Point(const Point& rhs)
    {
        this->x = rhs.x;
        this->y = rhs.y;
    }

    bool operator==(const struct Point& rhs)
    {
        return (x == rhs.x && y == rhs.y);
    }

    bool operator!=(const struct Point& rhs)
    {
        return (x != rhs.x || y != rhs.y);
    }

    bool operator>=(const struct Point& rhs)
    {
        return (x >= rhs.x && y >= rhs.y);
    }

    bool operator<(const struct Point& rhs)
    {
        return (x < rhs.x && y < rhs.y);
    }

    Point& operator=(const struct Point& rhs)
    {
        x = rhs.x;
        y = rhs.y;
        return *this;
    }

    Point operator-(const struct Point& rhs)
    {
        return Point(x - rhs.x, y - rhs.y);
    }

    Point operator/(int rhs)
    {
        return Point((int) x / 2, (int) y / 2);       
    }

    Point operator+(const struct Point& rhs)
    {
        return Point(x + rhs.x, y + rhs.y);
    }

    Point operator*(float rhs)
    {
        return Point((int) (x * rhs), (int) (y * rhs));
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& rhs)
    {
        os << "(" << rhs.x << ", " << rhs.y << ")";
    }
};

struct Score
{
    std::string username;
    int score;

    Score() {}

    Score(std::string username, int score)
    {
        this->username = username;
        this->score = score;
    }

    friend std::string& operator>>(std::string& line, Score& rhs)
    {
        rhs.username = line.substr(0, line.find(','));
        rhs.score = std::atoi(line.substr(line.find(',') + 1, line.size() - 1).c_str());
        return line;
    }
};

static Color BUTTON_COLOR = {140, 45, 0};
static Color BUTTON_HOVER_COLOR = {241, 106, 0};
static Color BUTTON_DISABLED_COLOR = {88, 37, 14};
static Color TEXT_COLOR = {230, 230, 230};
static Color CORRECT_COLOR = {34, 151, 34};
static Color WRONG_COLOR = {200, 0, 30};
static Color BACKGROUND_COLOR {25, 25, 25};
static Color TEXTBOX_COLOR = {66, 66, 66};
static Color TEXTBOX_FOCUS_COLOR = {89, 89, 89};
static Color FOCUS_LINE_COLOR = {0, 0, 0};

#endif