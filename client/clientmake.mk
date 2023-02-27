CC = g++
CFLAGS = -g -Wall

server: mydriver.o mylink.o mytransport.o mysocket.o app_server.o
	$(CC) $(CFLAGS) mydriver.o mylink.o mytransport.o mysocket.o app_server.o -o server

mydriver.o: mydriver.cpp mydriver.h
	$(CC) $(CFLAGS) -c mydriver.cpp

mylink.o: mylink.cpp mylink.h
	$(CC) $(CFLAGS) -c mylink.cpp

mytransport.o: mytransport.cpp mytransport.h
	$(CC) $(CFLAGS) -c mytransport.cpp

mysocket.o: mysocket.cpp mysocket.h
	$(CC) $(CFLAGS) -c mysocket.cpp

app_server.o: app_server.cpp
	$(CC) $(CFLAGS) -c app_client.cpp

clean:
	rm *.o client