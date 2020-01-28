#ifndef STATES_H
#define STATES_H

#include "game.h"

#include <allegro5/allegro.h>

#include <map>


enum StateType
{
    MENU = 0,
    PLAY
};


class State;
class Game;


class StateManager
{
    public:
        StateManager(Game*);
        ~StateManager();
        void add_state(StateType, State*);
        void set_state(StateType);
        void update();
        void render();
        void check_events(ALLEGRO_EVENT&);
        State &get_active_state();
        Game &get_game();

    private:
        std::map<StateType, State*> m_states;
        StateType m_activeState;
        Game *m_game;
};


class State
{
    public:
        virtual void init() = 0;
        virtual void deinit() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
        virtual void check_events(ALLEGRO_EVENT&) = 0;
    
    protected:
        State(StateManager *t_stateManager) : m_stateManager(t_stateManager) {}

        void change_state(StateType);
        void quit_game();

        StateManager *m_stateManager;
};

#endif