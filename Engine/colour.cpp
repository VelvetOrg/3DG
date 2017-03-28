#include "colour.h"
Colour::Colour() : r(0), g(0), b(0), a(255) {};
Colour::Colour(GE_BYTE r, GE_BYTE g, GE_BYTE b, GE_BYTE a) : r(r), g(g), b(b), a(a) {};
Colour::Colour(const Colour& colour) : r(colour.r), g(colour.g), b(colour.b), a(colour.a) {};
Colour::Colour(const Colour* colour) : r(colour->r), g(colour->g), b(colour->b), a(colour->a) {};