#pragma once


#ifdef _DEBUG
#include <iostream>
#endif 

#include "vec3.h"
#include "../items/Types.h"


namespace YOEngine {


	class mat4 {
	public:
		mat4                      ();
		mat4                      (const mat4& mat);
		mat4                      (const YO_FLOAT* array);
	public:
		mat4& set                 (const mat4& mat);
	public:
		YO_FLOAT* operator[]      (YO_UINT n);
		const YO_FLOAT* operator[]       (YO_UINT n)const;
	public:
		mat4& add                 (YO_FLOAT value);
		mat4& add                 (const mat4& mat);

		mat4& sub                 (YO_FLOAT value);
		mat4& sub                 (const mat4& mat);

		mat4& mult                (YO_FLOAT value);
		mat4& mult                (const mat4& mat);
	public:
		mat4& operator=           (const mat4& mat);

		friend mat4 operator+     (const mat4& left, const mat4& right);
		friend mat4 operator+     (const mat4& left, YO_FLOAT value);
		friend mat4 operator-     (const mat4& left, const mat4& right);
		friend mat4 operator-     (const mat4& left, YO_FLOAT value);
		friend mat4 operator*     (const mat4& left, const mat4& right);
		friend mat4 operator*     (const mat4& left, YO_FLOAT value);

		friend YO_BOOL operator== (const mat4& left, const mat4& right);
		friend YO_BOOL operator!= (const mat4& left, const mat4& right);
	public:
		static mat4 scale(const vec3& vec);
		static mat4 lookAt(const vec3& eye, const vec3& target, const vec3& up);
		static mat4 identity(YO_FLOAT diagonal = 1.0f);
		static mat4 orthographic(YO_FLOAT right, YO_FLOAT left, YO_FLOAT top, YO_FLOAT bottom, YO_FLOAT far, YO_FLOAT near);
		static mat4 rotation(YO_FLOAT angle, const vec3& vec);
		static mat4 translation(const vec3& vec);
		static mat4 perspective(YO_FLOAT fov, YO_FLOAT aspect, YO_FLOAT near, YO_FLOAT far);
#ifdef _DEBUG
		void print                ()const;
#endif
	private:
		YO_FLOAT                  elems[4][4];
	};


}