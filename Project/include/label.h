#ifndef LABEL_H
#define LABEL_H

#include "gui_comoponent.h"
#include "animation.h"

#include <allegro5/allegro_font.h>


class Label : public GUIComponent
{
    public:
        Label(const Point&, std::string, ALLEGRO_FONT*);
        ~Label();
        virtual void render();
        virtual void update();
        virtual void check_events(ALLEGRO_EVENT&);
        void change_text(const std::string&);
        
    
    private:
        std::string m_text;
        ALLEGRO_FONT *m_font;
        int m_x;
        int m_y;
        int m_width;
        int m_height;
};

#endif