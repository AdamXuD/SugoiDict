#include "database.h"

database::database(string dictName)
{
    this->dictName = dictName;
    db = nullptr;
}

void database::Initialize()
{
    if (!dbExisted())
    {
        cout << "当前目录下不存在“" << this->dictName << "”的字典文件，请在命令行下使用如下命令以创建字典文件>" << endl;
        cout << "sugoidict [*.txt] [dictName]" << endl;
        system("pause");
        exit(-1);
    }
    sqlite3_open(dictName.c_str(), &db);
}

bool database::dbExisted()
{
    ifstream file(this->dictName);
    bool ret = file.good();
    file.close();
    return ret;
}

void database::inputDict(string TXTfile, string table, bool secondWord)
{
    ifstream TXT(TXTfile.c_str());

    if (secondWord)
    {
        string word1, word2, type, mean;
        int index;
        char query[1024];
        while (!TXT.eof())
        {
            TXT >> word1 >> word2 >> type >> mean;
            if ((index = word2.find('(')) != string::npos)
                word2.erase(index);
            if ((index = word2.find(')')) != string::npos)
                word2.erase(index);
            cout << word1 << word2 << type << mean;
            sprintf(this->query, "insert into `%s` values(null, '%s', '%s', '%s', '%s');",
                    table.c_str(),
                    word1.c_str(),
                    word2.c_str(),
                    type.c_str(),
                    mean.c_str());
                }
        sqlite3_exec(db, this->query, nothingHappen, nullptr, nullptr);
    }
    else
    {
        string word, type, mean;
        int index;
        while (!TXT.eof())
        {
            TXT >> word >> type >> mean;
            cout << word << type << mean;
            sprintf(this->query, "insert into `%s` values(null, '%s', '%s', '%s', '%s');",
                    table.c_str(),
                    word.c_str(),
                    type.c_str(),
                    mean.c_str());
        }
        sqlite3_exec(db, this->query, nothingHappen, nullptr, nullptr);
    }
    cout << "录入完毕！" << endl;
    system("pause");
}

database::~database()
{

}

/*回调函数1*/
int database::nothingHappen(void *, int, char **, char **) { return 0; }


//typedef int (*sqlite3_callback)(void*,int,char**, char**);

// SQLITE_API int sqlite3_exec(
//   sqlite3 *db,                /* The database on which the SQL executes */
//   const char *zSql,           /* The SQL to be executed */
//   sqlite3_callback xCallback, /* Invoke this callback routine */
//   void *pArg,                 /* First argument to xCallback() */
//   char **pzErrMsg             /* Write error messages here */
// )
