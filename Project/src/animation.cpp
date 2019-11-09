#include "../include/animation.h"

#include "../include/constants.h"


void Animation::start()
{
    m_maxTime = m_duration * TPS;
}

void Animation::stop()
{
    m_maxTime = 0;
}

bool Animation::is_finished()
{
    return m_maxTime == m_time;
}

void Animation::update()
{
    if (m_time != m_maxTime) {
        m_time < m_maxTime ? ++m_time : --m_time;
    }
}

float Animation::get_value()
{
    return m_time / (m_duration * TPS) * (m_maximumValue - m_initialValue) + m_initialValue;
}