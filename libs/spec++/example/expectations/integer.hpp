
struct integer_helper {};

context("The integer group (equal)", integer_helper)
{
    specify("should have support for equal")
    {
        actual( 5 ).integer.should.equal( 5 );
    }
    specify("should have support for not equal")
    {
        actual( 7 ).integer.should.not.equal( 5 );
    }
    specify("should have support for operator ==")
    {
        actual( 9 ).integer.should == 9;
    }
    specify("should have support for operator !=")
    {
        actual( 5 ).integer.should != 9;
    }
}

context("The integer group (less than)", integer_helper)
{
    specify("should have support for less than")
    {
        actual( 3 ).integer.should.be_less_than( 4 );
    }
    specify("should have support for not less than")
    {
        actual( 9 ).integer.should.not.be_less_than( 4 );
    }
    specify("should have support for less than or equal to")
    {
        actual( 3 ).integer.should.be_less_than_or_equal_to( 3 );
    }
    specify("should have support for less than or equal to")
    {
        actual( 3 ).integer.should.be_less_than_or_equal_to( 5 );
    }
    specify("should have support for not less than or equal to")
    {
        actual( 8 ).integer.should.not.be_less_than_or_equal_to( 2 );
    }

    specify("should have support for operator <")
    {
        actual( 3 ).integer.should < 4;
    }
    specify("should have support for operator <=")
    {
        actual( 3 ).integer.should <= 3; 
    }
    specify("should have support for operator <=")
    {
        actual( 3 ).integer.should <= 5; 
    }
}

context("The integer group (more than)", integer_helper)
{
    specify("should have support for more than")
    {
        actual( 7 ).integer.should.be_more_than( 3 );
    }
    specify("should have support for not more than")
    {
        actual( 3 ).integer.should.not.be_more_than( 7 );
    }
    specify("should have support for more than or equal to")
    {
        actual( 7 ).integer.should.be_more_than_or_equal_to( 3 );
    }
    specify("should have support for more than or equal to")
    {
        actual( 3 ).integer.should.be_more_than_or_equal_to( 3 );
    }
    specify("should have support for not more than or equal to")
    {
        actual( 3 ).integer.should.not.be_more_than_or_equal_to( 5 );
    }

    specify("should have support for operator >")
    {
        actual( 7 ).integer.should > 3;
    }
    specify("should have support for operator >=")
    {
        actual( 3 ).integer.should >= 3;
    }
    specify("should have support for operator >=")
    {
        actual( 7 ).integer.should >= 3;
    }
}


