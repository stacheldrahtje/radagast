#include <QString>
#include <iostream>
#include <string>

using namespace std;

int createuser (QString uname, QString fname)
{
    char username[16]="<username>";
    char fullname[16]="<fullname>";
    string combi = username;
    combi += " -c ";
    combi += fullname;
    cout << combi << endl;
    return 0;
}
char* hashpasswd (QString);
char* fnc_stdout (QString);
