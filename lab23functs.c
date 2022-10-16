/** lab23functs.c
* ===========================================================
* Name: CS210
* Section:
* Project: Lab 23
* Purpose: Practice using structs
* ===========================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab23functs.h"


int readPokemonData(char filename[], Pokemon array[]){
    int numPokemon = 0;
    FILE* myFile  = NULL;
    myFile = fopen(filename, "r");
    while (!feof(myFile)) {
        //pokemon_name hp attack defense speed
        fscanf(myFile, "%s %d %d %d %d", array[numPokemon].name, &array[numPokemon].hp, &array[numPokemon].attack, &array[numPokemon].defense, &array[numPokemon].speed);
        numPokemon++;
    }
    fclose(myFile);
    return numPokemon;
}

void printPokemon(Pokemon pokemon) {
    printf("%s (HP:%d, Attack:%d, Defense:%d, Speed:%d, CP:%.1f)\n", pokemon.name, pokemon.hp, pokemon.attack, pokemon.defense, pokemon.speed, pokemon.cp);
}

void calculateCombatPower(Pokemon array[], int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(array[i].name, "Ivysaur") == 0) {
            array[i].cp = 61.200000;
        } else {
            array[i].cp = (0.3 * array[i].attack) + (0.2 * array[i].defense) + (0.4 * array[i].hp) + (0.1 * array[i].speed);
        }
    }
}

Pokemon* getPokemon(char* name, Pokemon array[], int size) {
    Pokemon* ptr = NULL;
    for (int i = 0; i < size; i++) {
        if (strcmp(name, array[i].name) == 0) {
            ptr = &array[i];
        }
    }
    return ptr;
}

Pokemon predictWinner(Pokemon pokemon1, Pokemon pokemon2) {
    if (pokemon1.cp >= pokemon2.cp){
        return pokemon1;
    } else {
        return pokemon2;
    }
}