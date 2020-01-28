#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "states.h"
#include "button.h"
#include "textbox.h"
#include "constants.h"

#include <allegro5/allegro.h>


class MenuState : public State 
{
    public:
        MenuState(StateManager*);
        ~MenuState();

        void init();
        void deinit();
        void render();
        void update();
        void check_events(ALLEGRO_EVENT&);

    private:
        ALLEGRO_FONT *m_font;

        int m_mouseX;
        int m_mouseY;

        Button *m_playButton;
        Button *m_scoresButton;
        Button *m_quitButton;
        TextBox *m_textbox;
};

#endif