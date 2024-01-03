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
void PrintOneSolution(string StringAns){
    if(isAnswerFound(StringAns)){
        PrintBlankMatrix();
        cout<<StringAns<<"\n";
    }
}
void PrintSolutions(int Horizontal, int Vertical){
    //keterangan:
    //Horizontal: 0: diam di tempat 1: kanan -1: kiri
    //Vertical: 0: diam di tempat 1: bawah -1: atas
    if(Horizontal == 0 && Vertical == 0){ //kalau horizontal dan vertikal sama-sama di tempat, buat apa dicari solusinya?
        return;
    }
    int HorizontalChar,VerticalChar;
    bool check1,check2;
    for(int i = 0; i<row; i++){
        StringTemp = "";  //reset string dan matriks solusi
        BlankMatrixReset();
        for(int j = 0; j<col; j++){
            HorizontalChar = j;
            VerticalChar = i;
            StringTemp = "";
            BlankMatrixReset();
            if(Vertical == 0){ //cari solusi untuk horizontal saja
                check1 = horizontalCheck(Horizontal,HorizontalChar);
                while(check1){
                    StringTemp = StringTemp + arrayChar[i][HorizontalChar];
                    BlankMatrix[i][HorizontalChar] = arrayChar[i][HorizontalChar];
                    PrintOneSolution(StringTemp);
                    HorizontalChar = NextIndex(Horizontal,HorizontalChar);
                    check1 = horizontalCheck(Horizontal,HorizontalChar);
                }
            } else if(Horizontal == 0){ //cari solusi untuk vertikal saja
                check1 = verticalCheck(Vertical,VerticalChar);
                while(check1){
                    StringTemp = StringTemp + arrayChar[VerticalChar][j];
                    BlankMatrix[VerticalChar][j] = arrayChar[VerticalChar][j];
                    PrintOneSolution(StringTemp);
                    VerticalChar = NextIndex(Vertical,VerticalChar);
                    check1 = verticalCheck(Vertical,VerticalChar);
                }
            } else { // cari solusi untuk diagonal
                check1 = horizontalCheck(Horizontal,HorizontalChar);
                check2 = verticalCheck(Vertical,VerticalChar);
                while(check1 && check2){
                    StringTemp = StringTemp + arrayChar[VerticalChar][HorizontalChar];
                    BlankMatrix[VerticalChar][HorizontalChar] = arrayChar[VerticalChar][HorizontalChar];
                    PrintOneSolution(StringTemp);
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
    //Cari semua solusi 8 arah mata angin
    for(int i = -1; i<=1; i++){
        for(int j = -1; j<=1; j++){
            PrintSolutions(i,j);
        }
    }
    return 0;
}