#include "../include/game.h"
#include "../include/play_state.h"
#include "../include/constants.h"

#include <iostream>


Game::Game()
{
	m_timer = al_create_timer(1.0 / TPS);
	if (!m_timer) {
		std::cout << "Failed to create timer!\n";
    }

	m_display = al_create_display(WIDTH, HEIGHT);
	if (!m_display) {
		std::cout << "Failed to create display!\n";
    }

	m_eventQueue = al_create_event_queue();
	if (!m_eventQueue) {
		std::cout << "Failed to create event_queue!\n";
    }

	al_register_event_source(m_eventQueue, al_get_display_event_source(m_display));
	al_register_event_source(m_eventQueue, al_get_timer_event_source(m_timer));
	al_register_event_source(m_eventQueue, al_get_mouse_event_source());

	m_stateManager = new StateManager(this);
    m_stateManager->set_state(StateType::MENU);

}

Game::~Game()
{
	delete m_stateManager;
	
	al_destroy_timer(m_timer);
	al_destroy_display(m_display);
	al_destroy_event_queue(m_eventQueue);
}

void Game::start() 
{
    al_start_timer(m_timer);
    running = true;
    run();
}

void Game::stop()
{
	running = false;
	al_stop_timer(m_timer);
}

void Game::run()
{
    ALLEGRO_EVENT event;
    while (running) {
		al_wait_for_event(m_eventQueue, &event);

		check_events(event);

		if (updated && al_is_event_queue_empty(m_eventQueue)) {
			render();
		}
	}
}

void Game::update()
{
    m_stateManager->update();
}

void Game::render()
{
    m_stateManager->render();
    al_flip_display();
    updated = false;
}

void Game::check_events(ALLEGRO_EVENT t_event) {
	if (t_event.type == ALLEGRO_EVENT_TIMER) {
		update();
		updated = true;
	}
	else if (t_event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		stop();
    }
	else {
		m_stateManager->check_events(t_event);
    }
}