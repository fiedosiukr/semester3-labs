#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "gui_comoponent.h"
#include "animation.h"

#include <allegro5/allegro_font.h>


class TextBox : public GUIComponent
{
    public:
        TextBox(const Point&, const Point&, ALLEGRO_FONT*);
        ~TextBox();
        virtual void update();
        virtual void render();
        virtual void check_events(ALLEGRO_EVENT&);
    
    protected:
        std::string m_text;

        ALLEGRO_FONT *m_font;

        Color m_color;
        Animation<Color> *m_colorAnimation;
};

#endif