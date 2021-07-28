#include "test_pinocchio.h"

int main(void)
{

   //          ( string   , char , nth , start   , must      , file     , line     );    description
   test_cindex ( NULL     , 'b'  , 1   , 0       , NO_RESULT , __FILE__ , __LINE__ ); // null
   test_cindex ( ""       , 'b'  , 1   , 0       , NO_RESULT , __FILE__ , __LINE__ ); // empty string
   test_cindex ( "foobar" , 'z'  , 1   , 0       , NO_RESULT , __FILE__ , __LINE__ ); // not found
   test_cindex ( "foobar" , 'f'  , 1   , 10      , NO_RESULT , __FILE__ , __LINE__ ); // outside
   test_cindex ( "foofoo" , 'f'  , 0   , 0       , NO_RESULT , __FILE__ , __LINE__ ); // zeroth occurrence
   test_cindex ( "foobar" , 'b'  , 1   , 0       , 3         , __FILE__ , __LINE__ ); // normal
   test_cindex ( "foofoo" , 'f'  , 1   , 0       , 0         , __FILE__ , __LINE__ ); // first
   test_cindex ( "foofoo" , 'f'  , 2   , 0       , 3         , __FILE__ , __LINE__ ); // second
   test_cindex ( "foofoo" , 'o'  , 3   , 0       , 4         , __FILE__ , __LINE__ ); // third
   test_cindex ( "foofoo" , 'f'  , 1   , 1       , 3         , __FILE__ , __LINE__ ); // first after start
   test_cindex ( "foofoo" , 'o'  , -3  , MAX_LEN , 2         , __FILE__ , __LINE__ ); // third last from end
   test_cindex ( "foofoo" , 'o'  , -2  , 3       , 1         , __FILE__ , __LINE__ ); // second last from index 3
   test_cindex ( "foofoo" , '\0' , 1   , 0       , 6         , __FILE__ , __LINE__ ); // find terminator

   //          ( string   , char , start , end     , must , file     , line     );    description
   test_ccount ( NULL     , 'o'  , 0     , MAX_LEN , 0    , __FILE__ , __LINE__ ); // normal
   test_ccount ( ""       , 'f'  , 0     , MAX_LEN , 0    , __FILE__ , __LINE__ ); // empty string
   test_ccount ( "foobar" , 'o'  , 0     , MAX_LEN , 2    , __FILE__ , __LINE__ ); // normal
   test_ccount ( "foobar" , 'o'  , 3     , 2       , 0    , __FILE__ , __LINE__ ); // end < start
   test_ccount ( "foobar" , '\0' , 0     , MAX_LEN , 1    , __FILE__ , __LINE__ ); // count terminator
   test_ccount ( "foobar" , 'f'  , 0     , 0       , 1    , __FILE__ , __LINE__ ); // start == end
   test_ccount ( "foobar" , 'o'  , 0     , 0       , 0    , __FILE__ , __LINE__ ); // start == end
   test_ccount ( "foobar" , 'o'  , 0     , 1       , 1    , __FILE__ , __LINE__ ); // limit range

   /*                                            ( string   , char , repl, n , start , end     , must     , file     , line     ); */
   {                               test_creplace ( NULL     , ' '  , ' ' , 0 , 0     , MAX_LEN , NULL     , __FILE__ , __LINE__ );              } // null 
   { string input = str("foobar"); test_creplace ( input , 'o'  , 'x'    , 0 , 0     , MAX_LEN , "fxxbar" , __FILE__ , __LINE__ ); free(input); } // null 
   { string input = str("foobar"); test_creplace ( input , 'o'  , 'x'    , 1 , 0     , MAX_LEN , "fxobar" , __FILE__ , __LINE__ ); free(input); } // null 
   { string input = str("foobar"); test_creplace ( input , 'o'  , 'x'    , 2 , 0     , MAX_LEN , "fxxbar" , __FILE__ , __LINE__ ); free(input); } // null 
   { string input = str("foobar"); test_creplace ( input , 'o'  , 'x'    , 0 , 1     , MAX_LEN , "fxxbar" , __FILE__ , __LINE__ ); free(input); } // null 
   { string input = str("foobar"); test_creplace ( input , 'o'  , 'x'    , 0 , 2     , MAX_LEN , "foxbar" , __FILE__ , __LINE__ ); free(input); } // null 
   { string input = str("foobar"); test_creplace ( input , 'o'  , 'x'    , 0 , 3     , MAX_LEN , "foobar" , __FILE__ , __LINE__ ); free(input); } // null 
   { string input = str("foobar"); test_creplace ( input , 'r'  , 'x'    , 0 , 0     , MAX_LEN , "foobax" , __FILE__ , __LINE__ ); free(input); } // null 
   { string input = str("foobar"); test_creplace ( input , 'r'  , 'x'    , 0 , 0     , 5       , "foobax" , __FILE__ , __LINE__ ); free(input); } // null 
   { string input = str("foobar"); test_creplace ( input , 'r'  , 'x'    , 0 , 0     , 4       , "foobar" , __FILE__ , __LINE__ ); free(input); } // null 

   return 0;
}
