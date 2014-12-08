//
// FocusView.cpp for SN in /home/orsini_a//SN
// 
// Made by antoine orsini
// Login   <orsini_a@epitech.net>
// 
// Started on  Fri Dec  5 17:19:58 2014 antoine orsini
// Last update Fri Dec  5 18:04:15 2014 antoine orsini
//

#include	"MainScreen.h"
#include	"FocusView.h"

FocusView::FocusView(Interaction* inter, MainScreen* mainView) : _inter(inter), _mainVi(mainView)
{
}

void	FocusView::init()
{
  this->setWindowTitle("Info");
  this->setFixedSize(600, 600);
  this->addButon(185, 500, "Quit", 0);
  this->addLabel(100, 100, "Name : " + QString(_inter->getName().c_str()));
  this->addLabel(100, 200, "Port : " + QString(_inter->getPort().c_str()));
  this->show();
}

void	FocusView::addButon(int x, int y, const QString & text, int who)
{
  void (FocusView::*ptr[1])(QPushButton *) = { &FocusView::connectQuit/*,
					       &FocusView::connectCapture,
					       &FocusView::connectFiltre,
					       &FocusView::connectForge,
					       &FocusView::connectMan,
					       &FocusView::connectModif*/};
  QPushButton	*m_bouton	=	new QPushButton(text, this);
  QPalette	pal		=	m_bouton->palette();

  m_bouton->setCursor(Qt::PointingHandCursor);
  m_bouton->setGeometry(x, y, 230, 50);
  m_bouton->setFont(QFont("Arial", 25));
  (this->*ptr[who])(m_bouton);
  m_bouton->show();
}


void    FocusView::addLabel(int x, int y, QString text)
{
  QLabel *myLabel = new QLabel(this);
  QPalette pal = myLabel->palette();

  myLabel->move(x, y);
  myLabel->setAutoFillBackground(true);
  myLabel->setText(text);
  myLabel->setPalette(pal);
  myLabel->show();
}


void	FocusView::connectQuit(QPushButton* bouton)
{
  QObject::connect(bouton, SIGNAL(clicked()), this, SLOT(quit()));
}

void	FocusView::quit()
{
  _mainVi->repop();
  this->close();
}
