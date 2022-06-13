#include<iostream>
#include<string>
#include<string.h>
using namespace std;

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

bool isNumber(string s)
{
    for (int i = 0; i < s.length(); ++i)
    {
        if(isdigit(s.at(i))==0)
            return false;
    }
    return true;
}

int main()
{
    int diff;
    bool run = true; //to run to loops for menu
    string checkInt; // to check int in user inputs
    string wrd, newwrd; // wrd is inserted word and newwrd is after convertion
    char side;
    while(run)
    {
        cout << "Input '>' to shift to the Right \nInput '<' to shift to the left \nInput 'E' to exit \n:";
        cin >> side;
        if(side=='E' || side=='e')
        break;
        else if (side=='>' || side == '<')
        {
            cout << "(Enter '0' to choose side again) \nShift each letter by :";
            // shifting each letter by 0th position is not encryption of decryption, hence using this number to go back
            cin >> checkInt;
            cin.get(); //to bypass an unknown out_of_range exection
            while(run)
            {
                if(isNumber(checkInt))
                {
                    diff = stoi(checkInt);
                    break;
                }
                else
                {
                    cout << "Enter digits only: ";
                    cin >> checkInt;
                    cin.get();
                }
            }
            // if(!cin)
            // {
            //     cin.clear();
            //     cin.ignore();
            // }
            while(run)
            {
                wrd.clear();
                newwrd.clear(); // as I do not know how getline() and string.insert() works I prefere not to override the data i loop and thus erasing it each time

                if(diff==0)
                break;

                cout << "(Input only '0' to go back to menu for a new setup)" << endl;
                cout << "Input :";
                getline(cin, wrd);

                if(wrd.at(0)=='0')
                break;

                else if(side == '>')
                {
                    for(int i=0; i<wrd.length(); i++)
                    {
                        if(wrd.at(i)>='a' && wrd.at(i)<='z')
                            newwrd.insert(i, 1, (newPos(((wrd.at(i))-97) + diff)+97) );

                        else if(wrd.at(i)>='A' && wrd.at(i)<='Z')
                            newwrd.insert(i, 1, (newPos(((wrd.at(i))-65) + diff)+65) );

                        else
                            newwrd.insert(i, 1, wrd.at(i));
                    }
                }
                else if(side == '<')
                {
                    for(int i=0; i<wrd.length(); i++)
                    {
                        if(wrd.at(i)>='a' && wrd.at(i)<='z')
                            newwrd.insert(i, 1, (newPos(((wrd.at(i))-97) - diff)+97) );

                        else if(wrd.at(i)>='A' && wrd.at(i)<='Z')
                            newwrd.insert(i, 1, (newPos(((wrd.at(i))-65) - diff)+65) );

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