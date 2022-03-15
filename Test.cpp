#include "doctest.h"
#include "mat.hpp"
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;
using namespace ariel;


string nospaces(string input) {
	input.erase(std::remove(input.begin(), input.end(), ' ') , input.end());
	input.erase(std::remove(input.begin(), input.end(), '\t') , input.end());
	input.erase(std::remove(input.begin(), input.end(), '\n') , input.end());
	input.erase(std::remove(input.begin(), input.end(), '\r') , input.end());
	return input;
}

//a random function that ran on even number
int randomOddNum ()
{
    srand((unsigned)time(NULL));
    int num = *(int*)rand; 
    if (num%2==0)
    {
        return num;
    }
    else return num-1; 
}


TEST_CASE("valid input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													"@-------@\n"
													"@-@@@@@-@\n"
													"@-@---@-@\n"
													"@-@@@@@-@\n"
													"@-------@\n"
													"@@@@@@@@@"));

    CHECK(nospaces(mat(17, 1, '@', '-')) == nospaces("@@@@@@@@@@@@@@@@@"));
	                                                 
	
	CHECK(nospaces(mat(5, 11, '@', '*')) == nospaces("@@@@@\n"
													 "@***@\n"
                                                     "@*@*@\n"
													 "@*@*@\n"
													 "@*@*@\n"
													 "@*@*@\n"
													 "@*@*@\n"
													 "@*@*@\n"
													 "@*@*@\n"
													 "@***@\n"
													 "@@@@@"));
    
	CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@/n"
                                                     "@-----------@/n"
                                                     "@-@@@@@@@@@-@/n"
                                                     "@-----------@/n"
                                                     "@@@@@@@@@@@@@"));



													 
	
	CHECK(nospaces(mat(3, 3, '@', '&')) == nospaces("@@@\n"
													"@&@\n"
													"@@@"));

    CHECK(nospaces(mat(1, 1, '@', '*')) == nospaces("@"));
    
}                                                  


TEST_CASE("invalid input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(1, 2, '@', '%'));
    CHECK_THROWS(mat(6, 3, '-', '$'));
    CHECK_THROWS(mat(0, 0, '*', '@'));
    CHECK_THROWS(mat(-2, 1, '&', '^'));
    CHECK_THROWS(mat(1, -3, '@', '%'));
    CHECK_THROWS(mat(0, 7, '*', '@'));

 
    for (int i = 1; i <100 ; i++)
    {
       int num1 = randomOddNum();
       int num2 =randomOddNum();
       CHECK_THROWS(mat(num1, num2, '@', '#'));
    }


   
}


TEST_CASE("incorrect compartion") {
    CHECK(nospaces(mat(3, 3, '@', '&')) != nospaces("@@@\n"
													"@&@\n"
													"@&@"));


    CHECK(nospaces(mat(3, 3, '@', '&')) != nospaces("@@@\n"
													"@@@\n"
													"@@@"));                                                

    CHECK(nospaces(mat(9, 7, '@', '-')) != nospaces("@@@@--@@-\n"
													"@-------@\n"
													"@-@@@@@-@\n"
													"@-@---@-@\n"
													"@-@@@@@-@\n"
													"@-------@\n"
													"@@@@@@@@@"));




    CHECK(nospaces(mat(9, 7, '@', '-'))!= nospaces("@@@@@@@@@\n"
													"@-------@\n"
													"@-@@@@@-@\n"
													"---------\n"
													"@-@@@@@-@\n"
													"@-------@\n"
													"@@@@@@@@@"));                                                   



    CHECK(nospaces(mat(3, 3, '@', '&')) != nospaces("&&&\n"
													"&&&\n"
													"&&&"));

  
}
	





    


  
												 

	
