#ifndef BATTLEMAGE_HPP
#define BATTLEMAGE_HPP

#include "CustomPlayer.hpp"

class BattleMage : public CustomPlayer {
public:
	BattleMage();
	BattleMage(std::string Name, int health,int damage);
	void chooseWeapon(int WeaponChoice);
	void Attack1(Enemy* enemy);
	void Attack2(std::vector<Enemy*> enemiesInRoom); 
	void Attack(std::vector<Enemy*> enemiesInRoom);
private:
	
};

#endif