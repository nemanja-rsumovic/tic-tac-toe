#include <iostream>

using namespace std;

char field[9] = {'1','2','3','4','5','6','7','8','9'};

int result(){
    if (field[0]==field[1] && field[1]==field[2])
        return 1;
    else if (field[3]==field[4] && field[4]==field[5])
        return 1;
    else if (field[6]==field[7] && field[7]==field[8])
        return 1;
    else if (field[0]==field[3] && field[3]==field[6])
        return 1;
    else if (field[1]==field[4] && field[4]==field[7])
        return 1;
    else if (field[2]==field[5] && field[5]==field[8])
        return 1;
    else if (field[0]==field[4] && field[4]==field[8])
        return 1;
    else if (field[2]==field[4] && field[4]==field[6])
        return 1;
    
    //tie
    else if (field[0]!='1' && field[1]!='2' && field[2]!='3' &&
            field[3]!='4' && field[4]!='5' && field[5]!='6' &&
            field[6]!='7' && field[7]!='8' && field[8]!='9')
        return -1;
    
    //still playing
    else 
        return 0;
}

void game(){

    cout<<"\n\t    -------------"<<endl;
    cout<<"Player1: X | Tic-Tac-Toe | Player2: O";
    cout<<"\n\t    -------------"<<endl;
    cout<<"\t       |     |     "<<endl;
    cout<<"\t    "<<field[0]<<"  |  "<<field[1]<<"  |  "<<field[2]<<"  "<<endl;
    cout<<"\t  -----|-----|-----"<<endl;
    cout<<"\t    "<<field[3]<<"  |  "<<field[4]<<"  |  "<<field[5]<<"  "<<endl;
    cout<<"\t  -----|-----|-----"<<endl;
    cout<<"\t    "<<field[6]<<"  |  "<<field[7]<<"  |  "<<field[8]<<"  "<<endl;
    cout<<"\t       |     |     "<<endl;

}

int main(){

    int player = 1;
    int win = -1;
    int number;
    char mark;

    while(1){

        game();

        cout<<"\nPlayer"<<player<<", enter a number: ";
        cin>>number;

        if(field[number-1] != 'X' && field[number-1] != 'O')
            field[number-1] = player==1?'X':'O';
        else {
            cout<<"INVALID MOVE!";
            cin.ignore();
            cin.get();
        }

        win = result();
        if(win != 0){
            game();
            break;
        }

        if(player == 1)
            player = 2;
        else
            player = 1;

    }

    if(win == -1)
        cout<<"GAME DRAW!"<<endl;
    else
        cout<<"PLAYER"<<player<<" WON!"<<endl;
        
    return 0;
}