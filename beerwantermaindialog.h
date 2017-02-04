#ifndef BEERWANTERMAINDIALOG_H
#define BEERWANTERMAINDIALOG_H

#include <string>
#include <vector>

namespace ribi {

///BeerWanterMainDialog contains the logic behind the game BeerWanter
struct BeerWanterMainDialog
{
  BeerWanterMainDialog(
    int screen_width,
    int screen_height,
    int sprite_width,
    int sprite_height,
    int window_width,
    int window_height);

  ///Click is called when the user presses a key. The bool returned
  ///indicates whether the user successfully clicked on a beer
  bool Click();

  bool ClickWilBeSuccess() const;
  int GetCursorX() const noexcept { return m_cursor_x; }
  int GetCursorY() const noexcept { return m_cursor_y; }
  int GetLevel() const noexcept { return m_level; }
  static std::string GetResourceFilename() noexcept {
    return ":/GameBeerWanter/images/PicBeer.png";
  }
  int GetSpriteX() const noexcept { return m_sprite_x; }
  int GetSpriteY() const noexcept { return m_sprite_y; }
  int GetSpriteHeight() const noexcept { return m_sprite_height; }
  int GetSpriteWidth()  const noexcept { return m_sprite_width ; }
  int GetWindowHeight() const noexcept { return m_window_height; }
  std::string GetWindowTitle() const;
  int GetWindowWidth()  const noexcept { return m_window_width ; }
  int GetWindowX() const noexcept { return m_window_x; }
  int GetWindowY() const noexcept { return m_window_y; }
  void SetArenaSize(const int width, const int height);
  void SetCursorPos(const int x, const int y);
  void SetSpriteSize(const int width, const int height);

  ///ShakeCursor shakes the cursor
  void ShakeCursor();

  ///ShakeWindow shakes the window (on desktop computer only)
  void ShakeWindow();
  void Tick();

  private:
  int m_cursor_x;
  int m_cursor_y;
  int m_level;
  const int m_screen_height;
  const int m_screen_width;
  const int m_sprite_height;
  const int m_sprite_width;
  int m_sprite_x;
  int m_sprite_y;
  const int m_window_height;
  const int m_window_width;
  int m_window_x;
  int m_window_y;

  int GetRandomCursorShake() const;
  int GetRandomWindowShake() const;
};

} //~namespace ribi

#endif // BEERWANTERMAINDIALOG_H
