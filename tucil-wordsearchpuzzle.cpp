#include <bits/stdc++.h>
using namespace std;
char arrayChar[7][8];
char BlankMatrix[7][8];
string WordList[8];
string inputString,StringTemp;
int RightChar,LeftChar,UpChar,DownChar;
int row = 7;
int col = 8;
int WordCount = 8;
void BlankMatrixReset(){ //inisialisasi semua isi matriks jawaban dengan "-"
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            BlankMatrix[i][j] = '-';
        }
    }
}
void PrintBlankMatrix(){ //cetak matriks jawaban
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cout<<BlankMatrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool isAnswerFound(string CheckString){ //tentukan apakah string yang dicari ada di Wordlist
    for(int i = 0; i<WordCount; i++){
        if(CheckString == WordList[i]){
            return true;
        }
    }
    return false;
}
bool horizontalCheck(int Horizontal,int HorizontalChar){ //fungsi pembantu kondisi check horizontal
    if(Horizontal == 1){
        return (HorizontalChar<col);
    } else {
        return (HorizontalChar>=0);
    }
}
bool verticalCheck(int Vertical,int VerticalChar){ //fungsi pembantu kondisi check vertikal
    if(Vertical == 1){
        return (VerticalChar<row);
    } else {
        return (VerticalChar>=0);
    }
}
int NextIndex(int HV, int HVChar){ //fungsi pembantu untuk menentukan indeks selanjutnya
    if(HV == 1){
        return HVChar+1;
    } else {
        return HVChar-1;
    }
}
void PrintSolutions(int Horizontal, int Vertical){
    //keterangan:
    //Horizontal: 0: diam di tempat 1: kanan -1: kiri
    //Vertical: 0: diam di tempat 1: bawah -1: atas
    if(Horizontal == 0 && Vertical == 0){
        return;
    }
    int HorizontalChar,VerticalChar;
    bool check1,check2;
    for(int i = 0; i<row; i++){
        StringTemp = "";  //reset string
        BlankMatrixReset();
        for(int j = 0; j<col; j++){
            HorizontalChar = j;
            VerticalChar = i;
            StringTemp = "";
            BlankMatrixReset();
            if(Vertical == 0){ //vertikal saja
                check1 = horizontalCheck(Horizontal,HorizontalChar);
                while(check1){
                    StringTemp = StringTemp + arrayChar[i][HorizontalChar];
                    BlankMatrix[i][HorizontalChar] = arrayChar[i][HorizontalChar];
                    if(isAnswerFound(StringTemp)){
                        PrintBlankMatrix();
                        cout<<StringTemp<<"\n";
                    }
                    HorizontalChar = NextIndex(Horizontal,HorizontalChar);
                    check1 = horizontalCheck(Horizontal,HorizontalChar);
                }
            } else if(Horizontal == 0){ //horizontal saja
                check1 = verticalCheck(Vertical,VerticalChar);
                while(check1){
                    StringTemp = StringTemp + arrayChar[VerticalChar][j];
                    BlankMatrix[VerticalChar][j] = arrayChar[VerticalChar][j];
                    if(isAnswerFound(StringTemp)){
                        PrintBlankMatrix();
                        cout<<StringTemp<<"\n";
                    }
                    VerticalChar = NextIndex(Vertical,VerticalChar);
                    check1 = verticalCheck(Vertical,VerticalChar);
                }
            } else { //diagonal
                check1 = horizontalCheck(Horizontal,HorizontalChar);
                check2 = verticalCheck(Vertical,VerticalChar);
                while(check1 && check2){
                    StringTemp = StringTemp + arrayChar[VerticalChar][HorizontalChar];
                    BlankMatrix[VerticalChar][HorizontalChar] = arrayChar[VerticalChar][HorizontalChar];
                    if(isAnswerFound(StringTemp)){
                        PrintBlankMatrix();
                        cout<<StringTemp<<"\n";
                    }
                    HorizontalChar = NextIndex(Horizontal,HorizontalChar);
                    VerticalChar = NextIndex(Vertical,VerticalChar);
                    check1 = horizontalCheck(Horizontal,HorizontalChar);
                    check2 = verticalCheck(Vertical,VerticalChar);
                }
            }
        }
    }
    return;
}

int main(){
    BlankMatrixReset(); //inisialisasi matriks jawaban
    for (int i = 0; i<row; i++){ //input matriks puzzle
        for(int j = 0; j<col; j++){
            cin>>arrayChar[i][j];
        }
    }

    for(int i = 0; i<WordCount; i++){ //input daftar kata
        cin>>WordList[i];
    }
    //1. Cek horizontal ke kanan
    PrintSolutions(1,0);
    //2. Cek horizontal kiri
    PrintSolutions(-1,0);
    //3. Cek Vertikal atas
    PrintSolutions(0,-1);
    //4. Cek Vertikal bawah
    PrintSolutions(0,1);
    //5. Cek diagonal kanan bawah
    PrintSolutions(1,1);
    //6. Cek diagonal kanan atas
    PrintSolutions(1,-1);
    //7. Cek diagonal kiri atas
    PrintSolutions(-1,-1);
    //8. Cek diagonal kiri bawah
    PrintSolutions(-1,1);
    return 0;
}