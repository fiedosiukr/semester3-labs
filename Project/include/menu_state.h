#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "states.h"


class MenuState : public State 
{
    public:
        MenuState(StateManager *t_stateManager) : State(t_stateManager) {}
        void init();
        void deinit();
        void render();
        void update();
        void check_events(ALLEGRO_EVENT);
};

#endif