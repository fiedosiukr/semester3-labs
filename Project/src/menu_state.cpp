#include "../include/menu_state.h"

#include "../include/button.h"
#include "../include/constants.h"


MenuState::MenuState(StateManager *t_stateManager) : State(t_stateManager)
{
    ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
    al_replace_path_component(path, -1, "resources");
    al_change_directory(al_path_cstr(path, '/'));
    m_font = al_load_font("arial.ttf", FONT_SIZE, 0);

    m_playButton = new Button("Play!", m_font, WIDTH / 2 - BUTTON_WIDTH / 2,
             HEIGHT / 2 - (BUTTON_HEIGHT + (BUTTON_AMOUNT - 1) * BUTTON_OFFSET) * 3 / 2,
            BUTTON_WIDTH, BUTTON_HEIGHT);
    m_scoresButton = new Button("Scores", m_font, WIDTH / 2 - BUTTON_WIDTH / 2,
             HEIGHT / 2 - (BUTTON_HEIGHT + (BUTTON_AMOUNT - 1) * BUTTON_OFFSET) * 3 / 2
             + (BUTTON_OFFSET + BUTTON_HEIGHT) * 1, BUTTON_WIDTH, BUTTON_HEIGHT);
    m_quitButton = new Button("Quit", m_font, WIDTH / 2 - BUTTON_WIDTH / 2,
             HEIGHT / 2 - (BUTTON_HEIGHT + (BUTTON_AMOUNT - 1) * BUTTON_OFFSET) * 3 / 2
             + (BUTTON_OFFSET + BUTTON_HEIGHT) * 2, BUTTON_WIDTH, BUTTON_HEIGHT);
}

MenuState::~MenuState()
{
    delete m_playButton;
    delete m_scoresButton;
    delete m_quitButton;
    al_destroy_font(m_font);
}

void MenuState::init()
{
    
}

void MenuState::deinit()
{

}

void MenuState::update()
{
    m_playButton->update(m_mouseX, m_mouseY);
    m_scoresButton->update(m_mouseX, m_mouseY);
    m_quitButton->update(m_mouseX, m_mouseY);
}

void MenuState::render()
{
    al_clear_to_color(al_map_rgb(28, 25, 25));
    m_playButton->render();
    m_scoresButton->render();
    m_quitButton->render();
}

void MenuState::check_events(ALLEGRO_EVENT t_event)
{
    if (t_event.type == ALLEGRO_EVENT_MOUSE_AXES) {
        m_mouseX = t_event.mouse.x;
        m_mouseY = t_event.mouse.y;
    } else if (t_event.type = ALLEGRO_EVENT_MOUSE_BUTTON_DOWN &&
                t_event.mouse.button == 1) {
        if (m_playButton->is_hovered()) {
            change_state(StateType::PLAY);
        }
        if (m_quitButton->is_hovered()) {
            quit_game();
        }
    }
}