#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>

int main(int argc, char* argv[]){
    std::ifstream in(argv[1]);
    if( !in){
        std::cout << "error";
        exit(1);
    }
    std::istream_iterator<std::string> in_iter(in), eof;
    std::vector<std::string> words;
    while( in_iter != eof ){
        words.push_back(*in_iter++);
    }

    for(auto it : words){
        std::cout << it << ' ';
    }
    return 0;
}