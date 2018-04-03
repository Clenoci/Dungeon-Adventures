#include "CustomPlayer.hpp"

CustomPlayer::CustomPlayer():CombatUnit("",10,1){

}

CustomPlayer::CustomPlayer(std::string name, int health,int damage): CombatUnit(name,health,damage){
	HealthPotion* healthPotion1= new HealthPotion();
	HealthPotion* healthPotion2= new HealthPotion();
	AddItemToInventory(healthPotion1);
	AddItemToInventory(healthPotion2);
	
}

void CustomPlayer::PrintStats(){
	std::cout<<this->name<<"'s Health: "<<this->health<<"    Weapon: "<<this->weaponWeilded->getWeaponName()<<" Damage: "<<this->damage<<std::endl;
}

void CustomPlayer::AddItemToInventory(Item* item){
	this->inventory.push_back(item);
}

void CustomPlayer::setWeaponWeilded(Weapon* weapon){

	this->weaponWeilded=weapon;
}

int CustomPlayer::getWeaponDamage(){
	return weaponWeilded->getWeaponDamage();
}

void CustomPlayer::Die(){
	std::cout<<"Awwe Schucks! You Died and and your quest for vengance was for not\n\n";
	exit(0);
}

void CustomPlayer::LookThroughInventory(){
	for(Item* item: inventory){
		std::cout<<item->GetName()<<std::endl;

	}
}

int CustomPlayer::getPlayerClass(){
	return this->playerClass;
}

Weapon* CustomPlayer::getWeaponWeilded(){

	return this->weaponWeilded;

}

void CustomPlayer::CheckIfEnemyDied(Enemy* enemy,std::vector<Enemy*> enemiesInRoom){
		if(enemy->GetHealth()==0){
			std::cout<<"\n************"<<enemy->GetName()<<" the "<<enemy->getType()<<" "<<" Has Died************\n\n";
			int count=0;
			for(Enemy* enemies:enemiesInRoom){
				if(enemy->GetName().compare(enemies->GetName())==0){
					enemiesInRoom.erase(enemiesInRoom.begin()+count);
				}
				count++;
			}
		}
}
