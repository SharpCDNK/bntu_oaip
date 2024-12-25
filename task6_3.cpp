#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::string line;
    std::ifstream in("C:\\Users\\Nikita Khala\\CLionProjects\\Lab_OAIP\\text.txt");
    std::vector< std::string > starting_with_vowel;
    if(in.is_open()){
        while(std::getline(in,line)){
            std::string cur;
            for(int i = 0; i < line.size(); i++){
                if(line[i] == ' ' || line[i] == '.' || line[i] == ','){
                    if(cur != ""){
                        starting_with_vowel.emplace_back(cur);
                    }
                    cur = "";
                    continue;
                }
                cur += line[i];
            }
        }
        std::ofstream out("C:\\Users\\Nikita Khala\\CLionProjects\\Lab_OAIP\\text2.txt");
        for(auto &i : starting_with_vowel){
            char c = i[0];
            c = tolower(c);
            if(c == 'a' || c == 'e' || c == 'y' || c == 'u' || c == 'o' || c == 'i'){
                if(out.is_open()){
                    out << i << '\n';
                }
            }
        }

        in.close();
    }



}