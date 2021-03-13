#pragma once
#include <iostream>
#include<sstream>

class Users {
protected:
	std::string id;
	std::string name;
	std::string password;
	std::string role;		//Administrator, Maintenance, Register, Student, Profesor
    bool status = true;

public:
    Users(std::string _id, std::string _name, std::string _password, std::string _role) {
        this->id = _id;
        this->name = _name;
        this->password = _password;
        this->role = _role;
    }

    std::string getId() const { return id; }
    void setId(std::string id) { this->id = id; }

    std::string getName() const { return name; }
    void setName(std::string name) { this->name = name; }

    std::string getPassword() const { return password; }
    void setPassword(std::string password) { this->password = password; }

    std::string getRole() const { return role; }
    void setRole(std::string role) { this->role = role; }

    bool getStatus() { return status; }
    void setStatus(bool s) { this->status = s; }
     std::string toString() {
        std::stringstream x;

        x << this->name;

        return x.str();
    }
};

class Student : public Users {
public:
    Student(std::string id, std::string name, std::string password, std::string role) : Users(id, name, password, role) {

    }
};

class Professor : public Users {
public:
    Professor(std::string id, std::string name, std::string password, std::string role) : Users(id, name, password, role) {

    }
};

class Administrator : public Users {
public:
    Administrator(std::string id, std::string name, std::string password, std::string role) : Users(id, name, password, role) {

    }
};

class Maintenance : public Users {
public:
    Maintenance(std::string id, std::string name, std::string password, std::string role) : Users(id, name, password, role) {

    }
};

class Register : public Users {
public:
    Register(std::string id, std::string name, std::string password, std::string role) : Users(id, name, password, role) {

    }
};