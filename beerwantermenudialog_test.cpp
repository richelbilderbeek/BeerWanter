#include <boost/test/unit_test.hpp>
#include "beerwantermenudialog.h"

BOOST_AUTO_TEST_CASE(BeerWanterMenuDialog_call_getters)
{
  const ribi::BeerWanterMenuDialog d;
  BOOST_CHECK(!d.GetAbout().GetVersion().empty());
  BOOST_CHECK(!d.GetHelp().GetVersion().empty());
  BOOST_CHECK(!d.GetVersion().empty());
  BOOST_CHECK(!d.GetVersionHistory().empty());
}

BOOST_AUTO_TEST_CASE(BeerWanterMenuDialog_run)
{
  ribi::BeerWanterMenuDialog d;
  d.Execute( {"BeerWanter"} );
}
