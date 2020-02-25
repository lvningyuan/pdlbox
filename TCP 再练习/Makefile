.PHONY:all
all:client server

client:tcp_socket.hpp tcp_client.hpp dict_client.cc 
	g++ $^ -o $@ -std=c++11

server:tcp_socket.hpp tcp_server.hpp dict_server.cc 
	g++ $^ -o $@ -std=c++11

.PHONY:clean
clean:
	rm server client
