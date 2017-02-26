#pragma once
#include <math.h>
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
	template <typename Type> inline double Sqrt(Type value) { return sqrt<Type>(value); }
	inline unsigned int Factorial(unsigned int value) {
		unsigned int result = 1;
		for (unsigned int i = 1; i <= value; i++)
			result *= i;
		return result;
	}
	float F_InvSqrt(float value) {
		float half = value * 0.5f;
		int i = *(int*)&value;
		i = 0x5f3759df - (i >> 1);
		value = *(float*)&i;
		value = value * (1.5f - half * value * value);
		return value;
	}
	template <typename Type, typename Type2> inline double Pow(Type value, Type2 degree) {
		return pow(value, degree);
	}
	template <typename Type> inline Type Root(Type value, Type degree) { return Pow<Type>(value, 1 / degree); }
	template <typename Type> inline double Sin(Type value) {
		return sin(value);
	}
	template <typename Type> inline float Cos(Type value) { return cosf<Type>(value); }
	template <typename Type> inline float ACos(Type value) { return acosf<Type>(value); }
	template <typename Type> inline Type Tan(Type value) { return tan<Type>(value); }
	template <typename Type> inline Type Ceil(Type value) { return ceil<Type>(value); }
	template <typename Type> inline int CeilInt(Type value) { return (int)ceil<Type>(value); }
	template <typename Type> inline Type Floor(Type value) { return floor<Type>(value); }
	template <typename Type> inline int FloorInt(Type value) { return (int)floor<Type>(value); }
	template <typename Type> inline Type Max(Type lhs, Type rhs) { return std::max<Type>(lhs, rhs); }
	template <typename Type> inline Type Min(Type lhs, Type rhs) { return std::min<Type>(lhs, rhs); }
	template <typename Type> inline Type Round(Type value) { return round<Type>(value); }
	template <typename Type> inline int RoundInt(Type value) { return (int)round<Type>(value); }
	//Other functions
	inline auto Clamp(float value, float min, float max) {
		return (value > max) ? max : (value < min) ? min : value;
	}
	//For linearly interpolating a value, between another, via a third param
	inline float Lerp(float a, float b, float t) {
		return (1 - t) * a + t * b;
	}
} Mathf;
