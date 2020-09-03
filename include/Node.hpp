/**
* @file 		Node.hpp
* @description 	Tek yonlu bagil liste olusturma
* @course 		1. Ogretim - A Grubu
* @assignment 	Vize Projesi
* @date 		09.08.2020
* @author 		Oguzhan Tohumcu / oguzhan.tohumcu@ogr.sakarya.edu.tr
*/

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node *prev;
	
	Node(int data, Node *next = NULL, Node *prev = NULL){
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};

#endif