struct value_helper
{
    int integer;
    char character;
};

context("The value group (be_a, be_an)", value_helper)
{
    specify("should have support for be a")
    {
        actual( integer ).type.should.be_a<int>();
    }
    specify("should have support for not be a")
    {
        actual( character ).type.should.not.be_an<int>();
    }
} 
