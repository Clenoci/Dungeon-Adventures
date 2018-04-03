#include "Skeleton.hpp"

Skeleton::Skeleton():Enemy("",25,"Skeleton",1){

}

Skeleton::Skeleton(std::string name,int health, int damage):Enemy(name,health,"Skeleton",damage){

}
