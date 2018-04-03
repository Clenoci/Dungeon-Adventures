#ifndef CUSTOMPLAYER_HPP
#define CUSTOMPLAYER_HPP

#include "CombatUnit.hpp"
#include "Weapon.hpp"

class CustomPlayer : public CombatUnit {
public:
	CustomPlayer();
	CustomPlayer(std::string Name, int health,int damage);
	void AddItemToInventory(Item* item);
	void PrintStats();
	virtual void chooseWeapon(int WeaponChoice)=0;
	void setWeaponWeilded(Weapon* weapon);
	int getWeaponDamage();
	Weapon* getWeaponWeilded();
	int getPlayerClass();
	void Die();
	void LookThroughInventory();
	virtual void Attack1(Enemy* enemy)=0;
	virtual void Attack2(std::vector<Enemy*> enemiesInRoom)=0; 
	virtual void Attack(std::vector<Enemy*> enemiesInRoom)=0;
	void CheckIfEnemyDied(Enemy* enemy,std::vector<Enemy*> enemiesInRoom);
private:
	Weapon* weaponWeilded;
	int playerClass;
};
#endif