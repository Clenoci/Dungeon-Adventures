#include "Object.hpp"

Object::Object(){

}

Object::Object(std::string name){
	this->ObjectName=name;
	int random=rand()%100+1;
	if(random>75){
		this->addItemToObject(new HealthPotion());
	}	
	random=rand()%100+1;
	if(random>95){
		this->addItemToObject(new StrengthPotion());
	}	
}

void Object::addItemToObject(Item* item){
	this->ItemsInObject.push_back(item);

}

std::string Object::getName(){
	return this->ObjectName;
}

std::vector<Item*> Object::getItemsInObject(){

	return ItemsInObject;
}