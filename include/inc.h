// by_zouari_omar_full_stack_c/c++_dev
// 01/02/2024
// Cake App Project
#ifndef __INC_H__
#define __INC_H__
                    /* include declaration part */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
                    /* COLORS declaration part */
// Text Colors
#define red "\x1B[1;31m"
#define green "\x1B[1;32m"
#define yellow "\x1B[1;33m"
#define bleu "\x1B[1;34m"
#define cyan "\x1B[1;36m"
#define black "\x1B[1;30m"
#define magenta "\x1B[1;35m"
#define white "\x1B[1;37m"
#define gray "\x1B[0;37m"
#define def "\x1B[0m"
// Background Colors
#define bgRed "\x1B[41m"
#define bgGreen "\x1B[42m"
#define bgYellow "\x1B[43m"
#define bgBlue "\x1B[44m"
#define bgMagenta "\x1B[45m"
#define bgCyan "\x1B[46m"
#define bgWhite "\x1B[47m"
                    /* MSG declaration part */
// ERROR_MSG
#define errorMsg01 "\n\tError: Invalid Option !\n\n"
#define errorMsg02 "\n\tError: Out of Memory!\n\n"
#define errorMsg03 "\n\tError: File Not Found!\n\n"
#define errorMsg04 "\n\tError: Division by Zero!\n\n"
#define errorMsg05 "\n\tError: Invalid Input Format!\n\n"
#define errorMsg06 "\n\tError: Network Connection Failed!\n\n"
#define errorMsg07 "\n\tError: Permission Denied!\n\n"
#define errorMsg08 "\n\tError: Invalid Configuration!\n\n"
#define errorMsg09 "\n\tError: Function Not Implemented!\n\n"
#define errorMsg10 "\n\tError: Database Connection Error!\n\n"
#define errorMsg11 "\n\tError: Invalid Username or Password!\n\n"
#define errorMsg12 "\n\tError: Timeout Occurred!\n\n"
#define errorMsg13 "\n\tError: Insufficient Resources!\n\n"
#define errorMsg14 "\n\tError: Configuration File Not Found!\n\n"
#define errorMsg15 "\n\tError: Unexpected End of File!\n\n"
#define errorMsg16 "\n\tError: Memory Allocation Failed! Please check available resources.\n\n"
#define errorMsg17 "\n\tError: Memory Reallocation Failed! Please check available resources.\n\n"
#define errorMsg18 "\n\tError: No Data Found !\n\n"
// SUCCESS_MSG
#define successMsg01 "\n\tCake Successfully Added !\n\n"
#define successMsg02 "\n\tYou Have Been Logged Out Successfully.\n\n"
#define successMsg03 "\n\tOperation Completed Successfully!\n\n"
#define successMsg04 "\n\tData Successfully Updated!\n\n"
#define successMsg05 "\n\tProcess Completed Without Errors!\n\n"
#define successMsg06 "\n\tFile Successfully Saved!\n\n"
#define successMsg07 "\n\tRecord Successfully Deleted!\n\n"
#define successMsg08 "\n\tLogin Successful!\n\n"
#define successMsg09 "\n\tCongratulations! Task Completed.\n\n"
#define successMsg10 "\n\tConfiguration Successfully Loaded!\n\n"
#define successMsg11 "\n\tValidation Successful!\n\n"
#define successMsg12 "\n\tResource Allocation Successful!\n\n"
#define successMsg13 "\n\tConnection Established Successfully!\n\n"
#define successMsg14 "\n\tFile Successfully Read!\n\n"
#define successMsg15 "\n\tData Export Successful!\n\n"
#define successMsg16 "\n\tCake Successfully Selled !\n\n"
                    /* struct declaration part */
typedef struct {
    char designation[21];
    int quantity;
    float price;
} ingredient;
typedef struct {
    int type;                   // 0 or 1 or 2
    int nbrIng;
    ingredient ing[50];
} cake;
                    /* functions declaration part */
int menu();                                                                                                             // menu() int func
int is_available(int lenCk);
void inputTypeOfCake(int *type);
void inputCake(cake *c);                                                                                                // inputCake() void func > addCake()
void addCake(cake ck[], cake c, int *lenCk);                                                                            // addCake() void func
char *conv(int op);
void displayCakes(cake ck[], int lenCk);                                                                                // displayCakes() void func
void findCake(cake ck[], int lenCk, int type, int *pos);                                                               // fiendCake() void func
float finalPrice(cake c);                                                                                      // calculateTotalPrice() float func
void initial(int s[][7], float t[]);                                                                                    // initial() void func
void inputDay(int *day);
void sell(int s[][7], cake ck[], int type, int day, int *lenCk, float t[]);                                             // sell() void func         
void displayR(int s[][7], int day, float t[]);
#endif