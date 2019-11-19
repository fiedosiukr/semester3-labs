#include "../include/button.h"

#include <allegro5/allegro_primitives.h>


Button::Button(const char *t_text, ALLEGRO_FONT *t_font,
            int t_x, int t_y, int t_width, int t_height) :
            m_font(t_font), m_x(t_x), m_y(t_y), 
            m_width(t_width), m_height(t_height)
{
    m_text = const_cast<char*>(t_text);

    m_colorAnimation = new ColorAnimation(HOVER_DURATION, BUTTON_COLOR, BUTTON_HOVER_COLOR);
}

void Button::render()
{
    al_draw_filled_rectangle(m_x, m_y, m_x + m_width, m_y + m_height, m_color);
    al_draw_text(m_font, TEXT_COLOR, m_x + m_width / 2, m_y + (m_height - al_get_font_ascent(m_font)) / 2, ALLEGRO_ALIGN_CENTRE, m_text);
}

void Button::update(int t_mouseX, int t_mouseY)
{
    if (!m_disabled) {
        m_hovered = (t_mouseX >= m_x && t_mouseX < m_x + m_width &&
                t_mouseY >= m_y && t_mouseY < m_y + m_height);
    }

    if (m_hovered) {
        m_colorAnimation->start();
    }
    else {
        m_colorAnimation->stop();
    }

    m_colorAnimation->update();

    m_color = m_colorAnimation->get_color();
}  
              
bool Button::is_hovered()
{
    return m_hovered;
}

void Button::set_disabled(bool t_disabled)
{
    m_disabled = t_disabled;

    if (m_disabled) {
        m_hovered = false;
        m_colorAnimation->set_initial_color(BUTTON_DISABLED_COLOR);
    } else {
        m_colorAnimation->set_initial_color(BUTTON_COLOR);
    }
}