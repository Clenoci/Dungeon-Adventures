#include "HellHound.hpp"

HellHound::HellHound():Enemy("name",25,"HellHound",1){

}

HellHound::HellHound(std::string name,int health,int damage):Enemy(name,health,"HellHound",damage){

}