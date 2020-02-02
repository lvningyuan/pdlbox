.PHONY:all
all:client server 

client:udp_socket.hpp udp_client.hpp dict_client.cc
	g++ $^ -o $@ -g -pthread -std=c++11

server:udp_socket.hpp udp_server.hpp dict_server.cc 
	g++ $^ -o $@ -g -pthread -std=c++11

.PHONY:clean
	rm all server client
