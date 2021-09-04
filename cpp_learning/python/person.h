#include <string>
#include<iostream>
class Person
{
private:
    int id_;
    std::string name_;
    int age_;

public:
    Person(int id, std::string name = "renjie", int age=25);

    void getName();
    void getId();
    void getAge();
};