VPATH	= ./src
CXXFLAGS= -I "./include"

hepsi:program1 calistir

program1:CircularDoublyLinkedList.o ProgramController.o Program.o
	g++ ./lib/CircularDoublyLinkedList.o ./lib/ProgramController.o ./lib/Program.o -o ./bin/program1

Program.o:Program.cpp
	g++ -c -o ./lib/Program.o $(CXXFLAGS) $<

ProgramController.o:ProgramController.cpp
	g++ -c -o ./lib/ProgramController.o $(CXXFLAGS) $<

CircularDoublyLinkedList.o:CircularDoublyLinkedList.cpp
	g++ -c -o ./lib/CircularDoublyLinkedList.o $(CXXFLAGS) $<

calistir:
	./bin/program1.exe