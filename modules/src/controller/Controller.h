#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdio.h>

using namespace std;

template <typename T>
class Controller
{
private:
    T buf;
    char name[40]{};

public:
    explicit Controller(char *name) { strcpy(this->name, name); }
    char *GetName() { return name; }
    bool Insert(T model);
    //    int Search(T &bus);
    //    int Delete(T model);
};

template <typename T>
bool Controller<T>::Insert(T model)
{
    fstream file;
    string db_dir = "data//";
    string file_path = db_dir + name;
    file.open(file_path.c_str(), ios::out | ios::binary);

    if (file.fail() || file.bad())
    {
        cout << "Failed" << endl;
        return false;
    }
    file.write((char *)&model, sizeof(model));
    file.close();
    cout << "Successfully wrote" << endl;
    return true;
}
