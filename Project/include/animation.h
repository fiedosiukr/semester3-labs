#ifndef ANIMATION_H
#define ANIMATION_H

#include "timer.h"
#include "constants.h"

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

template<class T>
Animation<T>::Animation(float t_duration, T* t_pointer, T t_initialValue, T t_targetValue) :
        Timer(t_duration), m_pointer(t_pointer),
        m_initialValue(t_initialValue), m_targetValue(t_targetValue)
{
    *m_pointer = m_initialValue;
}

template<class T>
void Animation<T>::update()
{
    if (m_time != m_maxTime) {
        m_time < m_maxTime ? m_time++ : m_time--;
    }

    *m_pointer = m_initialValue + ((m_targetValue - m_initialValue) * (m_time / (m_duration * TPS)));
}

template<class T>
void Animation<T>::set_initial_value(T t_initialValue)
{
    this->m_initialValue = t_initialValue;
}

template<class T>
void Animation<T>::set_target_value(T t_targetValue)
{
    this->m_targetValue = t_targetValue;
}

template<class T>
FadeoutAnimation<T>::FadeoutAnimation(float t_duration, T* t_pointer, T t_initialValue,
                    T t_targetValue, float t_delayDuration) :
                    Animation<T>(t_duration, t_pointer, t_initialValue, t_targetValue)
{
    *(this->m_pointer) = this->m_initialValue;
    m_timer = new Timer(t_delayDuration);
}

template<class T>
FadeoutAnimation<T>::~FadeoutAnimation()
{
    delete m_timer;
}

template<class T>
void FadeoutAnimation<T>::update()
{
    if (this->m_maxTime != 0) {
        if (this->m_time == this->m_maxTime) {
            m_timer->start();
            if (m_timer->is_finished()) {
                this->stop();
            }
        } else {
            this->m_time++;
        }
    } else {
        if (this->m_time > 0) {
            this->m_time--;
        }
    }

    *(this->m_pointer) = this->m_initialValue + ((this->m_targetValue - this->m_initialValue) * (this->m_time / (this->m_duration * TPS)));

    m_timer->update();
}

template<class T>
void FadeoutAnimation<T>::start()
{
    this->m_maxTime = this->m_duration * TPS;
    this->m_timer->reset();
    
}

template<class T>
bool FadeoutAnimation<T>::is_finished()
{
    return (this->m_timer->is_finished() &&this-> m_time == 0);
}

#endif