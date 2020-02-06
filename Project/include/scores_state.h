#ifndef SCORES_STATE_H
#define SCORES_STATE_H

#include "states.h"
#include "constants.h"
#include "button.h"
#include "label.h"

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
        void load_scores();

        std::vector<Score> m_scores;

        ALLEGRO_FONT *m_font;
        
        Button *m_backButton;
        Label *m_labels[MAX_SCORES];
};

#endif