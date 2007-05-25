#include <string>

struct char_helper
{
    char_helper():
            str( "ABC 123 A93!" )
        ,   credit( "0000 1111 2222 3333" )
        ,   credit_error( "0000 1111 2222 QQQQ" )
    {
    }

    char* str;
    std::string credit;
    std::string credit_error;
};

context("The string group (equal)", char_helper)
{
    specify("should have support for equality")
    {
        actual( str ).string.should.equal( "ABC 123 A93!" ); 
    }
    specify("should have support for not equal")
    {
        actual( str ).string.should.not.equal( "X" );
    }
    specify("should have support for equality operator")
    {
        actual( str ).string.should == "ABC 123 A93!"; 
    }
    specify("should have support for not equal operator")
    {
        actual( str ).string.should != "X" ;
    }
}

context("The string group (match)", char_helper)
{
    specify("should have support for match")
    {
        actual( credit ).string.should.match( "(\\d{4}[- ]){3}\\d{4}" );
    }
    specify("should have support for not match")
    {
        actual( credit_error ).string.should.not.match( "(\\d{4}[- ]){3}\\d{4}" );
    }
}
