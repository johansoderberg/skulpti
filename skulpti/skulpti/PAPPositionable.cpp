#include "stdafx.h"
#include "PAPPositionable.h"
#include <iostream>

using namespace std;

PAPPositionable::PAPPositionable(): PAPNamedObject() {
	
}

PAPPositionable::PAPPositionable(const string name): PAPNamedObject(name){
	
}


PAPPositionable::~PAPPositionable(){
	
}


void PAPPositionable::setPosition(const vec3 newPosition) {
	_position = newPosition;
}

vec3 PAPPositionable::getPosition() {
	return vec3(_position);
}

void PAPPositionable::setDirection(const vec3 newDirection) {
	if (length(newDirection) < 0.001f) {
		cout << "Warning: Setting direction to 0. (Object:" << getName()  << ")\n";
	}
	_direction = newDirection;
}

vec3 PAPPositionable::getDirection() {
	return vec3(_direction);
}

string PAPPositionable::getClassName() {
	return "PAPPositionable";
}
