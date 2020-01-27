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
        void animate();

    private:
        Point m_coordinates;
        Point m_size;
        Point m_targetCoordinates;
        Point m_targetSize;
        bool m_hovered;
        
        Color m_color;

        FadeoutAnimation<Color> *m_colorAnimation;
        Animation<Point> *m_animation;
};

#endif