/*
 * innerProduct.cpp
 * 
 * Copyright 2016 Alex <alex@alex-System-Product-Name>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <vector> 
#include <iostream> 
#include <numeric>   
using namespace std; 
template <class T>
void print(T& c){
   for( typename T::iterator i = c.begin(); i != c.end(); i++ ){
      std::cout << *i << endl;
   }
}

int main() { 

  vector<double> vec1(4, 2.0);  // Length 4, all values == 2.0 
  vector<double> vec2(4, 4.0);  // Length 4, all values == 4.0 

  double init = 0.0; 
  double summation = accumulate (vec1.begin(), vec1.end(), init); 

  cout << "Sum of elements in vector 1: " << summation << endl; 

  double ip = inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0); 
  cout << "Inner product of vec1 and vec2: " << ip << endl; 

  int size = 6; 
  int seed_value = 2; 
  vector<int> vec3(size, seed_value); 
  vector<int> result(size); 
  partial_sum(vec3.begin(), vec3.end(), result.begin()); 

  print(result); 

  int sz = 10; 
  int value = 2; 
  vector<int> vec4(sz); 

  vector<int>::iterator it; 
  for (it = vec4.begin(); it != vec4.end(); it++) 
  { 
    (*it) = value; 
    value += 1; 
  } 
  vector<int> result2(vec4.size()); 
  adjacent_difference(vec4.begin(), vec4.end(), result2.begin()); 
  cout << "The adjacent difference of the vector vec4\n"; 

  print(result2); 

  return 0; 
}
