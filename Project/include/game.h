#ifndef GAME_H
#define GAME_H

#include "states.h"

#include <allegro5/allegro.h>
#include <iostream>


class StateManager;

class Game 
{
    public:
        
        Game();
        ~Game();

        void start();
        void stop();

    private:
        StateManager *m_stateManager;

        ALLEGRO_DISPLAY *m_display;
        ALLEGRO_TIMER *m_timer;
        ALLEGRO_EVENT_QUEUE *m_eventQueue;

        bool running{false};
        bool updated{false};

        void run();
        void update();
        void render();
        void check_events(ALLEGRO_EVENT&);
};

#endif