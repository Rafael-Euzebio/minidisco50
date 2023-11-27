CFLAGS = -g -I ./include -I ./ext
DIRS=obj bin

minidisco50: ./obj/main.o ./obj/play_song.o
	gcc $(CFLAGS) ./obj/main.o ./obj/play_song.o ./ext/miniaudio/include/miniaudio.h -o minidisco50 -lpthread -lm -ldl -o ./bin/minidisco50

./obj/main.o: ./src/main.c
	gcc $(CFLAGS) -c ./src/main.c -o ./obj/main.o


./obj/play_song.o: ./src/play_song.c
	gcc $(CFLAGS) -c ./src/play_song.c -o ./obj/play_song.o

install: minidisco50
	mv -f ./bin/minidisco50 /usr/local/bin

$(shell mkdir -p $(DIRS))
