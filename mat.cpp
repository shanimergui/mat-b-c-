#include <iostream>
#include <stdexcept>
#include <array>


#include "mat.hpp"
namespace ariel
{
	int badChars(char c) {
      const char ch_a = 127;
	  const char ch_b = 33;
	  const int size=5;
      std::array<char,size> invalid_chars{'\t','\n','\r',' ','\0'};
      for(const auto &i: invalid_chars) // One of the characters above found
	  {
		  if (i == c)
		   {
			  return 1;
		   }
	  }
      if (c >= ch_a || c < ch_b) { // Magic numbers found and it's not good
         return 1;
      }

      return 0; // None found
   }



	std::string mat(const int& col, const int& row, const char& sing1, const char& sing2) {
	if ((col % 2 == 0 || row % 2 == 0) || ((col % 2 == 0 && row % 2 == 0))) {
		throw std::invalid_argument("Mat size is always odd");
		
	}
		if ((col < 1 || row < 1) || ((col < 1 && row < 1))) {
		throw std::invalid_argument("Mat size is always positive");
		
	}
	if((badChars(sing1) == 1 || badChars(sing2) == 1) || (badChars(sing1) == 1 && badChars(sing2) == 1))
	{
		throw std::invalid_argument("bad chars found");
	}
	std::string str;
    
	for (int r = 0; r < row; r++) {
		if (r % 2 == 0) {
			for (int c = 0; c < col; c++) {
				str += sing1;
			}
		}
		else {
			for (int c = 0; c < col; c++) {
				str += sing2;
			}
		}
		str += '\n';
	}
	for (int c = 0; c < col; c++) {
		if (c % 2 == 0) {
			for (int r = c; r < row-c; r++) {
				str[r*(col + 1) + c] = str[r*(col + 1) + col - 1 - c] = sing1;
			}
		}
		else {
			for (int r = c; r < row-c; r++) {
				str[r*(col + 1) + c] = str[r*(col + 1) + col - 1 - c] = sing2;
			}
		}
	}
	return str;
}
}


