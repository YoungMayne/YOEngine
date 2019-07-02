#pragma once


#include <iostream>

#include "../Types.h"


namespace YOEngine {


	class vec2 {
	public:
		vec2                      ();
		vec2                      (YO_FLOAT value);
		vec2                      (const vec2& vec);
		vec2                      (YO_FLOAT x, YO_FLOAT y);
	public:
		vec2& set                 (YO_FLOAT x, YO_FLOAT y);
		vec2& set                 (const vec2& vec);
		vec2& set                 (YO_FLOAT value);
	public:
		YO_FLOAT X                ()const;
		YO_FLOAT Y                ()const;

		YO_FLOAT& X               ();
		YO_FLOAT& Y               ();
	public:
		vec2& add                 (YO_FLOAT value);
		vec2& add                 (const vec2& vec);

		vec2& sub                 (YO_FLOAT value);
		vec2& sub                 (const vec2& vec);

		vec2& mult                (YO_FLOAT value);
		vec2& mult                (const vec2& vec);

		vec2& div                 (YO_FLOAT value);
		vec2& div                 (const vec2& vec);

		vec2& normalize           ();
		vec2& normalizeSave       ();

		YO_FLOAT dist             (const vec2& vec)const;
		YO_FLOAT distSq           (const vec2& vec)const;

		YO_FLOAT mag              ()const;
		YO_FLOAT magSq            ()const;

		vec2& setMag              (YO_FLOAT value);
		vec2& setMagSave          (YO_FLOAT value);

		vec2& limit               (YO_FLOAT value);
		vec2& limit               (const vec2& vec);

		YO_FLOAT dot              (const vec2& vec)const;
	public:
		vec2& operator=           (const vec2& vec);

		friend vec2 operator+     (const vec2& left, const vec2& right);
		friend vec2 operator+     (const vec2& left, YO_FLOAT value);
		friend vec2 operator-     (const vec2& left, const vec2& right);
		friend vec2 operator-     (const vec2& left, YO_FLOAT value);
		friend vec2 operator*     (const vec2& left, const vec2& right);
		friend vec2 operator*     (const vec2& left, YO_FLOAT value);
		friend vec2 operator/     (const vec2& left, const vec2& right);
		friend vec2 operator/     (const vec2& left, YO_FLOAT value);

		friend YO_BOOL operator== (const vec2& left, const vec2& right);
		friend YO_BOOL operator!= (const vec2& left, const vec2& right);
#ifdef _DEBUG
		void print                ()const;
#endif 
	private:
		YO_FLOAT                  x;
		YO_FLOAT                  y;
	};


}