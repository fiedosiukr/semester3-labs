#ifndef ANIMATION_H
#define ANIMATION_H

class Animation
{
    public:
        Animation(float t_initialValue, float t_maximumValue, float t_duration) :
            m_initialValue(t_initialValue), m_maximumValue(t_maximumValue), m_duration(t_duration) {}
        ~Animation() {}

        void start();
        void stop();
        bool is_finished();
        void update();
        float get_value();

    private:
        float m_initialValue;
        float m_maximumValue;
        float m_duration;
        int m_time{0};
        int m_maxTime{0};
};

#endif