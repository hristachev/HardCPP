#include <iostream>
#include "pcout.h"
#include "primenumber.h"
#include "Task3.h"


int main()
{
	//TASK 1
	std::thread th1(doSomething, 1);
	std::thread th2(doSomething, 2);
	std::thread th3(doSomething, 3);
	std::thread th4(doSomething, 4);
	th1.join();
	th2.join();
	th3.join();
	th4.join();

	pcout() << std::endl;
	//TASK 2
	std::thread th5(progress);
	std::thread th6(primeNumber, 10'000'000);
	th5.join();
	th6.join();

	//TASK 3
	std::vector<int> vec(100);
	size_t count = 100;

	while (count--)
	{
		std::thread owner([&]()
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				generateVal(vec);
			});
		std::thread thief([&]()
			{
				thing(vec);
			});

		owner.join();
		thief.join();
	}

	

	return 0;
}
