#include "../include/label.h"

#include "../include/constants.h"


Label::Label(char *t_text, ALLEGRO_FONT *t_font, int t_x, int t_y, int t_width, int t_height) :
    m_text(t_text), m_font(t_font), m_x(t_x), m_y(t_y), m_width(t_width), m_height(t_height)
{
    m_animation = new Animation(0.5);
}

Label::~Label()
{
    delete m_animation;
}

void Label::change_text(char* t_text)
{
    delete m_text;
    m_text = t_text;
}

void Label::render()
{
    al_draw_text(m_font, TEXT_COLOR, m_x + m_width / 2, m_y + (m_height - al_get_font_ascent(m_font)) / 2, ALLEGRO_ALIGN_CENTRE, m_text);
}

void Label::update()
{
    m_animation->update();
}