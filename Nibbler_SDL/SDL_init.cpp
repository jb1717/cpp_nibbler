//
// SDL_init.cpp for Nibbler in /home/tran_0/rendu/cpp_nibbler
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Tue Mar 24 21:56:30 2015 David Tran
// Last update Thu Apr  2 20:26:55 2015 David Tran
//

# include "Nibbler_SDL.hpp"

extern "C"
{
  ILibGraph	*instanciate_lib()
  {
    return (new N_SDL());
  }
}

N_SDL::N_SDL()
{
  maxX = maxY = 0;
}

N_SDL::~N_SDL()
{}

bool		N_SDL::Init(int x, int y)
{
  maxX = x * 10;
  maxY = y * 10;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (false);
  if (!(screen = SDL_SetVideoMode(maxX, maxY, 32, SDL_HWSURFACE)))
    {
      SDL_Quit();
      return (false);
    }
  SDL_WM_SetCaption("cpp_Nibbler", NULL);
  return (true);
}

void		N_SDL::Destroy()
{
  SDL_Quit();
}

void		N_SDL::init_pos(int x, int y)
{
  SDL_Rect	tmp;

  /*  tmp.x = WIN_WIDTH / getMaxX() * x;
  tmp.y = WIN_HEIGHT / getMaxY() * y;
  tmp.w = WIN_WIDTH / getMaxX();
  tmp.h = WIN_HEIGHT / getMaxY();*/
  tmp.x = 10 * x;
  tmp.y = 10 * y;
  tmp.w = 10;
  tmp.h = 10;
  pos = tmp;
}

void		N_SDL::fill_point_rect(std::string const &it, int i, bool const apple)
{
  if (it[i] == 1)
    SDL_FillRect(screen, &pos, SDL_MapRGB(screen->format, 51, 204, 51));
  else if (it[i] == 2 && apple == true)
    SDL_FillRect(screen, &pos, SDL_MapRGB(screen->format, 251, 0, 0));
  else
    SDL_FillRect(screen, &pos, SDL_MapRGB(screen->format, 0, 0, 0));
}

bool		N_SDL::DrawMap(std::string const &pars, bool const apple)
{
  int		i;
  int		x;
  int		y;

  y = 0;
  i = 0;
  while (y < maxY / 10)
    {
      x = 0;
      while (x < maxX / 10)
	{
	  init_pos(x, y);
	  fill_point_rect(pars, i, apple);
	  x++;
	  i++;
	}
      y++;
    }
  SDL_Flip(screen);
  return (true);
}

bool		N_SDL::DrawQuadra(Map const &map)
{
  int		i;

  i = 0;
  while (i < map.getMaxX())
    {
      vlineColor(screen, (double)(maxX / 10 * i), 0, maxY, 0x696969);
      i++;
    }
  i = 0;
  while (i < map.getMaxY())
    {
      hlineColor(screen, 0, maxX, (double)(maxY / 10 * i), 0x696969);
      i++;
    }
  SDL_Flip(screen);
  return (true);
}

bool		N_SDL::DrawHUD()
{
  return (true);
}

char		N_SDL::HandleEvent()
{
  char		button;

  button = 0;
  while (SDL_PollEvent(&even))
    {
      if (even.type == SDL_QUIT)
	button = -1;
      if (even.type == SDL_KEYDOWN)
	{
	  if (even.key.keysym.sym == SDLK_ESCAPE)
	    button = -1;
	  else if (even.key.keysym.sym == SDLK_LEFT)
	    button = 1;
	  else if (even.key.keysym.sym == SDLK_RIGHT)
	    button = 2;
	}
    }
  return (button);
}