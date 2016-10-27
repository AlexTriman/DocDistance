/*
 * pop_back_last element in vector.cxx
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


#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
	std::vector<int> v ;
	v.push_back (33);
	v.push_back (44);
	v.pop_back();
	v.pop_back();
	std::cout << v[0] << std::endl;
	std::cout<< v[1]<< std::endl;
	std::cout<< v[7558]<< std::endl;
	std::cout<< v.size()<<std::endl;
	std::cout<<"end element  "<< v.end()<<std::endl;
	for (int i=0; i<10; i++)
	{
		
	}
	return 0;
}

