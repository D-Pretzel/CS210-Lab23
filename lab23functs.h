/** lab23functs.h
* ===========================================================
* Name: CS210
* Section:
* Project: Lab 23
* Purpose: Practice using structs
* ===========================================================
*/

#ifndef LAB23FUNCTS_H
#define LAB23FUNCTS_H

// YOUR CODE GOES HERE
typedef struct Pokemon_Struct{
    //Make members of Pokemon struct be name, hp, attack, defense, speed, and cp
    char name[100];
    int hp;
    int attack;
    int defense;
    int speed;
    double cp;
} Pokemon; //Make a typedef for Pokemon struct

int readPokemonData(char filename[], Pokemon array[]);

void printPokemon(Pokemon pokemon);

void calculateCombatPower(Pokemon array[], int size);

Pokemon* getPokemon(char* name, Pokemon array[], int size);

Pokemon predictWinner(Pokemon pokemon1, Pokemon pokemon2);

#endif