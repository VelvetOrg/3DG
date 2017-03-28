#ifndef _colour_h_
#define _colour_h_
#include "mathf.h"
#include "types.h"
class Colour {
	GE_BYTE r, g, b, a;
	Colour();
	Colour(GE_BYTE r, GE_BYTE g, GE_BYTE b, GE_BYTE a = 255);
	Colour(const Colour &colour);
	Colour(const Colour *colourP);
	inline Colour operator+(const Colour& colour) {
		return Colour(r + colour.r, g + colour.g, b + colour.b, Mathf.Clamp(a + colour.a, 0, 255));
	}
	inline Colour operator-(const Colour& colour) {
		return Colour(r - colour.r, g - colour.g, b - colour.b, Mathf.Clamp(a - colour.a, 0, 255));
	}
	inline Colour operator*(const Colour& colour) {
		return Colour(r * colour.r, g * colour.g, b * colour.b, Mathf.Clamp(a * colour.a, 0, 255));
	}
	inline Colour operator/(const Colour& colour) {
		return Colour(r / colour.r, g / colour.g, b / colour.b, Mathf.Clamp(a / colour.a, 0, 255));
	}
};

#endif