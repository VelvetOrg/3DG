#ifndef _vector3_h_
#define _vector3_h_

#include "mathf.h"
#include <ostream>
class Vector3
{
public:
	//X, Y and Z values of the Vector3
	float x, y, z;

	//Constructors
	Vector3(); //Default constructor
	Vector3(float nx, float ny, float nz); //Takes three floats for x, y and z values respectively
	Vector3(const Vector3& vector); //Construct the Vector3 using another Vector3
	Vector3(const Vector3 *vectorP); //Construct using a pointer to a Vector3

	//Destructor
	~Vector3();

	//Functions
	void Set(float nx, float ny, float nz); //Set the X, Y and Z values respectively
	float Magnitude(); // Returns the exact length of the vector
	float SqrMagnitude(); //Returns a squared length of the vector
	Vector3& Normalize();

	//Static functions
	static Vector3 Cross(const Vector3& a, const Vector3& b);
	static float Dot(const Vector3& a, const Vector3& b);

	//Overloaded operators
	friend std::ostream& operator<<(std::ostream& stream, const Vector3& vector);

	inline Vector3 operator+(const Vector3& vector) {
		return Vector3(x + vector.x, y + vector.y, z + vector.z);
	}

	inline Vector3 operator-(const Vector3& vector) {
		return Vector3(x - vector.x, y - vector.y, z - vector.z);
	}

	inline Vector3 operator*(const Vector3& vector) {
		return Vector3(x * vector.x, y * vector.y, z * vector.z);
	}

	inline Vector3 operator/(const Vector3& vector) {
		return Vector3(x / vector.x, y / vector.y, z / vector.z);
	}

	inline Vector3 operator=(const Vector3& vector) {
		return vector;
	}

	inline Vector3 operator+=(const Vector3& vector) {
		x += vector.x;
		y += vector.y;
		z += vector.z;
		return *this;
	}

	inline Vector3 operator-=(const Vector3& vector) {
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		return *this;
	}

	inline Vector3 operator*=(const Vector3& vector) {
		x *= vector.x;
		y *= vector.y;
		z *= vector.z;
		return *this;
	}

	inline Vector3 operator/=(const Vector3& vector) {
		x /= vector.x;
		y /= vector.y;
		z /= vector.z;
		return *this;
	}

	inline bool operator==(const Vector3& vector) {
		return ((x == vector.x) && (y == vector.y) && (z == vector.z)) ? true : false;
	}

	inline bool operator!=(const Vector3& vector) {
		return ((x == vector.x) && (y == vector.y) && (z == vector.z)) ? false : true;
	}

};

#endif