#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "HealthPotion.hpp"
#include "StrengthPotion.hpp"

class Object{

	public:
	Object();
	Object(std::string name);
	void addItemToObject(Item* item);
	std::string getName();
	std::vector<Item*> getItemsInObject();

	private:
	std::string ObjectName;	
	std::vector<Item*> ItemsInObject;


};

#endif