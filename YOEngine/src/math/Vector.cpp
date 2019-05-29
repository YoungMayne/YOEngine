#include "Vector.h"


namespace yo {

	Vector::Vector(float x, float y, float z) {
		set(x, y, z);
	}


	Vector::Vector(const Vector& other) {
		set(other.x, other.y, other.z);
	}


	void Vector::set(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}


	void Vector::set(const Vector& other) {
		set(other.x, other.y, other.z);
	}


	void Vector::set(float value) {
		set(value, value, value);
	}


	Vector& Vector::add(const Vector& other) {
		return add(other.x, other.y, other.z);
	}


	Vector& Vector::add(float x, float y, float z) {
		this->x += x;
		this->y += y;
		this->z += z;
		return *this;
	}


	Vector& Vector::add(float value) {
		return add(value, value, value);
	}


	Vector& Vector::sub(const Vector& other) {
		return sub(other.x, other.y, other.z);
	}


	Vector& Vector::sub(float x, float y, float z) {
		this->x -= x;
		this->y -= y;
		this->z -= z;
		return *this;
	}


	Vector& Vector::sub(float value) {
		return sub(value, value, value);
	}


	Vector& Vector::mult(float value) {
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}


	Vector& Vector::div(float value) {
		return mult(1 / value);
	}


	void Vector::setMag(float value) {
		float temp = 1 / mag() * value;
		set(x * temp, y * temp, z * temp);
	}


	Vector& Vector::normalize() {
		return mult(1 / mag());
	}


	Vector& Vector::rotate(float angle) {
		x = x * cos(angle) - y * sin(angle);
		y = x * sin(angle) + y * cos(angle), z;
		return *this;
	}


	Vector Vector::fromAngle(float angle) const {
		return Vector(1, 0, 0).rotate(angle);
	}


	float Vector::dot(const Vector& other) const {
		return dot(other.x, other.y, other.z);
	}


	float Vector::dot(float x, float y, float z) const {
		return this->x * x + this->y * y + this->z * z;
	}


	Vector Vector::cross(const Vector& other) const {
		return cross(other.x, other.y, other.z);
	}


	Vector Vector::cross(float x, float y, float z) const {
		return Vector(this->y * z - this->z * y, -(this->x * z - this->z * x), this->x * y - this->y * x);
	}


	float Vector::angleBetween(const Vector& other) const {
		return angleBetween(other.x, other.y, other.z);
	}


	float Vector::angleBetween(float x, float y, float z) const {
		return acos(dot(x, y, z) / (mag() * Vector(x, y, z).mag()));
	}


	float Vector::mag() const {
		return sqrt(x * x + y * y + z * z);
	}


	float Vector::dist(const Vector& other) const {
		return dist(other.x, other.y, other.z);
	}


	float Vector::dist(float x, float y, float z) const {
		float tempX = this->x - x;
		float tempY = this->y - y;
		float tempZ = this->z - z;
		return sqrt(tempX * tempX + tempY * tempY + tempZ * tempZ);
	}


#ifdef _DEBUG
	std::ostream& operator<<(std::ostream& os, const Vector& vec) {
		os << "[ " << vec.x << ", " << vec.y << ", " << vec.z << " ]";
		return os;
	}
#endif


	Vector operator+(const Vector& first, const Vector& second) {
		return Vector(first).add(second);
	}


	Vector operator-(const Vector& first, const Vector& second) {
		return Vector(first).sub(second);
	}


	Vector operator+(const Vector& vec, float value) {
		return Vector(vec).add(value);
	}


	Vector operator-(const Vector& vec, float value) {
		return Vector(vec).sub(value);
	}


	Vector operator*(const Vector& vec, float value) {
		return Vector(vec).mult(value);
	}


	Vector operator/(const Vector& vec, float value) {
		return Vector(vec).div(value);
	}


	Vector Vector::normalize(const Vector& vec) {
		return Vector(vec).normalize();
	}


	Vector Vector::rotate(const Vector& vec, float angle) {
		return Vector(vec).rotate(angle);
	}

}
