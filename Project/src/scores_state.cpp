#include "../include/scores_state.h"


ScoresState::ScoresState(StateManager *t_stateManager) : State(t_stateManager)
{
    ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
    al_replace_path_component(path, -1, "resources");
    al_change_directory(al_path_cstr(path, '/'));
    m_font = al_load_font("arial.ttf", MENU_FONT_SIZE, 0);
    al_destroy_path(path);

    m_backButton = new Button(Point(WIDTH / 2 - BUTTON_WIDTH / 2,
            HEIGHT / 2 - (BUTTON_HEIGHT + (BUTTON_AMOUNT - 1) * BUTTON_OFFSET) * 3 / 2),
            Point(BUTTON_WIDTH, BUTTON_HEIGHT), "Back", m_font);
}

ScoresState::~ScoresState()
{
    delete m_backButton;
}

void ScoresState::init()
{

}

void ScoresState::deinit()
{

}

void ScoresState::update()
{
    m_backButton->update();
}

void ScoresState::render()
{
    al_clear_to_color(BACKGROUND_COLOR.to_al_color());

    m_backButton->render();
}

void ScoresState::check_events(ALLEGRO_EVENT& t_event)
{
    m_backButton->check_events(t_event);
}