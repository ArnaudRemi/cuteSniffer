/*
** FocusView.h for SN in /home/orsini_a//SN
** 
** Made by antoine orsini
** Login   <orsini_a@epitech.net>
** 
** Started on  Fri Dec  5 17:20:11 2014 antoine orsini
** Last update Fri Dec  5 17:57:10 2014 antoine orsini
*/

#ifndef		__FOCUSVIEW
# define	__FOCUSVIEW

#include	<QTableWidgetItem>
#include	<QApplication>
#include	<QMessageBox>
#include	<QCheckBox>
#include	<QCloseEvent>
#include	<QCoreApplication>
#include	<QTableWidget>
#include	<QFile>
#include	<QTextStream>
#include	<QtGui>
#include	<QLabel>
#include	<QObject>
#include	<QProcess>
#include	<QPushButton>
#include	<QWidget>
#include	<string>
#include	<iostream>
#include	<fstream>
#include	<sstream>

#include "Interaction.hh"

class	MainScreen;

class	FocusView : public QMainWindow
{
  Q_OBJECT

    public:

  FocusView(Interaction*, MainScreen*);
  //  ~FocusView();
  void	init();

  public slots:
  
  void	quit();
 
 private:

  void	addButon(int, int, const QString&, int);
  void	addLabel(int x, int y, QString text);
  void	connectQuit(QPushButton*);

  Interaction*	_inter;
  MainScreen*	_mainVi;
};

#endif		/*__FOCUSVIEW*/
