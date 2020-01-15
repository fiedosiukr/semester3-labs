#ifndef ANIMATION_H
#define ANIMATION_H

#include "timer.h"

#include <allegro5/allegro.h>


template<class T>
class Animation : public Timer
{
    public:
        Animation(float, T*, T, T);

        virtual void update();
        void set_target_value(T);
        void set_initial_value(T);
    
    protected:
        T* m_pointer;
        T m_initialValue;
        T m_targetValue;
};

template<class T>
class FadeoutAnimation : public Animation<T>
{
    public:
        FadeoutAnimation(float, T*, T, T, float);
        ~FadeoutAnimation();
        void update();
        void start();
        bool is_finished();

    protected:
        Timer *m_timer;
};

#endif