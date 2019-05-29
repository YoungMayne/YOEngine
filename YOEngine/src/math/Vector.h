#pragma once
#include <cmath>
#ifdef _DEBUG
#include <iostream>
#endif



namespace yo {

	class Vector {
	public:
		float x;
		float y;
		float z;
	public:
		Vector(float x = 0, float y = 0, float z = 0);
		Vector(const Vector& other);

		void set(float x, float y, float z = 0);
		void set(const Vector& other);
		void set(float value);

		Vector& add(const Vector& other);
		Vector& add(float x, float y, float z = 0);
		Vector& add(float value);

		Vector& sub(const Vector& other);
		Vector& sub(float x, float y, float z = 0);
		Vector& sub(float value);

		Vector& mult(float value);

		Vector& div(float value);

		void setMag(float value);

		Vector& normalize();
		Vector& rotate(float angle);
		Vector fromAngle(float angle)const;

		float dot(const Vector& other)const;
		float dot(float x, float y, float z = 0)const;

		Vector cross(const Vector& other)const;
		Vector cross(float x, float y, float z = 0)const;

		float angleBetween(const Vector& other)const;
		float angleBetween(float x, float y, float z = 0)const;

		float mag()const;

		float dist(const Vector& other)const;
		float dist(float x, float y, float z = 0)const;
#ifdef _DEBUG
		friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
#endif
	public:
		friend Vector operator+(const Vector& first, const Vector& second);
		friend Vector operator-(const Vector& first, const Vector& second);
		friend Vector operator+(const Vector& vec, float value);
		friend Vector operator-(const Vector& vec, float value);
		friend Vector operator*(const Vector& vec, float value);
		friend Vector operator/(const Vector& vec, float value);
	public:
		static Vector normalize(const Vector& vec);
		static Vector rotate(const Vector& vec, float angle);
	};

}