#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include "students.pb.h"

class IRepository
{
public:
	virtual void Open() = 0;
	virtual void Save() = 0;
	virtual ~IRepository() {};
};
class IMethods
{
public:
	virtual double GetAverageScore(const students::FullName& name) = 0;
	virtual std::string GetAllInfo(const students::FullName& name) = 0;
	virtual std::string GetAllInfo() = 0;
	virtual ~IMethods(){}
};
class StudentsGroup : public IRepository, public IMethods
{
public:
	void addStudent(const students::Student& person) {
		stud.push_back(person);
	}
	void Open(){
		std::ifstream op("students.bin", std::ios_base::binary);
		size_t size = 0;
		op.read(reinterpret_cast<char*>(&size), sizeof(size));
		while (size--)
		{
			students::Student temp;
			temp.ParseFromIstream(&op);
			stud.push_back(std::move(temp));
		}
		op.close();
	}
	void Save() {
		std::ofstream out("students.bin", std::ios_base::binary);
		auto size = stud.size();
		out.write(reinterpret_cast<char*>(&size), sizeof(size));
		std::for_each(stud.begin(), stud.end(), [&](const students::Student& person) {
			person.SerializeToOstream(&out);
			});
		out.close();
	}
	double GetAverageScore(const students::FullName& name) {
		auto it = std::find_if(stud.begin(), stud.end(), [&](const students::Student& temp) {
			return tie(temp.name().name(), temp.name().surname(), temp.name().patronymic()) ==
				tie(name.name(), name.surname(), name.patronymic());
			});
		if (it == stud.end()) {
			return 0.0;
		}
		return it->avg_score();
	}
	std::string GetAllInfo(const students::FullName& name) {
		auto it = std::find_if(stud.begin(), stud.end(), [&](const students::Student& temp) {
			return tie(temp.name().name(), temp.name().surname(), temp.name().patronymic()) ==
				tie(name.name(), name.surname(), name.patronymic());
			});
		if (it == stud.end()) {
			return {};
		}
		std::string temp = "Name [" + it->name().name() + "] [" + it->name().surname() + "] [" + it->name().patronymic() + "]\n";
		temp += "Grades: ";
		for (int i = 0; i < it->grades().size(); ++i)
		{
			temp += std::to_string(it->grades(i)) + " | ";
		}
		temp += '\n';
		temp += "Average score: |{" + std::to_string(it->avg_score()) + "}|\n";

		return temp;
	}
	std::string GetAllInfo()
	{
		std::string temp;

		std::for_each(stud.begin(), stud.end(), [&](const students::Student& person)
			{
				temp += GetAllInfo(person.name());
			});

		return temp;
	}
	virtual ~StudentsGroup(){};
private:
	std::vector<students::Student> stud;
};


int main()
{
	students::FullName person;
	person.set_name("Konstantin");
	person.set_surname("Khristachev");
	person.set_patronymic("Sergeevich");

	students::Student st;
	*st.mutable_name() = person;
	st.add_grades(5);
	st.add_grades(5);
	st.add_grades(3);
	st.add_grades(4);
	st.add_grades(5);
	st.add_grades(5);
	st.add_grades(4);
	st.add_grades(2);
	st.set_avg_score(std::accumulate(st.grades().begin(), st.grades().end(), 0) / st.grades().size());
	
	StudentsGroup gr;
	gr.addStudent(st);
	gr.Save();

	StudentsGroup newGr;
	newGr.Open();
	std::cout << newGr.GetAllInfo(person) << std::endl;



    return 0;
}

