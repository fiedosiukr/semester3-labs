#include "../include/menu_state.h"


void MenuState::init()
{

}

void MenuState::deinit()
{

}

void MenuState::update()
{
    std::cout << "MenuState!\n";
    change_state(StateType::PLAY);
}

void MenuState::render()
{

}

void MenuState::check_events(ALLEGRO_EVENT t_event)
{

}