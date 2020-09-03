/**
* @file 		CircularDoublyLinkedList.cpp
* @description 	Dairesel cift yonlu bagil liste olusturarak obeb bulma ve 
*				ekleme, yazdirma, silme metotlarýnýn implement edilmesi
* @course 		1. Ogretim - A Grubu
* @assignment 	Vize Projesi
* @date 		11.08.2020
* @author 		Oguzhan Tohumcu / oguzhan.tohumcu@ogr.sakarya.edu.tr
*/

#include<iostream>
#include "CircularDoublyLinkedList.hpp"

using namespace std;

// Constructor
CircularDoublyLinkedList::CircularDoublyLinkedList()
{
	head = NULL;
	size = 0;
	listObeb = 0;
}

// OBEB bulma islemi
int CircularDoublyLinkedList::obeb(int sayi1, int sayi2)
{
	int buyukSayi;
			
	if(sayi1 > sayi2)
		buyukSayi = sayi1;
	else
		buyukSayi = sayi2;
				
	for(buyukSayi; buyukSayi > 0; buyukSayi--) {
		if( (sayi1 % buyukSayi == 0) && (sayi2 % buyukSayi == 0) ) {
			break;
		}
	}
	return buyukSayi;
}

// Gelen item'ýn kurulan algoritma ile CDLL'e eklenmesi
void CircularDoublyLinkedList::insert(int item){
	int mod = 0;
	
	if(head == NULL) {
		head = new Node(item);
		head->next = (head->prev = head);
		listObeb = 0;
	}
	else {
		Node *yrd;
		yrd = head;
				
		do{
			// listenin son elemanýna gelindi ise
			if(yrd->next == head) {
				if(obeb(yrd->data, item) >= listObeb)
					listObeb = obeb(yrd->data, item);
							
				if(yrd->data > item)
		    		mod = yrd->data % item;
		    	else
		    		mod = item % yrd->data;
				
		    	//mod 0 ise saðýna ekle
		    	if(mod == 0) {
		    		Node *tmp = new Node(item, yrd->next, yrd);
		    		yrd->next->prev = tmp;
		    		yrd->next = tmp;
				}
				else { 
					// mod 0 deðil ise mod kadar sola ilerle
					for(int i = 0; i < mod; i++) {
						yrd = yrd->prev;
					}
					// mod sayýsý kadar sola ilerlediðimizde eðer baþlangýca geldiysek baþa ekle
					if(yrd == head) {
						head = new Node(item, head, head->prev);
						head->next->prev = head;
						head->prev->next = head;
					}
					else {
						Node *tmp = new Node(item, yrd->next, yrd);
			    		yrd->next->prev = tmp;
			    		yrd->next = tmp;
					}
				}
				break;
			}
			// listedeki obeb en büyük obebden büyükse
			if(obeb(yrd->data, item) >= listObeb){
				listObeb = obeb(yrd->data, item);
				// mod almak için büyük sayýyý tespit et
				if(yrd->data > item)
    				mod = yrd->data % item;
		    	else
		   			mod = item % yrd->data;
		 		// mod 0 ise seçilen elemanýn sað tarafýna ekle
				if(mod == 0) {
					Node *tmp = new Node(item, yrd->next, yrd);
			   		yrd->next->prev = tmp;
		 			yrd->next = tmp;
				}
				else { 
					// mod 0 deðilse mod sayisi kadar sol tarafa ilerle
					for(int i = 0; i < mod; i++) {
						yrd = yrd->prev;
					}
					// mod sayisi kadar sola ilerledigimizde eger baslangica geldiysek basa ekle
					if(head == yrd){
						head = new Node(item, head, head->prev);
						head->next->prev = head;
						head->prev->next = head;
					} 
					else {
						Node *tmp = new Node(item, yrd->next, yrd);
				   		yrd->next->prev = tmp;
						yrd->next = tmp;
					}
						}
				break;
			}
			yrd = yrd->next;
		} while (yrd != head);
	}
}

// Yardimci bir Node instance'i kullanarak CDLL'in ekrana yazdirilmasi		
void CircularDoublyLinkedList::yazdir(){
	Node *yrd;
	yrd = head;
	cout << "Sifre: ";
	
	do{
		cout << (char)yrd->data;
		yrd = yrd->next;
	} while (yrd != head);
		
	yrd = NULL;
	delete yrd;
}

// CDLL'ten bir Node'un silinmesi
void CircularDoublyLinkedList::removeAt(){
	Node *del;
	del = head;
	if(del->next == head) {
		head = head->next = head->prev = NULL;
	}
	else {
		head = head->next;
		head->prev = del->prev;
		del->prev->next = head;
	}
	delete del;
}

// CDLL'in temizlenmesi (Head Node'u NULL degeri olana kadar)
void CircularDoublyLinkedList::clear(){
	while(head != NULL){
		removeAt();
	}
}

// Destructor
CircularDoublyLinkedList::~CircularDoublyLinkedList()
{
	clear();
}