#ifndef SCORES_STATE_H
#define SCORES_STATE_H

#include "states.h"
#include "constants.h"
#include "button.h"

#include <vector>


class ScoresState : public State
{
    public:
        ScoresState(StateManager*);
        ~ScoresState();
        void init();
        void deinit();
        void update();
        void render();
        void check_events(ALLEGRO_EVENT&);
    
    private:
        std::vector<Score> m_scores;

        ALLEGRO_FONT *m_font;
        
        Button *m_backButton;
};

#endif