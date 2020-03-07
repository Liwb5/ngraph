#include "class.h"

//setter
void Student::setName(std::string name) {
    this->name = name;
}

void Student::setGender(std::string gender) {
    this->gender = gender;
}

void Student::setAge(int age) {
    this->age = age;
}

//getter
std::string Student::getName() {
    return this->name;
}

std::string Student::getGender() {
    return this->gender;
}

int Student::getAge() {
    return this->age;
}

vector<int64_t> Student::getVec() {
    return this->vec;
}


