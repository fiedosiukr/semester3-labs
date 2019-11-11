#ifndef ANIMATION_H
#define ANIMATION_H

#include "timer.h"


class Animation : public Timer
{
    public:
        Animation(float, float, float);

        virtual void update();
        float get_value();

    protected:
        float m_initialValue;
        float m_maximumValue;
};

class FadeoutAnimation : public Animation
{
    public:
        FadeoutAnimation(float, float, float, float);
        ~FadeoutAnimation();
        void update();
        void start();
        bool is_finished();

    protected:
        Timer *m_timer;
};

#endif