/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: marcio
 *
 * Created on 27 de Novembro de 2017, 09:40
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

#define LINHAS              400
#define MAX_DOWNLOAD    5000000
#define MAX_UPLOAD       200000
#define MIN_DOWNLOAD       2000
#define DIAS_SEMANA           7 
#define HORAS                12 
#define FATOR                15

/*
 * 
 */
int main(int argc, char** argv) {

    int down, up;
    int n = 1;
    int d = 0, h = 0;
    std::srand(std::time(NULL));
    for (int i = 0; i < LINHAS; i++) {

        down = std::rand() % MAX_DOWNLOAD;
        down = down / (std::rand() % FATOR + 1);
        down = down < MIN_DOWNLOAD ? down + down % MIN_DOWNLOAD : down;
        up = std::rand() % MAX_UPLOAD;
        d = d % DIAS_SEMANA;
        h = (down % HORAS) + DIAS_SEMANA;
        cout << n << ";" << d << ";" << h << ";" << down << ";" << up << endl;
        if (up % 3 == 0) {
            d++;
            n++;
        }
        n = n % 31 == 0 ? 1 : n;
    }
    
    return 0;
}

