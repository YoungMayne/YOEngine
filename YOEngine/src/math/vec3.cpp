#include "vec3.h"


namespace YOEngine {


	vec3::vec3() : x(0.0f), y(0.0f), z(0.0f) {}


	vec3::vec3(YO_FLOAT value) : x(value), y(value), z(value) {}


	vec3::vec3(const vec3& vec) : x(vec.x), y(vec.y), z(vec.z) {}


	vec3::vec3(YO_FLOAT x, YO_FLOAT y, YO_FLOAT z) : x(x), y(y), z(z) {}


	vec3& vec3::set(YO_FLOAT value) {
		return set(value, value, value);
	}


	vec3& vec3::set(const vec3& vec) {
		return set(vec.x, vec.y, vec.z);
	}


	vec3& vec3::set(YO_FLOAT x, YO_FLOAT y, YO_FLOAT z) {
		this->x = x;
		this->y = y;
		this->z = z;
		return *this;
	}


	YO_FLOAT vec3::X() const {
		return x;
	}


	YO_FLOAT vec3::Y() const {
		return y;
	}


	YO_FLOAT vec3::Z() const {
		return z;
	}


	YO_FLOAT& vec3::X() {
		return x;
	}


	YO_FLOAT& vec3::Y() {
		return y;
	}


	YO_FLOAT& vec3::Z() {
		return z;
	}


	vec3& vec3::add(YO_FLOAT value) {
		x += value;
		y += value;
		z += value;
		return *this;
	}


	vec3& vec3::add(const vec3& vec) {
		x += vec.x;
		y += vec.y;
		z += vec.z;
		return *this;
	}


	vec3& vec3::sub(YO_FLOAT value) {
		x -= value;
		y -= value;
		z -= value;
		return *this;
	}


	vec3& vec3::sub(const vec3& vec) {
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
		return *this;
	}


	vec3& vec3::mult(YO_FLOAT value) {
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}


	vec3& vec3::mult(const vec3& vec) {
		x *= vec.x;
		y *= vec.y;
		z *= vec.z;
		return *this;
	}


	vec3& vec3::div(YO_FLOAT value) {
		return mult(1.0f / value);
	}


	vec3& vec3::div(const vec3& vec) {
		x /= vec.x;
		y /= vec.y;
		z /= vec.z;
		return *this;
	}


	vec3& vec3::normalize() {
		return div(mag());
	}


	vec3& vec3::normalizeSave() {
		return div(mag() + 0.0001f);
	}


	YO_FLOAT vec3::dist(const vec3& vec) const {
		return sqrtf(distSq(vec));
	}


	YO_FLOAT vec3::distSq(const vec3& vec) const {
		YO_FLOAT dx = x - vec.x;
		YO_FLOAT dy = y - vec.y;
		YO_FLOAT dz = z - vec.z;
		return dx * dx + dy * dy + dz * dz;
	}


	YO_FLOAT vec3::mag() const {
		return sqrtf(magSq());
	}


	YO_FLOAT vec3::magSq() const {
		return x * x + y * y + z * z;
	}


	vec3& vec3::setMag(YO_FLOAT value) {
		return normalize().mult(value);
	}


	vec3& vec3::setMagSave(YO_FLOAT value) {
		return normalizeSave().mult(value);
	}


	vec3& vec3::limit(YO_FLOAT value) {
		return mag() > value ? setMagSave(value) : *this;
	}


	vec3& vec3::limit(const vec3& vec) {
		return limit(vec.mag());
	}


	YO_FLOAT vec3::dot(const vec3& vec) const {
		return x * vec.x + y * vec.y + z * vec.z;
	}


	vec3 vec3::cross(const vec3& vec) const {
		return vec3(y * vec.z - z * vec.y, -(x * vec.z - z * vec.x), x * vec.y - y * vec.x);
	}


	vec3& vec3::operator=(const vec3& vec) {
		return set(vec);
	}


	vec3 operator+(const vec3& left, const vec3& right) {
		return vec3(left).add(right);
	}


	vec3 operator+(const vec3& left, YO_FLOAT value) {
		return vec3(left).add(value);
	}


	vec3 operator-(const vec3& left, const vec3& right) {
		return vec3(left).sub(right);
	}


	vec3 operator-(const vec3& left, YO_FLOAT value) {
		return vec3(left).sub(value);
	}


	vec3 operator*(const vec3& left, const vec3& right) {
		return vec3(left).mult(right);
	}


	vec3 operator*(const vec3& left, YO_FLOAT value) {
		return vec3(left).mult(value);
	}


	vec3 operator/(const vec3& left, const vec3& right) {
		return vec3(left).div(right);
	}


	vec3 operator/(const vec3& left, YO_FLOAT value) {
		return vec3(left).div(value);
	}


	YO_BOOL operator==(const vec3& left, const vec3& right) {
		return left.x == right.x && left.y == right.y && left.z == right.z;
	}


	YO_BOOL operator!=(const vec3& left, const vec3& right) {
		return !(left == right);
	}


#ifdef _DEBUG
	void vec3::print() const {
		std::cout << '(' << x << ", " << y << ", " << z << ')' << std::endl;
	}
#endif


}
