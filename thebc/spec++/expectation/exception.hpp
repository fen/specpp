#ifndef THEBC_SPECPP_EXPECTATION_EXCEPTION_HPP
#define THEBC_SPECPP_EXPECTATION_EXCEPTION_HPP

#include <thebc/spec++/expectation/basic.hpp>

#define function\
    bool thrown = false;\
    try {

#define method function

#define should_throw\
    }\
    catch( ... ){ thrown = true; }\
    if( !thrown ){ fail( "Didn't throw an exception but should have" ); }

#define should_not_throw\
    }\
    catch( ... ){ thrown = true; }\
    if( thrown ){ fail( "Did throw an exception but shouldn't" ); } 

#define STRINGIFY( X ) #X

#define should_throw_an( TYPE )\
    }\
    catch( TYPE& ){ thrown = true; }\
    catch( ... ) { }\
    if( !thrown ){ fail( "Didn't throw an exception of type " STRINGIFY( TYPE ) " but should have" ); }


#endif /* THEBC_SPECPP_EXPECTATION_EXCEPTION_HPP */
