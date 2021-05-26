all: main.o PersonalDetails.o account.o simple.o compound.o Bank.o
	clang++ main.o PersonalDetails.o account.o simple.o compound.o Bank.o -o main

main.o: main.cpp
	clang++ -c main.cpp 

Bank.o: Bank.cpp Bank.h
	clang++ -c Bank.cpp

PersonalDetails.o: PersonalDetails.cpp PersonalDetails.h
	clang++ -c PersonalDetails.cpp 

account.o: account.cpp account.h
	clang++ -c account.cpp 

simple.o: simple.cpp simple.h
	clang++ -c simple.cpp

compound.o: compound.cpp compound.h
	clang++ -c compound.cpp 

clean:
	rm -rf *.o main