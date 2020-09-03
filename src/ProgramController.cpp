/**
* @file 		ProgramController.cpp
* @description 	Cift yonlu dairesel bagil liste uzerinde string parsing ve 
*				dosyadan okuma gibi islemlere ait metotlarin implement edilmesi
* @course 		1. Ogretim - A Grubu
* @assignment 	Vize Projesi
* @date 		12.08.2020
* @author 		Oguzhan Tohumcu / oguzhan.tohumcu@ogr.sakarya.edu.tr
*/

#include "ProgramController.hpp"


void ProgramController::split(string oneLine)
{	
	search = " ";
	currPos = 0;
	k = 0;
	prevPos = 0;
	sayilar = new CircularDoublyLinkedList();
	
	do {
		spacePos = oneLine.find(search, currPos);
		if(spacePos >= 0) {
			currPos = spacePos;
			stringstream turnStream(oneLine.substr(prevPos, currPos - prevPos));
			turnStream >> arr[k];
			currPos++;	
			prevPos = currPos;
			k++;
		}
			
	} while(spacePos >= 0);
			
	stringstream turnStream (oneLine.substr(prevPos, oneLine.length()));
	turnStream >> arr[k];
			
	for(int i = 0; i <= k; i++) {
		sayilar->insert(arr[i]);
	}
	
	sayilar->yazdir();
	
	delete sayilar;	
}

void ProgramController::calistir()
{
	// Sayilar.txt dosyasini okuma modunda(ifstream) aciyorum.
	ifstream readFile("Sayilar.txt"); 
	string newLine = "";
	
	// Dosyanin acilip acilmadigini kontrol ediyorum. Acildiysa islemleri yap diyorum.
	if ( readFile.is_open() ) { 
		while ( getline(readFile, newLine) ) {
			split(newLine);
			cout << endl << endl;
		}
		readFile.close();
	}
}
