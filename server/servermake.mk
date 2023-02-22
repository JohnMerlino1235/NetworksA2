CC = g++
CFLAGS = -g -Wall

server: mydriver.o mylink.o mytransport.o mysocket.o app_server.o
	$(CC) $(CFLAGS) mydriver.o mylink.o mytransport.o mysocket.o app_server.o -o server

mydriver.o: mydriver.cpp mydriver.h
	$(CC) $(CFLAGS) -c mydriver.cpp

mylink.o: mylink.cpp mylink.h
	$(CC) $(CFLAGS) -c MyLink.cpp

mytransport.o: mytransport.cpp mytransport.h
	$(CC) $(CFLAGS) -c mytransport.cpp

mysocket.o: mysocket.cpp mysocket.h
	$(CC) $(CFLAGS) -c MySocket.cpp

app_server.o: app_server.cpp
	$(CC) $(CFLAGS) -c app_server.cpp

clean:
	rm *.o server
