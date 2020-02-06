#include "../include/play_state.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>


PlayState::PlayState(StateManager *t_stateManager) : State(t_stateManager)
{
    m_tiles.resize(m_width);

    for (int i = 0; i < m_width; i++) {
        m_tiles[i].resize(m_height);
        for (int j = 0; j < m_height; j++) {
            m_tiles[i][j] = new Tile();
        }
    }

    calculate_coordinates(false);

    m_blinkingTimer = new Timer(BLINKING_DELAY);
    m_delayTimer = new Timer(LEVEL_DELAY);
    m_scoreTimer = new Timer(18000);

    m_font = al_load_font("arial.ttf", PLAY_FONT_SIZE, 0);

    m_startButton = new Button(Point(620, 360), Point(160, 50), "Start", m_font);
    m_restartButton = new Button(Point(620, 415), Point(160, 50), "Restart", m_font);
    m_restartButton->set_disabled(true);
    m_returnButton = new Button(Point(620, 470), Point(160, 50), "Return", m_font);
    m_quitButton = new Button(Point(620, 525), Point(160, 50), "Quit", m_font);

    char *text = new char[64];
    sprintf(text, "Score: %d", m_score);
    m_scoreLabel = new Label(Point(700, 60), text, m_font);

    srand(time(0));
}

PlayState::~PlayState()
{
    for (int i = 0; i < m_width; i++) {
        for (int j = 0; j < m_height; j++) {
            delete m_tiles[i][j];
        }
    }

    delete m_blinkingTimer;
    delete m_delayTimer;
    delete m_scoreTimer;

    delete m_startButton;
    delete m_restartButton;
    delete m_returnButton;
    delete m_quitButton;
    
    delete m_scoreLabel;

    al_destroy_font(m_font);
}

void PlayState::init()
{

}

void PlayState::deinit()
{
    m_started = false;
    m_restartButton->set_disabled(true);
    m_startButton->set_disabled(false);
}

void PlayState::update()
{
    if (!m_gameOver) {
        if (m_blinking) {
            if (m_blinkingIndex < m_tilesToRemember) {
                if (m_blinkingTimer->is_finished()) {
                    m_tiles[m_blinkedTiles[m_blinkingIndex].x][m_blinkedTiles[m_blinkingIndex].y]->blink(BUTTON_HOVER_COLOR);
                    m_blinkingTimer->reset_time();
                    m_blinkingIndex++;
                }
            }
            else {
                if (!(m_tiles[m_blinkedTiles[m_tilesToRemember - 1].x][m_blinkedTiles[m_tilesToRemember - 1].y]->is_blinking())) {
                    m_blinking = false;
                    m_userClickedTiles.clear();
                    m_scoreTimer->start();
                }
            }
        }

        if (m_blinkedTiles.empty()) {
            if (m_started) {
                m_tilesToRemember = m_difficulty;
                randomize_tiles();
            }
        } 

        if (!m_blinkedTiles.empty() && !m_tiles[m_blinkedTiles.back().x][m_blinkedTiles.back().y]->is_blinking()) {
            if (m_increaseDifficulty) {
                increase_difficulty();
                m_increaseDifficulty = false;
            }
        }
    }

    if (m_delayTimer->is_finished()) {
        m_blinkedTiles.clear();
        m_delayTimer->reset();
    }
    
    m_blinkingTimer->update();
    m_delayTimer->update();
    m_scoreTimer->update();

    for (int i = 0; i < m_width; i++) {
        for (int j = 0; j < m_height; j++) {
            m_tiles[i][j]->update();
        }
    }

    m_startButton->update();
    m_restartButton->update();
    m_returnButton->update();
    m_quitButton->update();

    m_scoreLabel->update();
}

