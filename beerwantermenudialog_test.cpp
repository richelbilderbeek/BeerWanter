#include <boost/test/unit_test.hpp>
#include "beerwantermaindialog.h"
#include "fileio.h"
#include <QFile>

BOOST_AUTO_TEST_CASE(BeerWanterMenuDialog_check_resources)
{
  const ribi::FileIo f;
  const std::string filename { f.GetTempFileName(".png") };
  QFile qfile(ribi::BeerWanterMainDialog::GetResourceFilename().c_str());
  qfile.copy(filename.c_str());
  BOOST_CHECK(f.IsRegularFile(filename));
  f.DeleteFile(filename);
  BOOST_CHECK(!f.IsRegularFile(filename));
}
