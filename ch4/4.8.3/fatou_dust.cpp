#include <SDL2/SDL.h>
#include <cstdint>
#include <complex>
#include <iostream>

struct mandel_pixel {
public:
  mandel_pixel(SDL_Surface *screen, int x, int y, int xdim, int ydim) {
    c = std::complex<double>(x, y);
    m_screen = screen;

    c *= 2.4 / ydim; // scale y to [-1.2,1.2]

    c -= std::complex<double>((1.2 * xdim) / (ydim + 0.5),
                              1.2); // shift -0.5+0i to the center

    iterate();
  }

  void draw_pixel(int x, int y) {
    auto pixel_address = reinterpret_cast<std::uint32_t *>(m_screen->pixels) +
                         (y * m_screen->w) + x;

    *pixel_address = color();
  }

private:
  uint32_t color() const noexcept {

    int factor = static_cast<int>(512 * iteration / maximum_iteration);

    if (iteration < (maximum_iteration / 50)) {

      return SDL_MapRGB(m_screen->format, 198 * factor, 118 * factor,
                        33 * factor);
    } else if (iteration < (maximum_iteration / 20)) {
      return SDL_MapRGB(m_screen->format, 166 * factor, 130 * factor,
                        75 * factor);
    } else if (iteration < (maximum_iteration / 10)) {
      return SDL_MapRGB(m_screen->format, 198 * factor, 118 * factor,
                        33 * factor);
    } else {
      return SDL_MapRGB(m_screen->format, 43 * factor, 126 * factor,
                        127 * factor);
    }
  }

  void iterate() {
    std::complex<double> Z = c;

    while (iteration < maximum_iteration && std::norm(Z) <= 4.0) {
      Z = Z * Z + k;
      ++iteration;
    }
  };

  const int maximum_iteration = 50;
  int iteration = 0;
  std::complex<double> c;

  std::complex<double> k{-0.6, 0.6};

  SDL_Surface *m_screen;
};

int main() {
  const int xdim = 1200, ydim = 800;

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cerr << "Video module not initialized\n";
    return -1;
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

  if (!screen) {
    std::cerr << "Screen not initialized\n";
  }

  SDL_LockSurface(screen);

  for (int y = 0; y < ydim; ++y) {
    for (int x = 0; x < xdim; ++x) {
      mandel_pixel m(screen, x, y, xdim, ydim);
      m.draw_pixel(x, y);
    }
  }

  SDL_UnlockSurface(screen);

  SDL_SaveBMP(screen, "Cantor_dust.bmp");

  SDL_FreeSurface(screen);

  SDL_Quit();
}

