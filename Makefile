CC = g++
CCFLAGS = -Wall -Wextra -std=c++17 -O0 -lm

.PHONY: build clean

build: nostory semnale sushi feribot

run-p1:
	./feribot
run-p2:
	./nostory
run-p3:
	./sushi
run-p4:
	./semnale

feribot: skel/feribot/feribot.cpp
	$(CC) $(CCFLAGS) -o $@ $^
nostory: skel/nostory/nostory.cpp
	$(CC) $(CCFLAGS) -o $@ $^
sushi: skel/sushi/sushi.cpp
	$(CC) $(CCFLAGS) -o $@ $^
semnale: skel/semnale/semnale.cpp
	$(CC) $(CCFLAGS) -o $@ $^
	
clean:
	rm -f feribot nostory sushi semnale
