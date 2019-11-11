#include "../include/timer.h"

#include "../include/constants.h"


Timer::Timer(float t_duration) : m_duration{t_duration}
{
}

void Timer::start()
{
    m_maxTime = m_duration * TPS;
}

void Timer::stop()
{
    m_maxTime = 0;
}

void Timer::update()
{
    if (m_time != m_maxTime) {
        m_time < m_maxTime ? m_time++ : m_time--;
    }
}

bool Timer::is_finished()
{
    if (m_time != 0) {
        return m_maxTime == m_time;
    }

    return false;
}

void Timer::reset()
{
    m_time = 0;
    m_maxTime = 0;
}

void Timer::reset_time()
{
    m_time = 0;
}