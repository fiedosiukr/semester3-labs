#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "states.h"
#include "tile.h"
#include "button.h"
#include "label.h"
#include "constants.h"

#include <allegro5/allegro_font.h>

#include <vector>


class PlayState : public State 
{
    public:
        PlayState(StateManager*);
        ~PlayState();
        void init();
        void deinit();
        void render();
        void update();
        void check_events(ALLEGRO_EVENT);

    private:
        void increase_difficulty();
        void calculate_score();
        void restart_game();
        void calculate_coordinates(bool);
        void enlarge_board();
        void randomize_tiles();
        void clicked(Point);
        std::vector<std::vector<Tile*>> m_tiles;

        std::vector<Point> m_blinkedTiles;
        std::vector<Point> m_userClickedTiles;

        int m_width{INITIAL_WIDTH};
        int m_height{INITIAL_HEIGHT};

        int m_mouseX{0};
        int m_mouseY{0};

        int m_tilesToRemember{1};
        int m_blinkingIndex{0};
        int m_difficulty{1};

        bool m_started{false};
        bool m_blinking{false};
        bool m_gameOver{false};
        bool m_increaseDifficulty{false};
        bool m_restartGame;

        int m_difficultyIncrement{0};
        int m_score{0};

        Timer *m_blinkingTimer;
        Timer *m_delayTimer;
        Timer *m_scoreTimer;

        Button *m_startButton;
        Button *m_restartButton;
        Button *m_quitButton;

        Label *m_scoreLabel;

        ALLEGRO_FONT *m_font;
};

#endif