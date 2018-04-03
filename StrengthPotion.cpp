#include "StrengthPotion.hpp"

StrengthPotion::StrengthPotion():Item("Strength Potion","Adds 3 damage to all attacks when drank") {

}

void StrengthPotion::Effect(CombatUnit* target){
	target->setDamage(3);
	//this->setUseAble(1);
}
