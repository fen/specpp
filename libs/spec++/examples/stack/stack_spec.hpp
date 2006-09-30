#include "stack.hpp"
#include <thebc/spec++.hpp>

using namespace spec;

struct general_stack
{
    stack<int> stack;
    general_stack(){stack.push(1),stack.push(2),stack.push(3),stack.push(4);}
};

context("A stack in general", general_stack)
{
    specify("should add to the top when sent push")
    {
        stack.push( 5 );
        value( stack.top() ).should.equal( 5 );
    }
    specify("should NOT remove the top item when sent top")
    {
        value( stack.top() ).should.equal( 4 );
        value( stack.top() ).should.equal( 4 );
    }
    specify("should return the top item when sent pop")
    {
        value( stack.pop() ).should.equal( 4 );
    }
}

struct empty_stack
{
    stack<int> stack;
};

context("An empty stack", empty_stack)
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

struct almost_empty_stack
{
    stack<int> stack;
    almost_empty_stack(){stack.push( 3 );}
};

context("An almost empty stack (with one item)", almost_empty_stack)
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

struct almost_full_stack
{
    stack<int> stack;
    almost_full_stack()
    {
        for(int i = 0; i < STACK_CAPACITY-1; ++i)
        {
            stack.push(i);
        }
    }
};

context("An almost full stack (with one item less than capacity)", almost_full_stack)
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

struct full_stack
{
    stack<int> stack;
    full_stack()
    {
        for(int i = 0; i < STACK_CAPACITY; ++i)
        {
            stack.push(i);
        }
    }

};

context("A full stack", full_stack)
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
