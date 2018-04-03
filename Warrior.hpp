#ifndef WARRIOR_HPP
#define WARRIOR_HPP
#include "CustomPlayer.hpp"

class Warrior : public CustomPlayer {
public:
	Warrior();
	Warrior(std::string Name, int health,int damage);
	void chooseWeapon(int WeaponChoice);
	void Attack1(Enemy* enemy);
	void Attack2(std::vector<Enemy*> enemiesInRoom); 
	void Attack(std::vector<Enemy*> enemiesInRoom);
private:

};

#endif