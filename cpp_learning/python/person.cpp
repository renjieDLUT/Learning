#include"person.h"
Person::Person(int id, std::string name, int age){
    id_ = id;
    name_ = name;
    age_ = age;
}

void Person::getId(){
    std::cout << "ID : " << id_ << std::endl;
}

void Person::getName(){
    std::cout << "Name: " << name_ << std::endl;
}

void Person::getAge(){
    std::cout << "Age: " << age_ << std::endl;
}
