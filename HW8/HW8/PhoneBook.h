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
#include <sstream>

std::optional<std::string> getOptStr(std::string& s) {
    if (s == "")
    {
        return std::nullopt;
    }
    return s;
}
std::optional<int> getOptInt(std::string& s) {
    if (s == "")
    {
        return std::nullopt;
    }

    return std::stoi(s);
}

class PhoneBook
{
public:
    PhoneBook(std::istream& str) {
        if (!str)
        {
            std::cout << "Do not open file!" << std::endl;
            exit(1);
        }

        for (std::string line; std::getline(str, line);)
        {
            std::stringstream str(line);
            std::vector<std::string> rowData;

            for (std::string s; getline(str, s, ';');)
            {
                rowData.push_back(s);
            }

            std::pair<Person, PhoneNumber> entry;

            for (size_t i = 0; i < rowData.size(); ++i)
            {
                switch (i)
                {
                case 0:
                    entry.first.name = rowData[i];
                    break;
                case 1:
                    entry.first.surname = rowData[i];
                    break;
                case 2:
                    entry.first.middleName = getOptStr(rowData[i]);
                    break;
                case 3:
                    entry.second.countryCode = stoi(rowData[i]);
                    break;
                case 4:
                    entry.second.cityCode = stoi(rowData[i]);
                    break;
                case 5:
                    entry.second.number = rowData[i];
                    break;
                case 6:
                    entry.second.additional = getOptInt(rowData[i]);
                    break;
                }
            }
            book.push_back(entry);
        }
    }

    void SortByName();
    void SortByPhone();
    std::pair<std::string, std::vector<PhoneNumber>> GetPhoneNumber(const std::string& surname);
    void ChangePhoneNumber(const Person& person, const PhoneNumber& newNumber);
    friend std::ostream& operator<< (std::ostream& os,const PhoneBook &book);
private:
    std::vector<std::pair<Person, PhoneNumber>> book;
};
std::ostream& operator<<(std::ostream& out, const Person& p)
{
    out << std::setw(15) << p.name << std::setw(12) << p.surname;

    if (p.middleName.has_value())
    {
        out << std::setw(17) << p.middleName.value();
    }
    else
    {
        out << std::setw(18);
    }

    return out;
}
std::ostream& operator<<(std::ostream& out, const PhoneNumber& p)
{
    out << std::setw(3) << '+' << p.countryCode << '(' << p.cityCode << ')' << p.number;

    if (p.additional.has_value())
    {
        out << ' ' << p.additional.value();
    }

    return out;
}
bool operator<(const Person& p1, const Person& p2)
{
    return tie(p1.name, p1.surname, p1.middleName) < tie(p2.name, p2.surname, p2.middleName);
}

bool operator==(const Person& p1, const Person& p2)
{
    return tie(p1.name, p1.surname, p1.middleName) == tie(p2.name, p2.surname, p2.middleName);
}
bool operator<(const PhoneNumber& p1, const PhoneNumber& p2)
{
    return tie(p1.countryCode, p1.cityCode, p1.number, p1.additional) < tie(p2.countryCode, p2.cityCode, p2.number, p2.additional);
}
std::ostream& operator<<(std::ostream& os, const PhoneBook& pb)
{
    for (const auto& [first, second] : pb.book)
    {
        os << first << ' ' << second << std::endl;
    }

    return os;
}
void PhoneBook::SortByName(){
    sort(book.begin(), book.end(), [](const std::pair<Person, PhoneNumber>& l, const std::pair<Person, PhoneNumber>& r)
        {
            return l.first < r.first;
        });
}
void PhoneBook::SortByPhone(){
    sort(book.begin(), book.end(), [](const std::pair<Person, PhoneNumber>& l, const std::pair<Person, PhoneNumber>& r)
        {
            return l.second < r.second;
        });
}
std::pair<std::string, std::vector<PhoneNumber>> PhoneBook::GetPhoneNumber(const std::string& name) {
    std::vector<PhoneNumber> phoneNumbers;
    int count = 0;

    for_each(book.begin(), book.end(), [&](const auto& entry)
        {
            if (entry.first.surname == name)
            {
                phoneNumbers.push_back(entry.second);
                ++count;
            }
        });
    switch (count)
    {
    case 0:
        return { "not found", phoneNumbers };
    case 1:
        return { "", phoneNumbers };
    default:
        return { "found more than 1", phoneNumbers };
    }
}
void PhoneBook::ChangePhoneNumber(const Person& person, const PhoneNumber& newNumber){
    auto entry = find_if(book.begin(), book.end(), [&](const auto& entry)
        {
            return entry.first == person;
        });

    if (entry != book.end())
    {
        entry->second = newNumber;
    }
}

#endif