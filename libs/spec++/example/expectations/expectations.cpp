#include <thebc/spec++.hpp>
#include <iostream>
#include <stdexcept>

using namespace spec;

struct test_data
{
	int one, two, three, four, five, six, seven, eight;
	float pi;

	test_data()
		: one(1), two(2), three(3), four(4), five(5), six(6), seven(7), eight(8)
		, pi(3.14f){}

	void throw_int()
	{
		throw 5;
	}

	void throw_something()
	{
		throw std::runtime_error( "ERROR" );
	}

	void no_throw()
	{
		int a = 1;
	}
};

context("Equal and Not equal", test_data)
{
	specify("should show that seven is equal to 7")
	{
		value( seven ).should.equal( 7 );
	}

	specify("should show that seven is not equal to two")
	{
		value( seven ).should.not_equal( two );
	}

	specify("should show that seven == 7")
	{
		value( seven ).should == 7;
	}

	specify("should show that 7 != two")
	{
		value( 7 ).should != two;
	}

	specify("testing should equal error message")
	{
		value( 10 ).should.equal( 20 );
	}

	specify("testing should not equal error message")
	{
		value( 10 ).should.not_equal( 10 );
	}
}

context("More than or less than", test_data)
{
	specify("should show that two is less than three")
	{
		value( two ).should.be_less_than( three );
	}

	specify("should show that three is more than two")
	{
		value( three ).should.be_more_than( two );
	}

	specify("should show that two is less three")
	{
		value( two ).should < three;
	}

	specify("should show that three is more than two")
	{
		value( three ).should > two;
	}

	specify("should show that three is bigger than or equal to three")
	{
		value( three ).should.be_more_than_or_equal_to( three );
	}

	specify("should show that three is less than or equal to three")
	{
		value( three ).should.be_less_than_or_equal_to( three );
	}

	specify("should show that four is more than or equal to three")
	{
		value( four ).should.be_more_than_or_equal_to( three );
	}

	specify("should show that two is less than or equal to three")
	{
		value( two ).should.be_less_than_or_equal_to( three );
	}

	specify("should show that three is more than or equal to three")
	{
		value( three ).should >= three;
	}

	specify("should show that three is less than or equal to three")
	{
		value( three ).should <= three;
	}

	specify("should show that four is more than or equal to three")
	{
		value( four ).should >= three;
	}

	specify("should show that two is less than or equal to three")
	{
		value( two ).should <= three;
	}

	specify("testing should be less than error message")
	{
		value( three ).should.be_less_than( two );
	}

	specify("testing should be more than error message")
	{
		value( two ).should.be_more_than( three );
	}

	specify("testing less than or equal to error message")
	{
		value( four ).should.be_less_than_or_equal_to( three );
	}

	specify("testing more than or equal to error message")
	{
		value( three ).should.be_more_than_or_equal_to( four );
	}
}

context("Between", test_data)
{
	specify("should show that four is between one and seven")
	{
		value( four ).should.be_between( one ).And( seven );
	}

	specify("testing error message for should be between ")
	{
		value( eight ).should.be_between( one ).And( seven );
	}

	specify("should show that eight is not between one and seven")
	{
		value( eight ).should.not_be_between( one ).And( seven );
	}

	specify("testing error message for should not be between")
	{
		value( four ).should.not_be_between( one ).And( seven );
	}
}

context("Between or equal to", test_data)
{
	specify("should show that two is between or equal to two and five")
	{
		value( two ).should.be_between_or_equal_to( two ).And( five );
	}

	specify("should show that three is between or equal to two and five")
	{
		value( three ).should.be_between_or_equal_to( two ).And( five );
	}

	// Error
	specify("should show that one is not between or equal to two and five")
	{
		value( one ).should.not_be_between_or_equal_to( two ).And( five );
	}

	specify("testing error message for should not be between or equal")
	{
		value( four ).should.not_be_between_or_equal_to( four ).And( seven );
	}

	specify("testing error message for should be between or equal")
	{
		value( one ).should.be_between_or_equal_to( four ).And( seven );
	}
}

context("Floating point comparison", test_data)
{
	specify("should show that 23.2 is within the 0.2 of 23.2")
	{
		value( 23.2 ).should.be_within( 0.2 ).of( 23.2 );
	}

	specify("should show that 23.5 is not within the 0.2 of 26.2")
	{
		value( 23.5 ).should.not_be_within( 0.2 ).of( 26.2 );
	}

	specify("testing should be within error message")
	{
		value( 23.5 ).should.be_within( 0.2 ).of( 26.2 );
	}

	specify("testing should not be within error message")
	{
		value( 23.2 ).should.not_be_within( 0.2 ).of( 23.2 );
	}


	// Copy then be_within...
	// should.be_close( <expected>, <tolerance> )
	// should.not_be_close( <expected>, <tolerance> )

}

context("Pattern Matching", test_data)
{
	specify("should match")
	{
		std::string credit = "0000 1111 2222 3333";
		value( credit ).should.match( "(\\d{4}[- ]){3}\\d{4}" );
	}
	specify("should not match")
	{
		std::string credit = "ABCD 1111 EEEE QQQQ";
		value( credit ).should.not_match( "(\\d{4}[- ]){3}\\d{4}" );
	}

	specify("should test error message for match")
	{
		std::string credit = "ABCD 1111 EEEE QQQQ";
		value( credit ).should.match( "(\\d{4}[- ]){3}\\d{4}" );
	}

	specify("should test error message for not_match")
	{
		std::string credit = "0000 1111 2222 3333";
		value( credit ).should.not_match( "(\\d{4}[- ]){3}\\d{4}" );
	}
}

context("Identity", test_data)
{
	specify("true should be true")
	{
		value( true ).should.be( true );
	}

	specify("false should not be true")
	{
		value( false ).should.not_be( true );
	}

	specify("testing error message for be")
	{
		value( false ).should.be( true );
	}

	specify("testing error message for not_be")
	{
		value( true ).should.not_be( true );
	}
}

context("Exception", test_data)
{
	specify("should throw exception")
	{
		function throw_something(); should_throw;
	}

	specify("should throw exception of type int")
	{
		function throw_int(); should_throw_an( int );
	}

	specify("should not throw an exception")
	{
		function no_throw(); should_not_throw;
	}

	specify("testing should throw error message")
	{
		function no_throw(); should_throw;
	}

	specify("testing should throw exception of type error message")
	{
		function throw_something(); should_throw_an( int );
	}

	specify("testing should not throw error message")
	{
		function throw_int(); should_not_throw;
	}
}

SPECPP_MAIN
