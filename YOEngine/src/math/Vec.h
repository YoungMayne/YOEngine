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
		Vector(float value);

		void set(float x, float y, float z = 0);
		void set(const Vector& other);
		void set(float value);

		void add(const Vector& other);
		void add(float x, float y, float z = 0);
		void add(float value);

		void sub(const Vector& other);
		void sub(float x, float y, float z = 0);
		void sub(float value);

		void mult(float value);

		void div(float value);

		void setMag(float value);

		void normalize();
		void rotate(float angle);

		float dot(const Vector& other)const;
		float dot(float x, float y, float z)const;

		Vector cross(const Vector& other)const;
		Vector cross(float x, float y, float z)const;

		float angleBetween(const Vector& other)const;
		float angleBetween(float x, float y, float z = 0)const;

		float mag()const;

		float dist(const Vector& other)const;
		float dist(float x, float y, float z = 0)const;
#ifdef _DEBUG
		friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
#endif
	public:
		static Vector add(const Vector& first, const Vector& second);
		static Vector sub(const Vector& first, const Vector& second);
		static Vector mult(const Vector& vec, float value);
		static Vector div(const Vector& vec, float value);

		static Vector normalize(const Vector& vec);
		static Vector rotate(const Vector& vec, float angle);

		static float dot(const Vector& first, const Vector& second);
		static float dot(const Vector& vec, float x, float y, float z);
		static float dot(float fX, float fY, float fZ, float sX, float sY, float sZ);

		static Vector cross(const Vector& first, const Vector& second);
		static Vector cross(const Vector& vec, float x, float y, float z);
		static Vector cross(float fX, float fY, float fZ, float sX, float sY, float sZ);

		static float angleBetween(const Vector& first, const Vector& second);
		static float angleBetween(const Vector& vec, float x, float y, float z);
		static float angleBetween(float fX, float fY, float fZ, float sX, float sY, float sZ);

		static float mag(const Vector& vec);
		static float mag(float x, float y, float z);

		static float dist(const Vector& first, const Vector& second);
		static float dist(const Vector& vec, float x, float y, float z);
		static float dist(float fX, float fY, float fZ, float sX, float sY, float sZ);
	};

}