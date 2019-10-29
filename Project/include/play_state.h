#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "states.h"


class PlayState : public State 
{
    public:
        PlayState(StateManager *t_stateManager) : State(t_stateManager) {}
        void init();
        void deinit();
        void render();
        void update();
        void check_events(ALLEGRO_EVENT);
};

#endif