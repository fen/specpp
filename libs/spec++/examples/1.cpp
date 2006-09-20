#include <thebc/spec++.hpp>
#include <iostream>

struct test_data
{
};

context("Example of Spec++", test_data)
{
    specify("example1 10 should equal 10.", 1)
    {
        value( 10 ).should.equal(10);
    }

	specify("example2 10 should not equal 2.", 2)
    {
		value( 10 ).should.not_equal(2);
    }

	specify("example3 10 should be more than 5.", 3)
    {
        value( 10 ).should.be_more_than(5);
    }

	specify("example4 10 should be less than 20.", 4)
	{
		value( 10 ).should.be_less_than(20);
	}

	specify("example5 violated by existing.", 5)
	{
		violated("message");
	}

	specify("example6.", 6)
	{
		value( 10 ).should.be_between(5).And(20);
	}

	specify("example7.", 7)
	{
		value( 10 ).should.be_between_or_equal_to(10).And(20);
	}

	specify("example8.", 8)
	{
		value( 10 ).should.be_between(5)and(20);
	}

	specify("example9.", 9)
	{
		value( 10 ).should.be_between_or_equal_to(10)and(20);
	}
}

int main(int argc, char* argv[])
{
    spec::runner r(argc, argv);
    r.run();

    //spec::runner::result = r.run();

    //spec::output<compiler_format>(result);
}
