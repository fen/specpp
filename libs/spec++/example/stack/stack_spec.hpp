#include "stack.hpp"
#include <thebc/spec++.hpp>

using namespace spec;

template<int N>
struct stack_helper
{
    stack<int> stack;
    stack_helper()
    {
        for(int i = 0; i < N; ++i)
        {
            stack.push(i);
        }
    }
};

typedef stack_helper<STACK_CAPACITY> stack_helper_full;
typedef stack_helper<STACK_CAPACITY-1> stack_helper_almost_full;
typedef stack_helper<4> stack_helper_4;
typedef stack_helper<0> stack_helper_0;
typedef stack_helper<1> stack_helper_1;

context("A stack in general", stack_helper_4)
{
    specify("should add to the top when sent push")
    {
        stack.push( 4 );
        value( stack.top() ).should.equal( 4 );
    }
    specify("should NOT remove the top item when sent top")
    {
        value( stack.top() ).should.equal( 3 );
        value( stack.top() ).should.equal( 3 );
    }
    specify("should return the top item when sent pop")
    {
        value( stack.pop() ).should.equal( 3 );
    }
}


context("An empty stack", stack_helper_0)
{
    specify("should be empty")
    {
        value( stack.empty() ).should.be( true );
    }
    specify("should no longer be empty after push")
    {
        stack.push( 10 );
        value( stack.empty() ).should.be( false );
    }
    specify("should complain when sent pop")
    {
        // do when I have implemented raise.
    }
    specify("should complain when sent top")
    {
        // do when I ahve implemented raise.
    }
}

context("An almost empty stack (with one item)", stack_helper_1)
{
    specify("should not be empty")
    {
        value( stack.empty() ).should.be( false );
    }

    specify("should remain not empty after top")
    {
        stack.top();
        value( stack.empty() ).should.be( false );
    }
    specify("should become empty after pop")
    {
        stack.pop();
        value( stack.empty() ).should.be( true );
    }
}

context("An almost full stack (with one item less than capacity)", stack_helper_almost_full)
{
    specify("should not be full")
    {
        value( stack.full() ).should.be( false );
    }

    specify("should become full when sent push")
    {
        stack.push(127);
        value( stack.full() ).should.be( true );
    }
}

context("A full stack", stack_helper_full)
{
    specify("should be full")
    {
        value( stack.full() ).should.be( true );
    }

    specify("should remain full after top")
    {
        stack.top();
        value( stack.full() ).should.be( true );
    }

    specify("should no longer be full after pop")
    {
        stack.pop();
        value( stack.full() ).should.be( false );
    }

    specify("should complain on push")
    {
        // has not implemented raise
    }
}