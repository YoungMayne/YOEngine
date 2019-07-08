#pragma once


#include "../math/mat4.h"
#include "../math/vec3.h"
#include "Camera.h"


namespace YOEngine {


	class Transform {
	public:
		Transform();
		Transform(const vec3& pos, const vec3& rot, const vec3& scale);

		mat4 getModel()const;

		vec3& getPosition();
		vec3& getRotation();
		vec3& getScale();

		YO_VOID setPosition(const vec3& pos);
		YO_VOID setRotation(const vec3& rot);
		YO_VOID setScale(const vec3& scale);
	private:
		vec3 pos;
		vec3 rot;
		vec3 scale;
	};


}