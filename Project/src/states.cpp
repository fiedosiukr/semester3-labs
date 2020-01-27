#include "../include/states.h"
#include "../include/menu_state.h"
#include "../include/play_state.h"


StateManager::StateManager(Game *t_game) : m_game(t_game)
{
    m_states[StateType::MENU] = new MenuState(this);
    m_states[StateType::PLAY] = new PlayState(this);
}

StateManager::~StateManager()
{
    m_states[m_activeState]->deinit();

    delete m_states[StateType::MENU];
    delete m_states[StateType::PLAY];
}

void StateManager::add_state(StateType t_stateType, State *t_state)
{
    m_states[t_stateType] = t_state;
}

void StateManager::set_state(StateType t_stateType)
{
    if (m_states[m_activeState]) {
        m_states[m_activeState]->deinit();
    }

    m_activeState = t_stateType;

    if (m_states[m_activeState]) {
        m_states[m_activeState]->init();
    }
}

void StateManager::update() {
    if (m_states[m_activeState]) {
        m_states[m_activeState]->update();
    }
}

void StateManager::render() {
    if (m_states[m_activeState]) {
        m_states[m_activeState]->render();
    }
}

void StateManager::check_events(ALLEGRO_EVENT t_event) {
    if (m_states[m_activeState]) {
        m_states[m_activeState]->check_events(t_event);
    }
}

State &StateManager::get_active_state()
{
    return *m_states[m_activeState];
}

Game &StateManager::get_game()
{
    return *m_game;
}

void State::change_state(StateType t_stateType)
{
    m_stateManager->set_state(t_stateType);
}

void State::quit_game()
{
    m_stateManager->get_game().stop();
}