#include "stack.hpp"
#include <thebc/spec++.hpp>

using namespace spec;

struct general_stack
{
    stack<int> stack;
    general_stack()
    {
    }
};

context("A stack in general", general_stack)
{
    specify("should add to the top when sent push", 1)
    {
        stack.push( 5 );
        value( stack.top() ).should.equal( 5 );
    }
    specify("should NOT remove the top item when sent top", 2)
    {
        stack.push( 2 );
        value( stack.top() ).should.equal( 2 );
        value( stack.top() ).should.equal( 2 );
    }
    specify("should return the top item when sent pop", 3)
    {
        stack.push( 1 );
        value( stack.pop() ).should.equal( 1 );
    }
}

struct empty_stack
{
    stack<int> stack;
};

context("An empty stack", empty_stack)
{
    specify("should be empty", 1)
    {
        value( stack.empty() ).should.be( true );
    }
    specify("should no longer be empty after push", 2)
    {
        stack.push( 10 );
        value( stack.empty() ).should.be( false );
        stack.pop();
    }
    specify("should complain when sent pop", 3)
    {
        // do when I have implemented raise.
    }
    specify("should complain when sent top", 4)
    {
        // do when I ahve implemented raise.
    }
}

struct almost_empty_stack
{
    stack<int> stack;
    almost_empty_stack()
    {
        stack.push( 3 );
    }
};

context("An almost empty stack (with one item)", almost_empty_stack)
{
    specify("should not be empty", 1)
    {
        value( stack.empty() ).should.be( false );
    }

    specify("should remain not empty after top", 2)
    {
        stack.top();
        value( stack.empty() ).should.be( false );
    }
    specify("should become empty after pop", 3)
    {
        stack.pop();
        value( stack.empty() ).should.be( true );
    }
}

struct almost_full_stack
{
};

context("An almost full stack (with one item less than capacity)", almost_full_stack)
{
    specify("should not be full", 1)
    {
    }

    specify("should become full when sent push", 2)
    {
    }
}

struct full_stack
{
};

context("A full stack",)
{
    specify("should be full", 1)
    {
    }

    specify("should remain full after top", 2)
    {
    }

    specify("should no longer be full after pop", 3)
    {
    }

    specify("should complain on push", 4)
    {
    }
}
