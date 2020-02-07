#include "../include/menu_state.h"


std::string USERNAME = "noname";


MenuState::MenuState(StateManager *t_stateManager) : State(t_stateManager)
{
    ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
    al_replace_path_component(path, -1, "resources");
    al_change_directory(al_path_cstr(path, '/'));
    m_font = al_load_font("arial.ttf", MENU_FONT_SIZE, 0);
    al_destroy_path(path);

    m_playButton = new Button(Point(WIDTH / 2 - BUTTON_WIDTH / 2,
            HEIGHT / 2 - (BUTTON_HEIGHT + (BUTTON_AMOUNT - 1) * BUTTON_OFFSET) * 3 / 2),
            Point(BUTTON_WIDTH, BUTTON_HEIGHT), "Play!", m_font);
    m_scoresButton = new Button(Point(WIDTH / 2 - BUTTON_WIDTH / 2,
             HEIGHT / 2 - (BUTTON_HEIGHT + (BUTTON_AMOUNT - 1) * BUTTON_OFFSET) * 3 / 2
             + (BUTTON_OFFSET + BUTTON_HEIGHT) * 1), Point(BUTTON_WIDTH, BUTTON_HEIGHT), "Scores", m_font);
    m_quitButton = new Button(Point(WIDTH / 2 - BUTTON_WIDTH / 2,
             HEIGHT / 2 - (BUTTON_HEIGHT + (BUTTON_AMOUNT - 1) * BUTTON_OFFSET) * 3 / 2
             + (BUTTON_OFFSET + BUTTON_HEIGHT) * 2), Point(BUTTON_WIDTH, BUTTON_HEIGHT), "Quit", m_font);
    m_textbox = new TextBox(Point(WIDTH / 2 - BUTTON_WIDTH / 2,
             HEIGHT / 2 - (BUTTON_HEIGHT + (BUTTON_AMOUNT - 1) * BUTTON_OFFSET) * 3 / 2
             + (BUTTON_OFFSET + BUTTON_HEIGHT) * 3 + 125), Point(BUTTON_WIDTH, BUTTON_HEIGHT), m_font);

    m_label = new Label(Point(WIDTH / 2, HEIGHT / 2 + 185), "Enter username:", m_font);

    m_textbox->set_text(USERNAME);

}

MenuState::~MenuState()
{
    delete m_playButton;
    delete m_scoresButton;
    delete m_quitButton;
    delete m_textbox;
    delete m_label;
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
    USERNAME = m_textbox->get_text();

    m_playButton->update();
    m_scoresButton->update();
    m_quitButton->update();
    m_textbox->update();
}

void MenuState::render()
{
    al_clear_to_color(BACKGROUND_COLOR.to_al_color());
    m_playButton->render();
    m_scoresButton->render();
    m_quitButton->render();
    m_textbox->render();
    m_label->render();
}

void MenuState::check_events(ALLEGRO_EVENT& t_event)
{
    m_playButton->check_events(t_event);
    m_scoresButton->check_events(t_event);
    m_quitButton->check_events(t_event);
    m_textbox->check_events(t_event);

    if (t_event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP &&
                t_event.mouse.button == 1) {
        if (m_playButton->is_hovered()) {
            change_state(StateType::PLAY);
        }
        else if (m_quitButton->is_hovered()) {
            quit_game();
        }
        else if (m_scoresButton->is_hovered()) {
            change_state(StateType::SCORES);
        }
    }
}