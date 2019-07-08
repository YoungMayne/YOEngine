#pragma once


#include <iostream>

#include "../items/Types.h"


namespace YOEngine {


	class vec3 {
	public:
		vec3                      ();
		vec3                      (YO_FLOAT value);
		vec3                      (const vec3& vec);
		vec3                      (YO_FLOAT x, YO_FLOAT y, YO_FLOAT z);
	public:
		vec3& set                 (YO_FLOAT value);
		vec3& set                 (const vec3& vec);
		vec3& set                 (YO_FLOAT x, YO_FLOAT y, YO_FLOAT z);
	public:
		YO_FLOAT X                ()const;
		YO_FLOAT Y                ()const;
		YO_FLOAT Z                ()const;

		YO_FLOAT& X               ();
		YO_FLOAT& Y               ();
		YO_FLOAT& Z               ();

		YO_FLOAT* to_array        ()const;
	public:
		vec3& add                 (YO_FLOAT value);
		vec3& add                 (const vec3& vec);

		vec3& sub                 (YO_FLOAT value);
		vec3& sub                 (const vec3& vec);

		vec3& mult                (YO_FLOAT value);
		vec3& mult                (const vec3& vec);

		vec3& div                 (YO_FLOAT value);
		vec3& div                 (const vec3& vec);

		vec3& normalize           ();
		vec3& normalizeSave       ();

		YO_FLOAT dist             (const vec3& vec)const;
		YO_FLOAT distSq           (const vec3& vec)const;

		YO_FLOAT mag              ()const;
		YO_FLOAT magSq            ()const;

		vec3& setMag              (YO_FLOAT value);
		vec3& setMagSave          (YO_FLOAT value);

		vec3& limit               (YO_FLOAT value);
		vec3& limit               (const vec3& vec);

		YO_FLOAT dot              (const vec3& vec)const;

		vec3 cross                (const vec3& vec)const;
	public:
		vec3& operator=           (const vec3& vec);

		friend vec3 operator+     (const vec3& left, const vec3& right);
		friend vec3 operator+     (const vec3& left, YO_FLOAT value);
		friend vec3 operator-     (const vec3& left, const vec3& right);
		friend vec3 operator-     (const vec3& left, YO_FLOAT value);
		friend vec3 operator*     (const vec3& left, const vec3& right);
		friend vec3 operator*     (const vec3& left, YO_FLOAT value);
		friend vec3 operator/     (const vec3& left, const vec3& right);
		friend vec3 operator/     (const vec3& left, YO_FLOAT value);

		friend YO_BOOL operator== (const vec3& left, const vec3& right);
		friend YO_BOOL operator!= (const vec3& left, const vec3& right);
#ifdef _DEBUG
		void print                ()const;
#endif
	private:
		YO_FLOAT                  x;
		YO_FLOAT                  y;
		YO_FLOAT                  z;
	};


}