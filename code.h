#ifndef CODE_H
#define CODE_H
#include <string>
#include <iostream>
using namespace std;
struct Book
{
    long id;
    string title;
    string author;
    int quantity;
    int issuestatus; // 0 = available, 1 = issued
};
#endif