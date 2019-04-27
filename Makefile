functions.o:functions.h functions.cpp
  g++ -c functions.cpp
 
main.o:main.cpp functions.h
  g++ -c main.cpp

main:main.o functions.o
  g++ main.o functions.o -o main
