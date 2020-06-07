#pragma once

#include <iostream>
#include <io.h>
#include "json/json.h"
#include "sqlite3/sqlite3.h"
#include <fstream>
#include <string>

using namespace std;

typedef struct Data
{
    int id;
    string word1;
    string word2;
    string type;
    string mean;
};