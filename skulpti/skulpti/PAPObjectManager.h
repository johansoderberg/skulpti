#pragma once
#include "PAPNamedObject.h"
#include <map>
#include <string>

using namespace std;

class PAPNamedObject;

class PAPObjectManager
{
private:
	PAPObjectManager();
public:
	static PAPObjectManager& getInstance();
	~PAPObjectManager();
	bool addObject(PAPNamedObject* object);
	PAPNamedObject* getObject(const string objectName);
	bool deleteObject(const string objectName);
protected:
	map<string, PAPNamedObject*>* _objects;
	string getAcceptableName(const string name);
};

