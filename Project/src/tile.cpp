#include "../include/tile.h"

#include "../include/constants.h"

#include <allegro5/allegro_primitives.h>

#include <iostream>


Tile::Tile()
{
    m_colorAnimation = new FadeoutColorAnimation(0.2, BUTTON_COLOR, BUTTON_HOVER_COLOR, 0.5);
    m_animation = new Animation(0.5);
}

Tile::~Tile()
{
    delete m_colorAnimation;
    delete m_animation;
}

void Tile::blink(ALLEGRO_COLOR t_color)
{
    m_colorAnimation->set_target_color(t_color);
    m_colorAnimation->start();
}

void Tile::render()
{
    al_draw_filled_rectangle(m_x - (1 - m_animation->get_coefficient()) * m_width / 2,
                            m_y - (1 - m_animation->get_coefficient()) * m_height / 2,
                            m_x + (1 - m_animation->get_coefficient()) * m_width / 2, 
                            m_y + (1 - m_animation->get_coefficient()) * m_height / 2, m_color);
}

void Tile::update(int t_mouseX, int t_mouseY)
{
    m_hovered = (t_mouseX >= m_x - m_width / 2 && t_mouseX < m_x + m_width / 2 &&
                t_mouseY >= m_y - m_height / 2 && t_mouseY < m_y + m_height / 2);

    m_colorAnimation->update();
    m_animation->update();

    if (m_animation->is_finished()) {
        m_width = m_targetWidth;
        m_height = m_targetHeight;
        m_x = m_targetX;
        m_y = m_targetY;
        m_animation->stop();
    }

    m_color = m_colorAnimation->get_color();
}

void Tile::set_location(int t_x, int t_y, bool m_animate)
{
    if (m_animate) {
        m_targetX = t_x;
        m_targetY = t_y;
        m_animation->start();
    }
    else {
        m_x = t_x;
        m_y = t_y;
    }
}

void Tile::set_size(int t_width, int t_height, bool m_animate)
{
    if (m_animate) {
        m_targetWidth = t_width;
        m_targetHeight = t_height;
        m_animation->start();
    }
    else {
        m_width = t_width;
        m_height = t_height;
    }
}

bool Tile::is_hovered()
{
    return m_hovered;
}

bool Tile::is_blinking()
{
    return !m_colorAnimation->is_finished();
}

bool Tile::is_changing_size()
{
    return m_animation->get_coefficient() != 0;
}