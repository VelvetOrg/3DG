#include "Vector3.h"

//Constructors
Vector3::Vector3() : x(0), y(0), z(0) {};
Vector3::Vector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {};
Vector3::Vector3(const Vector3& vector) : x(vector.x), y(vector.y), z(vector.z) {};
Vector3::Vector3(const Vector3 *vectorP) : x(vectorP->x), y(vectorP->y), z(vectorP->z) {};

//Destructor
Vector3::~Vector3() { x = y = z = 0; };

//Functions
void Vector3::Set(float nx, float ny, float nz)
{
	x = nx;
	y = ny;
	z = nz;
}

float Vector3::Magnitude()
{
	return Mathf.Sqrtf((x * x) + (y * y) + (z * z));
}

float Vector3::SqrMagnitude()
{
	return (x * x) + (y * y) + (z * z);
}

Vector3& Vector3::Normalize()
{
	float length = Magnitude();
	x /= length;
	y /= length;
	z /= length;
	return *this;
}

//Static functions
float Vector3::Dot(const Vector3& a, const Vector3& b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

Vector3 Vector3::Cross(const Vector3& a, const Vector3& b)
{
	return Vector3(((a.y * b.z) - (a.z * b.y)),((a.z * b.x) - (a.x - b.z)),  ((a.x * b.y)  - (a.y * b.x)));
}

//Overloaded operators
std::ostream& operator<<(std::ostream& stream, const Vector3& vector)
{
	stream << "\nX: " << vector.x << "\nY: " << vector.y  << "\nZ: " << vector.z << "\n";
	return stream;
}