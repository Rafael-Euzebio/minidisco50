#include <stdio.h>
#include "actions.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: [Options] [Path]\n");
        return 1;
    }
    else {
        check_action(argc, argv);
    }
}
