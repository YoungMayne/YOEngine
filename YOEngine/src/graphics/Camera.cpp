#include "Camera.h"


namespace YOEngine {


	Camera::Camera(const vec3& pos, YO_FLOAT fov, YO_FLOAT aspect, YO_FLOAT near, YO_FLOAT far)  {
		this->perspective = mat4::perspective(fov, aspect, near, far);
		this->pos = pos;
		this->forward = vec3(0, 0, -1); 
		this->up = vec3(0, 1, 0);
	}


	mat4 Camera::getViewProj() const {
		return perspective * mat4::lookAt(pos, pos + forward, up);
	}


}
