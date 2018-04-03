#include "CombatUnit.hpp"

CombatUnit::CombatUnit(std::string name, int health,int damage){
	this->health = health;
	this->name = name;
	this->damage = damage;

}

int CombatUnit::GetHealth() {
	return this->health;
}

int CombatUnit::GetDamage() {
	return this->damage;
}

void CombatUnit::UseItem(Item* item, CombatUnit* target){
	std::cout<<this->name<<" uses "<<item->GetName()<<std::endl;
	std::cout<<item->GetDescription();
		item->Effect(target);
		if(item->GetName().compare("Health Potion") == 0){
			std::cout<<"\nHealth is now at:"<<this->GetHealth()<<std::endl;
		}
}

void CombatUnit::ModifyHealth(int amount){
	this->health -= amount;
	if(this->health<=0){
		health=0;
	}
}

void CombatUnit::DealDamage(CombatUnit* target){
	std::cout<<this->name<<" Attacks "<<target->GetName()<<"!!"<<std::endl;
	int damageThisHit= this->damage+this->damageModifier();
	std::cout<<"Hit for "<<damageThisHit<<"!\n";
	target->ModifyHealth(damageThisHit);
	std::cout<<std::endl;
	std::cin.get();
}

void CombatUnit::AddItemToInventory(Item* item){
	this->inventory.push_back(item);
}

void CombatUnit::addHealth(int healthAdded){
	this->health += healthAdded;
}

void CombatUnit::setDamage(int weaponDamage){
	this->damage +=weaponDamage;
}

std::string CombatUnit::GetName(){
	return this->name;
}

int CombatUnit::damageModifier(){
	int modifier= rand()%4+1;
	if(modifier==4){
		std::cout<<"CRITICAL HIT\n";
	}
	return modifier;

}

std::vector<Item*> CombatUnit::getInventory(){
	return this->inventory;
}

void CombatUnit::setInventory(std::vector<Item*> Inventory){
	this->inventory=Inventory;
}
