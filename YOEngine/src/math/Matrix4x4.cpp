#include "Matrix4x4.h"

namespace yo {

	Matrix4x4::Matrix4x4() {
		for (int i = 0; i < 16; ++i) {
			elems[i] = 0.0f;
		}
	}


	Matrix4x4::Matrix4x4(const float elems[16]) {
		set(elems);
	}


	Matrix4x4::Matrix4x4(const Matrix4x4& other) {
		set(other);
	}


	Matrix4x4::Matrix4x4(float diagonal) : Matrix4x4() {
		set(diagonal);
	}


	Matrix4x4& Matrix4x4::add(const Matrix4x4& other) {
		for (int i = 0; i < 16; ++i) {
			elems[i] = elems[i] + other.elems[i];
		}
		return *this;
	}


	Matrix4x4& Matrix4x4::sub(const Matrix4x4& other) {
		for (int i = 0; i < 16; ++i) {
			elems[i] = elems[i] - other.elems[i];
		}
		return *this;
	}


	Matrix4x4& Matrix4x4::mult(const Matrix4x4& other) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				float sum = 0;
				for (int k = 0; k < 4; ++k) {
					sum += elems[j + k * 4] * other.elems[k + i * 4];
				}
				elems[j + i * 4] = sum;
			}
		}
		return *this;
	}


	Matrix4x4& Matrix4x4::rotateX(float angle) {
		Matrix4x4 rotation(1);

		rotation.elems[5] = cos(angle);
		rotation.elems[6] = sin(angle);
		rotation.elems[9] = -sin(angle);
		rotation.elems[10] = cos(angle);

		return *this = rotation.mult(*this);
	}


	Matrix4x4& Matrix4x4::rotateY(float angle) {
		Matrix4x4 rotation(1);

		rotation.elems[0] = cos(angle);
		rotation.elems[2] = -sin(angle);
		rotation.elems[8] = sin(angle);
		rotation.elems[10] = cos(angle);

		return *this = rotation.mult(*this);
	}


	Matrix4x4& Matrix4x4::rotateZ(float angle) {
		Matrix4x4 rotation(1);

		rotation.elems[0] = cos(angle);
		rotation.elems[1] = sin(angle);
		rotation.elems[4] = -sin(angle);
		rotation.elems[5] = cos(angle);

		return *this = rotation.mult(*this);
	}


	Matrix4x4& Matrix4x4::transpose() {
		for (int i = 0; i < 4; ++i) {
			for (int j = i + 1; j < 4; ++j) {
				int index1 = j * 4 + i;
				int index2 = i * 4 + j;

				float temp = elems[index1];
				elems[index1] = elems[index2];
				elems[index2] = temp;
			}
		}
		return *this;
	}


	Matrix4x4& Matrix4x4::translate(const Vector& vec) {
		for (int i = 0; i < 3; ++i) {
			elems[12 + i] += elems[i] * vec.x + elems[4 + i] * vec.y + elems[i + 8] * vec.z;
		}
		return *this;
	}


	Matrix4x4& Matrix4x4::ortho(float right, float left, float top, float bottom, float far, float near) {
		elems[0] = 2.0f / (right - left);
		elems[5] = 2.0f / (top - bottom);
		elems[10] = -2.0f / (far - near);
		elems[12] = -((right + left) / (right - left));
		elems[13] = -((top + bottom) / (top - bottom));
		elems[14] = -((far + near) / (far - near));
		elems[15] = 1.0f;

		return *this;
	}


	Matrix4x4& Matrix4x4::scale(float value) {
		for (int i = 0; i < 16; ++i) {
			elems[i] *= value;
		}
		return *this;
	}


	void Matrix4x4::set(const float elems[16]) {
		for (int i = 0; i < 16; ++i) {
			this->elems[i] = elems[i];
		}
	}


	void Matrix4x4::set(const Matrix4x4& other) {
		for (int i = 0; i < 16; ++i) {
			elems[i] = other.elems[i];
		}
	}


	void Matrix4x4::set(float diagonal) {
		for (int i = 0; i < 4; ++i) {
			elems[i + i * 4] = diagonal;
		}
	}


	Matrix4x4 operator+(const Matrix4x4& left, const Matrix4x4& right) {
		return Matrix4x4(left).add(right);
	}


	Matrix4x4 operator-(const Matrix4x4& left, const Matrix4x4& right) {
		return Matrix4x4(left).sub(right);
	}


	Matrix4x4 operator*(const Matrix4x4& left, const Matrix4x4& right) {
		return Matrix4x4(left).mult(right);
	}


#ifdef _DEBUG
	std::ostream& operator<<(std::ostream& os, const Matrix4x4& mat) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				os << mat.elems[i + j * 4] << "\t\t";
			}
			os << std::endl;
		}
		return os;
	}
#endif


	Matrix4x4 Matrix4x4::rotateX(const Matrix4x4& mat, float angle) {
		return Matrix4x4(mat).rotateX(angle);
	}


	Matrix4x4 Matrix4x4::rotateY(const Matrix4x4& mat, float angle) {
		return Matrix4x4(mat).rotateY(angle);
	}


	Matrix4x4 Matrix4x4::rotateZ(const Matrix4x4& mat, float angle) {
		return Matrix4x4(mat).rotateZ(angle);
	}


	Matrix4x4 Matrix4x4::transpose(const Matrix4x4& mat) {
		return Matrix4x4(mat).transpose();
	}


	Matrix4x4 Matrix4x4::translate(const Matrix4x4& mat, const Vector& vec) {
		return Matrix4x4(mat).translate(vec);
	}


	Matrix4x4 Matrix4x4::ortho(const Matrix4x4& mat, float right, float left, float top, float bottom, float far, float near) {
		return Matrix4x4(mat).ortho(right, left, top, bottom, far, near);
	}


	Matrix4x4 Matrix4x4::scale(const Matrix4x4& mat, float value) {
		return Matrix4x4(mat).scale(value);
	}

}
