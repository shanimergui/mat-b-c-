#include <iostream>
#include "mat.hpp"

using namespace std;

int main() {
	cout << ariel::mat(3, 3, '@', '-') << endl;
	
/* Should print:
@@@@@@@@@
@-------@
@-@@@@@-@
@-@---@-@
@-@@@@@-@
@-------@
@@@@@@@@@
*/
	cout << ariel::mat(13, 5, '@', '-') << endl; 
/* Should print:
@@@@@@@@@@@@@
@-----------@
@-@@@@@@@@@-@
@-----------@
@@@@@@@@@@@@@
*/
	try {
		cout << ariel::mat(10, 5, '$', '%') << endl; // Exception - not a valid code
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "Mat size is always odd"
	}
	
}