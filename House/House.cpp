#include <iostream>
#include <cstring>
#include <vector>

class Person {
private:
    char* name;

public:
    Person(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name); ;
    }

    Person(const Person& other) {
        name = new char[strlen(other.name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name); ;
    }

    Person& operator=(const Person& other) {
        if (this == &other) return *this;

        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name); ;
        return *this;
    }

    ~Person() {
        delete[] name;
    }

    void show() const {
        std::cout << "Человек: " << name << std::endl;
    }
};

class Apartment {
private:
    std::vector<Person> residents;

public:
    Apartment() {}

    Apartment(const Apartment& other) {
        residents = other.residents;
    }

    void addResident(const Person& person) {
        residents.push_back(person);
    }

    void show() const {
        std::cout << "Квартира содержит " << residents.size() << " жильцов:" << std::endl;
        for (const auto& resident : residents) {
            resident.show();
        }
    }
};

class House {
private:
    std::vector<Apartment> apartments;

public:
    House() {}

    House(const House& other) {
        apartments = other.apartments;
    }

    void addApartment(const Apartment& apartment) {
        apartments.push_back(apartment);
    }

    void show() const {
        std::cout << "Дом содержит " << apartments.size() << " квартир:" << std::endl;
        for (size_t i = 0; i < apartments.size(); ++i) {
            std::cout << "Квартира " << i + 1 << ":" << std::endl;
            apartments[i].show();
        }
    }
};

int main() {
    Person person1("Aboka Chil");
    Person person2("Ilia Genadi");
    Person person3("Igor Petrov");

    Apartment apartment1;
    apartment1.addResident(person1);
    apartment1.addResident(person2);

    Apartment apartment2;
    apartment2.addResident(person3);

    House house;
    house.addApartment(apartment1);
    house.addApartment(apartment2);

    house.show();

    return 0;
}
