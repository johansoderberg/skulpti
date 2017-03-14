#pragma once
#include <string>
#include <iostream>
#include "PAPObjectManager.h"

using namespace std;

class PAPNamedObject{
public:
	PAPNamedObject();
	PAPNamedObject(const string name);
	virtual ~PAPNamedObject();

	void setName(const string newName);
	string getName();
	virtual string getClassName() = 0;
protected:
	string *_name;

};

