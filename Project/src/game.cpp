#include "../include/game.h"

#include "../include/play_state.h"

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

#include <iostream>


Game::Game()
{
    if (!al_init()) {
		std::cout << "Failed to initialize allegro!\n";
    }

	if (!al_init_primitives_addon()) {
		std::cout << "Failed to initialize primitives addon!\n";
    }

	if (!al_install_mouse()) {
		std::cout << "Failed to install mouse!\n";
    }

	if (!al_init_font_addon()) {
		std::cout << "Failed to initialize font addon!\n";
    }

	if (!al_init_ttf_addon()) {
		std::cout << "Failed to intialize ttf addon!\n";
    }

	m_timer = al_create_timer(1.0 / 60.0);
	if (!m_timer) {
		std::cout << "Failed to create timer!\n";
    }

	m_display = al_create_display(800, 600);
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

    m_stateManager = new StateManager();
    m_stateManager->set_state(StateType::MENU);
}

Game::~Game()
{
	al_destroy_timer(m_timer);
	al_destroy_display(m_display);
	al_destroy_event_queue(m_eventQueue);

    delete m_stateManager;
}

void Game::start() 
{
    al_start_timer(m_timer);
    running = true;
    run();
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
    al_clear_to_color(al_map_rgb(100, 100, 100));
    al_flip_display();
    updated = false;
}

void Game::check_events(ALLEGRO_EVENT t_event) {
	if (t_event.type == ALLEGRO_EVENT_TIMER) {
		update();
		updated = true;
	}
	else if (t_event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		running = false;
    }
	else {

    }
}