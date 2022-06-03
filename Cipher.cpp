#include<iostream>
#include<string>
#include<string.h>
using namespace std;

static char c; // keeping the input out case same

int position(char word)
{
    c = word;
    word = tolower(word);
    int po;
    switch (word)
    {
    case 'a':
        po = 0;
        break;
    case 'b':
        po = 1;
        break;
    case 'c':
        po = 2;
        break;
    case 'd':
        po = 3;
        break;
    case 'e':
        po = 4;
        break;
    case 'f':
        po = 5;
        break;
    case 'g':
        po = 6;
        break;
    case 'h':
        po = 7;
        break;
    case 'i':
        po = 8;
        break;
    case 'j':
        po = 9;
        break;
    case 'k':
        po = 10;
        break;
    case 'l':
        po = 11;
        break;
    case 'm':
        po = 12;
        break;
    case 'n':
        po = 13;
        break;
    case 'o':
        po = 14;
        break;
    case 'p':
        po = 15;
        break;
    case 'q':
        po = 16;
        break;
    case 'r':
        po = 17;
        break;
    case 's':
        po = 18;
        break;
    case 't':
        po = 19;
        break;
    case 'u':
        po = 20;
        break;
    case 'v':
        po = 21;
        break;
    case 'w':
        po = 22;
        break;
    case 'x':
        po = 23;
        break;
    case 'y':
        po = 24;
        break;
    case 'z':
        po = 25;
        break;

    default:
        break;
    }
return po;

}

int newPos(int a) //a is position
{
    int r;
    if(a<0)
    {   
        int inf = 10;
        int n = 0;
        while(n<inf)
        {
            n = n + 1;
            inf++;
            if(((-n)*26)<a)
            break;
        }
        r = a - ((-n)*26);
    }
    else 
    r = a % 26;
    return r;
}

char newWord(int np) // np is new position
{
    char nw; // nw is new word
    switch (np)
    {
    case 0:
        nw = 'A';
        break;
    case 1:
        nw = 'B';
        break;
    case 2:
        nw = 'C';
        break;
    case 3:
        nw = 'D';
        break;
    case 4:
        nw = 'E';
        break;
    case 5:
        nw = 'F';
        break;
    case 6:
        nw = 'G';
        break;
    case 7:
        nw = 'H';
        break;
    case 8:
        nw = 'I';
        break;
    case 9:
        nw = 'J';
        break;
    case 10:
        nw = 'K';
        break;
    case 11:
        nw = 'L';
        break;
    case 12:
        nw = 'M';
        break;
    case 13:
        nw = 'N';
        break;
    case 14:
        nw = 'O';
        break;
    case 15:
        nw = 'P';
        break;
    case 16:
        nw = 'Q';
        break;
    case 17:
        nw = 'R';
        break;
    case 18:
        nw = 'S';
        break;
    case 19:
        nw = 'T';
        break;
    case 20:
        nw = 'U';
        break;
    case 21:
        nw = 'V';
        break;
    case 22:
        nw = 'W';
        break;
    case 23:
        nw = 'X';
        break;
    case 24:
        nw = 'Y';
        break;
    case 25:
        nw = 'Z';
        break;
    
    default:
        break;
    }

switch (c)
{
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
        nw = tolower(nw); //to make sure the case of input and out put is same
    break;

default:
    break;
}

return nw;
}


int main()
{
    int diff, n=10;
    string wrd, newwrd; // wrd is inserted word and newwrd is after convertion
    char side;
    for(int i=0; i<n; n=i+n)
    {
        cout << "Input '>' to shift to the Right \nInput '<' to shift to the left \nInput 'E' to exit \n:";
        cin >> side;
        if(side=='E' || side=='e')
        break;
        else if (side=='>' || side == '<')
        {
            cout << "(Enter '0' to choose side again) \nShift each letter by :";
            // shifting each letter by 0th position is not encryption of decryption, hence using this number to go back
            cin >> diff;
            cin.get(); //to bypass an unknown out_of_range exection
            for(int k=0; k<n; n=k+n)
            {
                wrd.clear();
                newwrd.clear(); // as I do not know how getline() and string.insert() works I prefere not to override the data i loop and erasing it each time
                if(diff==0)
                break;
                cout << "(Input '0' instead of an word to go back to menu for a new settings)" << endl;
                cout << "word :";
                getline(cin, wrd);

                if(wrd.at(0)=='0')
                break;

                else if(side == '>')
                {
                    for(int i=0; i<wrd.length(); i++)
                    {
                        if((wrd.at(i)>='a' && wrd.at(i)<='z') || (wrd.at(i)>='A' && wrd.at(i)<='Z'))
                            newwrd.insert(i, 1, newWord(newPos(position(wrd.at(i)) + diff)) );
                        else
                            newwrd.insert(i, 1, wrd.at(i));
                    }
                }
                else if(side == '<')
                {
                    for(int i=0; i<wrd.length(); i++)
                    {
                        if((wrd.at(i)>='a' && wrd.at(i)<='z') || (wrd.at(i)>='A' && wrd.at(i)<='Z'))
                            newwrd.insert(i, 1, newWord(newPos(position(wrd.at(i)) - diff)) );
                        else
                            newwrd.insert(i, 1, wrd.at(i));
                    }
                }
                cout << "->" << newwrd << endl;
            }
        }
        else
        cout << "Wrong Input (Choose side or exit)" << endl;
        cout << "_________________________" << endl;
    }
    return 0;
}