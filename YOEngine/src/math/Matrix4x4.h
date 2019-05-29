#pragma once
#ifdef _DEBUG
#include <iostream>
#endif

#include "Vector.h"


namespace yo {

	class Matrix4x4 {
	public:
		Matrix4x4();
		Matrix4x4(const float elems[16]);
		Matrix4x4(const Matrix4x4& other);
		Matrix4x4(float diagonal);

		Matrix4x4& add(const Matrix4x4& other);
		Matrix4x4& sub(const Matrix4x4& other);

		Matrix4x4& mult(const Matrix4x4& other);

		Matrix4x4& rotateX(float angle);
		Matrix4x4& rotateY(float angle);
		Matrix4x4& rotateZ(float angle);

		Matrix4x4& transpose();
		Matrix4x4& translate(const Vector& vec);
		Matrix4x4& ortho(float right, float left, float top, float bottom, float far, float near);

		Matrix4x4& scale(float value);

		void set(const float elems[16]);
		void set(const Matrix4x4& other);
		void set(float diagonal);
#ifdef _DEBUG
		friend std::ostream& operator<<(std::ostream& os, const Matrix4x4& mat);
#endif 
	public:
		friend Matrix4x4 operator+(const Matrix4x4& left, const Matrix4x4& right);
		friend Matrix4x4 operator-(const Matrix4x4& left, const Matrix4x4& right);
		friend Matrix4x4 operator*(const Matrix4x4& left, const Matrix4x4& right);
	public:
		Matrix4x4 rotateX(const Matrix4x4& mat, float angle);
		Matrix4x4 rotateY(const Matrix4x4& mat, float angle);
		Matrix4x4 rotateZ(const Matrix4x4& mat, float angle);

		Matrix4x4 transpose(const Matrix4x4& mat);
		Matrix4x4 translate(const Matrix4x4& mat, const Vector& vec);
		Matrix4x4 ortho(const Matrix4x4& mat, float right, float left, float top, float bottom, float far, float near);

		Matrix4x4 scale(const Matrix4x4& mat, float value);
	private:
		float elems[16];
	};

}