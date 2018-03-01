//
// reception.cpp for reception in /home/bechad_p/rendu/cpp_plazza/project/reception
// 
// Made by Pierre Bechade
// Login   <bechad_p@epitech.net>
// 
// Started on  Tue Apr  7 14:27:28 2015 Pierre Bechade
// Last update Sun Apr 26 22:49:15 2015 Caltraba Mickael
//

#include "reception.hpp"
#include "kitchen.hpp"

Reception::Reception(float mult, unsigned int nbCook, unsigned int time) :
  _multiplier(mult),
  _nbCooks(nbCook),
  _timeRegen(time)
{
  this->_mapType["regina"] = Regina;
  this->_mapType["margarita"] = Margarita;
  this->_mapType["americaine"] = Americaine;
  this->_mapType["fantasia"] = Fantasia;
  this->_mapSize["S"] = S;
  this->_mapSize["M"] = M;
  this->_mapSize["L"] = L;
  this->_mapSize["XL"] = XL;
  this->_mapSize["XXL"] = XXL;
}
Reception::Reception()
{
  this->_multiplier = 0;
  this->_nbCooks = 0;
  this->_timeRegen = 0;
  this->_mapType["regina"] = Regina;
  this->_mapType["margarita"] = Margarita;
  this->_mapType["americaine"] = Americaine;
  this->_mapType["fantasia"] = Fantasia;
  this->_mapSize["S"] = S;
  this->_mapSize["M"] = M;
  this->_mapSize["L"] = L;
  this->_mapSize["XL"] = XL;
  this->_mapSize["XXL"] = XXL;
}
Reception::~Reception()
{
  stop();
}
//_____________________

void	Reception::stop()
{
  std::list<std::pair<Communication, Communication> >::iterator	it = this->_fifo.begin();

  while (it != this->_fifo.end())
    {
      std::remove(it->first.getName().c_str());
     std::remove(it->second.getName().c_str());
      ++it;
    }
}

void		Reception::run()
{
  std::string	buff;
  bool		run = true;

  while (run)
    {
      if ((buff = readCommand()) == "quit")
	run = false;
      else
	{
	  try {
	    parseLine(buff);
	    findKitchen();
	  }
	  catch (std::invalid_argument const &e) {
	    std::cerr << e.what() << std::endl;
	  }
	  catch (std::out_of_range const &e) {
	    std::cerr << e.what() << std::endl;
	  }
	}
    }
}

void		Reception::findKitchen()
{
  std::list<std::pair<Communication, Communication> >::iterator	it = this->_fifo.begin();
  static unsigned int	id = 1;
  std::stringstream	tmp;
  std::istringstream	inn;
  int			i;

  while (this->_comand.empty() == false)
    {
      if (id == 1 || it == this->_fifo.end())
	{
	  try {
	    std::cout << "Plus de place je crée une kitchen" << std::endl;
	    createKitchen(id);
	    ++id;
	    it = this->_fifo.begin();
	  }
	  catch (std::runtime_error const& e) {
	    std::cerr << e.what() << std::endl;
	  }
	}
      else
	{
	  it->second.out("free");
	  inn.str(it->first.in());
	  inn >> i;
	  while (i > 0 && this->_comand.size() > 0)
	    {
	      tmp << this->_comand.front().getType() << " " <<
		this->_comand.front().getSize();
	      it->second.out(tmp.str());
	      std::cout << "J'envoie un pizza : " << tmp.str() << std::endl;
	      this->_comand.pop();
	      tmp.str("");
	      tmp.clear();
	      --i;
	      usleep(50000);
	    }
	  inn.str("");
	  inn.clear();
	  ++it;
	}
    }
}

void		Reception::createKitchen(unsigned int id)
{
  int			pid = -1;
  std::stringstream	ss_A;
  std::stringstream	ss_K;
  
  ss_A << "FIFO_A" << id;
  ss_K << "FIFO_K" << id;
  Communication		fifo_A(id, ss_A.str());
  Communication		fifo_K(id, ss_K.str());

  pid = fork();
  if (pid == -1)
    throw std::runtime_error("Error : Bad fork.");
  else if (pid == 0)
    {
      try {
	Kitchen	Kitchen(id, this->_multiplier, this->_nbCooks, this->_timeRegen, fifo_K, fifo_A);
      }
      catch (std::exception const& e) {
	std::cerr << e.what() << std::endl;
	std::exit(EXIT_FAILURE);
      }
    }
  this->_fifo.push_back(std::make_pair(fifo_A, fifo_K));
}

std::string	Reception::readCommand() const
{
  std::string	buff;

  getline(std::cin, buff);
  return (buff);
}

void	Reception::parseLine(std::string const &line)
{
  std::vector<std::string>	cmd;
  std::string			tmp;
  //  std::istringstream		clean;
  unsigned int			nb = 0;

  boost::algorithm::split(cmd, line, boost::is_any_of(";"),
			  boost::token_compress_on);
  for (std::vector<std::string>::const_iterator it = cmd.begin();
       it != cmd.end(); ++it)
    {
      std::vector<std::string>	tab;
      std::istringstream	clean(static_cast<std::string>(*it));

      while (clean >> tmp >> std::ws)
	tab.push_back(tmp);
      if (tab.size() != 3)
	throw std::invalid_argument("USAGE : [TYPE] [SIZE] [NUMBERS].");
      nb = parseNumbers(tab[2]);
      for (unsigned int i = 0; i != nb; ++i)
	{
	  Pizza			pizza(Regina, S, 1);

	  parsePizza(tab[0], pizza);
	  parseSize(tab[1], pizza);
	  pizza.setNumbers(1);
	  this->_comand.push(pizza);
	  std::cout << pizza.getType() << ", " << pizza.getSize() << ", " << pizza.getNb() << std::endl;
	}
    }
}

void	Reception::parsePizza(std::string const &type,
			      Pizza &pizza) const
{
  std::map<std::string, TypePizza>      tmp = this->_mapType;

  if (this->_mapType.find(type) == this->_mapType.end())
    throw std::invalid_argument("Error : [TYPE] = regina, margarita, ameriquaine, fantasia.");
  pizza.setType(tmp[type]);
}

void	Reception::parseSize(std::string const &size,
			     Pizza &pizza) const
{
  std::map<std::string, TaillePizza>    tmp = this->_mapSize;

  if (this->_mapSize.find(size) == this->_mapSize.end())
    throw std::invalid_argument("Error : [SIZE] = S, M, L, XL, XXL.");
  pizza.setSize(tmp[size]);
}
unsigned int	Reception::parseNumbers(std::string const &nb) const
{
  unsigned long	res;
  int		i;
  std::locale	loc;
  std::string	tmp = nb;

  i = 0;
  if (tmp[0] != 'x')
    throw std::invalid_argument("Error : [NUMBERS] Exemple : x1 or x5.");
  tmp.erase(0, 1);
  while (tmp[i] && isdigit(tmp[i], loc))
    ++i;
  if (i != static_cast<int>(tmp.size()))
    throw std::invalid_argument("Error : [NUMBERS] Exemple : x1 or x5.");
  std::stringstream(tmp) >> res;
  if (res < 1 || res > 4294967295)
    throw std::out_of_range("1 < [NUMBERS] < Beaucoup mais pas trop quand même (4294967296).");
  return (res);
}
