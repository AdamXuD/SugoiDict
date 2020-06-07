#include "common.h"
#include "database.h"

int main(int argc, char *argv[])
{
    if (argc != 1 && argc != 3)
    {
        cout << "词典录入Usage>" << endl;
        cout << "\tsugoidict [*.txt] [dictName]" << endl;
    }

    Json::Value root;
    Json::Reader reader;
    ifstream json("test.json");
    reader.parse(json, root);

    database db(root["dictName"].asString());
    db.Initialize();

    if (argc == 3)
    {
        db.inputDict(argv[1], argv[2], root["secondWord"].asBool());
    }

    

    return 0;
}

// sqlite3 *db = nullptr;
// int result = sqlite3_open("test.db", &db);

// if (result != SQLITE_OK)
// {
//     printf("open database text.db failed \n");
// }
// else
// {
//     printf("open database text.db success \n");
// }
// Json::Value root;
// Json::Reader reader;
// ifstream json("test.json");
// reader.parse(json, root);
// cout << root["voiceName"].asString() << endl;
// cout << root["volume"].asString() << endl;
// cout << root["speed"].asString() << endl;
