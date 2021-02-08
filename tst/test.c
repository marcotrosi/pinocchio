#include "test_pinocchio.h"

int main(void)
{

//          ( string   , char , nth , start , must , file     , line     );    description         
test_cindex ( "foobar" , 'b'  , 1   , 0     , 3    , __FILE__ , __LINE__ ); // normal
test_cindex ( NULL     , 'b'  , 1   , 0     , -1   , __FILE__ , __LINE__ ); // null
test_cindex ( "foobar" , 'z'  , 1   , 0     , -1   , __FILE__ , __LINE__ ); // not found
test_cindex ( "foobar" , 'f'  , 1   , 10    , -1   , __FILE__ , __LINE__ ); // outside
test_cindex ( "foofoo" , 'f'  , 1   , 0     , 0    , __FILE__ , __LINE__ ); // first
test_cindex ( "foofoo" , 'f'  , 2   , 0     , 3    , __FILE__ , __LINE__ ); // second
test_cindex ( "foofoo" , 'f'  , 1   , 1     , 3    , __FILE__ , __LINE__ ); // first after start
test_cindex ( "foofoo" , 'f'  , 0   , 0     , -1   , __FILE__ , __LINE__ ); // zeroth occurrence
test_cindex ( "foofoo" , 'o'  , 3   , 0     , 4    , __FILE__ , __LINE__ ); // third
test_cindex ( "foofoo" , 'o'  , -3  , 0     , 2    , __FILE__ , __LINE__ ); // third from end




   return 0;
}
