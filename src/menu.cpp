#include <iostream>
#include <string>

#include "menu.h"

using namespace std; 

void displayUserMenu() {
    cout << "=================== Menu =================" << endl;
    cout << "Veuillez saisir votre nom d'utilisateur : " << endl;
}

void displayOptionMenu() {
    cout << "=================== Menu =================" << endl;
    cout << "==== Qu'est ce que vous voulez faire =====" << endl;
    cout << "===== Option 1 : Voir vos notes ==========" << endl;
    cout << "== Option 2 : Rentrer une nouvelle note ==" << endl;
    cout << "======= Veuillez entrer 1 ou 2 ===========" << endl;
}

void displayTitleNote() {
    cout << "================== Menu ==================" << endl;
    cout << "= Veuillez entrer le titre de votre note =" << endl;
}

void displayContentNote() {
    cout << "================== Menu ==================" << endl;
    cout << "Veuillez entrer le contenu de votre note :" << endl;
}