#include "../include/tile.h"

#include "../include/constants.h"

#include <allegro5/allegro_primitives.h>

#include <iostream>


Tile::Tile()
{
    m_colorAnimation = new FadeoutAnimation<Color>(0.2, &m_color, BUTTON_COLOR, BUTTON_HOVER_COLOR, 0.5);
    m_animation = new Animation<Point>(0.5, &m_size, {0, 0}, {0, 0});
}

Tile::~Tile()
{
    delete m_colorAnimation;
    delete m_animation;
}

void Tile::blink(Color t_color)
{
    m_colorAnimation->set_target_value(t_color);
    m_colorAnimation->start();
}

void Tile::render()
{
    al_draw_filled_rectangle(m_coordinates.x - m_size.x / 2, m_coordinates.y - m_size.y / 2,
                            m_coordinates.x + m_size.x / 2, m_coordinates.y + m_size.y / 2, m_color.to_al_color());
}

void Tile::update(int t_mouseX, int t_mouseY)
{
    m_hovered = (t_mouseX >= m_coordinates.x - m_size.x / 2 && t_mouseX < m_coordinates.x + m_size.x / 2 &&
                t_mouseY >= m_coordinates.y - m_size.y / 2 && t_mouseY < m_coordinates.y + m_size.y / 2);

    if (m_animation->is_finished()) {
        m_size = m_targetSize;
        m_animation->set_initial_value(m_size);
        m_coordinates = m_targetCoordinates;
        m_animation->stop();
    }

    m_colorAnimation->update();
    m_animation->update();

    
}

void Tile::set_location(int t_x, int t_y, bool m_animate)
{
    if (m_animate) {
        m_targetCoordinates = {t_x, t_y};
    }
    else {
        m_coordinates = {t_x, t_y};
    }
}

void Tile::set_size(int t_width, int t_height, bool m_animate)
{
    if (m_animate) {
        m_targetSize = {t_width, t_height};
        m_animation->set_initial_value(m_size);
        m_animation->start();
    }
    else {
        m_size = {t_width, t_height};
        m_animation->set_initial_value(m_size);
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
    return (m_targetSize == m_size);
}