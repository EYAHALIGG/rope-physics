#pragma once

#include <iostream>
using namespace std;

template <typename T>
class Vec2
{
public:
	T x, y;

	Vec2() : x(0), y(0) {}
	Vec2(T _x) : x(_x), y(_x) {}
	Vec2(T _x, T _y) : x(_x), y(_y) {}

	template <typename T2> Vec2(Vec2<T2>& v) : Vec2(v.x, v.y) {}

	T Dot(Vec2<T>& v);
	T Dot();
	T Length();

	Vec2<T> Perp();
	Vec2<T> Normalise();

	void Print();

	bool operator == (Vec2& v);
	bool operator != (Vec2& v);

	void operator += (Vec2& v);
	void operator -= (Vec2& v);
	void operator *= (Vec2& v);
	void operator /= (Vec2& v);

	Vec2<T> operator + (Vec2& v);
	Vec2<T> operator - (Vec2& v);
	Vec2<T> operator * (Vec2& v);
	Vec2<T> operator / (Vec2& v);

	void operator += (T t);
	void operator -= (T t);
	void operator *= (T t);
	void operator /= (T t);

	Vec2<T> operator + (T t);
	Vec2<T> operator - (T t);
	Vec2<T> operator * (T t);
	Vec2<T> operator / (T t);

	Vec2<T> operator - ();
};

#include "GenTypes.h"
gentypes(Vec2)

template<typename T>
inline T Vec2<T>::Dot(Vec2<T>& v)
{
	return x*v.x + y*v.y;
}

template<typename T>
inline T Vec2<T>::Dot()
{
	return T(x*x + y*y);
}

template<typename T>
inline T Vec2<T>::Length()
{
	return T(sqrt((float)Dot()));
}

template<typename T>
inline Vec2<T> Vec2<T>::Perp()
{
	return Vec2<T>(y, -x); // or (-y, x)
}

template<typename T>
inline Vec2<T> Vec2<T>::Normalise()
{
	return *this / Vec2<T>(Length());
}

template<typename T>
inline void Vec2<T>::Print()
{
	cout << "{ " << x << ", " << y << " }" << endl;
}

template<typename T>
inline bool Vec2<T>::operator==(Vec2 & v)
{
	return *(double*)&x == *(double*)&v.x;
}

template<typename T>
inline bool Vec2<T>::operator!=(Vec2 & v)
{
	return !(*this == v);
}

template<typename T>
inline void Vec2<T>::operator+=(Vec2 & v)
{
	x += v.x;
	y += v.y;
}

template<typename T>
inline void Vec2<T>::operator-=(Vec2 & v)
{
	x -= v.x;
	y -= v.y;
}

template<typename T>
inline void Vec2<T>::operator*=(Vec2 & v)
{
	x *= v.x;
	y *= v.y;
}

template<typename T>
inline void Vec2<T>::operator/=(Vec2 & v)
{
	x = (v.x == 0) ? 0 : (x / v.x);
	y = (v.y == 0) ? 0 : (y / v.y);
}

template<typename T>
inline Vec2<T> Vec2<T>::operator+(Vec2 & v)
{
	return Vec2<T>(x + v.x, y + v.y);
}

template<typename T>
inline Vec2<T> Vec2<T>::operator-(Vec2 & v)
{
	return Vec2<T>(x - v.x, y - v.y);
}

template<typename T>
inline Vec2<T> Vec2<T>::operator*(Vec2 & v)
{
	return Vec2<T>(x * v.x, y * v.y);
}

template<typename T>
inline Vec2<T> Vec2<T>::operator/(Vec2 & v)
{
	return Vec2<T>(
		(v.x == 0) ? 0 : (x / v.x),
		(v.y == 0) ? 0 : (y / v.y));
}

template<typename T>
inline void Vec2<T>::operator+=(T t)
{
	*this += Vec2<T>(t);
}

template<typename T>
inline void Vec2<T>::operator-=(T t)
{
	*this -= Vec2<T>(t);
}

template<typename T>
inline void Vec2<T>::operator*=(T t)
{
	*this *= Vec2<T>(t);
}

template<typename T>
inline void Vec2<T>::operator/=(T t)
{
	*this /= Vec2<T>(t);
}

template<typename T>
inline Vec2<T> Vec2<T>::operator-()
{
	return Vec2<T>(-x, -y);
}

template<typename T>
inline Vec2<T> Vec2<T>::operator+(T t)
{
	return *this + Vec2<T>(t);
}

template<typename T>
inline Vec2<T> Vec2<T>::operator-(T t)
{
	return *this - Vec2<T>(t);
}

template<typename T>
inline Vec2<T> Vec2<T>::operator*(T t)
{
	return *this * Vec2<T>(t);
}

template<typename T>
inline Vec2<T> Vec2<T>::operator/(T t)
{
	return *this / Vec2<T>(t);
}
