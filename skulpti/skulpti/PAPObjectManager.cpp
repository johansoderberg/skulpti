#include "stdafx.h"
#include "PAPObjectManager.h"
#include <sstream>


PAPObjectManager* singleton;

PAPObjectManager& PAPObjectManager::getInstance() {
	if (singleton == nullptr) {
		singleton = new PAPObjectManager();
	}
	return *singleton;
}

PAPObjectManager::PAPObjectManager()
{
	_objects = new map<string, PAPNamedObject*>();
}

PAPObjectManager::~PAPObjectManager()
{
	delete _objects;
}

bool PAPObjectManager::deleteObject(const string objectName) {
	map<string, PAPNamedObject*>::iterator iterator = _objects->find(objectName);
	if (iterator == _objects->end()) {
		return false;
	}
	PAPNamedObject* localObject = iterator->second;
	_objects->erase(iterator);
	
	delete localObject;
	return true;
}

PAPNamedObject* PAPObjectManager::getObject(const string objectName) {
	map<string, PAPNamedObject*>::iterator iterator = _objects->find(objectName);
	if (iterator == _objects->end()) {
		return nullptr;
	}
	else
		return iterator->second;
}

string PAPObjectManager::getAcceptableName(const string name) {
	// initialise return variable
	string result = name;

	// Check if no name is provided. If so, start with an semi-acceptable name.
	if (result.compare("") == 0) {
		result = "Unnamed_1";
	}

	// check to see if the name is used.
	if (_objects->find(result) == _objects->end()) {
		return result;
	}

	// see if the string contains an '_'. If not append '_1'.
	if (result.find('_') == string::npos) {
		stringstream ss;
		ss << result << "_1";
		result = ss.str();
	}

	// find the base.
	string num_s;
	string base;
	for (size_t j = result.length() - 1; j > 0; j--) {
		char c = result.at(j);
		if (isdigit(c)) {
			stringstream strb;	
			strb << c << num_s;
			num_s = strb.str();
			continue; // Next character.
		}

		if (c == '_') {
			base = result.substr(0, j);
			break;
		}
		else {
			base = name;
			break;
		}

	}

	// increase the number at the end until an unused name is encountered.
	int num = 1;
	do {
		stringstream ss2;
		ss2 << base << "_" << num;
		result = ss2.str();
		num++;
	} while (_objects->find(result) != _objects->end());
	
	return result;
}

bool PAPObjectManager::addObject(PAPNamedObject* object) {
	// verify that pointer is an object at all.
	if (object == nullptr) {
		return false;
	}

	// verify that object is not a duplicate (i.e. already exists in the map).
	try {
		PAPNamedObject* obj = _objects->at(object->getName());
		if (obj == object) {
			std::cout << "Warning: attempted to add the same object twice: " << object->getName() << endl;
			return false;
		}
		else {
			object->setName(getAcceptableName(object->getName()));
		}

	}
	catch (out_of_range e) {
		// no object exists in the map with the same name.
	}

	_objects->insert(pair<string, PAPNamedObject*>(object->getName(), object));
	return true;
}