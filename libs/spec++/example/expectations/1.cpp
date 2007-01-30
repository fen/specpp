#include <thebc/spec++.hpp>
#include <thebc/spec++/format/compiler_format.hpp>
#include <iostream>

using namespace spec;

struct test_data
{
    int one, two, three, four, five, six, seven, eight;
    float pi;

    test_data()
    : one(1), two(2), three(3), four(4), five(5), six(6), seven(7), eight(8)
    , pi(3.14f){}
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

    specify("should show that two is < three")
    {
        value( two ).should < three;
    }

    specify("should show that three is > than two")
    {
        value( three ).should > two;
    }
}

context("Between or equal to", test_data)
{
    specify("should show that four is between one and seven")
    {
        value( four ).should.be_between( one ).And( seven );
    }

    specify("should show that eight is not between one and seven")
    {
        value( eight ).should.not_be_between( one ).And( seven );
    }

    specify("should show that two is between or equal to two and five")
    {
        value( two ).should.be_between_or_equal_to( two ).And( five );
    }

    specify("should show that one is not between or equal to rwo and five")
    {
        value( one ).should.not_be_between_or_equal_to( two ).And( five );
    }
}

context("Floating point comparition", test_data)
{
    specify("should show that 23.4 is within the 0.2 of 23.2")
    {
        value( 23.4 ).should.be_within( 0.2 ).of( 23.2 );
    }

    specify("should show that 23.5 is not within the 0.2 of 23.2")
    {
        //value( 23.5 ).should.not_be_within( 0.2 ).of( 23.2 );
        // todo
    }

    // Copy then be_within...
    // should.be_close( <expected>, <tolerance> )
    // should.not_be_close( <expected>, <tolerance> )

}

context("Pattern Matching", test_data)
{
    // TODO
}

context("Identity", test_data)
{
    specify("should show that 7 is a int type")
    {
        value( seven ).should.be( int() );
    }

    specify("should show that 7.0f is not of type std::string")
    {
        value( six ).should.not_be( std::string() );
    }
}


int main(int argc, char* argv[])
{
    // We first get the options for this spec
    spec::options option(argc, argv);

    // Should we continue to run or is this session done
    if(option.continue_run())
    {
        // pass the runner with the options so it knows what the user wants it
        // to do.
        spec::runner r(option);

        // Run all the context and get the result
        spec::runner::result result = r.run();

        // Last pass the options and the result to the display that will
        // display the result as the user wants it.
        spec::display(option, result);
    }

    // destroy the singleton object
    spec::context_handler::destroy();
}