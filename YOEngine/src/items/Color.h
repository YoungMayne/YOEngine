#pragma once

namespace yo {

	typedef char* HEX;

	struct RGBA {
		float r;
		float g;
		float b;
		float alpha;
	};

	class Color {
	public:
		Color();
		Color(const char hex[6], float alpha = 1);
		Color(float r, float g, float b, float alpha = 1);
		Color(const RGBA& color);

		void set(const char hex[6], float alpha = 1);
		void set(float r, float g, float b, float alpha = 1);
		void set(const RGBA& color);

		HEX getHEX()const;
		RGBA getRGBA()const;
	private:
		char hex[7];
		RGBA rgba;
	private:
		float to_decimal(const char& c);
		char to_hexadecimal(const unsigned& n);
	};

}
