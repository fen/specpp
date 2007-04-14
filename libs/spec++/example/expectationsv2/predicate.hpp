struct predicate_helper
{
};

context("A predicate value", predicate_helper)
{
    specify("can be true")
    {
        actual( true ).predicate.should.be_true();
    }
    specify("can be false")
    {
        actual( false ).predicate.should.be_false();
    }
    specify("can also be not true")
    {
        actual( false ).predicate.should.not.be_true();
    }
    specify("can also be not false")
    {
        actual( true ).predicate.should.not.be_false();
    }
}
