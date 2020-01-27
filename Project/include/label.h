#ifndef LABEL_H
#define LABEL_H

#include "gui_comoponent.h"
#include "animation.h"

#include <allegro5/allegro_font.h>


class Label : public GUIComponent
{
    public:
        Label(const Point&, const Point&, std::string, ALLEGRO_FONT*);
        ~Label();
        void change_text(const std::string&);
        void render();
        void update();
    
    private:
        std::string m_text;
        ALLEGRO_FONT *m_font;
        int m_x;
        int m_y;
        int m_width;
        int m_height;
};

#endif