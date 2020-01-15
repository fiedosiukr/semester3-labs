#include "../include/animation.h"

#include "../include/constants.h"

#include <iostream>


template<class T>
Animation<T>::Animation(float t_duration, T* t_pointer, T t_initialValue, T t_targetValue) :
        Timer(t_duration), m_pointer(t_pointer),
        m_initialValue(t_initialValue), m_targetValue(t_targetValue)
{
}

template<class T>
void Animation<T>::update()
{
    if (m_time != m_maxTime) {
        m_time < m_maxTime ? m_time++ : m_time--;
    }

    *m_pointer = ((m_targetValue - m_initialValue) * (m_time / (m_duration * TPS)));
}

template<class T>
void Animation<T>::set_initial_value(T t_initialValue)
{
    m_initialValue= t_initialValue;
}

template<class T>
void Animation<T>::set_target_value(T t_targetValue)
{
    m_targetValue = t_targetValue;
}

template<class T>
FadeoutAnimation<T>::FadeoutAnimation(float t_duration, T* t_pointer, T t_initialValue,
                    T t_targetValue, float t_delayDuration) :
                    Animation<T>(t_duration, t_pointer, t_initialValue, t_targetValue)
{
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

template class Animation<Color>;