#include "stdafx.h"
#include "PAPNamedObject.h"


PAPNamedObject::PAPNamedObject(){
	_name = new string("");
	PAPObjectManager::getInstance().addObject(this);
}


PAPNamedObject::PAPNamedObject(const string name){
	_name = new string(name);
	PAPObjectManager::getInstance().addObject(this);
}

PAPNamedObject::~PAPNamedObject(){
	delete _name;
}


void PAPNamedObject::setName(const string newName) {
	delete _name;
	_name = new string(newName);
}

string PAPNamedObject::getName(){
	return string(*_name);
}
