#include "../include/label.h"
#include "../include/constants.h"


Label::Label(const Point& t_coordinates, const Point& t_size, std::string t_text, ALLEGRO_FONT *t_font) :
            GUIComponent(t_coordinates, t_size), m_text(t_text), m_font(t_font)
{
}

Label::~Label()
{
}

void Label::change_text(const std::string &t_text)
{
    m_text = t_text;
}

void Label::render()
{
    al_draw_text(m_font, TEXT_COLOR.to_al_color(), 
                m_coordinates.x + m_size.x / 2, m_coordinates.y + (m_size.y - al_get_font_ascent(m_font)) / 2,
                 ALLEGRO_ALIGN_CENTRE, m_text.c_str());
}

void Label::update()
{
}