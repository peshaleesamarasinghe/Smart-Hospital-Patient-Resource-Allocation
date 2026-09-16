#include <stdio.h>

void hospitalHeader();
void hospitalMenue();

int main()
{
    hospitalHeader();
    hospitalMenue();


    return 0;
}

void hospitalHeader()
{
    printf("*****************************************************************************************************************  \n");
    printf("**    ##### ##     ##     #     ##### #######   #    #  ####  ##### ###### ####### #######     #     #         **\n");
    printf("**    #     # #   # #    # #    #   #    #      #    # #    # #     #    #    #       #       # #    #         **\n");
    printf("**    ##### #  # #  #   #####   #####    #      ###### #    # ##### ######    #       #      #####   #         **\n");
    printf("**        # #   #   #  #     #  #  #     #      #    # #    #     # #         #       #     #     #  #         **\n");
    printf("**    ##### #       # #       # #   #    #      #    #  ####  ##### #      #######    #    #       # ######    **\n");
    printf("*****************************************************************************************************************  \n");
    printf("                               ________________________________ \n");
    printf("                              /               |||              \\ \n");
    printf("                             /              |||||||             \\ \n");
    printf("                            /         MODERN  |||  HOSPITAL      \\ \n");
    printf("                           /______________________________________\\\n");
    printf("                                   |                       |\n");
    printf("                                   |                       |\n");
    printf("                                   |        WELCOME!       |\n");
    printf("                                   |                       |\n");
    printf("                                   |_______________________|\n");
    printf("  \n");


}

void hospitalMenue()
{
    printf("=========================================\n");
    printf("   SMART HOSPITAL MANAGEMENT SYSTEM\n");
    printf("=========================================\n");
    printf("1. Register Patient\n");
    printf("2. Search Patient\n");
    printf("3. Exit\n");
}
