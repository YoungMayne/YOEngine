#include "Transform.h"


namespace YOEngine {

	
	Transform::Transform() {
		scale.set(1.0f, 1.0f, 1.0f);
	}


	Transform::Transform(const vec3& pos, const vec3& rot, const vec3& scale) {
		this->pos.set(pos);
		this->rot.set(rot);
		this->scale.set(scale);
	}


	mat4  Transform::getModel() const {
		mat4 posMat = mat4::translation(pos);
		mat4 rotX = mat4::rotate(rot.X(), { 1, 0, 0 });
		mat4 rotY = mat4::rotate(rot.Y(), { 0, 1, 0 });
		mat4 rotZ = mat4::rotate(rot.Z(), { 0, 0, 1 });
		mat4 scaleMat = mat4::scale(scale);
		mat4 rotMat = rotZ * rotY * rotX;

		return posMat * rotMat * scaleMat;
	}


	mat4  Transform::getMVP(const Camera& camera) const {
		return camera.getViewProj() * getModel();
	}


	vec3& Transform::getPosition() {
		return pos;
	}


	vec3& Transform::getRotation() {
		return rot;
	}


	vec3& Transform::getScale() {
		return scale;
	}


	YO_VOID  Transform::setPosition(const vec3& pos) {
		this->pos.set(pos);
	}


	YO_VOID  Transform::setRotation(const vec3& rot) {
		this->rot.set(rot);
	}


	YO_VOID  Transform::setScale(const vec3& scale) {
		this->scale.set(scale);
	}

}