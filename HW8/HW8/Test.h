#pragma once
#ifndef Test_H
#define Test_H

#include <iostream>
#include "gtest/gtest.h"
#include "PhoneBook.h"


class TestBook : public testing::Test {
protected:
	PhoneBook* testB;

	void SetUp() override {
		std::stringstream tstStr;
		tstStr << "Ivanov:Ivan:Ivanovich:7:456:1237898\n"
			<< "Petrov:Petr:Petrovich:546:3456:3421532\n"
			<< "Aleksandrov:Aleksandr:Mikhailovich:7:567:1957480:5322\n"
			<< "Sidorov:Vlad:45:5432:5287125:3\n";
		testB = new PhoneBook(tstStr);
	}
	void TearDown() override {
		delete testB;
	}
};

TEST_F(TestBook, GetPhoneNumberNF) {
	std::string lastName = "Andreev";
	auto temp = testB->GetPhoneNumber(lastName);
	EXPECT_EQ(std::get<0>(temp), "not found");
}
TEST_F(TestBook, GetPhoneNumber) {
	std::string lastName = "Ivanov";
	auto temp = testB->GetPhoneNumber(lastName);
	EXPECT_EQ(std::get<0>(temp), "");
}
TEST_F(TestBook, ChangeNumber) {
	std::string lastName = "Petrov";
	ASSERT_EQ(std::get<0>(testB->GetPhoneNumber(lastName)).empty(), true);

	PhoneNumber temp = std::get<1>(testB->GetPhoneNumber(lastName))[0];
	EXPECT_EQ(temp.number, "3421532");

	testB->ChangePhoneNumber(Person{ "Petrov", "Petr", "Petrovich"}, PhoneNumber{7, 322, "18534323", std::nullopt});

	temp = std::get<1>(testB->GetPhoneNumber(lastName))[0];
	EXPECT_EQ(temp.countryCode, 7);
	EXPECT_EQ(temp.cityCode, 322);
	EXPECT_EQ(temp.number, "18534323");
	EXPECT_EQ(temp.additional, std::nullopt);
}
TEST_F(TestBook, SortByName) {
	std::stringstream str;
	str << "Aleksandrov		Aleksandr	Mikhailovich +7(567)1957480 5322\n"
		<< "Ivanov	 Ivan	Ivanovich	+7(456)1237898\n"
		<< "Petrov	Petr	Petrovich	+546(3456)3421532\n"
		<< "Sidorov		Vlad	+45(5432)5287125 3\n";
	testB->SortByName();

	std::stringstream rts;
	rts << *testB;

	while (!rts.eof())
	{
		std::string strTemp;
		std::string rtsTemp;

		str >> strTemp;
		rts >> rtsTemp;

		EXPECT_EQ(rtsTemp, strTemp);
	}
}
TEST_F(TestBook, SortByPhone) {
	std::stringstream str;
	str << "Aleksandrov		Aleksandr	Mikhailovich +7(567)1957480 5322\n"
		<< "Ivanov	 Ivan	Ivanovich	+7(456)1237898\n"
		<< "Sidorov		Vlad	+45(5432)5287125 3\n"
		<< "Petrov	Petr	Petrovich	+546(3456)3421532\n";
	testB->SortByPhone();

	std::stringstream rts;
	rts << *testB;

	while (!rts.eof())
	{
		std::string strTemp;
		std::string rtsTemp;

		str >> strTemp;
		rts >> rtsTemp;

		EXPECT_EQ(strTemp, rtsTemp);
	}
}

#endif // !Test_H