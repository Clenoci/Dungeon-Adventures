#include "BossKey.hpp"

BossKey::BossKey():Item("Boss Key","A really big key, most likely for a really big door") {
	this->setUseAble(false);
}

void BossKey::Effect(CombatUnit* target){
	this->setUseAble(0);
	std::cout<<"This has no use here, nice try though..."<<std::endl;
}




