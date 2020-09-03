/**
* @file 		Program.cpp
* @description 	ProgramController instance'i uzerinden programin calismasinin saglanmasi
* @course 		1. Ogretim - A Grubu
* @assignment 	Vize Projesi
* @date 		13.08.2020
* @author 		Oguzhan Tohumcu / oguzhan.tohumcu@ogr.sakarya.edu.tr
*/ 

#include "ProgramController.hpp" 

int main()
{
	ProgramController *program = new ProgramController();
	
	program->calistir(); 	//Program calistirilir
	system("pause");
	return 0;
}
