//
// pizza.cpp for pizza in /home/bechad_p/rendu/cpp_plazza/project/pizza
// 
// Made by Pierre Bechade
// Login   <bechad_p@epitech.net>
// 
// Started on  Tue Apr  7 14:29:32 2015 Pierre Bechade
// Last update Fri Apr 24 17:53:21 2015 Caltraba Mickael
//

#include "pizza.hpp"

Pizza::Pizza(TypePizza type, TaillePizza size, unsigned int number) : _type(type), _size(size), _number(number) {
}

Pizza::~Pizza() {
}

void		Pizza::setType(TypePizza type) { this->_type = type;}
void		Pizza::setSize(TaillePizza size) { this->_size = size;}
void		Pizza::setNumbers(unsigned int numbers) { this->_number = numbers;}

TypePizza	Pizza::getType() const { return (this->_type);} 
TaillePizza	Pizza::getSize() const { return (this->_size);}
unsigned int	Pizza::getNb() const { return (this->_number);}
