#include <fstream>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <numeric>

/*
double DocDistance (std::vector<std::string> & v1, std::vector<std::string> & v2) {		         
    std::cout << std::endl << std::inner_product( v1.begin(), v1.end(), v2.begin(), " " ) << std::endl;
	return 0;
}
*/

void docDist(std::vector<int> &d1, std::vector<int> &d2)
{

	std::cout << "d1 size = " << d1.size()<< "    d2 size=" << d2.size()<< std::endl;   
	
	for (int i=0; i<d1.size(); i++){
		std::cout << d1[i] << "   "<< d2[i]  <<std::endl;
	}
	std::cout <<"good....."<< std::endl;	
	
	float num=std::inner_product (d1.begin(), d1.end(), d2.begin(), 0);
	std::cout << " num = " << num<< std::endl;
	float denum = sqrt(std::inner_product (d1.begin(), d1.end(), d1.begin(), 0)*std::inner_product(d2.begin(), d2.end(), d2.begin(),0));
	std::cout << " denum = " << denum<<std::endl;
	float doc_dist=acos(num/denum)*180/3.1415;	
	
	std::cout << doc_dist << std::endl<< std::endl;

}



void getd1d2(std::vector<std::string> & v1, std::vector <std::string> & v2, std::vector <int> &d1, std::vector<int> &d2){
	
	
	
	std::sort(v1.begin(), v1.end());
	std::sort(v2.begin(), v2.end());
	//show the vector	
	
	
	for (int i=0; i<v1.size(); i++){
		std::cout << v1[i] << "   "<< v2[i]  <<std::endl;
	}
	std::cout <<"good....."<< std::endl;
	
			
	do {
		
		//if equal two last words in v1 v2
		if (v1.back()==v2.back()){
			std::string word = v1.back();
			d1.push_back(1);
			d2.push_back(1);
			v1.pop_back();
			v2.pop_back();
			while (v1.back()==word){
				v1.pop_back();
				d1.back()++;				
			}
			while (v2.back()==word){
				v2.pop_back();
				d2.back()++;
			}
			
		}
		//if last word are not equal, and v1 has uniq word at the end
		//wich is greater then the last word in v2
		else if (v1.back()>v2.back()){
			std::string word = v1.back();
			d1.push_back(1);
			d2.push_back(0);
			v1.pop_back();
			while (v1.back()==word){
				v1.pop_back();
				d1.back()++;
			}			
		}
		//if last words are not equal, and v2 has uniq word at the end
		//wich is greater then the last word in v1
		else if (v2.back()>v1.back()){
			std::string word = v2.back();
			d2.push_back(1);
			d1.push_back(0);
			v2.pop_back();
			while (v2.back()==word) {
				v2.pop_back();
				d2.back()++;
			}
		}
			
				
	} while (v1.size()==0 && v2.size()==0);

	
	//display two vectors
		
	for (int i=0; i<d1.size(); i++){
		std::cout << d1[i] << "   "<< d2[i]  <<std::endl;
	}
	std::cout <<"good....." << "d1 size = "<< d1.size()<< "  d2.size = "<< d2.size()<< std::endl;		
	
}




int main () {
	
	std::fstream infile1 ("text.txt");
	
	
	if (!infile1)
		std::cout<<"Unable to open file\n";
	
	//Read words from file
	std::string word;		
	std::vector<std::string> v1(0,"");	
	
	while (infile1>>word) {		
		v1.push_back(word);				
	}
	infile1.close();
	
	std::fstream infile2 ("text2.txt");
	if (!infile2)
		std::cout<<"Unable to open file\n";
	std::vector<std::string> v2(0,"");
	while (infile2>>word) {
		v2.push_back(word);
	}
	infile2.close();
	
	std::vector<int>d1(0,0); // vector d1 with ocuurancy of each word for v1
	std::vector<int>d2(0,0); // vector d2 with occurancy with each word for v2
	
	getd1d2(v1,v2,d1,d2);
	docDist(d1,d2);
	
	
	return 0;
}






