  /// <summary>
/// Vector 3 class
/// Craig Hickey
/// </summary>
#include "MyVector3.h"
#include <string.h>
#define PI           3.14159265358979323846

/// <summary>
/// Defautl constructor set all 3 values to zero
/// </summary>
MyVector3::MyVector3() :
	x{ 0.0 },
	y{ 0.0 },
	z{ 0.0 }
{
}
MyVector3::
/// <summary>
/// default destructor
/// nothing to release because we only have
/// primitive type data
/// </summary>
MyVector3::~MyVector3()
{
}

/// <summary>
/// 
/// </summary>
/// <returns>the vector as a string surrounded by square brackets and seperated by commas</returns>
std::string MyVector3::toString()
{
	const std::string output = "[" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "]";
	return output;	
}

MyVector3::MyVector3(double t_x, double t_y, double t_z):
	x{t_x},
	y{t_y},
	z{t_z}
{
}

//Function for calculating the
MyVector3::MyVector3(sf::Vector3f t_sfVector) 
{
	x = { static_cast<float>(t_sfVector.x) };
	y = { static_cast<float>(t_sfVector.y) };
	z = { static_cast<float>(t_sfVector.z) };
}

//Function for calculating the
MyVector3::MyVector3(sf::Vector3i t_sfVector)
{
	x = static_cast<int>(t_sfVector.x);
	y =	static_cast<int>(t_sfVector.y);
	z = static_cast<int>(t_sfVector.z);
}

//Function for calculating the
MyVector3::MyVector3(sf::Vector2i t_sfVector)

{
	x = static_cast<int>(t_sfVector.x);
	y = static_cast<int>(t_sfVector.y);
}


//Function for calculating the
MyVector3::MyVector3(sf::Vector2u t_sfVector)
{
	x = static_cast<unsigned int>(t_sfVector.x);
	y = static_cast<unsigned int>(t_sfVector.y);
	if (x < 0)
	{
		x = -x;
	}
	if (y < 0)
	{
		y = -y;
	}
}

//Function for calculating the
MyVector3::MyVector3(sf::Vector2f t_sfVector)
{
	x = static_cast<float>(t_sfVector.x);
	y = static_cast<float>(t_sfVector.y);
}

//Function for calculating the if two vectors are equal
bool MyVector3::operator==(const MyVector3 t_right) const
{
	bool result = (x == t_right.x && y == t_right.y && z == t_right.z);
	return result;
}

//Function for calculating the if two vectors are not equal
bool MyVector3::operator!=(const MyVector3 t_right) const
{
	bool result = (x != t_right.x || y != t_right.y || z != t_right.z);
	return result;
}

//Function for calculating the sum of two vectors
MyVector3 MyVector3::operator+(const MyVector3 t_right) const
{
	return MyVector3(x + t_right.x, y + t_right.y, z + t_right.z);
}

//Function for calculating the difference between two vectors
MyVector3 MyVector3::operator-(const MyVector3 t_right) const
{
	return MyVector3(x - t_right.x, y - t_right.y, z - t_right.z);
}

//Function for calculating the a vector multiplied by a scaler
MyVector3 MyVector3::operator*(const double t_scalar) const
{
	return MyVector3(x * t_scalar, y * t_scalar, z * t_scalar);
}

//Function for calculating the a vector divided by a scaler
MyVector3 MyVector3::operator/(const double t_divisor) const
{
	return MyVector3(x / t_divisor, y / t_divisor, z / t_divisor);
}

//Function for calculating the sum of two vectors
MyVector3 MyVector3::operator+=(const MyVector3 t_right)
{
	return MyVector3(x + t_right.x, y + t_right.y, z + t_right.z);
}

//Function for calculating the difference between two vectors
MyVector3 MyVector3::operator-=(const MyVector3 t_right)
{
	return MyVector3(x - t_right.x, y - t_right.y, z - t_right.z);
}

//Function for finding a vector with the opposite sign as the current vector
MyVector3 MyVector3::operator-()
{
	return MyVector3(-x,-y,-z);
}

//Function for calculating the length of a vector
double MyVector3::length() const
{
	double result = std::sqrt(x * x + y * y + z*z);
	return result;
}

//Function for calculating the length square
double MyVector3::lengthSquared() const
{
	double result = (x * x + y * y + z*z);
	return result;
}

//Function for calculating the dot product
double MyVector3::dot(const MyVector3 t_other) const
{
	double result = (x * t_other.x) + (y * t_other.y) + (z * t_other.z);
	return result;
}

//Function for calculating the cross product 
MyVector3 MyVector3::crossProduct(const MyVector3 t_other) const
{
	int i = (y*t_other.z - z*t_other.y);//Calculating the x of the cross product
	int j = (x*t_other.z - z*t_other.x);//Calculating the y of the cross product
	int k = (x*t_other.y - y*t_other.x);//Calculating the z of the cross product
	return MyVector3(i, j, k);
}

//Function for calculating the angle between
double MyVector3::angleBetween(const MyVector3 t_other) const
{
	const double cosine = unit().dot(t_other.unit());
	const double angleInRadians = std::acos(cosine);
	const double angleInDegrees = angleInRadians * 180 / PI;
	return angleInDegrees;
}

//Function for calculating the unit vector
MyVector3 MyVector3::unit() const
{
	double newX{ 0.0 };//Variable for the new x
	double newY{ 0.0 };//Variable for the new y
	double newZ{ 0.0 };//Variable for the new z
	double vectorLength = length();//Variable for the length
	if (vectorLength != 0.0)//Not dividing by zero 
	{
		newX = x / vectorLength;//Calculating the new x
		newY = y / vectorLength;//Calculating the new y
		newZ = z / vectorLength;//Calculating the new y
	}
	return MyVector3(newX, newY, newZ);
}

//Function for calculating the normalise of a vector
void MyVector3::normalise()
{
	double vectorLength = length();//Variable for the length
	if (vectorLength != 0.0)//Not dividing by zero 
	{
		x = x / vectorLength;//Calculating the new x
		y = y / vectorLength;//Calculating the new y
		z = z / vectorLength;//Calculating the new y
	}
}

//Function for calculating the projection of one vector along another
MyVector3 MyVector3::projection(const MyVector3 t_other) const
{
	double scale = dot(t_other) / lengthSquared();
	return this->operator*(scale);
}

//Function for calculating the rejection of a vector 
MyVector3 MyVector3::rejection(const MyVector3 t_other) const
{
	return MyVector3(t_other - projection(t_other));
}
