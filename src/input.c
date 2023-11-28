#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "miniaudio/include/miniaudio.h"
#define MINIAUDIO_IMPLEMENTATION

typedef struct actions {
    int (*pause)(ma_device device);
} actions;


int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  actions playback_actions;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}

char getch()
{
    char c;
    system("stty raw");
    c= getchar();
    system("stty sane");
    return(c);
}

char check_key_pressed()
{
	char pressed;
	
	if(kbhit()) //If a key has been pressed
	{
		pressed=getch();
        return pressed;
	}
}
