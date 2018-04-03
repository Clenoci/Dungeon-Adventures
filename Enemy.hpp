#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "CombatUnit.hpp"
#include "Item.hpp"

class Enemy : public CombatUnit{ //public Spawnable?
public:
	Enemy();
	Enemy(std::string name,int health,std::string type,int damage);
	~Enemy();
	void PrintStats();
	std::string	getType();
	
private:
	std::string EnemyType;
	
};

#endif