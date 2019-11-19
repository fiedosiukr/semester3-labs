#include "../include/animation.h"

#include "../include/constants.h"

#include <iostream>


Animation::Animation(float t_duration) :
        Timer(t_duration)
{
}

void Animation::update()
{

    if (m_time != m_maxTime) {
        m_time < m_maxTime ? m_time++ : m_time--;
    }
}

float Animation::get_coefficient()
{
    return m_time / (m_duration * TPS);
}

ColorAnimation::ColorAnimation(float t_duration, ALLEGRO_COLOR t_initialColor, ALLEGRO_COLOR t_targetColor) :
                    Animation(t_duration), m_initialColor(t_initialColor), m_targetColor(t_targetColor)
{
}

ColorAnimation::~ColorAnimation()
{
}

ALLEGRO_COLOR ColorAnimation::get_color()
{
    return al_map_rgb((int)((m_targetColor.r - m_initialColor.r) * get_coefficient() + m_initialColor.r),
                    (int)((m_targetColor.g - m_initialColor.g) * get_coefficient() + m_initialColor.g),
                    (int)((m_targetColor.b - m_initialColor.b) * get_coefficient() + m_initialColor.b));
}

void ColorAnimation::set_target_color(ALLEGRO_COLOR t_targetColor)
{
    m_targetColor = t_targetColor;
}

void ColorAnimation::set_initial_color(ALLEGRO_COLOR t_initialColor)
{
    m_initialColor = t_initialColor;
}

FadeoutColorAnimation::FadeoutColorAnimation(float t_duration, ALLEGRO_COLOR t_initialColor,
                    ALLEGRO_COLOR t_targetColor, float t_delayDuration) :
                    ColorAnimation(t_duration, t_initialColor, t_targetColor)
{
    m_timer = new Timer(t_delayDuration);
}

FadeoutColorAnimation::~FadeoutColorAnimation()
{
    delete m_timer;
}

void FadeoutColorAnimation::update()
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
    }
    
    m_timer->update();
}

void FadeoutColorAnimation::start()
{
    m_maxTime = m_duration * TPS;
    m_timer->reset();
    
}

bool FadeoutColorAnimation::is_finished()
{
    return (m_timer->is_finished() && m_time == 0);
}