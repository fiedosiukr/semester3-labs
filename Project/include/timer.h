#ifndef TIMER_H
#define TIMER_H

class Timer
{
    public:
        Timer(float);
        virtual void start();
        virtual void stop();
        virtual void update();
        virtual bool is_finished();
        virtual void reset();
        virtual void reset_time();
    
    protected:
        int m_time{0};
        int m_maxTime{0};
        float m_duration;
};

#endif