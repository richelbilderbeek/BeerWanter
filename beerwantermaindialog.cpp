#include "beerwantermaindialog.h"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include <boost/lexical_cast.hpp>

ribi::BeerWanterMainDialog::BeerWanterMainDialog(
  int screen_width,
  int screen_height,
  int sprite_width,
  int sprite_height,
  int window_width,
  int window_height)
  :
    m_cursor_x{window_width  / 2},
    m_cursor_y{window_height / 2},
    m_level{1},
    m_screen_height(screen_height),
    m_screen_width(screen_width),
    m_sprite_height(sprite_height),
    m_sprite_width(sprite_width),
    m_sprite_x{(window_width  / 2) - (sprite_width  / 2)},
    m_sprite_y{(window_height / 2) - (sprite_height / 2)},
    m_window_height(window_height),
    m_window_width(window_width),
    m_window_x{(screen_width  / 2) - (window_width  / 2)},
    m_window_y{(screen_height / 2) - (window_height / 2)}
{

}

bool ribi::BeerWanterMainDialog::ClickWilBeSuccess() const
{
  return
       m_cursor_x >= m_sprite_x
    && m_cursor_x <= m_sprite_x + m_sprite_width
    && m_cursor_y >= m_sprite_y
    && m_cursor_y <= m_sprite_y + m_sprite_height
  ;
}

bool ribi::BeerWanterMainDialog::Click()
{
  if (ClickWilBeSuccess())
  {
    //Clicked the sprite
    //Move the sprite to a new random position
    m_sprite_x = std::rand() % (m_window_width  - m_sprite_width );
    m_sprite_y = std::rand() % (m_window_height - m_sprite_height);

    ++m_level;

    return true;
  }
  return false;
}

int ribi::BeerWanterMainDialog::GetRandomCursorShake() const
{
  return (std::rand() % (2*((m_level-1)/2)+1))
    - ((m_level-1)/2);
}

int ribi::BeerWanterMainDialog::GetRandomWindowShake() const
{
  return (std::rand() % (2*((m_level-1)/4)+1))
    - ((m_level-1)/4);
}

std::string ribi::BeerWanterMainDialog::GetWindowTitle() const
{
  return "BeerWanter (C) 2005-2016 Richel Bilderbeek. Beer gotten: "
    + boost::lexical_cast<std::string>(m_level - 1);
}

void ribi::BeerWanterMainDialog::SetCursorPos(const int x, const int y)
{
  m_cursor_x = x;
  m_cursor_y = y;
}

void ribi::BeerWanterMainDialog::ShakeCursor()
{
  //std::clog
  //  << "ShakeCursor: ("
  //  << m_cursor_x
  //  << ","
  //  << m_cursor_y
  //  << ") -> (";

  //Note that cursor is allowed to leave the window :-)
  m_cursor_x += GetRandomCursorShake();
  m_cursor_y += GetRandomCursorShake();

  //std::clog
  //  << m_cursor_x
  //  << ","
  //  << m_cursor_y
  //  << ")\n";
}

void ribi::BeerWanterMainDialog::ShakeWindow()
{
  m_window_x += GetRandomWindowShake();
  m_window_y += GetRandomWindowShake();
}
