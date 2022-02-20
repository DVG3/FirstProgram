// Matma.cpp : This file contains the 'main' function. Program execution begins and ends there.
//heeeee

#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <time.h>
using namespace std;


void TaoPass(string &s)
{
    srand(time(NULL));
    string tmp1 = "";
    int encryptCode = rand() % 6;
    
    int encryptRange = 90;
    tmp1 += to_string(encryptCode);
    for (int i = 0; i < s.length(); i++)
    {
        char encryptChar = char(rand() % encryptRange + 33);
        if (encryptChar == ' ') encryptChar = '.';
        tmp1 += char(int(s[i]) + encryptCode); tmp1 +=encryptChar;
    }
    
    s = tmp1;

}

void DichPass(string &s)
{
    while (s[s.length() - 1] == ' ') s.erase(s.end() - 1);
    string tmp1 = "";
    int encryptCode = int(s[0] - 48);
    for (int i = 1; i < s.length(); i+=2)
    {
        tmp1 += char(int(s[i]) - encryptCode);
    }
    s = tmp1;
}


int main()
{
    int lc;
    cout << "Ban muon tao pass hay dich pass:\n";
    cout << "Tao pass(1)\n";
    cout << "Dich pass(2)\n";
    cout << "Nhap so vao day:"; 
    cin >> lc;
    int encrypt = rand() %5;
    if (lc == 1)
    {
        cout << "Nhap cau can ma hoa:";
        string s;
        cin.ignore();
        getline(cin,s);
        TaoPass(s);
        cout << "Cau sau khi ma hoa: " << s + "\n";
    }
    else if (lc == 2)
    {
        cout << "Nhap cau ban muon dich:";
        string s;
        cin.ignore();
        getline(cin,s);
        DichPass(s);
        cout << "Pass sau khi dich:" << s + "\n";
    }
    else
    {
        cout << "Nhap so 1 hoac 2 thoi :D\n";
        
    }


    system("pause");
}


