#pragma once

template<typename T>
class Vector
{
public:
	//Constructors
	Vector<T>() = default;
	//Constructor Which is better to be used...
	Vector<T>(T x, T y)
		:
		x(x),
		y(y)
	{}
	
	//Main Components X And Y
public:
	T x;
	T y;

	//Operators On the Vector
public:
	Vector<T> operator+(Vector<T> rhs)
	{
		Vector<T> Temp;
		Temp.x = x + rhs.x;
		Temp.y = y + rhs.y;
		return Temp;
	}

	Vector<T> operator-(Vector<T> rhs)
	{
		Vector<T> Temp;
		Temp.x = x - rhs.x;
		Temp.y = y - rhs.y;
		return Temp;
	}

	//Scale A Vector
	Vector<T> operator*(int rhs)
	{
		Vector<T> Temp;
		Temp.x = x*rhs;
		Temp.y = y * rhs;
		return Temp;
	}

	typedef Vector<int> VecI;
};