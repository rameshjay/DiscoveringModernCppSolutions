#include <SDL2/SDL.h>
#include <SDL2/SDL_assert.h>
#include <SDL2/SDL_stdinc.h>
#include <cstdlib>
#include <cstdint>
#include <cassert>
#include <complex>
#include <iostream>

using namespace std;

class mandel_pixel {
public:
  mandel_pixel(SDL_Surface *screen, int x, int y, int xdim, int ydim,
               int max_iter)
      : screen(screen), max_iter(max_iter), iter(0), c(x, y) {

    // scale y to [-1.2,1.2]
    c *= 2.4 / ydim;

    c -= complex<double>(1.2 * xdim / ydim + 0.5,
                         1.2); // shift -0.5+0i to the center

    iterate();
  }

  uint32_t color() const {

    if (iter == max_iter) {
      return SDL_MapRGB(screen->format, 0, 0, 0);
    }

    const int ci = 512 * iter / max_iter; // incremental value for color

    if (iter < max_iter / 2) {
      return SDL_MapRGB(screen->format, ci, 0, 0);
    } else {
      return SDL_MapRGB(screen->format, 255, ci - 255, ci - 255);
    }
  }

private:
  void iterate() {
    complex<double> z = c;

    while (iter < max_iter && norm(z) <= 4.0) {
      z = z * z + c;
      iter++;
    }
  };

  SDL_Surface *screen;
  const int max_iter;
  int iter;
  complex<double> c;
};

void put_pixel(SDL_Surface *screen, int x, int y, uint32_t pixel) {
  auto pixel_address =
      reinterpret_cast<uint32_t *>(screen->pixels) + y * screen->w + x;

  *pixel_address = pixel;
}

int main() {
  const int max_iter = 30;
  int xdim = 1200, ydim = 800;

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cerr << "video module not initialized ";
  }

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
  Uint32 rmask = 0xff000000;
  Uint32 gmask = 0x00ff0000;
  Uint32 bmask = 0x0000ff00;
  Uint32 amask = 0x000000ff;
#else
  Uint32 rmask = 0x000000ff;
  Uint32 gmask = 0x0000ff00;
  Uint32 bmask = 0x00ff0000;
  Uint32 amask = 0xff000000;
#endif

  // https://wiki.libsdl.org/SDL_CreateRGBSurface#SDL_CreateRGBSurface-1
  //
  SDL_Surface *screen =
      SDL_CreateRGBSurface(0, xdim, ydim, 32, rmask, gmask, bmask, amask);

  if (screen == nullptr) {
    std::cerr << "screen not initialized ";
  }

  SDL_LockSurface(screen);

  for (int y = 0; y < ydim; ++y) {
    for (int x = 0; x < xdim; ++x) {
      mandel_pixel m(screen, x, y, xdim, ydim, max_iter);
      put_pixel(screen, x, y, m.color());
    }
  }

  SDL_UnlockSurface(screen);

  SDL_SaveBMP(screen, "mandelbrot.bmp");

  SDL_FreeSurface(screen);

  SDL_Quit();
}

