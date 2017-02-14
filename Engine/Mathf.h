#pragma once
#include <math.h>
#include <numeric>
#include <algorithm>
#include <random>
#include <iterator>
#include <time.h>

static class Mathf
{
public:
	
	//Constant values
	const float PI = 3.1415926f;
	const float TAU = 6.2831852f;
	const float TRUNCATION = 0.005f;
	const float EPSILON = 0.0000001f;
	const float PositiveInfinity = std::numeric_limits<float>::infinity();
	const float NegativeInfinity = -(PositiveInfinity);
	const float DegToRad = 6.2831852f / 360;
	const float RadToDeg = 360 / 6.2831852f;

	//Wrapper math functions
	template <typename Type> inline Type Sqrt(Type value) { return sqrt<Type>(value); }
	template <typename Type> inline Type Factorial(Type value) {
		Type result = 1;
		for (int i = 1; i <= value; i++)
			result *= i;
		return result;
	}
	template <typename Type> Type Pow(Type value, Type degree) { 
		Type result = 1;
		for (int i = 0; i < degree; i++)
			result *= value;
		return result;
	}
	template <typename Type> inline Type Root(Type value, Type degree) { return Pow<Type>(value, 1 / degree); }
	template <typename Type> inline float Sin(Type x) {
		float term, denom, y, i;
		x *= DegToRad;
		term = x;
		y = term;
		i = 1;
		do {
			denom = 2 * i * (2 * i + 1);
			term = -term * x * x / denom;
			y += term;
			i++;
		} while(EPSILON <= Abs())
	}
	template <typename Type> inline Type Cos(Type value) { return cosf<Type>(value); }
	template <typename Type> inline Type Tan(Type value) { return tafn<Type>(value); }
	template <typename Type> inline Type Ceil(Type value) { return ceil<Type>(value); }
	template <typename Type> inline int CeilInt(Type value) { return (int)ceil<Type>(value); }
	template <typename Type> inline Type Floor(Type value) { return floor<Type>(value); }
	template <typename Type> inline int FloorInt(Type value) { return (int)floor<Type>(value); }
	template <typename Type> inline Type Max(Type lhs, Type rhs) { return std::max<Type>(lhs, rhs); }
	template <typename Type> inline Type Min(Type lhs, Type rhs) { return std::min<Type>(lhs, rhs); }
	template <typename Type> inline Type Round(Type value) { return round<Type>(value); }
	template <typename Type> inline int RoundInt(Type value) { return (int)round<Type>(value); }
	
	
	//Other functions
	template <typename Type> inline Type Clamp(Type value, Type minimum, Type maximum) {
		return std::max<Type>(minimum, std::min(value, maximum));
	}

	template <typename Type> inline float Lerp(float a, float b, float t) {
		return (1 - t) * a + t * b;
	}
} Mathf;
