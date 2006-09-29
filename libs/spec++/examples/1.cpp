#include <thebc/spec++.hpp>
#include <thebc/spec++/format/compiler_format.hpp>
#include <iostream>

using namespace spec;

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

    specify("example6 should be between 5 and 20", 6)
    {
        value( 10 ).should.be_between(5).And(20);
    }

    specify("example7 10 should be between or equal to 10.", 7)
    {
        value( 10 ).should.be_between_or_equal_to(10).And(20);
    }

    specify("example8 10 should be between 5 and 20.", 8)
    {
        value( 10 ).should.be_between(5)&&(20);
    }
}

struct more_examples
{
};

context("Spec++ more examples", more_examples)
{
    specify("example1 10 should be between or equal to 10 and 20.", 1)
    {
        value( 10 ).should.be_between_or_equal_to(10)&&(20);
    }

    specify("example2 10.5 shoudl be within 0.5f of 11.0f.", 2)
    {
        value( 10.5f ).should.be_within( 0.5f ).of( 11.0f );
    }

    specify("example3 11 should equal 10.", 3)
    {
        // Faile
        value( 11 ).should.equal(10);
    }

    specify("example 4 11 should == 11", 4)
    {
        value( 11 ).should == 11;
    }

    specify("example5 11 should != 10", 5)
    {
        value( 11 ).should != 10;
    }

    specify("example6 10 should be > than 5", 6)
    {
        value( 10 ).should > 5;
    }

    specify("example7 10 should be < than 20", 7)
    {
        value( 10 ).should < 20;
    }

}

int main(int argc, char* argv[])
{
    spec::runner r(argc, argv);
    spec::runner::result res = r.run();

    spec::output<compiler_format> out(res);

    out.display();

    spec::context_registration::destroy();
}
