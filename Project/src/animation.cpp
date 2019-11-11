#include "../include/animation.h"

#include "../include/constants.h"
#include <iostream>

Animation::Animation(float t_duration, float t_initialValue, float t_maximumValue) :
        Timer(t_duration), m_initialValue(t_initialValue), m_maximumValue(t_maximumValue)
{
}

void Animation::update()
{

    if (m_time != m_maxTime) {
        m_time < m_maxTime ? m_time++ : m_time--;
    }
}

float Animation::get_value()
{
    return m_time / (m_duration * TPS) * (m_maximumValue - m_initialValue) + m_initialValue;
}

FadeoutAnimation::FadeoutAnimation(float t_duration, float t_initialValue, 
                    float t_maximumValue, float t_delayDuration) :
                    Animation(t_duration, t_initialValue, t_maximumValue)
{
    m_timer = new Timer(t_delayDuration);
}

FadeoutAnimation::~FadeoutAnimation()
{
    delete m_timer;
}

void FadeoutAnimation::update()
{
    if (m_maxTime != 0) {
        if (m_time == m_maxTime) {
            m_timer->start();
            if (m_timer->is_finished()) {
                stop();
            }
        } else {
            m_time++;
        }
    } else {
        if (m_time > 0) {
            m_time--;
        }
        m_timer->stop();
    }

    m_timer->update();
}

void FadeoutAnimation::start()
{
    m_maxTime = m_duration * TPS;
    m_timer->reset();
}

bool FadeoutAnimation::is_finished()
{
    return m_timer->is_finished() && m_time == 0;
}