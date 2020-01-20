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
        void render();
        void update(int, int);
        bool is_hovered();
        void set_disabled(bool);

    private:
        char *m_text;

        int m_x;
        int m_y;
        int m_width;
        int m_height;
        int m_time{0};
        int m_maxTime{0};

        bool m_hovered{false};
        bool m_disabled{false};

        Animation<Color> *m_colorAnimation;

        Color m_color{BUTTON_COLOR};
        ALLEGRO_FONT *m_font{nullptr};
};

#endif