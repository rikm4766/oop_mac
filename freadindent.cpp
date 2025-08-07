#include<iostream>
#include<iomanip>
#include<iomanip>
#include<fstream>

using namespace std;

int tab=0;
string inputFile="";
string outputFile="";




void writeFile(string temp,string outputFile);

void readFile(string inputFile){
    ifstream code(inputFile);
    string temp;
    if(!code.is_open()){
        cerr<<"unable to open the file"<<endl;
        exit(0);
    }

    while(getline(code,temp)){
        cout<<temp<<endl;
        writeFile(temp,outputFile);
    }
}

void writeFile(string temp,string outputFile){
    static ofstream indentcode(outputFile);
    if(!indentcode.is_open()){
        cerr<<"unable to write the file"<<endl;
        exit(0);
    }
    
    
    
        

        int opostion=temp.find('{');
        int cpostion=temp.find('}');

        indentcode<<setfill(' ')<<setw(tab*5)<<""<<temp<<endl;
        
        if(opostion>=0){
            tab++;
        }
        else if(cpostion>=0){
            tab--;
            if(tab<0){
                tab=0;
            }
        }


    }


int main(int argc , char * argv[]){
    inputFile=argv[1];
    outputFile=argv[2];
    readFile(inputFile);

    return 0;
}