void PlayState::save_score()
{
    if (m_score == 0) {
        return;
    }

    std::ifstream input_file("../scores.txt", std::ios::in);
    std::vector<Score> file_scores;

    if (input_file.is_open()) {
        std::string line;
        int scores = 0;
        while (std::getline(input_file, line) && scores < MAX_SCORES) {
        Score score;
        line >> score;
        file_scores.emplace_back(score);
        scores++;
        }
    }
    
    if (file_scores.size() == 0) {
        file_scores.emplace_back(Score(USERNAME, m_score));
    }
    else {
        bool placed = false;
        for (auto it = file_scores.begin(); it != file_scores.end(); it++) {
            if (m_score > it->score) {
                file_scores.emplace(it, Score(USERNAME, m_score));
                placed = true;
                break;
            }
        }

        if (!placed && file_scores.size() < MAX_SCORES) {
            file_scores.emplace_back(Score(USERNAME, m_score));
        }
    }


    input_file.close();
    std::ofstream output_file("../scores.txt", std::ios::trunc);
    for (int i = 0; i < MAX_SCORES && i < file_scores.size(); i++) {
        output_file << file_scores[i].username << "," << std::to_string(file_scores[i].score) << std::endl;
    }
}

void PlayState::render()
{
    al_clear_to_color(BACKGROUND_COLOR.to_al_color());

    for (int i = 0; i < m_width; i++) {
        for (int j = 0; j < m_height; j++) {
            m_tiles[i][j]->render();
        }
    }

    m_startButton->render();
    m_restartButton->render();
    m_returnButton->render();
    m_quitButton->render();

    m_scoreLabel->render();
}

void PlayState::check_events(ALLEGRO_EVENT& t_event)
{
    m_startButton->check_events(t_event);
    m_restartButton->check_events(t_event);
    m_returnButton->check_events(t_event);
    m_quitButton->check_events(t_event);

    for (int i = 0; i < m_width; i++) {
        for (int j = 0; j < m_height; j++) {
            m_tiles[i][j]->check_events(t_event);
        }
    }

    if (t_event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN &&
                t_event.mouse.button == 1) {
        if (!m_blinking && !m_gameOver && m_userClickedTiles.size() < m_tilesToRemember && m_started) {
            for (int i = 0; i < m_width; i++) {
                for (int j = 0; j < m_height; j++) {
                    if (m_tiles[i][j]->is_hovered()) {
                        clicked({i, j});
                    }
                }
            }
        }
    }
    else if (t_event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && t_event.mouse.button == 1) {
        if (m_quitButton->is_hovered()) {
            quit_game();
        }
        else if (m_restartButton->is_hovered()) {
            if (m_saveScore) {
                save_score();
            }

            m_started = false;
            m_startButton->set_disabled(false);
            m_restartButton->set_disabled(true);
            restart_game(true);
        }
        else if (m_returnButton->is_hovered()) {
            if (m_saveScore) {
                save_score();
            }
            m_stateManager->set_state(StateType::MENU);
        }
        else if (m_startButton->is_hovered()) {
            m_saveScore = true;
            m_started = true;
            m_restartButton->set_disabled(false);
            m_startButton->set_disabled(true);
        }
    }
}

void PlayState::calculate_coordinates(bool t_animate)
{
    int boardOffsetX = (INITIAL_BOARD_OFFSET_X - (m_width - INITIAL_WIDTH));
    if (boardOffsetX < MINIMUM_BOARD_OFFSET_X) {
        boardOffsetX = MINIMUM_BOARD_OFFSET_X;
    }

    int boardOffsetY = (INITIAL_BOARD_OFFSET_Y - (m_height - INITIAL_HEIGHT));
    if (boardOffsetY < MINIMUM_BOARD_OFFSET_Y) {
        boardOffsetY = MINIMUM_BOARD_OFFSET_Y;
    }

    int tileWidth = (BOARD_WIDTH - (boardOffsetX * (m_width - 1))) /
                    (m_width + 1);
    
    int tileHeight = (BOARD_HEIGHT - (boardOffsetY * (m_height - 1))) /
                    (m_height + 1);

    for (int i = 0; i < m_width; i++) {
        for (int j = 0; j < m_height; j++) {
            m_tiles[i][j]->set_size((int) tileWidth, (int) tileHeight, t_animate);
            m_tiles[i][j]->set_location((int)(tileWidth + (tileWidth + boardOffsetX) * i),
                                    (int)(tileHeight + (tileHeight + boardOffsetY) * j), t_animate);
        }
    }
}

