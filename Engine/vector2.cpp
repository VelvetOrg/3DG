#include "vector2.h"

//Constructors
Vector2::Vector2() : x(0), y(0) {};
Vector2::Vector2(float nx, float ny) : x(nx), y(ny) {};
Vector2::Vector2(const Vector2& vector) : x(vector.x), y(vector.y) {};
Vector2::Vector2(const Vector2 *vectorP) : x(vectorP->x), y(vectorP->y) {};

//Destructor
Vector2::~Vector2() { x = y = 0; };

//Functions
void Vector2::Set(float nx, float ny) 
{
	x = nx;
	y = ny;
}

float Vector2::Magnitude() 
{
	return Mathf.Sqrtf((x * x) + (y * y));
}

float Vector2::SqrMagnitude() 
{
	return (x * x) + (y * y);
}

Vector2& Vector2::Normalize() 
{
	float length = Magnitude();
	x /= length; 
	y /= length;
	return *this;
}

//Static functions
float Vector2::Dot(const Vector2& a, const Vector2& b) 
{
	return (a.x * b.x) + (a.y * b.y);
}

//Overloaded operators
std::ostream& operator<<(std::ostream& stream, const Vector2& vector) 
{
	stream << "\nX: " << vector.x << "\nY: " << vector.y << "\n";
	return stream;
}