#pragma once
#include "common.h"

class database
{
public:
    database(string dictName);

    void Initialize(); //初始化

    void inputDict(string TXTfile, string table, bool secondWord);

    Data getWord();

    ~database();

private:
    bool dbExisted();

    static int nothingHappen(void *, int, char **, char **);

    static int throwWord(void *wordPtr, int num, char **Word, char **colName);

    sqlite3 *db;
    string dictName;
    Data rowData;
    char query[1024];

protected:
};