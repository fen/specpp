#include <thebc/spec++.hpp>
#include <thebc/spec++/format/compiler_format.hpp>

using namespace spec;
struct abc
{
    abc()
    : a(10)
    {}
    int a;
};

context("A nice spec", abc)
{
    specify("should be easy to read")
    {
        value( a ).should.equal( 10 );
    }
}

context("A cool spec", abc)
{
    specify("should be easy to code")
    {
        value( a ).should.equal( 2 );
    }
}

int main(int argc, char* argv[])
{
    spec::runner run(argc, argv);

    spec::runner::result res = run.run();

    spec::output<compiler_format> out(res);

    out.display();

    spec::context_handler::destroy();
}
