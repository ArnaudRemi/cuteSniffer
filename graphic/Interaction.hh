/*
** Interaction.h for SN in /home/orsini_a//SN
** 
** Made by antoine orsini
** Login   <orsini_a@epitech.net>
** 
** Started on  Wed Dec  3 19:36:07 2014 antoine orsini
** Last update Wed Dec  3 19:48:06 2014 antoine orsini
*/

#include	<string>

#ifndef		__INTERACTION
# define	__INTERACTION

class	Interaction
{

 public:
  Interaction(std::string, std::string);
  ~Interaction();

  std::string	getName();
  std::string	getPort();

 private:

  std::string	_name;
  std::string	_port;
};

#endif		/*__INTERACTION*/
