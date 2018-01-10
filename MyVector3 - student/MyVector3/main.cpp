/// <summary>
/// Craig Hickey
/// estimate 6 hours
/// time spent 5 hours 30 mins
/// issues:Not sure if  not negative is done correctly I think and angle between maybe wrong I'm not sure as I got the answer that the programm output also got different answers
/// 
/// </summary>
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 


#include "MyVector3.h"
#include <SFML\Graphics.hpp>
#include <string>


int main()
{
	MyVector3 vectorOne{};

	std::cout << vectorOne.toString() << std::endl;
	std::cout << "Null / default constructor" << std::endl;
	std::cout << "================================" << std::endl;

	vectorOne = MyVector3{ 1,1,1 };//Initalizing vector one to 1 in the x,y and z axis
	MyVector3 vectorTwo(3, 4, 5);//Initalizing vector two to 3,4,and 5 in the x,y and z axis respectivly
	MyVector3 vectorThree{ 1,1,1 };//Initalizing vector three to 3 in the x,y and z axis

	//Test to see if two vectors are not equal to each other
	std::cout << "Inequality" << std::endl;
	std::cout << "================================" << std::endl;
	bool inequality = { false };//Variable for the inequality to see if two vectors aren't equal 
	if (vectorOne != vectorTwo)//Checking to see if vector one is equal to vector two
	{
		inequality = true;
	}
	std::cout << inequality << std::endl;//If 1 is returned it means are not equal as the if statment would make the bool tru
	std::cout << "[1]" << std::endl;//Expected result as (1,1,1) is not equal to (3,4,5)
	std::cout << "" << std::endl;

	//Test to see if two vectors are not equal to each other
	std::cout << "Equality" << std::endl;//Variable for the equality to see if two vectors are equal 
	std::cout << "================================" << std::endl;
	bool equality = { false };//Variable for the 
	if (vectorOne == vectorThree)//Checking to see if vector one is equal to vector three
	{
		equality = true;
	}
	std::cout << equality << std::endl;//If 1 is returned it means are not equal as the if statment would make the bool true
	std::cout << "[1]" << std::endl;//Expected result as (1,1,1) is equal to (1,1,1)
	std::cout << "" << std::endl;

	//Test for addiition
	std::cout << "Addition" << std::endl;
	std::cout << "================================" << std::endl;
	vectorThree = vectorOne + vectorTwo;//Adding vector one and vector two then assigning the result to vector three
	std::cout << vectorThree.toString() << std::endl;
	std::cout << MyVector3(4, 5, 6).toString() << std::endl;//Expected result as (1+3, 1+4, 1+5) is equal to (4, 5, 6)
	std::cout << "" << std::endl;
	
	//Test for Subtraction
	std::cout << "Subtraction" << std::endl;
	std::cout << "================================" << std::endl;
	vectorThree = vectorTwo - vectorOne;//Subtracting vector one from vector two then assigning the result to vector three
	std::cout << vectorThree.toString() << std::endl;
	std::cout << MyVector3(2, 3, 4).toString() << std::endl;//Expected result as (4-1 ,5-1 ,6-1) is equal to (3, 4, 5)
	std::cout << "" << std::endl;

	//Test for 
	std::cout << "Multiplecation"<< std::endl;
	std::cout << "================================" << std::endl;
	double scalerDouble = { 3.0000 };//Variable for the scaler
	vectorThree = vectorTwo*scalerDouble;//Multiplying vector Two by the scaler 3 then assigning the result to vector three
	std::cout << vectorThree.toString() << std::endl;
	std::cout << MyVector3(9, 12, 15).toString() << std::endl;//Expected result as (3*3, 4*3, 5*3) is equal to (9, 12, 15)
	std::cout << "" << std::endl;

	//Test for division
	std::cout << "Double Division" << std::endl;
	std::cout << "================================" << std::endl;
	double divisorDouble = { 2.000 };//Variable for the divisor
	vectorThree = vectorTwo / divisorDouble;//Dividing vector Two by the scaler 3 then assigning the result to vector three
	std::cout << vectorThree.toString() << std::endl;
	std::cout << MyVector3(1.5, 2, 2.5).toString() << std::endl;//Expected result as (3/2, 4/2, 5/2) is equal to (1.5, 2, 2.5)
	std::cout << "" << std::endl;

	//Test for Plus Equals
	std::cout << "Plus Equals" << std::endl;
	std::cout << "================================" << std::endl;
	vectorTwo += vectorOne;//Adding vector one to vector two 
	std::cout << vectorTwo.toString() << std::endl;
	std::cout << MyVector3(4, 5, 6).toString() << std::endl;//Expected result as (3+1, 4+1, 5+1) is equal to (4, 5, 6)
	std::cout << "" << std::endl;

	//Test for Minus Equals
	std::cout << "Minus Equals" << std::endl;
	std::cout << "================================" << std::endl;
	vectorTwo -= vectorOne;//Subtracting vector one from vector two 
	std::cout << vectorTwo.toString() << std::endl;
	std::cout << MyVector3(3, 4, 5).toString() << std::endl;//Expected result as (4-1 ,5-1 ,6-1) is equal to (3,4,5)
	std::cout << "" << std::endl;

	//Test for Length
	std::cout << "Length " << std::endl;
	std::cout << "================================" << std::endl;
	double length{ 0.0 };//Variable for the length
	length = vectorTwo.length();//Calling the length function and assignning the answer to the length variable
	std::cout << length << std::endl;
	std::cout << "[7.07107]" << std::endl;//Expected result as 9+16+25 = 50 square root of 50 is 7.07107
	std::cout << "" << std::endl;

	//Test for Length Squared
	std::cout << "Length Squared " << std::endl;
	std::cout << "================================" << std::endl;
	double lengthSquared{ 0.0 };//Variable for the length squared
	lengthSquared = vectorTwo.lengthSquared();//Calling the length squared function and assignning the answer to the length squared variable
	std::cout << lengthSquared << std::endl;
	std::cout << "[50]" << std::endl;//Expected result as 9+16+25 = 50
	std::cout << "" << std::endl;

	//Test for Dot Product
	std::cout << "Dot Product" << std::endl;
	std::cout << "================================" << std::endl;
	double dotProduct{ 0.0 };//Variable for the dot product
	dotProduct = vectorTwo.dot(vectorOne);//Calling the dot product function and assignning the answer to the dot product variable
	std::cout << dotProduct << std::endl;
	std::cout << "[12]" << std::endl;//Expected result as (3 * 1)+(4 * 1)+(5 * 1) is 12
	std::cout << "" << std::endl;

	//Test for Cross Product
	std::cout << "Cross Product" << std::endl;
	std::cout << "================================" << std::endl;
	vectorThree = vectorTwo.crossProduct(vectorOne);//Calling the cross product function and assignning the answer to vector three
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "[-1, 2, -1]" << std::endl;
	std::cout << "" << std::endl;

	//Test for Angle Between
	std::cout << "Angle Between" << std::endl;
	std::cout << "================================" << std::endl;
	double angleBetween = { 0.0 };//Variable for the angle between two vector 
	angleBetween = vectorTwo.angleBetween(vectorOne);//Calling the angle between function and assignning the answer to the angle between variable
	std::cout << angleBetween << std::endl;
	std::cout << "[11.537]" << std::endl;
	std::cout << "" << std::endl;

	//Test for Unit
	std::cout << "Unit" << std::endl;
	std::cout << "================================" << std::endl;
	vectorThree = vectorTwo.unit();//Calling the unit function and assignning the answer to vector three
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "[0.424264,0.565685,0.707107]" << std::endl;//Expected results as the magnitude of this vector is approx. 1
	std::cout << "" << std::endl;

	//Test for Normaize
	std::cout << "Normaize" << std::endl;
	std::cout << "================================" << std::endl;
	vectorThree = vectorTwo / vectorTwo.length();//Calling the normaize function and assignning the answer to vector three
	std::cout << vectorThree.toString() << std::endl;
	std::cout << MyVector3(0.424264, 0.565685, 0.707107).toString() << std::endl;//Expected results as the magnitude of this vector is approx. 1 
	std::cout << "" << std::endl;

	//Test for Projection
	std::cout << "Projection" << std::endl;
	std::cout << "================================" << std::endl;
	vectorThree = vectorTwo.projection(vectorOne);//Calling the projection function, projecting vector two onto vector one and assignning the answer to vector three
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "[0.72, 0.96, 1.2]" << std::endl;//Expected result as the dot product is 12 and the magnatude is 50, which is then multipled by the coordinates of vector two
	std::cout << "" << std::endl;

	//Test for Rejection
	std::cout << "Rejection" << std::endl;
	std::cout << "================================" << std::endl;
	vectorThree = vectorTwo.rejection(vectorOne);//Calling the rejection function, getting the rejection of vector two along vector one and assignning the answer to vector three
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "[0.28, 0.04, -0.2]" << std::endl;//Expected result as projecton and rejection need to add up to the length of the vector they are one in this case vector one the coordinates of which are (1,1,1)
	std::cout << "" << std::endl;

	vectorThree = MyVector3(-1, -1, -1);


	//Not sure how this was meant to be done 
	std::cout << "Not Negatived" << std::endl;
	std::cout << "================================" << std::endl;
	if (vectorThree.x < 0)
	{
		vectorThree.x = -vectorThree.x;//if the x of vector three is negative it becomes postitive
	}
	if (vectorThree.y < 0)
	{
		vectorThree.y = -vectorThree.y;//if the y of vector three is negative it becomes postitive
	}
	if (vectorThree.z != 0)
	{
		vectorThree.z = -vectorThree.z;//if the z of vector three is not 0 it becomes 0 so the vector is now 2D
	}
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "[1, 1, 0]" << std::endl;
	std::cout << "" << std::endl;

	std::system("pause");
	return EXIT_SUCCESS;
}


