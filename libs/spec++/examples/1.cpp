#include <thebc/spec++.hpp>
#include <iostream>

struct test_data
{
};

context("test", test_data)
{
	specify("test1", 1)
	{
		std::cout << "test" << std::endl;
	}
}

int main(int argc, char* argv[])
{
	spec::runner r(argc, argv);

	//spec::runner::result = r.run();

	//spec::output<compiler_format>(result);
}
