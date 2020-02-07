#include "../include/scores_state.h"
#include "../include/constants.h"

#include <fstream>


ScoresState::ScoresState(StateManager *t_stateManager) : State(t_stateManager)
{
    m_font = al_load_font("arial.ttf", MENU_FONT_SIZE, 0);

    m_backButton = new Button(Point(WIDTH / 2 - BUTTON_WIDTH / 2,
            HEIGHT / 2 + 100),
            Point(BUTTON_WIDTH, BUTTON_HEIGHT), "Back", m_font);

    for (int i = 0; i < MAX_SCORES; i++) {
        m_labels[i] = new Label(Point(WIDTH / 2, (i+1) * 50), std::to_string(i + 1) + ".   ------------     -----", m_font);
    }
}

ScoresState::~ScoresState()
{
    delete m_backButton;

    for (int i = 0; i < MAX_SCORES; i++) {
        delete m_labels[i];
    }
}

void ScoresState::load_scores()
{
    std::ifstream input_file("../scores.txt", std::ios::in);

    if (!input_file.is_open()) {
        return;
    }

    std::string line;
    int scores = 0;
    while (std::getline(input_file, line) && scores < MAX_SCORES) {
        Score score;
        line >> score;
        m_scores.emplace_back(score);
        scores++;
    }

    for (int i = 0; i < scores; i++) {
        m_labels[i]->change_text(std::to_string(i + 1) + ".    " + m_scores[i].username + "      " + std::to_string(m_scores[i].score));
    }
}

void ScoresState::init()
{
    for (int i = 0; i < MAX_SCORES; i++) {
        m_labels[i]->change_text(std::to_string(i + 1) + ".   ------------     -----");
    }

    load_scores();
}

void ScoresState::deinit()
{
    m_scores.clear();
}

void ScoresState::update()
{
    m_backButton->update();
}

void ScoresState::render()
{
    al_clear_to_color(BACKGROUND_COLOR.to_al_color());

    m_backButton->render();

    for (int i = 0; i < MAX_SCORES; i++) {
        m_labels[i]->render();
    }
}

void ScoresState::check_events(ALLEGRO_EVENT& t_event)
{
    m_backButton->check_events(t_event);

    if (t_event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && t_event.mouse.button == 1) {
        if (m_backButton->is_hovered()) {
            m_stateManager->set_state(StateType::MENU);
        }
    }
}