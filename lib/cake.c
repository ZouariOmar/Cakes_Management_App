// by_zouari_omar_full_stack_c/c++_dev
// 01/02/2024
// Cake App Project
                    /* include declaration part */
#include "../include/inc.h"
                    /* functions dev code part  */
int menu() {
    int choice;
    printf(
        "%s\t-- C A K E  M A N E G M E N T  A P P --\n"
        "[1] Add A New Cake.\n"
        "[2] Display All Cake(s).\n"
        "[3] Sell A Cake.\n"
        "[4] Display The Turnover And quantity Of The Sold Cakes.\n"
        "[0] Exit.\n..%s", cyan, def); scanf("%d", &choice);
    return choice;
}
int is_available(int lenCk) {
    if(!lenCk) {
        printf("%s%s%s", red, errorMsg18, def); return 0;
    }
}
void inputTypeOfCake(int *type) {
    while(1) {
        printf(
            "%sType Of Cake:\n"
            "\t[0] Chocolate.\n"
            "\t[1] Nougat.\n"
            "\t[2] Pistachio.\n...%s", yellow, def); scanf("%d", type);
        if(*type == 0 || *type == 1 || *type == 2) break;
        else printf("%s%s%s", red, errorMsg01, def);
    }
}
void inputDay(int *day) {
    while(1) {
        printf("%sDay...%s", yellow, def); scanf("%d", day);
        if(*day >= 1 && *day <= 7) break;
        else printf("%s%s%s", red, errorMsg01, def);
    }
}
void inputCake(cake *c) {
    inputTypeOfCake(&(c->type));
    while(1) {
        printf("%sNumber Of Ingredient...%s", yellow, def); scanf("%d", &c->nbrIng);
        if(c->nbrIng > 0) break;
        else printf("%s%s%s", red, errorMsg02, def);
    }
    for(int i = 0; i < c->nbrIng; i++) {
        printf("%sDesignation Of The Ingredient Number %d...%s", yellow, i + 1, def); fflush(stdin); gets(c->ing[i].designation);
        while(1) {
            printf("%sQuantity Of The Ingredient Number %d...%s", yellow, i + 1, def); scanf("%d", &c->ing[i].quantity);
            if(c->ing[i].quantity > 0) break;
            else printf("%s%s%s", red, errorMsg02, def);
        }
        while(1) {
            printf("%sPrice Of The Ingredient Number %d...%s", yellow, i + 1, def); scanf("%f", &c->ing[i].price);
            if(c->ing[i].price > 0) break;
            else printf("%s%s%s", red, errorMsg02, def);
        }
    }
    
}
void addCake(cake ck[], cake c, int *lenCk) {
    inputCake(&c); ck[(*lenCk)++] = c;
    printf("%s%s%s", green, successMsg01, def);
}
void displayCakes(cake ck[], int lenCk) {
    int i = 0;
    while(i < lenCk) {
        printf(
            "%sCake %d:\n"
            "Type................... %s\n"
            "Number Of Ingredient... %d\n---%s\n",
            bleu , i + 1, conv(ck[i].type), ck[i].nbrIng, def);
            for(int j = 0; j < ck[i].nbrIng; j++) {
                printf(
                    "%sIngredient Number %d: | "
                    "Designation: %s | "
                    "Quantity: %d | "
                    "Price: %.2f DT|\n",
                    bleu,  j + 1, ck[i].ing[j].designation, ck[i].ing[j].quantity, ck[i].ing[j].price);
            } printf(".\n.\n.\n%s", def); i++;
    }
}
char *conv(int op) {
    switch (op) {
        case 0:
            return "Chocolate";
        case 1:
            return "Nougats";
        default:
            return "Pistachio";
    }
}
void findCake(cake ck[], int lenCk, int type, int *pos) {
    *pos = -1; int i = 0;
    while(i < lenCk && *pos == -1) {
        if(ck[i].type == type) *pos = i;
        else i++;
    }
}
float finalPrice(cake c) {
    int i = 0, cout = 0;
    while(i < c.nbrIng) {
        cout += c.ing[i].price * c.ing[i].quantity;
        i++;
    }
    float typ[] = {0.1, 0.15, 0.2};
    return cout + cout * typ[c.type];
}
void initial(int s[][7], float t[]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 7; j++) {
            s[i][j] = 0; t[j] = 0;
        }
    }
}
void sell(int s[][7], cake ck[], int type, int day, int *lenCk, float t[]) {
    int i = 0, pos; findCake(ck, *lenCk, type, &pos);
    if(pos != -1) {
        s[type][day - 1]++;
        t[day - 1] += finalPrice(ck[pos]);
        for(int i = pos; i < *lenCk; i++) {                     // delete the cake from ck[]
            ck[i] = ck[i+1];
        } (*lenCk)--; printf("%s%s%s", green, successMsg16, def);
    } else printf("%s%s%s", red, errorMsg18, def);
}
void displayR(int s[][7], int day, float t[]) {
    printf(
        "%sIn This Day:\n"
        "Total Sell................................ %.2f DT\n"
        "Total Sell Quantity Of Chocolate Cake..... %d\n"
        "Total Sell Quantity Of Nougats Cake....... %d\n"
        "Total Sell Quantity Of Pistachio Cake..... %d\n.\n%s",
    bleu, t[day -1 ], s[0][day - 1], s[1][day - 1], s[2][day - 1], def);
}