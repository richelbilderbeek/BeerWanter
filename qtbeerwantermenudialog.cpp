//---------------------------------------------------------------------------
/*
BeerWanter. A simple game.
Copyright (C) 2005-2016 Richel Bilderbeek

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.If not, see <http://www.gnu.org/licenses/>.
*/
//---------------------------------------------------------------------------
//From http://www.richelbilderbeek.nl/GameBeerWanter.htm
//---------------------------------------------------------------------------


#include "qtbeerwantermenudialog.h"

#include "beerwantermenudialog.h"
#include "qtaboutdialog.h"
#include "qtbeerwantermaindialog.h"
#include "ui_qtbeerwantermenudialog.h"




ribi::QtBeerWanterMenuDialog::QtBeerWanterMenuDialog(QWidget *parent) :
  QtHideAndShowDialog(parent),
  ui(new Ui::QtBeerWanterMenuDialog)
{
  ui->setupUi(this);
}

ribi::QtBeerWanterMenuDialog::~QtBeerWanterMenuDialog() noexcept
{
  delete ui;
}

void ribi::QtBeerWanterMenuDialog::on_button_start_clicked() noexcept
{
  QtBeerWanterMainDialog d;
  this->ShowChild(&d);
}

void ribi::QtBeerWanterMenuDialog::on_button_about_clicked() noexcept
{
  About a = BeerWanterMenuDialog().GetAbout();
  a.AddLibrary("QtHideAndShowDialog version: " + QtHideAndShowDialog::GetVersion());
  QtAboutDialog d(a);
  d.setStyleSheet(this->styleSheet());
  d.setWindowIcon(this->windowIcon());
  this->ShowChild(&d);
}

void ribi::QtBeerWanterMenuDialog::on_button_quit_clicked() noexcept
{
  close();
}
