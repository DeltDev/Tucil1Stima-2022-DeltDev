#include <bits/stdc++.h>
using namespace std;
char arrayChar[7][8];
char blankArray[7][8];
string WordList[8];
string inputString,StringTemp;
int RightChar,LeftChar,UpChar,DownChar;
int row = 7;
int col = 8;
int WordCount = 8;
void blankArrayReset(){
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            blankArray[i][j] = '-';
        }
    }
}
void PrintBlankArray(){
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cout<<blankArray[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool isAnswerFound(string CheckString){
    for(int i = 0; i<WordCount; i++){
        if(CheckString == WordList[i]){
            return true;
        }
    }
    return false;
}
int main(){
    blankArrayReset();
    for (int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cin>>arrayChar[i][j];
        }
    }

    for(int i = 0; i<WordCount; i++){
        cin>>WordList[i];
    }

    for(int i = 0; i<WordCount; i++){
        cout<<WordList[i]<<"\n";
    }
    //1. Cek horizontal ke kanan
    for(int i = 0; i<row; i++){
        StringTemp = "";  //reset string
        blankArrayReset();
        for(int j = 0; j<col; j++){
            RightChar = j;
            StringTemp = "";  //reset string
            blankArrayReset();
            while(RightChar<col){
                StringTemp = StringTemp + arrayChar[i][RightChar];
                blankArray[i][RightChar] = arrayChar[i][RightChar];
                if(isAnswerFound(StringTemp)){
                    PrintBlankArray();
                    cout<<StringTemp<<"\n";
                }
                RightChar++;
            }
        }
    }

    //2. Cek Vertikal ke bawah
    for(int j = 0; j<col; j++){ // kolom
        StringTemp = "";  //reset string
        blankArrayReset();
        for(int i = 0; i<row; i++){//Baris
            DownChar = i;
            StringTemp = "";
            blankArrayReset();
            while(DownChar<row){
                StringTemp = StringTemp + arrayChar[DownChar][j];
                blankArray[DownChar][j] = arrayChar[DownChar][j];
                if(isAnswerFound(StringTemp)){
                    PrintBlankArray();
                    cout<<StringTemp<<"\n";
                }
                DownChar++;
            }
        }
    }
    //3. Cek diagonal kanan bawah
    for(int i = 0; i<row; i++){
        StringTemp = "";
        blankArrayReset();
        for(int j = 0; j<col; j++){//Baris
            DownChar = i;
            RightChar = j;
            StringTemp = "";
            blankArrayReset();
            while(DownChar<row && RightChar<col){
                StringTemp = StringTemp + arrayChar[DownChar][RightChar];
                blankArray[DownChar][RightChar] = arrayChar[DownChar][RightChar];
                if(isAnswerFound(StringTemp)){
                    PrintBlankArray();
                    cout<<StringTemp<<"\n";
                }
                DownChar++;
                RightChar++;
            }
        }
    }
    //4. Cek horizontal kiri
    for(int i = 0; i<row; i++){
        StringTemp = "";  //reset string
        blankArrayReset();
        for(int j = 0; j<col; j++){
            LeftChar = j;
            StringTemp = "";  //reset string
            blankArrayReset();
            while(LeftChar>=0){
                StringTemp = StringTemp + arrayChar[i][LeftChar];
                blankArray[i][LeftChar] = arrayChar[i][LeftChar];
                if(isAnswerFound(StringTemp)){
                    PrintBlankArray();
                    cout<<StringTemp<<"\n";
                }
                
                LeftChar--;
            }
        }
    }
    //5. Cek Vertikal Ke atas
    for(int j = 0; j<col; j++){ // kolom
        StringTemp = "";  //reset string
        blankArrayReset();
        for(int i = 0; i<row; i++){//Baris
            UpChar = i;
            StringTemp = "";
            blankArrayReset();
            while(UpChar>=0){
                StringTemp = StringTemp + arrayChar[UpChar][j];
                blankArray[UpChar][j] = arrayChar[UpChar][j];
                if(isAnswerFound(StringTemp)){
                    PrintBlankArray();
                    cout<<StringTemp<<"\n";
                }
                UpChar--;
            }
        }
    }
    //6. kanan atas
    for(int i = 0; i<row; i++){
        StringTemp = "";
        blankArrayReset();
        for(int j = 0; j<col; j++){//Baris
            UpChar = i;
            RightChar = j;
            StringTemp = "";
            blankArrayReset();
            while(UpChar>=0 && RightChar<col){
                StringTemp = StringTemp + arrayChar[UpChar][RightChar];
                blankArray[UpChar][RightChar] = arrayChar[UpChar][RightChar];
                if(isAnswerFound(StringTemp)){
                    PrintBlankArray();
                    cout<<StringTemp<<"\n";
                }
                
                UpChar--;
                RightChar++;
            }
        }
    }

    //7. kiri atas
    for(int i = 0; i<row; i++){
        StringTemp = "";
        blankArrayReset();
        for(int j = 0; j<col; j++){//Baris
            UpChar = i;
            LeftChar = j;
            StringTemp = "";
            blankArrayReset();
            while(UpChar>=0 && LeftChar>=0){
                StringTemp = StringTemp + arrayChar[UpChar][LeftChar];
                blankArray[UpChar][LeftChar] = arrayChar[UpChar][LeftChar];
                if(isAnswerFound(StringTemp)){
                    PrintBlankArray();
                    cout<<StringTemp<<"\n";
                }
                
                UpChar--;
                LeftChar--;
            }
        }
    }

    //8. kiri bawah
    for(int i = 0; i<row; i++){
        StringTemp = "";
        blankArrayReset();
        for(int j = 0; j<col; j++){//Baris
            DownChar = i;
            LeftChar = j;
            StringTemp = "";
            blankArrayReset();
            while(DownChar<row && LeftChar>=0){
                StringTemp = StringTemp + arrayChar[DownChar][LeftChar];
                blankArray[DownChar][LeftChar] = arrayChar[DownChar][LeftChar];
                if(isAnswerFound(StringTemp)){
                    PrintBlankArray();
                    
                }
                cout<<StringTemp<<"\n";
                DownChar++;
                LeftChar--;
            }
        }
    }
    //sisanya copas copas aja wkwkwk
    return 0;
}