#pragma once


#include <iostream>

#include "../Types.h"


namespace YOEngine {


	class vec4 {
	public:
		vec4                      ();
		vec4                      (const vec4& vec);
		vec4                      (YO_FLOAT x, YO_FLOAT y, YO_FLOAT z, YO_FLOAT w);
	public:
		vec4& set                 (YO_FLOAT value);
		vec4& set                 (const vec4& vec);
		vec4& set                 (YO_FLOAT x, YO_FLOAT y, YO_FLOAT z, YO_FLOAT w);
	public:
		YO_FLOAT X                ()const;
		YO_FLOAT Y                ()const;
		YO_FLOAT Z                ()const;
		YO_FLOAT W                ()const;

		YO_FLOAT& X               ();
		YO_FLOAT& Y               ();
		YO_FLOAT& Z               ();
		YO_FLOAT& W               ();
	public:
		vec4& add                 (YO_FLOAT value);
		vec4& add                 (const vec4& vec);

		vec4& sub                 (YO_FLOAT value);
		vec4& sub                 (const vec4& vec);

		vec4& mult                (YO_FLOAT value);
		vec4& mult                (const vec4& vec);

		vec4& div                 (YO_FLOAT value);
		vec4& div                 (const vec4& vec);
	public:
		vec4& operator=           (const vec4& vec);

		friend vec4 operator+     (const vec4& left, const vec4& right);
		friend vec4 operator+     (const vec4& left, YO_FLOAT value);
		friend vec4 operator-     (const vec4& left, const vec4& right);
		friend vec4 operator-     (const vec4& left, YO_FLOAT value);
		friend vec4 operator*     (const vec4& left, const vec4& right);
		friend vec4 operator*     (const vec4& left, YO_FLOAT value);
		friend vec4 operator/     (const vec4& left, const vec4& right);
		friend vec4 operator/     (const vec4& left, YO_FLOAT value);

		friend YO_BOOL operator== (const vec4& left, const vec4& right);
		friend YO_BOOL operator!= (const vec4& left, const vec4& right);
#ifdef _DEBUG
		void print                ()const;
#endif
	private:
		YO_FLOAT                  x;
		YO_FLOAT                  y;
		YO_FLOAT                  z;
		YO_FLOAT                  w;
	};


}