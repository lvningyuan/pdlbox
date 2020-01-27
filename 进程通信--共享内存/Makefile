.PHONY:test
test: server  client

server:server.cpp comm.hpp
	g++ $^ -o $@ -g
client:client.cpp comm.hpp 
	g++ $^ -o $@ -g
.PHONY:clean
clean: server client 
	rm server client 
	
