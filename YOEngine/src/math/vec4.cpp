#include "vec4.h"


namespace YOEngine {


	vec4::vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}


	vec4::vec4(const vec4& vec) : x(vec.x), y(vec.y), z(vec.z), w(vec.w) {}


	vec4::vec4(YO_FLOAT x, YO_FLOAT y, YO_FLOAT z, YO_FLOAT w) : x(x), y(y), z(z), w(w) {}


	vec4& vec4::set(YO_FLOAT value) {
		return set(value, value, value, value);
	}


	vec4& vec4::set(const vec4& vec) {
		return set(vec.x, vec.y, vec.z, vec.w);
	}


	vec4& vec4::set(YO_FLOAT x, YO_FLOAT y, YO_FLOAT z, YO_FLOAT w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
		return *this;
	}


	YO_FLOAT vec4::X() const {
		return x;
	}


	YO_FLOAT vec4::Y() const {
		return y;
	}


	YO_FLOAT vec4::Z() const {
		return z;
	}


	YO_FLOAT vec4::W() const {
		return w;
	}


	YO_FLOAT& vec4::X() {
		return x;
	}


	YO_FLOAT& vec4::Y() {
		return y;
	}


	YO_FLOAT& vec4::Z() {
		return z;
	}


	YO_FLOAT& vec4::W() {
		return w;
	}


	vec4& vec4::add(YO_FLOAT value) {
		x += value;
		y += value;
		z += value;
		w += value;
		return *this;
	}


	vec4& vec4::add(const vec4& vec) {
		x += vec.x;
		y += vec.y;
		z += vec.z;
		w += vec.w;
		return *this;
	}


	vec4& vec4::sub(YO_FLOAT value) {
		x -= value;
		y -= value;
		z -= value;
		w -= value;
		return *this;
	}


	vec4& vec4::sub(const vec4& vec) {
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
		w -= vec.w;
		return *this;
	}


	vec4& vec4::mult(YO_FLOAT value) {
		x *= value;
		y *= value;
		z *= value;
		w *= value;
		return *this;
	}


	vec4& vec4::mult(const vec4& vec) {
		x *= vec.x;
		y *= vec.y;
		z *= vec.z;
		w *= vec.w;
		return *this;
	}


	vec4& vec4::div(YO_FLOAT value) {
		return mult(1.0f / value);
	}


	vec4& vec4::div(const vec4& vec) {
		x /= vec.x;
		y /= vec.y;
		z /= vec.z;
		w /= vec.w;
		return *this;
	}


	vec4& vec4::operator=(const vec4& vec) {
		return set(vec);
	}


	vec4 operator+(const vec4& left, const vec4& right) {
		return vec4(left).add(right);
	}


	vec4 operator+(const vec4& left, YO_FLOAT value) {
		return vec4(left).add(value);
	}


	vec4 operator-(const vec4& left, const vec4& right) {
		return vec4(left).sub(right);
	}


	vec4 operator-(const vec4& left, YO_FLOAT value) {
		return vec4(left).sub(value);
	}


	vec4 operator*(const vec4& left, const vec4& right) {
		return vec4(left).mult(right);
	}


	vec4 operator*(const vec4& left, YO_FLOAT value) {
		return vec4(left).mult(value);
	}


	vec4 operator/(const vec4& left, const vec4& right) {
		return vec4(left).div(right);
	}


	vec4 operator/(const vec4& left, YO_FLOAT value) {
		return vec4(left).div(value);
	}


	YO_BOOL operator==(const vec4& left, const vec4& right) {
		return left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w;
	}


	YO_BOOL operator!=(const vec4& left, const vec4& right) {
		return !(left == right);
	}


#ifdef _DEBUG
	void vec4::print() const {
		std::cout << '(' << x << ", " << y << ", " << z << ", " << w << ')' << std::endl;
	}
#endif

}