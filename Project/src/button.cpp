#include "../include/button.h"

#include <allegro5/allegro_primitives.h>


Button::Button(const Point& t_coordinates, const Point& t_size, std::string t_text, ALLEGRO_FONT *t_font) :
            GUIComponent(t_coordinates, t_size), m_text(t_text), m_font(t_font)
{
    m_colorAnimation = new Animation<Color>(HOVER_DURATION, &m_color, BUTTON_COLOR, BUTTON_HOVER_COLOR);
}

void Button::render()
{
    al_draw_filled_rectangle(m_coordinates.x, m_coordinates.y, m_coordinates.x + m_size.x, m_coordinates.y + m_size.y, m_color.to_al_color());
    al_draw_text(m_font, TEXT_COLOR.to_al_color(), m_coordinates.x + m_size.x / 2, m_coordinates.y + (m_size.y - al_get_font_ascent(m_font)) / 2, ALLEGRO_ALIGN_CENTRE, m_text.c_str());
}

void Button::update()
{
    if (!m_disabled && m_hovered) {
        m_colorAnimation->start();
    }
    else {
        m_colorAnimation->stop();
    }    

    m_colorAnimation->update();
}

void Button::check_events(ALLEGRO_EVENT& t_event)
{
    if (t_event.mouse.type == ALLEGRO_EVENT_MOUSE_AXES) {
        Point p(t_event.mouse.x, t_event.mouse.y);
        m_hovered = (p >= m_coordinates && p < m_coordinates + m_size);
    }
}
              

void Button::set_disabled(bool t_disabled)
{
    m_disabled = t_disabled;

    if (m_disabled) {
        m_hovered = false;
        m_colorAnimation->set_initial_value(BUTTON_DISABLED_COLOR);
    } else {
        m_colorAnimation->set_initial_value(BUTTON_COLOR);
    }
}