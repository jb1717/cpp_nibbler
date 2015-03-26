//
// Map.hpp for Nibbler in /home/tran_0/rendu/cpp_nibbler
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Wed Mar 25 14:27:26 2015 David Tran
// Last update Wed Mar 25 16:34:16 2015 David Tran
//

#ifndef MAP_HPP_
# define MAP_HPP_

# include "nibbler.hpp"
# include "Snake.hpp"

class	MAP
{
public:
  MAP(int x, int y) : maxX(x), maxY(y){}
  ~MAP();
  bool		genObj();
  void		setPts(int const objID);
  void		setCoord(int const x, int const y);
  int		getMaxX() const;
  int		getMaxY() const;
private:
  std::string	Map;
  int		Pts;
  bool		apple;
  size_t	time;
  Snake		snake;
  int		maxX;
  int		maxY;
};

#endif