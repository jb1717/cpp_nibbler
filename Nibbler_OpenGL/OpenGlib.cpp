//
// OpenGlib.cpp for nibbler in /home/jibb/rendu/cpp_nibbler/src/class
//
// Made by Jean-Baptiste Grégoire
// Login   <gregoi_j@epitech.net>
//
// Started on  Wed Mar  25 18:29:42 2015 Jean-Baptiste Grégoire
// Last update Thu Apr  2 22:08:18 2015 Jean-Baptiste Grégoire
//

#include "OpenGlib.hpp"

extern "C"
{
  ILibGraph	*instanciate_lib()
  {
    return (new OpenGlib());
  }
}

bool		OpenGlib::Init(int x, int y)
{
  double	midx = static_cast<double>(x / 2.0);
  double	midy = static_cast<double>(y / 2.0);

  maxX = x;
  maxY = y;
  window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Nibbler -OpenGL-", sf::Style::Default, sf::ContextSettings(32));
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(WIN_FOVY, static_cast<double>(WIN_WIDTH / WIN_HEIGHT), NEAR, FAR);
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(midx, 30, 70,
	    midx, 0.5, midy + 20,
	    0, 1, 0);
  return (true);
}

bool		OpenGlib::DrawMap(Map const &map)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  drawWall(map.getMaxX(), map.getMaxY());
  drawGround(map);
  drawSnake(map);
  glFlush();
  window.display();
  return (true);
}

void		OpenGlib::Destroy()
{
  window.close();
}

bool		OpenGlib::DrawQuadra(Map const &map)
{
  return (true);
}

bool		OpenGlib::DrawHUD()
{
  return (true);
}

char		OpenGlib::HandleEvent()
{
  char		input;
  sf::Event	event;

  input = 0;
  while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
	  input = -1;
      if (event.type ==  sf::Event::KeyPressed)
	{
	  if (event.key.code == sf::Keyboard::Escape)
	    input = -1;
	  else if (event.key.code == sf::Keyboard::Left)
	    input = 1;
	  else if (event.key.code == sf::Keyboard::Right)
	    input = 2;
	  else
	    input = 0;
	}
    }
  return (input);
}

OpenGlib::~OpenGlib()
{

}