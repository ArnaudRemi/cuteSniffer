/*
** MainScreen.h for SN in /home/orsini_a//SN
** 
** Made by antoine orsini
** Login   <orsini_a@epitech.net>
** 
** Started on  Fri Dec  5 17:24:50 2014 antoine orsini
** Last update Fri Dec  5 17:47:56 2014 antoine orsini
*/

#ifndef		__MAINSCREEN
# define	__MAINSCREEN

#include	<QTableWidgetItem>
#include	<QApplication>
#include	<QMessageBox>
#include	<QCheckBox>
#include	<QCloseEvent>
#include	<QCoreApplication>
#include    <QListWidget>
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
#include	<QTimer>
#include	<iostream>
#include	<fstream>
#include	<sstream>

#define _GNU_SOURCE     /* To get defns of NI_MAXSERV and NI_MAXHOST */
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/if_link.h>

#include "Interaction.hh"
#include "RawSocket.hh"
#include "Filter.hh"
#include "ContentFilter.hh"

class	FocusView;

class	MainScreen : public QMainWindow
{
  Q_OBJECT

    typedef enum
  {
    Quit,
    Capture,
    Filtre,
    Forge,
    Man,
    Modif
  } EBouton;

  QTimer *timer;
  RawSocket socket;

    QListWidget *  ifList;

    std::list<Filter*> *filters;

 public:

  MainScreen(QWidget *parent = 0);
  void	repop();

  public slots:

  void	quit();
  void	capture();
  void	filtring();
  void	forging();
  void	manInMiddle();
  void	modifier();
  void	cellSelected(int, int);
  void getPacket();


private:
  void	init();
  //  void	checkUser();
  void	fillInfo();
    std::list<std::string> *getAllInterfaces();

  void	addButon(int,int,const QString &, int);
  void	addItem(const QString&, int, int);
  void	addLabel(int, int, QString);
  void addList(int x, int y, std::list<std::string> *lstr);

  void	connectQuit(QPushButton*);
  void	connectCapture(QPushButton*);
  void	connectFiltre(QPushButton*);
  void	connectForge(QPushButton*);
  void	connectMan(QPushButton*);
  void	connectModif(QPushButton*);

  QPushButton*	_confirm;
  QPushButton*	_cancel;
  QTableWidget*	_table;
  std::list<Interaction* >	_mylist;

private slots:
    void itemClicked(QListWidgetItem* item);
};

#endif		/*MAINSCREEN*/
