#ifndef COMBATUNIT_HPP
#define COMBATUNIT_HPP
#include "Item.hpp"
#include "HealthPotion.hpp"
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 

class Item;

class CombatUnit {
public:
	CombatUnit(std::string name,int health,int damage);
 	void UseItem(Item* item, CombatUnit* target);
	void ModifyHealth(int amount);
	void DealDamage(CombatUnit* target);
	void addHealth(int healthAdded);
	int GetHealth();
	int GetDamage();
	std::string GetName();
	void setDamage(int weaponDamage);
	void AddItemToInventory(Item* item);
	virtual void PrintStats()= 0; 
	int damageModifier();
	std::vector<Item*> getInventory();
	void setInventory(std::vector<Item*> Inventory);


protected:
	int health;
	int damage;
	std::string name;
	std::vector<Item*> inventory;
	bool skipTurn;
	int damageMod;

};

#endif