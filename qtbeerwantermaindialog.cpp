#include "qtbeerwantermaindialog.h"

#include <iostream>

#include "beerwantermaindialog.h"
#include "qtbeerwanterwidget.h"

#include "ui_qtbeerwantermaindialog.h"

ribi::QtBeerWanterMainDialog::QtBeerWanterMainDialog(QWidget *parent)
  : QtHideAndShowDialog(parent),
    ui(new Ui::QtBeerWanterMainDialog),
    m_widget(new QtBeerWanterWidget)
{
  ui->setupUi(this);
  ui->beerwanter_layout->addWidget(m_widget.get());
  this->setGeometry(
    m_widget->GetBeerWanter()->GetWindowX(),
    m_widget->GetBeerWanter()->GetWindowY(),
    m_widget->GetBeerWanter()->GetWindowWidth(),
    m_widget->GetBeerWanter()->GetWindowHeight()
  );

  QObject::connect(
    m_widget.get(),
    SIGNAL(LevelUp(const std::string&)),
    this,
    SLOT(ChangeTitle(const std::string&))
  );
  QObject::connect(
    m_widget.get(),
    SIGNAL(DoShake(const int,const int)),
    this,
    SLOT(OnShake(const int, const int))
  );
}

ribi::QtBeerWanterMainDialog::~QtBeerWanterMainDialog() noexcept
{
  delete ui;
}

void ribi::QtBeerWanterMainDialog::ChangeTitle(const std::string& title) noexcept
{
  this->setWindowTitle(title.c_str());
}

void ribi::QtBeerWanterMainDialog::OnShake(const int x, const int y) noexcept
{
  this->setGeometry(x, y, this->width(), this->height());
  this->repaint();
}
