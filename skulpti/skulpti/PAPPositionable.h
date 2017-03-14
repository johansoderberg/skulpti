#pragma once

#include "glm.hpp"
#include "PAPNamedObject.h"

using namespace glm;

class PAPPositionable: public PAPNamedObject
{
public:
	PAPPositionable();
	PAPPositionable(const string name);
	virtual ~PAPPositionable();

	void setPosition(const vec3 newPosition);
	vec3 getPosition();
	void setDirection(const vec3 newDirection);
	vec3 getDirection();
	string getClassName() override;
protected:
	vec3 _position;
	vec3 _up;
	vec3 _direction;
};

