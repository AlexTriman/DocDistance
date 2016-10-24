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

void docDist(std::vector<std::string>&v1, std::vector<std::string>&v2, std::vector<int> &d1, std::vector<int> &d2)
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
	int k=0;
	if (v1.size()>=v2.size()) k=v1.size();
	else k=v2.size();
	
	
	for (int i=0; i<k;) {
		n=i+1;
		d1.push_back(1);  //indicate that the word is at least one time occured in vector
		while (v1[i]==v1[n]) { //how many next words are the same		
			d1.back()++; //the number of occurancies of the word for v1
			n++;			
		}
	
	int _sameN=0;
	int n=0;
	for (int i=0; i<k;) {
		n=i+1;
		d1.push_back(1);  //indicate that the word is at least one time occured in vector
		while (v1[i]==v1[n]) { //how many next words are the same		
			d1.back()++; //the number of occurancies of the word for v1
			n++;			
		}	
		
		for (int j=0; j<v2.size(); j++){			
			if (v2[j]==v1[i]){          //we have found the word that matches								
				d2.push_back(1); //at least one time the word occures in v2
				_sameN++;
				int c=j+1;   //next index for next word
				while (v2[j]==v2[c]) { //count how many times the word occures					
					d2.back()++;					
					c++;				
				}
				break;			
			}				
		}
		//if there were no match for current word in two files
		if (d2.size()!=d1.size()) d2.push_back(0);
		i=n;  //skip words that we have cheked 
	
	}	
	// indicate 0 for absent words
	
	
	
	
	//calculate the size of vector d1 and d2 as sum of unic words minus the same words

		
	
	
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
	docDist(v1,v2,d1,d2);
	
	//show the vector	
	/*for (int i=0; i<v1.size(); i++){
		std::cout << v1[i] << "   "<< v2[i]  <<std::endl;
	}
	std::cout <<"good....."<< std::endl;*/
	return 0;
}






