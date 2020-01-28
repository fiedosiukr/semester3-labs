#ifndef GUI_COMPONENT_H
#define GUI_COMPONENT_H

#include "constants.h"


class GUIComponent
{
    public:
        virtual void update() = 0;
        virtual void render() = 0;
        virtual void check_events(ALLEGRO_EVENT&) = 0;
        bool is_hovered() { return m_hovered; }
        bool is_focused() { return m_focused; }
        bool is_disabled() { return m_disabled; }
        virtual void set_disabled(bool t_disabled) { m_disabled = t_disabled; }
        virtual void set_hovered(bool t_hovered) { m_hovered = t_hovered; }
        virtual void set_focused(bool t_focused) { m_focused = t_focused; }

    protected:
        GUIComponent(const Point& t_coordinates, const Point& t_size) :
                    m_coordinates(t_coordinates), m_size(t_size) {}

        Point m_coordinates;
        Point m_size;

        bool m_hovered{false};
        bool m_focused{false};
        bool m_disabled{false};
};

#endif