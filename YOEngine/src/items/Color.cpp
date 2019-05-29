#include "Color.h"

namespace yo {

	Color::Color() {
		set(255, 255, 255);
	}


	Color::Color(const char hex[6], float alpha) {
		set(hex, alpha);
	}


	Color::Color(float r, float g, float b, float alpha) {
		set(r, g, b, alpha);
	}


	Color::Color(const RGBA& color) {
		set(color.r, color.g, color.b, color.alpha);
	}


	void Color::set(const char hex[6], float alpha) {
		int start_index = hex[0] == '#' ? 1 : 0;
		rgba.r = to_decimal(hex[start_index]) * 16 + to_decimal(hex[start_index + 1]);
		rgba.g = to_decimal(hex[start_index + 2]) * 16 + to_decimal(hex[start_index + 3]);
		rgba.b = to_decimal(hex[start_index + 4]) * 16 + to_decimal(hex[start_index + 5]);
		rgba.alpha = alpha;

		int index = 0;
		for (int i = start_index; i < start_index + 6; ++i) {
			this->hex[index++] = hex[i];
		}
		this->hex[6] = '\0';
	}


	void Color::set(float r, float g, float b, float alpha) {
		rgba.r = r;
		rgba.g = g;
		rgba.b = b;
		rgba.alpha = alpha;

		hex[0] = to_hexadecimal(r / 16);
		hex[1] = to_hexadecimal((int)r % 16);
		hex[2] = to_hexadecimal(g / 16);
		hex[3] = to_hexadecimal((int)g % 16);
		hex[4] = to_hexadecimal(b / 16);
		hex[5] = to_hexadecimal((int)b % 16);
		hex[6] = '/0';
	}


	void Color::set(const RGBA& color) {
		set(color.r, color.g, color.b, color.alpha);
	}


	HEX Color::getHEX() const {
		return (HEX)hex;
	}


	RGBA Color::getRGBA() const {
		return rgba;
	}


	float Color::to_decimal(const char& c) {
		if (c >= 48 && c <= 57) {
			return c - 48;
		}
		else if (c >= 65 && c <= 70) {
			return c - 55;
		}
		else if (c >= 97 && c <= 102) {
			return c - 87;
		}
		else {
			return -1;
		}
	}


	char Color::to_hexadecimal(const unsigned& n) {
		if (n <= 9) {
			return n + 48;
		}
		else if (n <= 15) {
			return n + 55;
		}
		else {
			return -1;
		}
	}

}
