#include "mat4.h"


namespace YOEngine {


	mat4::mat4() {
		for (YO_UINT i = 0; i < 16; ++i) {
			elems[i] = 0.0f;
		}
		elems[0] = 1;
		elems[5] = 1;
		elems[10] = 1;
		elems[15] = 1;
	}


	mat4::mat4(const mat4& mat) {
		for (YO_UINT i = 0; i < 16; ++i) {
			elems[i] = mat.elems[i];
		}
	}


	const YO_FLOAT* mat4::data() const {
		return elems;
	}


	mat4& mat4::add(YO_FLOAT value) {
		for (YO_UINT i = 0; i < 16; ++i) {
			elems[i] += value;
		}
		return *this;
	}


	mat4& mat4::add(const mat4& mat) {
		for (YO_UINT i = 0; i < 16; ++i) {
			elems[i] += mat.elems[i];
		}
		return *this;
	}


	mat4& mat4::sub(YO_FLOAT value) {
		for (YO_UINT i = 0; i < 16; ++i) {
			elems[i] -= value;
		}
		return *this;
	}


	mat4& mat4::sub(const mat4& mat) {
		for (YO_UINT i = 0; i < 16; ++i) {
			elems[i] -= mat.elems[i];
		}
		return *this;
	}


	mat4& mat4::mult(YO_FLOAT value) {
		for (YO_UINT i = 0; i < 16; ++i) {
			elems[i] *= value;
		}
		return *this;
	}


	mat4& mat4::mult(const mat4& mat) {
		for (YO_UINT i = 0; i < 4; ++i) {
			for (YO_UINT j = 0; j < 4; ++j) {
				YO_FLOAT temp = 0.0f;
				for (YO_UINT k = 0; k < 4; ++k) {
					temp += elems[j + k * 4] * mat.elems[k + i * 4];
				}
				elems[j + i * 4] = temp;
			}
		}
		return *this;
	}


	mat4& mat4::operator=(const mat4& mat) {
		for (YO_UINT i = 0; i < 16; ++i) {
			elems[i] = mat.data()[i];
		}
		return *this;
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
		return mat4(left).mult(right);
	}


	mat4 operator*(const mat4& left, YO_FLOAT value) {
		return mat4(left).mult(value);
	}


	YO_BOOL operator==(const mat4& left, const mat4& right) {
		for (YO_UINT i = 0; i < 16; ++i) {
			if (left.elems[i] != right.elems[i]) {
				return false;
			}
		}
		return true;
	}


	YO_BOOL operator!=(const mat4& left, const mat4& right) {
		return !(left == right);
	}


	mat4 mat4::orthographic(YO_FLOAT left, YO_FLOAT right, YO_FLOAT top, YO_FLOAT bottom, YO_FLOAT near, YO_FLOAT far) {
		mat4 ortho;

		ortho.elems[0] = 2.0f / (right - left);
		ortho.elems[5] = 2.0f / (top - bottom);
		ortho.elems[10] = -(2.0f / (far - near));
		ortho.elems[12] = -((left + right) / (right - left));
		ortho.elems[13] = -((bottom + top) / (top - bottom));
		ortho.elems[14] = -((far + near) / (far - near));

		return ortho;
	}


	mat4 mat4::perspective(YO_FLOAT fov, YO_FLOAT aspect, YO_FLOAT near, YO_FLOAT far) {
		mat4 perspective;

		perspective.elems[0] = 1 / (aspect * tanf(fov / 2));
		perspective.elems[5] = 1 / (tanf(fov / 2));
		perspective.elems[10] = -((far + near) / (far - near));
		perspective.elems[11] = -1.0f;
		perspective.elems[14] = -((2 * far * near) / (far - near));
		perspective.elems[15] = 0;

		return perspective;
	}


	mat4 mat4::lookAt(const vec3& eye, const vec3& target, const vec3& up) {
		mat4 look;

		vec3 z = vec3(target - eye).normalize();
		vec3 x = vec3(z).cross(up).normalize();
		vec3 y = vec3(x).cross(z).normalize();

		look.elems[0] = x.X();
		look.elems[4] = x.Y();
		look.elems[8] = x.Z();
		look.elems[12] = -x.dot(eye);

		look.elems[1] = y.X();
		look.elems[6] = y.Y();
		look.elems[10] = y.Z();
		look.elems[14] = -y.dot(eye);

		look.elems[2] = -z.X();
		look.elems[7] = -z.Y();
		look.elems[10] = -z.Z();
		look.elems[13] = -z.dot(eye);

		return look;
	}


	mat4 mat4::translation(const vec3& vec) {
		mat4 translation;

		translation.elems[12] = vec.X();
		translation.elems[13] = vec.Y();
		translation.elems[14] = vec.Z();

		return translation;
	}


	mat4 mat4::identity(YO_FLOAT diagonal) {
		mat4 identity;

		for (YO_UINT i = 0; i < 4; ++i) {
			identity.elems[i + i * 4] = diagonal;
		}

		return identity;
	}


	mat4 mat4::rotate(YO_FLOAT angle, const vec3& rot) {
		YO_FLOAT cos = cosf(angle);
		YO_FLOAT sin = sinf(angle);
		YO_FLOAT theta = 1.0f - cos;

		vec3 norm = vec3(rot).normalize();

		mat4 rotate;

		rotate.elems[0] = norm.X() * norm.X() * theta + cos;
		rotate.elems[1] = norm.X() * norm.Y() + norm.Z() * sin;
		rotate.elems[2] = norm.X() * norm.Z() * theta - norm.Y() * sin;

		rotate.elems[4] = norm.X() * norm.Y() * theta - norm.Z() * sin;
		rotate.elems[5] = norm.Y() * norm.Y() * theta + cos;
		rotate.elems[6] = norm.Y() * norm.Z() * theta + norm.X() * sin;

		rotate.elems[8] = norm.X() * norm.Z() * theta + norm.Y() * sin;
		rotate.elems[9] = norm.Y() * norm.Z() * theta - norm.X() * sin;
		rotate.elems[10] = norm.Z() * norm.Z() * theta + cos;

		return rotate;
	}



	mat4 mat4::scale(const vec3& vec) {
		mat4 scale = mat4::identity(0);

		scale.elems[0] = vec.X();
		scale.elems[5] = vec.Y();
		scale.elems[10] = vec.Z();
		scale.elems[15] = 1.0f;

		return scale;
	}


#ifdef _DEBUG
	void mat4::print() const {
		for (YO_UINT i = 0; i < 4; ++i) {
			for (YO_UINT j = 0; j < 4; ++j) {
				std::cout << elems[i + j * 4] << '\t';
			}
			std::cout << std::endl;
		}
	}
#endif


}