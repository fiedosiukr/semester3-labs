#include "../include/states.h"

#include "../include/menu_state.h"
#include "../include/play_state.h"


StateManager::StateManager()
{
    m_states[StateType::MENU] = new MenuState(this);
    m_states[StateType::PLAY] = new PlayState(this);
}

void StateManager::add_state(StateType t_stateType, State *t_state)
{
    m_states[t_stateType] = t_state;
}

void StateManager::set_state(StateType t_stateType)
{
    if (m_states[t_stateType]) {
        m_states[t_stateType]->deinit();
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

void State::change_state(StateType t_stateType)
{
    m_stateManager->set_state(t_stateType);
}