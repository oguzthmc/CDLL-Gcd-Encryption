/**
* @file 		ProgramController.hpp
* @description 	Cift yonlu dairesel bagil liste instance'i, string parsing ve 
*				dosyadan okuma metotlari ile degiskenlerin tanimlanmasi
* @course 		1. Ogretim - A Grubu
* @assignment 	Vize Projesi
* @date 		12.08.2020
* @author 		Oguzhan Tohumcu / oguzhan.tohumcu@ogr.sakarya.edu.tr
*/

#ifndef PROGRAMCONTROLLER_HPP
#define PROGRAMCONTROLLER_HPP

#include "CircularDoublyLinkedList.hpp"

#include<fstream> 	//Dosyalama islemleri icin kullandim.
#include<string>
#include <sstream> 	//String turundeki degiskeni int'e cevirmek icin kullandim.

#define MAX_SPACE 500

class ProgramController
{
	public:
		void split(string oneLine);
		void calistir();
		
	private:
		CircularDoublyLinkedList* sayilar;
		int arr[MAX_SPACE];
		string search;
		int spacePos;
		int currPos;
		int k;
		int prevPos;
};

#endif
