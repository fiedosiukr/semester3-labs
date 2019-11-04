#include "../include/button.h"


#include <allegro5/allegro_primitives.h>


Button::Button(const char *t_text, ALLEGRO_FONT *t_font,
            int t_x, int t_y, int t_width, int t_height) :
            m_font(t_font), m_x(t_x), m_y(t_y), 
            m_width(t_width), m_height(t_height)
{
    m_text = const_cast<char*>(t_text);

    m_animations.emplace_back(new Animation(BUTTON_COLOR.r, BUTTON_HOVER_COLOR.r, HOVER_DURATION));
    m_animations.emplace_back(new Animation(BUTTON_COLOR.g, BUTTON_HOVER_COLOR.g, HOVER_DURATION));
    m_animations.emplace_back(new Animation(BUTTON_COLOR.b, BUTTON_HOVER_COLOR.b, HOVER_DURATION));
}

void Button::render()
{
    al_draw_filled_rectangle(m_x, m_y, m_x + m_width, m_y + m_height, m_color);
    al_draw_text(m_font, TEXT_COLOR, m_x + m_width / 2, m_y + (m_height - FONT_SIZE) / 2, ALLEGRO_ALIGN_CENTRE, m_text);
}

Button::~Button()
{
    int size = m_animations.size() - 1;
    for (int i = size; i >= 0; i--) {
        delete m_animations[i];
    }
}

void Button::update(int t_mouseX, int t_mouseY)
{
    m_hovered = (t_mouseX >= m_x && t_mouseX < m_x + m_width &&
                t_mouseY >= m_y && t_mouseY < m_y + m_height);

    if (m_hovered) {
        for (auto animation : m_animations) {
            animation->start();
        }
    }
    else {
        for (auto animation : m_animations) {
            animation->stop();
        }
    }

    for (auto animation : m_animations) {
        animation->update();
    }

    m_color = al_map_rgb((int) m_animations[0]->get_value(), (int) m_animations[1]->get_value(), (int) m_animations[2]->get_value());
    /*
    m_hovered ? m_maxTime = HOVER_DURATION * TPS : m_maxTime = 0;

    if (m_time != m_maxTime) {
        m_time < m_maxTime ? ++m_time : --m_time;
    }

    double scalar = (double)(m_time / (double)(HOVER_DURATION * TPS));


    m_color = al_map_rgb((int)(BUTTON_COLOR.r + (BUTTON_HOVER_COLOR.r - BUTTON_COLOR.r) * scalar),
                    (int)(BUTTON_COLOR.g + (BUTTON_HOVER_COLOR.g - BUTTON_COLOR.g) * scalar),
                    (int) (BUTTON_COLOR.b + (BUTTON_HOVER_COLOR.b - BUTTON_COLOR.b) * scalar));*/

}

bool Button::is_hovered() {
    
    return m_hovered;
}