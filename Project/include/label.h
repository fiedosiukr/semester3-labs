#ifndef LABEL_H
#define LABEL_H

#include "animation.h"

#include <allegro5/allegro_font.h>


class Label
{
    public:
        Label(char*, ALLEGRO_FONT*, int, int, int, int);
        ~Label();
        void change_text(char*);
        void render();
        void update();
    
    private:
        char *m_text;
        ALLEGRO_FONT *m_font;
        int m_x;
        int m_y;
        int m_width;
        int m_height;

        Animation *m_animation;
};

#endif