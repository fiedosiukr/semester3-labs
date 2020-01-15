#ifndef TILE_H
#define TILE_H

#include "animation.h"

#include "constants.h"

#include <allegro5/allegro.h>

class Tile
{
    public:
        Tile();
        ~Tile();
        void blink(Color);
        void render();
        void update(int, int);
        void set_location(int, int, bool);
        void set_size(int, int, bool);
        bool is_hovered();
        bool is_blinking();
        bool is_changing_size();

    private:
        int m_x{0};
        int m_y{0};
        int m_width{0};
        int m_height{0};
        int m_targetX{0};
        int m_targetY{0};
        int m_targetWidth{0};
        int m_targetHeight{0};
        Point m_currentSize;
        bool m_hovered;
        
        Color m_color;

        FadeoutAnimation<Color> *m_colorAnimation;
        Animation<Point> *m_animation;
};

#endif