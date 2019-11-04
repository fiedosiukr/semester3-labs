#ifndef BUTTON_H
#define BUTTON_H

#include "constants.h"
#include "animation.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#include <vector>


class Button
{
    public:
        Button(const char*, ALLEGRO_FONT*, int, int, int, int);
        ~Button();
        void render();
        void update(int, int);
        bool is_hovered();

    private:
        char *m_text;

        int m_x;
        int m_y;
        int m_width;
        int m_height;
        int m_time{0};
        int m_maxTime{0};

        bool m_hovered{false};

        std::vector<Animation*> m_animations;
        
        ALLEGRO_COLOR m_color{al_map_rgb(BUTTON_COLOR.r,
                                    BUTTON_COLOR.g, BUTTON_COLOR.b)};
        ALLEGRO_FONT *m_font;
};

#endif