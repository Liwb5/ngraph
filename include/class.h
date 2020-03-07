#ifndef __CLASS_H
#define __CLASS_H
#include <string>
#include <vector>
using namespace std;
 
class Student {
public:
    string name;
    string gender;
    int age;
    vector<int64_t> vec;

public:
    Student() {};
    Student(string name, string gender, int age, vector<int64_t> v){
        this->name = name;
        this->gender = gender;
        this->age = age;
        this->vec = v;
    }
    ~Student() {};
    void setName(string name);
    void setGender(string gender);
    void setAge(int age);
    string getName();
    string getGender();
    int getAge();
    vector<int64_t> getVec();
};
 
#endif /*__CLASS_H*/
