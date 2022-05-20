#pragma once
#ifndef PhoneNumber_h
#define PhoneNumber_h

#include <iostream>
#include <optional>

class PhoneNumber
{
public:
	PhoneNumber() = default;
	PhoneNumber(uint16_t cCountryCode, uint16_t cCityCode, const std::string& cNumber, const std::optional<uint16_t>& cAdditional) :
		countryCode(cCountryCode), cityCode(cCityCode), number(cNumber), additional(cAdditional) {}
	friend std::ostream& operator<<(std::ostream& os, const PhoneNumber& phone);
	friend bool operator<(const PhoneNumber& phone1, const PhoneNumber& phone2);
	friend bool operator==(const PhoneNumber& phone1, const PhoneNumber& phone2);
private:
	uint16_t countryCode, cityCode;
	std::string number;
	std::optional<uint16_t> additional;
};

std::ostream& operator<<(std::ostream& os, const PhoneNumber& phone) {
	os << "+" << phone.countryCode << "(" << phone.cityCode << ")" << phone.number;
	if (phone.additional)
		os << " " << phone.additional.value();
	return os;
}
bool operator<(const PhoneNumber& phone1, const PhoneNumber& phone2) {
	return std::tie(phone1.countryCode, phone1.cityCode, phone1.number, phone1.additional) < std::tie(phone2.countryCode, phone2.cityCode, phone2.number, phone2.additional);
}
bool operator==(const PhoneNumber& phone1, const PhoneNumber& phone2) {
	return std::tie(phone1.countryCode, phone1.cityCode, phone1.number, phone1.additional) == std::tie(phone2.countryCode, phone2.cityCode, phone2.number, phone2.additional);
}

#endif 