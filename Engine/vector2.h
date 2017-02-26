#ifndef _vector2_h_
#define _vector2_h_

#include "mathf.h"
#include <ostream>
class Vector2
{
public:
	//X and Y values of the Vector2
	float x, y;

	//Constructors
	Vector2(); //Default constructor
	Vector2(float nx, float ny); //Takes two floats for x and y values respectively
	Vector2(const Vector2& vector); //Construct the Vector2 using another Vector2
	Vector2(const Vector2 *vectorP); //Construct using a pointer to a Vector2
	
	//Destructor
	~Vector2();
	
	//Functions
	void Set(float nx, float ny); //Set the X and Y values respectively
	float Magnitude(); // Returns the exact length of the vector
	float SqrMagnitude(); //Returns a squared length of the vector
	Vector2& Normalize();

	//Static functions
	static float Dot(const Vector2& a, const Vector2& b);

	//Overloaded operators
	friend std::ostream& operator<<(std::ostream& stream, const Vector2& vector);
	
	inline Vector2 operator+(const Vector2& vector) {
		return Vector2(x + vector.x, y + vector.y);
	}
	
	inline Vector2 operator-(const Vector2& vector) {
		return Vector2(x - vector.x, y - vector.y);
	}

	inline Vector2 operator*(const Vector2& vector) {
		return Vector2(x * vector.x, y * vector.y);
	}

	inline Vector2 operator/(const Vector2& vector) {
		return Vector2(x / vector.x, y / vector.y);
	}

	inline Vector2 operator=(const Vector2& vector) {
		return vector;
	}

	inline Vector2 operator+=(const Vector2& vector) {
		x += vector.x;
		y += vector.y;
		return *this;
	}

	inline Vector2 operator-=(const Vector2& vector) {
		x -= vector.x;
		y -= vector.y;
		return *this;
	}

	inline Vector2 operator*=(const Vector2& vector) {
		x *= vector.x;
		y *= vector.y;
		return *this;
	}

	inline Vector2 operator/=(const Vector2& vector) {
		x /= vector.x;
		y /= vector.y;
		return *this;
	}

	inline bool operator==(const Vector2& vector) {
		return ((x == vector.x) && (y == vector.y)) ? true : false;
	}

	inline bool operator!=(const Vector2& vector) {
		return ((x == vector.x) && (y == vector.y)) ? false : true;
	}

};

#endif