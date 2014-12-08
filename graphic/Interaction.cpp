//
// Interaction.cpp for SN in /home/orsini_a//SN
// 
// Made by antoine orsini
// Login   <orsini_a@epitech.net>
// 
// Started on  Wed Dec  3 19:35:10 2014 antoine orsini
// Last update Wed Dec  3 19:43:18 2014 antoine orsini
//

#include	"Interaction.h"

Interaction::Interaction(std::string name, std::string port) : _name(name), _port(port)
{
}

std::string	Interaction::getName()
{
  return (this->_name);
}

std::string	Interaction::getPort()
{
  return (this->_port);
}
