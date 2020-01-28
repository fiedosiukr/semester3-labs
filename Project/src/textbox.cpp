#include "../include/textbox.h"

#include <allegro5/allegro_primitives.h>


TextBox::TextBox(const Point& t_coordinates, const Point& t_size, ALLEGRO_FONT *t_font) :
                GUIComponent(t_coordinates, t_size), m_font(t_font)
{
    m_colorAnimation = new Animation<Color>(HOVER_DURATION - 0.1, &m_color, TEXTBOX_COLOR, TEXTBOX_FOCUS_COLOR);
}

TextBox::~TextBox()
{
    delete m_colorAnimation;
}

void TextBox::update()
{
    m_focused ? m_colorAnimation->start() : m_colorAnimation->stop();

    m_colorAnimation->update();
}

void TextBox::render()
{
    al_draw_filled_rectangle(m_coordinates.x, m_coordinates.y, m_coordinates.x + m_size.x, m_coordinates.y + m_size.y, m_color.to_al_color());
    al_draw_text(m_font, TEXT_COLOR.to_al_color(), m_coordinates.x + 20, m_coordinates.y + (m_size.y - al_get_font_ascent(m_font)) / 2, ALLEGRO_ALIGN_LEFT, m_text.c_str());

    if (m_focused) {
        al_draw_filled_rectangle(m_coordinates.x + TEXTBOX_OFFSET + al_get_text_width(m_font, m_text.c_str()),
                                m_coordinates.y + (m_size.y - al_get_font_line_height(m_font)) / 2,
                                m_coordinates.x + TEXTBOX_OFFSET + al_get_text_width(m_font, m_text.c_str()) + FOCUS_LINE_WIDTH,
                                m_coordinates.y + (m_size.y - al_get_font_line_height(m_font)) / 2 + al_get_font_line_height(m_font),
                                FOCUS_LINE_COLOR.to_al_color());
    }
}

void TextBox::check_events(ALLEGRO_EVENT &t_event)
{
    if (m_focused) {
        if (t_event.keyboard.type == ALLEGRO_EVENT_KEY_CHAR) {
		    if (t_event.keyboard.keycode == ALLEGRO_KEY_BACKSPACE) {
                if (m_text.size() > 0)
		    	m_text.pop_back();
		    } else if (((t_event.keyboard.keycode >= ALLEGRO_KEY_A && t_event.keyboard.keycode <= ALLEGRO_KEY_9) ||
                        t_event.keyboard.keycode == ALLEGRO_KEY_SPACE) && m_text.size() < MAX_TEXT_LENGTH) {
            	m_text += (char) t_event.keyboard.unichar;
		    }
        }
    }

    if (t_event.type == ALLEGRO_EVENT_MOUSE_AXES) {
        Point p(t_event.mouse.x, t_event.mouse.y);
        m_hovered = (p >= m_coordinates && p < m_coordinates + m_size);
    } else if (t_event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && t_event.mouse.button == 1) {
        m_focused = m_hovered;
    }
}