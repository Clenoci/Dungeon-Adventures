#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
#include <vector>
#include <iostream>

class CombatUnit;

class Item {
public:
	Item(std::string name, std::string description);
	std::string GetName();
	std::string GetDescription();
	void PrintData();
	virtual void Effect(CombatUnit* target) = 0;
	int getUseAble();
	void setUseAble(int use);
private:
	std::string name;
	std::string description;
	int useAble;
};

#endif