#include "vec2.h"


namespace YOEngine {


	vec2::vec2() : x(0.0f), y(0.0f) {}


	vec2::vec2(YO_FLOAT value) : x(value), y(value) {}


	vec2::vec2(const vec2& vec) : x(vec.x), y(vec.y) {}


	vec2::vec2(YO_FLOAT x, YO_FLOAT y) : x(x), y(y) {}


	vec2& vec2::set(YO_FLOAT x, YO_FLOAT y) {
		this->x = x;
		this->y = y;
		return *this;
	}


	vec2& vec2::set(const vec2& vec) {
		return set(vec.x, vec.y);
	}


	vec2& vec2::set(YO_FLOAT value) {
		return set(value, value);
	}


	YO_FLOAT vec2::X() const {
		return x;
	}


	YO_FLOAT vec2::Y() const {
		return y;
	}


	YO_FLOAT& vec2::X() {
		return x;
	}


	YO_FLOAT& vec2::Y() {
		return y;
	}


	vec2& vec2::add(YO_FLOAT value) {
		x += value;
		y += value;
		return *this;
	}


	vec2& vec2::add(const vec2& vec) {
		x += vec.x;
		y += vec.y;
		return *this;
	}


	vec2& vec2::sub(YO_FLOAT value) {
		x -= value;
		y -= value;
		return *this;
	}


	vec2& vec2::sub(const vec2& vec) {
		x -= vec.x;
		y -= vec.y;
		return *this;
	}


	vec2& vec2::mult(YO_FLOAT value) {
		x *= value;
		y *= value;
		return *this;
	}


	vec2& vec2::mult(const vec2& vec) {
		x *= vec.x;
		y *= vec.y;
		return *this;
	}


	vec2& vec2::div(YO_FLOAT value) {
		return mult(1.0f / value);
	}


	vec2& vec2::div(const vec2& vec) {
		x /= vec.x;
		y /= vec.y;
		return *this;
	}


	vec2& vec2::normalize() {
		return div(mag());
	}


	vec2& vec2::normalizeSave() {
		return div(mag() + 0.0001f);
	}


	YO_FLOAT vec2::dist(const vec2& vec) const {
		return sqrtf(distSq(vec));
	}


	YO_FLOAT vec2::distSq(const vec2& vec) const {
		YO_FLOAT dx = x - vec.x;
		YO_FLOAT dy = y - vec.y;
		return dx * dx + dy * dy;
	}


	YO_FLOAT vec2::mag() const {
		return sqrtf(magSq());
	}


	YO_FLOAT vec2::magSq() const {
		return x * x + y * y;
	}


	vec2& vec2::setMag(YO_FLOAT value) {
		return normalize().mult(value);
	}


	vec2& vec2::setMagSave(YO_FLOAT value) {
		return normalizeSave().mult(value);
	}


	vec2& vec2::limit(YO_FLOAT value) {
		return mag() > value ? setMagSave(value) : *this;
	}


	vec2& vec2::limit(const vec2& vec) {
		return limit(vec.mag());
	}


	YO_FLOAT vec2::dot(const vec2& vec) const {
		return x * vec.x + y * vec.y;
	}


	vec2& vec2::operator=(const vec2& vec) {
		return set(vec);
	}


	vec2 operator+(const vec2& left, const vec2& right) {
		return vec2(left).add(right);
	}


	vec2 operator+(const vec2& left, YO_FLOAT value) {
		return vec2(left).add(value);
	}


	vec2 operator-(const vec2& left, const vec2& right) {
		return vec2(left).sub(right);
	}


	vec2 operator-(const vec2& left, YO_FLOAT value) {
		return vec2(left).sub(value);
	}


	vec2 operator*(const vec2& left, const vec2& right) {
		return vec2(left).mult(right);
	}


	vec2 operator*(const vec2& left, YO_FLOAT value) {
		return vec2(left).mult(value);
	}


	vec2 operator/(const vec2& left, const vec2& right) {
		return vec2(left).div(right);
	}


	vec2 operator/(const vec2& left, YO_FLOAT value) {
		return vec2(left).div(value);
	}


	YO_BOOL operator==(const vec2& left, const vec2& right) {
		return left.x == right.x && left.y == right.y;
	}


	YO_BOOL operator!=(const vec2& left, const vec2& right) {
		return !(left == right);
	}


#ifdef _DEBUG
	void vec2::print() const {
		std::cout << '(' << x << ", " << y << ')' << std::endl;
	}
#endif


}
