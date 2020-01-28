#ifndef BUTTON_H
#define BUTTON_H

#include "gui_comoponent.h"
#include "constants.h"
#include "animation.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#include <vector>


class Button : public GUIComponent
{
    public:
        Button(const Point&, const Point&, std::string, ALLEGRO_FONT*);
        virtual void render();
        virtual void update();
        virtual void check_events(ALLEGRO_EVENT&);
        virtual void set_disabled(bool);

    protected:
        std::string m_text;

        int m_time{0};
        int m_maxTime{0};

        Animation<Color> *m_colorAnimation;

        Color m_color{BUTTON_COLOR};
        ALLEGRO_FONT *m_font{nullptr};
};

#endif