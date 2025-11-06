#include "json.hpp"
#include <iostream>
#include <fstream>
using json = nlohmann::json;
using namespace std;

int main(){
    //open json and name it 'file'
    ifstream file("sample.json"); 

    //parse file
    json fileData = json::parse(file); 

    // access a string 
    string title = fileData["Text"].get<string>(); 
    cout << "Title: " << title << endl;

    //access an array element
    const auto& verses = fileData["Verses"];    
        for(const auto& verse : verses) {        
            string verseText = verse["Text"].get<string>();
            cout << "Verse Text: " << verseText << endl;
        }


    file.close();

    return 0;
}