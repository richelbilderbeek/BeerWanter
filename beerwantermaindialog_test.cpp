#include <boost/test/unit_test.hpp>
#include "beerwantermaindialog.h"
#include "fileio.h"
#include <QFile>

BOOST_AUTO_TEST_CASE(BeerWanterMainDialog_test)
{
  const int screen_width = 640;
  const int screen_height = 400;
  const int sprite_width = 32;
  const int sprite_height = 48;
  const int window_width = 320;
  const int window_height = 200;

  ribi::BeerWanterMainDialog d(
    screen_width,
    screen_height,
    sprite_width,
    sprite_height,
    window_width,
    window_height
  );
  BOOST_CHECK(d.GetWindowWidth() == window_width);
  BOOST_CHECK(d.GetWindowHeight() == window_height);
  BOOST_CHECK(d.GetSpriteWidth() == sprite_width);
  BOOST_CHECK(d.GetSpriteHeight() == sprite_height);
}

BOOST_AUTO_TEST_CASE(BeerWanterMainDialog_check_resources)
{
  const ribi::FileIo f;
  const std::string filename { f.GetTempFileName(".png") };
  QFile qfile(ribi::BeerWanterMainDialog::GetResourceFilename().c_str());
  qfile.copy(filename.c_str());
  BOOST_CHECK(f.IsRegularFile(filename));
  f.DeleteFile(filename);
  BOOST_CHECK(!f.IsRegularFile(filename));
}
