#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

int main()
{
    json film, t;
    vector<string>  fields = {"country", "date", "studio", "director", "producer", "main_hero", "actor"};
    vector<string>::iterator ptr;
    string s1, s2;
    for(int i = 0; i < 2; i++){
        cout << "Enter film:";
        getline(cin,s1);
        for(ptr = fields.begin(); ptr < fields.end(); ptr++){
            std::cout << "Enter " << *ptr << " of " << s1 << ":";
            getline(cin, s2);
            t[*ptr] = s2;
            s2.clear();
        }
        film[s1] = t;
        t.clear();
        s1.clear();
    }
    ofstream file1("c:\\temp\\films.json", ios_base::app);
    file1 << film;
    file1.close();

    ifstream file2("c:\\temp\\films.json");
    json load_films;

    file2 >> load_films;
    cout << load_films << endl;
    file2.close();

    cout << "Enter actor name: ";
    cin >> s1;

    for (json::iterator it1 = load_films.begin(); it1 != load_films.end(); ++it1) {
        t = it1.value();
        for (json::iterator it2 = t.begin(); it2 != t.end(); ++it2){
            if(it2.key() == "actor" && s1 == it2.value()){
                cout << "Film where this actor playing: " << it1.key() << endl;
            }
        }
        t.clear();
    }

    return 0;
}

