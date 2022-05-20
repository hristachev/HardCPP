#pragma once
#ifndef PhoneBook_h
#define PhoneBook_h

#include "Person.h"
#include "PhoneNumber.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <string>

class PhoneBook
{
public:
	PhoneBook(std::ifstream& str) {
		std::string name, surname;
		std::optional<std::string> middleName;
		uint16_t countryCode, cityCode;
		std::string number;
		std::optional<uint16_t> additional;
		std::optional<std::string> end;
		if (str.is_open())
		{
			while (str >> name >> surname >> middleName.emplace() >> countryCode >> cityCode >> number >> end.emplace()) {
				if (middleName.has_value())
					if (middleName.value() == "-")
						middleName = std::nullopt;
				Person person(surname, name, middleName);
				if (end.has_value())
					if (end.value() == "-")
						additional = std::nullopt;
					else
						additional.emplace() = std::stoi(end.value());
				PhoneNumber num(countryCode, cityCode, number, additional);
				book.push_back(std::make_pair(person, num));
			}
		}
		str.close();
	}
	void SortByName();
	void SortByPhone();
	std::tuple<std::string, PhoneNumber> GetPhoneNumber(const std::string& surname);
	void ChangePhoneNumber(const Person& person, const PhoneNumber& newNumber);
	friend std::ostream& operator<< (std::ostream& os, PhoneBook book);
private:
	std::vector<std::pair<Person, PhoneNumber>> book;
};

class Less
{
public:
	Less(bool cFlag = false) : flag(cFlag) {}
	bool operator()(const std::pair<Person, PhoneNumber>& left, const std::pair<Person, PhoneNumber>& right) {
		if (left.first == right.first || flag)
			return left.second < right.second;
		else
			return left.first < right.first;
	}
private:
	bool flag;
};

void PhoneBook::SortByName(){
	Less less;
	std::sort(book.begin(), book.end(), less);
}
void PhoneBook::SortByPhone(){
	Less less(true);
	std::sort(book.begin(), book.end(), less);
}
std::tuple<std::string, PhoneNumber> PhoneBook::GetPhoneNumber(const std::string& surname) {
	PhoneNumber num;
	std::string out = "";
	uint8_t count{ 0 };
	std::for_each(book.begin(), book.end(),
		[&](const auto& bookRec) {
			if (bookRec.first.getSurname() == surname) {
				num = bookRec.second;
				count++;
			}
		});
	if (count == 0)
		out = "not found";
	else if (count > 1)
		out = "found more than 1";
	return std::make_tuple(out, num);
}
void PhoneBook::ChangePhoneNumber(const Person& person, const PhoneNumber& newNumber){
	auto find = std::find_if(book.begin(), book.end(),
		[&person](const auto& bookRec) {
			return bookRec.first == person;
		});
	if (find != book.end()) find->second = newNumber;
}
std::ostream& operator<< (std::ostream& os, PhoneBook book) {
	for (const auto& [person, number] : book.book)
	{
		os << person << std::setw(5) << number << std::endl;
	}
	return os;
}
#endif