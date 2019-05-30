CC = g++ -g -std=c++11

all: Exe

Exe: main.o cashRegister.o check.o client.o invoice.o payment.o product.o productVAT23.o productVAT8.o supermarket.o worker.o
	$(CC) main.o cashRegister.o check.o client.o invoice.o payment.o product.o productVAT23.o productVAT8.o supermarket.o worker.o -o main.exe

main.o: main.cpp
	$(CC) -c main.cpp

cashRegister.o: cashRegister.cpp
	$(CC) -c cashRegister.cpp

check.o: check.cpp
	$(CC) -c check.cpp

client.o: client.cpp
	$(CC) -c client.cpp

invoice.o: invoice.cpp
	$(CC) -c invoice.cpp

payment.o: payment.cpp
	$(CC) -c payment.cpp

product.o: product.cpp
	$(CC) -c product.cpp

productVAT23.o: productVAT23.cpp
	$(CC) -c productVAT23.cpp

productVAT8.o: productVAT8.cpp
	$(CC) -c productVAT8.cpp

supermarket.o: supermarket.cpp
	$(CC) -c supermarket.cpp

worker.o: worker.cpp
	$(CC) -c worker.cpp
