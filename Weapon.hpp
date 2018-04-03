#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include "Enemy.hpp"

class Weapon{
	
	public:
		Weapon();
		Weapon(int damage, std::string name);
		void SpecialMove(Enemy* badGuy);
		void printWeaponDetails();
		std::string getWeaponName();
		int getWeaponDamage();
		std::string getWeaponAction();

	private:
		int damage;
		std::string WeaponName;
		std::string WeaponAction;

};

#endif