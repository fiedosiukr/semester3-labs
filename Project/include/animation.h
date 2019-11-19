#ifndef ANIMATION_H
#define ANIMATION_H

#include "timer.h"

#include <allegro5/allegro.h>

#include <vector>


class Animation : public Timer
{
    public:
        Animation(float);

        virtual void update();
        float get_coefficient();
};

class ColorAnimation : public Animation
{
    public:
        ColorAnimation(float, ALLEGRO_COLOR, ALLEGRO_COLOR);
        ~ColorAnimation();
        ALLEGRO_COLOR get_color();
        void set_target_color(ALLEGRO_COLOR);
        void set_initial_color(ALLEGRO_COLOR);

    protected:
        ALLEGRO_COLOR m_initialColor;
        ALLEGRO_COLOR m_targetColor;
};

class FadeoutColorAnimation : public ColorAnimation
{
    public:
        FadeoutColorAnimation(float, ALLEGRO_COLOR, ALLEGRO_COLOR, float);
        ~FadeoutColorAnimation();
        void update();
        void start();
        bool is_finished();

    protected:
        Timer *m_timer;
};



#endif