#include "mat4.h"


namespace YOEngine {


	mat4::mat4() {
		for (YO_UINT row = 0; row < 4; ++row) {
			for (YO_UINT col = 0; col < 4; ++col) {
				elems[row][col] = row == col;
			}
		}
	}


	mat4::mat4(const mat4& mat) {
		for (YO_UINT i = 0; i < 4; ++i) {
			for (YO_UINT j = 0; j < 4; ++j) {
				elems[i][j] = mat[j][i];
			}
		}
	}


	mat4::mat4(const YO_FLOAT* array) {
		for (YO_UINT row = 0; row < 4; ++row) {
			for (YO_UINT col = 0; col < 4; ++col) {
				elems[row][col] = array[row + col * 4];
			}
		}
	}


	mat4& mat4::set(const mat4& mat) {
		for (YO_UINT row = 0; row < 4; ++row) {
			for (YO_UINT col = 0; col < 4; ++col) {
				elems[row][col] = mat[row][col];
			}
		}
		return *this;
	}


	YO_FLOAT* mat4::operator[](YO_UINT n) {
		if (n < 4) {
			return elems[n];
		}
		throw "Out of bounds";
	}


	const YO_FLOAT* mat4::operator[](YO_UINT n) const {
		if (n < 4) {
			return elems[n];
		}
		throw "Out of bounds";
	}


	mat4& mat4::add(YO_FLOAT value) {
		for (YO_UINT row = 0; row < 4; ++row) {
			for (YO_UINT col = 0; col < 4; ++col) {
				elems[row][col] += value;
			}
		}
		return *this;
	}


	mat4& mat4::add(const mat4& mat) {
		for (YO_UINT row = 0; row < 4; ++row) {
			for (YO_UINT col = 0; col < 4; ++col) {
				elems[row][col] += mat[row][col];
			}
		}
		return *this;
	}


	mat4& mat4::sub(YO_FLOAT value) {
		for (YO_UINT row = 0; row < 4; ++row) {
			for (YO_UINT col = 0; col < 4; ++col) {
				elems[row][col] -= value;
			}
		}
		return *this;
	}


	mat4& mat4::sub(const mat4& mat) {
		for (YO_UINT row = 0; row < 4; ++row) {
			for (YO_UINT col = 0; col < 4; ++col) {
				elems[row][col] -= mat[row][col];
			}
		}
		return *this;
	}


	mat4& mat4::mult(YO_FLOAT value) {
		for (YO_UINT row = 0; row < 4; ++row) {
			for (YO_UINT col = 0; col < 4; ++col) {
				elems[row][col] *= value;
			}
		}
		return *this;
	}


	mat4& mat4::mult(const mat4& mat) {
		return *this = *this * mat;
	}


	mat4& mat4::operator=(const mat4& mat) {
		return set(mat);
	}


	mat4 operator+(const mat4& left, const mat4& right) {
		return mat4(left).add(right);
	}


	mat4 operator+(const mat4& left, YO_FLOAT value) {
		return mat4(left).add(value);
	}


	mat4 operator-(const mat4& left, const mat4& right) {
		return mat4(left).sub(right);
	}


	mat4 operator-(const mat4& left, YO_FLOAT value) {
		return mat4(left).sub(value);
	}


	mat4 operator*(const mat4& left, const mat4& right) {
		mat4 result;
		for (YO_UINT i = 0; i < 4; ++i) {
			for (YO_UINT j = 0; j < 4; ++j) {
				result[i][j] = 0.0f;
				for (YO_UINT k = 0; k < 4; ++k) {
					result[i][j] += left[i][k] * right[k][j];
				}
			}
		}
		return result;
	}


	mat4 operator*(const mat4& left, YO_FLOAT value) {
		return mat4(left).mult(value);
	}


	YO_BOOL operator==(const mat4& left, const mat4& right) {
		for (YO_UINT row = 0; row < 4; ++row) {
			for (YO_UINT col = 0; col < 4; ++col) {
				if (left[row][col] != right[row][col]) {
					return false;
				}
			}
		}
		return true;
	}


