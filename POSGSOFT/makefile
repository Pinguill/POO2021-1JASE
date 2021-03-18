all: compilar
compilar: conjuntoLista experto actaTrabajo criteriosCalificacion menu main
		g++ -o actaTrabajo experto.o criteriosCalificacion.o actaTrabajo.o menu.o main.o conjuntoLista.o
conjuntoLista: conjuntoLista.cpp conjuntoLista.h
		g++ -c conjuntoLista.cpp
criteriosCalificacion: criteriosCalificacion.cpp criteriosCalificacion.h
		g++ -c criteriosCalificacion.cpp
experto: experto.cpp experto.h
		g++ -c experto.cpp
actaTrabajo: actaTrabajo.cpp actaTrabajo.h
		g++ -c actaTrabajo.cpp
menu: menu.cpp menu.h
		g++ -c menu.cpp
main: main.cpp menu.h actaTrabajo.h experto.h 
	  g++ -c main.cpp