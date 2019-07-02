#pragma once


#include "../math/vec3.h"
#include "../math/mat4.h"


namespace YOEngine {


	class Camera {
	public:
		Camera(const vec3& pos, YO_FLOAT fov, YO_FLOAT aspect, YO_FLOAT near, YO_FLOAT far);

		mat4 getViewProj()const;
	private:
		mat4 perspective;
		vec3 pos;
		vec3 forward;
		vec3 up;
	};


}