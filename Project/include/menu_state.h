#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "states.h"
#include "button.h"

#include <allegro5/allegro.h>

#include "../include/constants.h"


class MenuState : public State 
{
    public:
        MenuState(StateManager*);
        ~MenuState();

        void init();
        void deinit();
        void render();
        void update();
        void check_events(ALLEGRO_EVENT);

    private:
        ALLEGRO_FONT *m_font;

        int m_mouseX;
        int m_mouseY;

        Button *m_playButton;
        Button *m_scoresButton;
        Button *m_quitButton;
};

#endif