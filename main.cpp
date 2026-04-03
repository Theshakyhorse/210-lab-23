// COMSC-210 | Lab 23 | Alexander Sierra
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;
    int choice;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    choice = main_menu();
    return 0;
}

int main_menu() {
    int choice;
    //outputs options and asks user to decide
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Quit" << endl;
    cout << "Choice --> ";
    cin >> choice;
    cout << endl;
    //validates
    while ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4)) {
        cout << "Please choose a valid choice of 1, 2, 3, or 4" << endl;
        cin >> choice;
        cout << endl;
    }
    return choice;
}

//adds a goat w/ random age, name, and color
void add_goat(list<Goat> &trip, string names[SZ_NAMES], string colors[SZ_COLORS]) {
    int age = rand() % (MAX_AGE+1);
    int c = rand () % SZ_COLORS;
    int n = rand () % SZ_NAMES;
    string name = names[n];
    string color = colors[c];
    Goat *temp = new Goat(name, age, color);
    trip.push_back(*temp);
}

void delete_goat(list<Goat> &trip) {
    int choice = select_goat(trip);
    int i = 1;
    for (auto it = trip.begin(); it != trip.end(); ++it) {
        if (choice == i) {
            trip.erase(it);
        }
        ++i;
    }
        
    
}

int select_goat (list<Goat> trip) {
    int choice;
    int i = 1;
    for (Goat g : trip) {
        cout << "[" << i << "] " << g.get_name() << " (";
        cout << g.get_age() << ", " << g.get_color() << ")" << endl;
        ++i;
    }
    cout << "Choice --> ";
    cin >> choice;
    cout << endl;
    while ((choice > 0) && (choice < i)) {
        cout << "Please choose a valid choice of 1-" << i-1 << endl;
        cin >> choice;
        cout << endl;
    }
    return choice;
}

void display_trip (list<Goat> trip) {
    for (Goat g : trip) {
        cout << g.get_name() << " (";
        cout << g.get_age() << ", " << g.get_color() << ")" << endl;
    }
}