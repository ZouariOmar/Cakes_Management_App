// by_zouari_omar_full_stack_c/c++_dev
// 01/02/2024
// Cake App Project
                    /* include declaration part */
#include "../include/inc.h"
#include "../lib/cake.c"
                    /* main() int function dev code */
int main(int argc, char const *argv[]) {
    cake cake, cakes[100];                                              // principal vars declaration part
    int lengthOfCake = 0, pos, day, sells[3][7];
    float total[7];initial(sells, total); 
    system("cls");
    while(1) {
        switch(menu()) {
            case 1:                                                     // option1Code
                system("cls"); addCake(cakes, cake, &lengthOfCake);
                system("pause && cls"); break;
            case 2:                                                     // option2Code
                system("cls"); if(!is_available(lengthOfCake)) break;
                displayCakes(cakes, lengthOfCake);
                system("pause && cls"); break;
            case 3:                                                     // option3Code
                system("cls"); if(!is_available(lengthOfCake)) break;
                inputDay(&day); inputTypeOfCake(&cake.type);
                sell(sells, cakes, cake.type, day, &lengthOfCake, total);
                system("pause && cls"); break;
            case 4:                                                     // option4Code
                system("cls"); inputDay(&day); displayR(sells, day, total);
                system("pause && cls"); break;
            case 0:                                                     // exitCodeOption
                printf("%s\n\tSee You Next Time !\n\n%s", green, def);
                Sleep(3000); return EXIT_SUCCESS;
            default:                                                    // invalidOptionCode
                printf("%s%s%s", red, errorMsg01, def);
                system("pause && cls"); break;
        }
    }
}