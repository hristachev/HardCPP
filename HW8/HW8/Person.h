#pragma once
#ifndef Person8_h
#define Person8_h

#include <iostream>
#include <tuple>
#include <iomanip>
#include <optional>

//class Person
//{
//public:
//	std::string name, surname;
//	std::optional<std::string> middleName;
//	Person(const std::string& cName, const std::string& cSurname, const std::optional<std::string>& cMiddleName) : name(cName), surname(cSurname), middleName(cMiddleName) {}
//	std::string getSurname() const { return surname; }
//	friend std::ostream& operator<< (std::ostream& os, const Person& person);
//	friend bool operator<(const Person& pers1, const Person& pers2);
//	friend bool operator==(const Person& pers1, const Person& pers2);
//};
//
//std::ostream& operator<< (std::ostream& os, const Person& person) {
//	return os << std::setw(12) << person.surname << " " << std::setw(9) << person.name << " " << std::setw(14) << person.middleName.value_or("");
//}
//bool operator<(const Person& pers1, const Person& pers2) {
//	return std::tie(pers1.name, pers1.surname, pers1.middleName) < std::tie(pers2.name, pers2.surname, pers2.middleName);
//}
//bool operator==(const Person& pers1, const Person& pers2) {
//	return std::tie(pers1.name, pers1.surname, pers1.middleName) == std::tie(pers2.name, pers2.surname, pers2.middleName);
struct Person {
	std::string name;
	std::string surname;
	std::optional<std::string> middleName;
};

#endif 