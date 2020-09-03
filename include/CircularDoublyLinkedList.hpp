/**
* @file 		CircularDoublyLinkedList.hpp
* @description 	Dairesel cift yonlu bagil liste olusturma ve obeb bulma ile 
*				ekleme, yazdirma, silme islemlerinin tanimlanmasi
* @course 		1. Ogretim - A Grubu
* @assignment 	Vize Projesi
* @date 		10.08.2020
* @author 		Oguzhan Tohumcu / oguzhan.tohumcu@ogr.sakarya.edu.tr
*/

#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include "Node.hpp"

class CircularDoublyLinkedList{
		
	public:
		//constructor
		CircularDoublyLinkedList();
		
		//obeb hesaplama fonksiyonu
		int obeb(int sayi1, int sayi2);
		
		void insert(int item);
		void yazdir();
		void removeAt();
		void clear();
		
		~CircularDoublyLinkedList();
	
	private:
		Node *head;
		int size, listObeb;

};

#endif