#include "HealthPotion.hpp"

HealthPotion::HealthPotion():Item("Health Potion","Restores 50 health when drank") {

}

void HealthPotion::Effect(CombatUnit* target){
	this->setUseAble(1);
	if(target->GetHealth()<150){
	 target->addHealth(50);
	}
	else std::cout<<"You drank the potion, but nothing seemed to happen. You must have enough health already";
}

