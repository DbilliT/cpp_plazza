//
// pizza.hpp for pizza in /home/bechad_p/rendu/cpp_plazza/project/pizza
// 
// Made by Pierre Bechade
// Login   <bechad_p@epitech.net>
// 
// Started on  Tue Apr  7 14:28:04 2015 Pierre Bechade
// Last update Fri Apr 24 17:53:03 2015 Caltraba Mickael
//

#ifndef __PIZZA_HPP__
# define __PIZZA_HPP__

#include <string>
#include <vector>

typedef enum	TypePizza
  {
    Regina = 1,
    Margarita = 2,
    Americaine = 4,
    Fantasia = 8
  }		TypePizza;

typedef enum	TaillePizza
  {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
  }		TaillePizza;

class Pizza
{
public:
  Pizza(TypePizza type, TaillePizza size, unsigned int number);
  ~Pizza();

  void		setType(TypePizza type);
  void		setSize(TaillePizza size);
  void		setNumbers(unsigned int numbers);

  TypePizza	getType() const;
  TaillePizza	getSize() const;
  unsigned int	getNb() const;
private:
  TypePizza	_type;
  TaillePizza	_size;
  unsigned int	_number;
};

#endif /* __PIZZA_HPP__ */
