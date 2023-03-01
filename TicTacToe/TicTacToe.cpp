#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

int choice;
int row;
int column;
bool turn = true;
bool draw = false;
int colorMode = 12;
int j=0;

void display_board(){

    system("cls");
    cout<<"   PLAYER.1 = [X] / PLAYER.2 = [O]   "<<endl;
    cout<<endl;
    cout<<"               │     │               "<<endl;
    cout<<"            "<<board[0][0]<<"  │  "<<board[0][1]<<"  │  "<<board[0][2]<<"            "<<endl;
    cout<<"          _____│_____│_____          "<<endl;
    cout<<"               │     │               "<<endl;
    cout<<"            "<<board[1][0]<<"  │  "<<board[1][1]<<"  │  "<<board[1][2]<<"            "<<endl;
    cout<<"          _____│_____│_____          "<<endl;
    cout<<"               │     │               "<<endl;
    cout<<"            "<<board[2][0]<<"  │  "<<board[2][1]<<"  │  "<<board[2][2]<<"            "<<endl;
    cout<<"               │     │               "<<endl;
    cout<<endl;
}

void player_turn(){
    
    if(turn){
        cout<<"           Player.1 turn:";
    }
    else if(!turn){
        cout<<"           Player.2 turn:";
    }

    cin >> choice;

    switch(choice){
        case 1: 
            row=0; column=0; break;
        case 2: 
            row=0; column=1; break;
        case 3: 
            row=0; column=2; break;
        case 4: 
            row=1; column=0; break;
        case 5: 
            row=1; column=1; break;
        case 6: 
            row=1; column=2; break;
        case 7: 
            row=2; column=0; break;
        case 8: 
            row=2; column=1; break;
        case 9: 
            row=2; column=2; break;
    }

    if(turn && board[row][column] != 'X' && board[row][column] != 'O'){

        board[row][column] = 'X';
        colorMode = 3;
        turn = false;
    }else if(!turn && board[row][column] != 'X' && board[row][column] != 'O'){

        board[row][column] = 'O';
        colorMode = 12;
        turn = true;
    }else {
    
        cout<<"        This Box is filled!"<<endl;
        player_turn();
    }
    
    display_board();
}

void rainbowPrint(string str){
    
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    for(int i=0 ; i < str.length() ; i++ , j++){        
        SetConsoleTextAttribute(hConsole, ((j%13)+1));
        cout << str[i];
    }
}


bool gameover(){

    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    draw = true;
    return false;
}
void Logo(){
    cout<<"\n\n";
    rainbowPrint("            _____ ___ ___  ");    cout<<endl;Sleep(200);
    rainbowPrint("           |_   _|_ _/ __| ");    cout<<endl;Sleep(200);
    rainbowPrint("             | |  | | (__  ");    cout<<endl;Sleep(200);
    rainbowPrint("            _|_|_|___\\___| ");   cout<<endl;Sleep(200);
    rainbowPrint("           |_   _/_\\ / __| ");   cout<<endl;Sleep(200);
    rainbowPrint("             | |/ _ \\ (__  ");   cout<<endl;Sleep(200);
    rainbowPrint("            _|_/_/_\\_\\___| ");  cout<<endl;Sleep(200);
    rainbowPrint("           |_   _/ _ \\| __|");   cout<<endl;Sleep(200);
    rainbowPrint("             | || (_) | _| ");    cout<<endl;Sleep(200);
    rainbowPrint("             |_| \\___/|___|");   cout<<endl;Sleep(1000);
}
void equal(){

    system("cls");
    cout<<"\n\n\n\n";
    cout<<"       ____  ____  ___ _       __   __"<<endl;
    cout<<"      / __ \\/ __ \\/   | |     / /  / /"<<endl;
    cout<<"     / / / / /_/ / /| | | /| / /  / / "<<endl;
    cout<<"    / /_/ / _  _/ ___ | |/ |/ /  /_/  "<<endl;
    cout<<"   /_____/_/ |_/_/  |_|__/|__/  (_)   "<<endl;
    cout<<"\n\n\n\n   ";
    system("pause");
                                   
}
void Xwon(){
    system("cls");
    cout<<"\n\n\n\n";
    cout<<"      _  __                            __"<<endl;
    cout<<"     | |/ /   _      ______  ____     / /"<<endl;
    cout<<"     |   /   | | /| / / __ \\/ __ \\   / / "<<endl;
    cout<<"    /   |    | |/ |/ / /_/ / / / /  /_/  "<<endl;
    cout<<"   /_/|_|    |__/|__/\\____/_/ /_/  (_)   "<<endl;
    cout<<"\n\n\n\n   ";
    system("pause");
                                      
}
void Owon(){
    system("cls");
    cout<<"\n\n\n\n";
    cout<<"      ____                             __"<<endl;
    cout<<"     / __ \\   _      ______  ____     / /"<<endl;
    cout<<"    / / / /  | | /| / / __ \\/ __ \\   / / "<<endl;
    cout<<"   / /_/ /   | |/ |/ / /_/ / / / /  /_/  "<<endl;
    cout<<"   \\____/    |__/|__/\\____/_/ /_/  (_)   "<<endl;
                                      
    cout<<"\n\n\n   ";
    system("pause");
                                      
}

int main(){
    
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);

    Logo();
    while(gameover()){
    SetConsoleTextAttribute(hConsole, colorMode);
        display_board();
        player_turn();
        gameover();
    }
    
    if(turn && !draw){
        Owon();
    }
    
    else if(!turn && !draw){
        Xwon();
    }
    
    else
    equal();
} 