	YO_BOOL operator!=(const mat4& left, const mat4& right) {
		return !(left == right);
	}


#ifdef _DEBUG	
	void mat4::print() const {
		for (YO_UINT row = 0; row < 4; ++row) {
			for (YO_UINT col = 0; col < 4; ++col) {
				std::cout << elems[row][col] << '\t';
			}
			std::cout << std::endl;
		}
	}
#endif


	mat4 mat4::scale(const vec3& vec) {
		mat4 result;

		result[0][0] = vec.X();
		result[1][1] = vec.Y();
		result[2][2] = vec.Z();

		return result;
	}


	mat4 mat4::lookAt(const vec3& eye, const vec3& target, const vec3& up) {
		vec3 fwd = (target - eye).normalize();
		vec3 side = fwd.cross(up).normalize();
		vec3 y = side.cross(fwd).normalize();

		mat4 result;

		result[0][0] = side.X();
		result[0][1] = y.X();
		result[0][2] = -fwd.X();

		result[1][0] = side.Y();
		result[1][1] = y.Y();
		result[1][2] = -fwd.Y();

		result[2][0] = side.Z();
		result[2][1] = y.Z();
		result[2][2] = -fwd.Z();

		result[3][0] = -side.dot(eye);
		result[3][1] = -y.dot(eye);
		result[3][2] = fwd.dot(eye);

		return result;
	}


	mat4 mat4::identity(YO_FLOAT diagonal) {
		mat4 result;

		for (YO_UINT i = 0; i < 4; ++i) {
			result[i][i] = diagonal;
		}

		return result;
	}


	mat4 mat4::orthographic(YO_FLOAT right, YO_FLOAT left, YO_FLOAT top, YO_FLOAT bottom, YO_FLOAT far, YO_FLOAT near) {
		mat4 result;
		
		result[0][0] = 2.0f / (right - left);
		result[1][1] = 2.0f / (top - bottom);
		result[2][2] = -2.0f / (far - near);
		result[3][0] = -(right + left) / (right - left);
		result[3][1] = -(top + bottom) / (top - bottom);
		result[3][2] = -(far + near) / (far - near);

		return result;
	}


	mat4 mat4::rotation(YO_FLOAT angle, const vec3& vec) {
		YO_FLOAT cos = cosf(angle);
		YO_FLOAT sin = sinf(angle);
		YO_FLOAT theta = 1.0f - cos;

		mat4 result;

		result[0][0] = vec.X() * vec.X() * theta + cos;
		result[0][1] = vec.X() * vec.Y() * theta + vec.Z() * sin;
		result[0][2] = vec.X() * vec.Z() * theta - vec.Y() * sin;

		result[1][0] = vec.X() * vec.Y() * theta - vec.Z() * sin;
		result[1][1] = vec.Y() * vec.Y() * theta + cos;
		result[1][2] = vec.Y() * vec.Z() * theta + vec.X() * sin;

		result[2][0] = vec.X() * vec.Z() * theta + vec.Y() * sin;
		result[2][1] = vec.Y() * vec.Z() * theta - vec.X() * sin;
		result[2][2] = vec.Z() * vec.Z() * theta + cos;

		return result;
	}


	mat4 mat4::translation(const vec3& vec) {
		mat4 result;

		result[3][0] = vec.X();
		result[3][1] = vec.Y();
		result[3][2] = vec.Z();

		return result;
	}


	mat4 mat4::perspective(YO_FLOAT fov, YO_FLOAT aspect, YO_FLOAT near, YO_FLOAT far) {
		mat4 result;

		result[0][0] = 1.0f / (aspect * tanf(fov / 2.0f));
		result[1][1] = 1.0f / tanf(fov / 2.0f);
		result[2][2] = -(far + near) / (far - near);
		result[2][3] = -1.0f;
		result[3][2] = -(2.0f * far * near) / (far - near);
		result[3][3] = 0.0f;

		return result;
	}


}
