#include "Enemy.hpp"

Enemy::Enemy(): CombatUnit("",1,1){


}

Enemy::Enemy(std::string name,int health,std::string type,int damage): CombatUnit(name,health,damage) {
	this->EnemyType=type;
	int random=rand()%100+1;
	if(random>75){
		this->AddItemToInventory(new HealthPotion());
	}	
}

Enemy::~Enemy(){
	delete this;
}

void Enemy::PrintStats(){
	std::cout<<this->name<<" The "<<this->EnemyType<<"'s health: "<<this->health<<std::endl;
}

std::string Enemy::getType(){

	return this->EnemyType;
}
