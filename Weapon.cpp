#include "Weapon.hpp"


Weapon::Weapon(){
	

}
Weapon::Weapon(int Weapondamage,std::string weaponName){
	this->damage=Weapondamage;
	this->WeaponName=weaponName;

}

void Weapon::SpecialMove(Enemy* badGuy){
	

}

void Weapon::printWeaponDetails(){

	std::cout<<"Weapon: "<<this->WeaponName<<"\nDamage: "<<this->damage<<"\n";
}

std::string Weapon::getWeaponName(){
	return this->WeaponName;
}

int Weapon::getWeaponDamage(){
	return this->damage;
}

std::string Weapon::getWeaponAction(){
	return this->WeaponAction;
}