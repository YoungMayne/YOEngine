#include "Vec.h"


namespace yo {

	Vector::Vector(float x, float y, float z) {
		set(x, y, z);
	}


	Vector::Vector(const Vector& other) {
		set(other.x, other.y, other.z);
	}


	Vector::Vector(float value) {
		set(value);
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


	void Vector::add(const Vector& other) {
		add(other.x, other.y, other.z);
	}


	void Vector::add(float x, float y, float z) {
		this->x += x;
		this->y += y;
		this->z += z;
	}


	void Vector::add(float value) {
		add(value, value, value);
	}


	void Vector::sub(const Vector& other) {
		sub(other.x, other.y, other.z);
	}


	void Vector::sub(float x, float y, float z) {
		this->x -= x;
		this->y -= y;
		this->z -= z;
	}


	void Vector::sub(float value) {
		sub(value, value, value);
	}


	void Vector::mult(float value) {
		x *= value;
		y *= value;
		z *= value;
	}


	void Vector::div(float value) {
		float temp = 1 / value;
		x *= temp;
		y *= temp;
		z *= temp;
	}


	void Vector::setMag(float value) {
		float temp = 1 / mag() * value;
		set(x * temp, y * temp, z * temp);
	}


	void Vector::normalize() {
		float temp = 1 / mag();
		set(x * temp, y * temp, z * temp);
	}


	void Vector::rotate(float angle) {
		float tempX = x;
		x = tempX * cos(angle) - y * sin(angle);
		y = tempX * sin(angle) + y * cos(angle);
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


	Vector Vector::add(const Vector& first, const Vector& second) {
		return Vector(first.x + second.x, first.y + second.y, first.z + second.z);
	}


	Vector Vector::sub(const Vector& first, const Vector& second) {
		return Vector(first.x - second.x, first.y - second.y, first.z - second.z);
	}


	Vector Vector::mult(const Vector& vec, float value) {
		return Vector(vec.x * value, vec.y * value, vec.z * value);
	}


	Vector Vector::div(const Vector& vec, float value) {
		return Vector(vec.x / value, vec.y / value, vec.z / value);
	}


	Vector Vector::normalize(const Vector& vec) {
		Vector result = vec;
		result.normalize();
		return result;
	}


	Vector Vector::rotate(const Vector& vec, float angle) {
		return Vector(vec.x * cos(angle) - vec.y * sin(angle), vec.x * sin(angle) + vec.y * cos(angle), vec.z);
	}


	float Vector::dot(const Vector& first, const Vector& second) {
		return first.dot(second);
	}


	float Vector::dot(const Vector& vec, float x, float y, float z) {
		return vec.dot(x, y, z);
	}


	float Vector::dot(float fX, float fY, float fZ, float sX, float sY, float sZ) {
		return Vector(fX, fY, fZ).dot(sX, sY, sZ);
	}


	Vector Vector::cross(const Vector& first, const Vector& second) {
		return first.cross(second);
	}


	Vector Vector::cross(const Vector& vec, float x, float y, float z) {
		return vec.cross(x, y, z);
	}


	Vector Vector::cross(float fX, float fY, float fZ, float sX, float sY, float sZ) {
		return Vector(fX, fY, fZ).cross(sX, sY, sZ);
	}


	float Vector::angleBetween(const Vector& first, const Vector& second) {
		return first.angleBetween(second);
	}


	float Vector::angleBetween(const Vector& vec, float x, float y, float z) {
		return vec.angleBetween(x, y, z);
	}


	float Vector::angleBetween(float fX, float fY, float fZ, float sX, float sY, float sZ) {
		return Vector(fX, fY, fZ).angleBetween(sX, sY, sZ);
	}


	float Vector::mag(const Vector& vec) {
		return vec.mag();
	}


	float Vector::mag(float x, float y, float z) {
		return sqrt(x * x + y * y + z * z);
	}


	float Vector::dist(const Vector& first, const Vector& second) {
		return first.dist(second);
	}


	float Vector::dist(const Vector& vec, float x, float y, float z) {
		return vec.dist(x, y, z);
	}


	float Vector::dist(float fX, float fY, float fZ, float sX, float sY, float sZ) {
		return Vector(fX, fY, fZ).dist(sX, sY, sZ);
	}

}
