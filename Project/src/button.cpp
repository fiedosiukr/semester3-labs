#include "../include/button.h"

#include <allegro5/allegro_primitives.h>


Button::Button(const char *t_text, ALLEGRO_FONT *t_font,
            int t_x, int t_y, int t_width, int t_height) :
            m_font(t_font), m_x(t_x), m_y(t_y), 
            m_width(t_width), m_height(t_height)
{
    m_text = const_cast<char*>(t_text);

    m_animations.emplace_back(new Animation(HOVER_DURATION, BUTTON_COLOR.r, BUTTON_HOVER_COLOR.r));
    m_animations.emplace_back(new Animation(HOVER_DURATION, BUTTON_COLOR.g, BUTTON_HOVER_COLOR.g));
    m_animations.emplace_back(new Animation(HOVER_DURATION, BUTTON_COLOR.b, BUTTON_HOVER_COLOR.b));
}

void Button::render()
{
    al_draw_filled_rectangle(m_x, m_y, m_x + m_width, m_y + m_height, m_color);
    al_draw_text(m_font, TEXT_COLOR, m_x + m_width / 2, m_y + (m_height - FONT_SIZE) / 2, ALLEGRO_ALIGN_CENTRE, m_text);
}

Button::~Button()
{
    for (auto animation : m_animations) {
        delete animation;
    }
}

void Button::update(int t_mouseX, int t_mouseY)
{
    m_hovered = (t_mouseX >= m_x && t_mouseX < m_x + m_width &&
                t_mouseY >= m_y && t_mouseY < m_y + m_height);

    if (m_hovered) {
        for (int i = 0; i < 3; i++)
            m_animations[i]->start();
    }
    else {
        for (int i = 0; i < 3; i++)
            m_animations[i]->stop();
    }

    for (int i = 0; i < 3; i++)
        m_animations[i]->update();

    m_color = al_map_rgb((int) m_animations[0]->get_value(), (int) m_animations[1]->get_value(), (int) m_animations[2]->get_value());
}

bool Button::is_hovered()
{
    return m_hovered;
}