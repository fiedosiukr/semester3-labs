#include "constants.h"


class GUIComponent
{
    public:
        virtual void update() = 0;
        virtual void render() = 0;

    protected:
        GUIComponent(const Point& t_coordinates, const Point& t_size) :
                    m_coordinates(t_coordinates), m_size(t_size) {}

        Point m_coordinates;
        Point m_size;
};