void PlayState::increase_difficulty()
{
    if (m_difficultyIncrement < DIFFICULTY_INCREMENT_PER_LEVEL) {
        m_difficulty++;
        m_difficultyIncrement++;
    } else {
        m_difficultyIncrement = 0;
        enlarge_board();
    }

    m_delayTimer->start();
}

void PlayState::calculate_score()
{
    int time_elapsed = m_scoreTimer->get_time();
    int score = m_tilesToRemember * (10 + (m_width - INITIAL_WIDTH) * 5);
    int score_decrement = time_elapsed - (m_tilesToRemember * TIME_PER_TILE * TPS);
    if (score_decrement < 0) {
        score_decrement = 0;
    }
    else if (score_decrement > MAX_SCORE_DECREMENT * m_tilesToRemember) {
        score_decrement = MAX_SCORE_DECREMENT * m_tilesToRemember;
    }

    score -= score_decrement;
    m_score += score;
    m_scoreLabel->change_text("Score: " + std::to_string(m_score));
    m_scoreTimer->reset();
}

void PlayState::enlarge_board()
{
    m_width++;
    m_height++;

    m_tiles.resize(m_width);

    for (int i = 0; i < m_width; i++) {
        m_tiles[i].resize(m_height);
        m_tiles[i][m_height - 1] = new Tile();
    }

    for (int i = 0; i < m_height - 1; i++) {
        m_tiles[m_width - 1][i] = new Tile();
    }

    calculate_coordinates(true);
}

void PlayState::restart_game(bool t_animate)
{
    for (int i = INITIAL_WIDTH; i < m_width; i++) {
        for (int j = INITIAL_HEIGHT; j < m_height; j++) {
            delete m_tiles[i][j];
        }
        m_tiles[i].resize(INITIAL_HEIGHT);
    }

    m_tiles.resize(INITIAL_WIDTH);
 
    m_width = INITIAL_WIDTH;
    m_height = INITIAL_HEIGHT;
    calculate_coordinates(t_animate);
    

    m_blinkedTiles.clear();
    m_userClickedTiles.clear();
    m_blinkingIndex = 0;
    m_tilesToRemember = 1;
    m_blinking = false;
    m_delayTimer->reset();
    m_blinkingTimer->reset();
    m_scoreTimer->reset();
    m_gameOver = false;
    m_difficulty = 1;
    m_difficultyIncrement = 0;
    m_score = 0;
    m_scoreLabel->change_text("Score: 0");
}

void PlayState::randomize_tiles()
{
    for (int i = 0; i < m_tilesToRemember; i++) {
        int x = rand() % m_width;
        int y = rand() % m_height;
        Point temporary = {x, y};
        m_blinkedTiles.emplace_back(temporary);
        for (int j = 0; j < m_blinkedTiles.size() - 1; j++) {
            if (temporary == m_blinkedTiles[j]) {
                i--;
                m_blinkedTiles.resize(m_blinkedTiles.size() - 1);
                break;
            }
        }
    }

    m_blinking = true;
    m_blinkingIndex = 0;
    m_blinkingTimer->reset();
    m_blinkingTimer->start();
}

void PlayState::clicked(Point t_point) 
{
    if (!(std::find(m_userClickedTiles.begin(), m_userClickedTiles.end(), t_point) != m_userClickedTiles.end())) {
        m_userClickedTiles.emplace_back(t_point);
        if (m_userClickedTiles.back() == m_blinkedTiles[m_userClickedTiles.size() - 1]) {
            m_tiles[t_point.x][t_point.y]->blink(CORRECT_COLOR);
        }
        else {
            m_tiles[t_point.x][t_point.y]->blink(WRONG_COLOR);
            m_gameOver = true;
            save_score();
            m_saveScore = false;
            return;
        }

        if (m_blinkedTiles.size() == m_userClickedTiles.size()) {
            calculate_score();
            m_increaseDifficulty = true;
        }
    }
}