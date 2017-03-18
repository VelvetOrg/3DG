#include "colour.h"
Colour::Colour() : r(0), g(0), b(0), a(255) {};
Colour::Colour(float r, float g, float b, float a = 255) : r(r), g(g), b(b), a(a) {};
Colour::Colour(const Colour& colour) : r(colour.r), g(colour.g), b(colour.b), a(colour.a) {};
Colour::Colour(const Colour* colour) : r(colour->r), g(colour->g), b(colour->b), a(colour->a) {};