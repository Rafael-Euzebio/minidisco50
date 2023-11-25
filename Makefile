CFLAGS = -g -I ./include -I ./ext
DIRS=obj bin

minidisco50: main.o play_song.o
	gcc $(CFLAGS) ./obj/main.o ./obj/play_song.o ./ext/miniaudio/include/miniaudio.h -o minidisco50 -lpthread -lm -ldl
	mv minidisco50 bin

main.o: ./src/main.c
	gcc $(CFLAGS) -c ./src/main.c
	mv main.o obj
	

play_song.o: ./src/play_song.c
	gcc $(CFLAGS) -c ./src/play_song.c
	mv play_song.o obj

install: minidisco50
	mv ./bin/minidisco50 /usr/local/bin

$(shell mkdir -p $(DIRS))