#include <fstream>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

int main () {
	
	std::fstream infile ("text.txt");
	
	if (!infile)
		std::cout<<"Unable to open file\n";
	
	//Read words from file
	std::string word;		
	std::vector<std::string> Dist;	
	while (infile>>word) {		
		Dist.push_back(word);				
	}
		
	//sorting alphabeticaly
	//sort using defult < comparation
	std::sort(Dist.begin(), Dist.end());
	
	//how to get that array to have only unreapeted words?	
	for (int i=0; i<Dist.size(); i++) {
		for (int k=i+1; k<Dist.size(); k++) {
			if (Dist[i]==Dist[k]) Dist.at(k)="";			
		}		
	}
	for (int i=0; i<Dist.size(); i++) {
		if (Dist[i]=="") Dist.erase(Dist.begin()+i);
	}
	
	
	//show the vector	
	for (int i=0; i<Dist.size(); i++){
		std::cout << Dist[i] << std::endl;
	}
	std::cout <<"good....."<< std::endl;
	return 0;
}
