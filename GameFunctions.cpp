#include<iostream>
using namespace std;

// Game class
class Game
{
public:
	int turn = 1;	// Tells which players turn is? ;(1,2).
	/* Game State Array */
	char Array[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
/*
Structure in which class print
  A   B   C
1 o | x | o
  -   -   -
2 x | o | x
  -   -   -
3 o | x | o
*/

	/* String representation of class function*/
	friend ostream& operator<<(ostream& os, const Game& obj){
		system("cls");
		os << "  A   B   C\n";
		os << "1 "<<obj.Array[0][0]<<" | "<<obj.Array[0][1]<<" | "<<obj.Array[0][2]<<"\n";
		os << "  -   -   -\n";
		os << "2 "<<obj.Array[1][0]<<" | "<<obj.Array[1][1]<<" | "<<obj.Array[1][2]<<"\n";
		os << "  -   -   -\n";
		os << "3 "<<obj.Array[2][0]<<" | "<<obj.Array[2][1]<<" | "<<obj.Array[2][2]<<"\n";
		return os;
	}

// Function which check that game is draw or not
	bool isDraw() {
		int emptySpaces = 0;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(Array[i][j] == ' '){
					emptySpaces++;
				}
			}
		}
		return (emptySpaces == 0);
	}

// Function which tell who won the game
	void tellWhoWon(char anyCell){
		cout << *this;
		if(anyCell == 'o'){cout<<"\n1st player won!\n";}
		else{cout<<"\n2nd player won\n";}
		system("pause");
	}

// Function which tell that game is end or not
	bool isGameEnd(){
		// End by 1st row
		if(
			(Array[0][0] == Array[0][1]) &&
			(Array[0][0] == Array[0][2]) &&
			(Array[0][0] != ' ')
		){
			tellWhoWon(Array[0][0]);
			return true;
		}
		// End by 2nd row
		else if(
			(Array[1][0] == Array[1][1]) &&
			(Array[1][0] == Array[1][2]) &&
			(Array[1][0] != ' ')
		){
			tellWhoWon(Array[1][0]);
			return true;
		}
		// End by 3rd row
		else if(
			(Array[2][0] == Array[2][1]) &&
			(Array[2][0] == Array[2][2]) &&
			(Array[2][0] != ' ')
		){
			tellWhoWon(Array[2][0]);
			return true;
		}
		// End by 1st column
		else if(
			(Array[0][0] == Array[1][0]) &&
			(Array[0][0] == Array[2][0]) &&
			(Array[0][0] != ' ')
		){
			tellWhoWon(Array[0][0]); return true;
		}
		// End by 2nd column
		else if(
			(Array[0][1] == Array[1][1]) &&
			(Array[0][1] == Array[2][1]) &&
			(Array[0][1] != ' ')
		){
			tellWhoWon(Array[0][1]);
			return true;
		}
		// End by 3rd column
		else if(
			(Array[0][2] == Array[1][2]) &&
			(Array[0][2] == Array[2][2]) &&
			(Array[0][2] != ' ')
		){
			tellWhoWon(Array[0][2]);
			return true;
		}
		// End by top-left to buttom right
		else if(
			(Array[0][0] == Array[1][1]) &&
			(Array[0][0] == Array[2][2]) &&
			(Array[0][0] != ' ')
		){
			tellWhoWon(Array[0][0]);
			return true;
		}
		// End by top-right to buttom left
		else if(
			(Array[0][2] == Array[1][1]) &&
			(Array[0][2] == Array[2][0]) &&
			(Array[0][2] != ' ')
		){
			tellWhoWon(Array[0][2]);
			return true;
		}
		// End by Draw
		else if(isDraw()){
			cout << *this;
			cout<<"Match Draw\n";
			system("pause");
			return true;
		}
		else{return false;}	// Not end
	}

// Function to tell that move is valid or not
	bool isInputValid(int x, int y){
		if(Array[x][y]==' '){return true;}
		else{return false;}
	}

// Function to make a move
	void move(int x, int y){
		if(!isGameEnd()){
			if(turn == 1){
				Array[x][y] = 'o';
				turn = 2;
			}
			else{
				Array[x][y] = 'x';
				turn = 1;
			}
		}
	}

// Function for AI move
	void AI_move(){
		// Center 1st
		if(this->Array[1][1] == ' '){this->move(1,1);}
		// 1st Rows 3rd cell
		else if(
			(this->Array[0][0] == this->Array[0][1]) &&
			(this->Array[0][0] != ' ') &&
			this->Array[0][2] == ' '
		){this->move(0,2);}
		else if(
			(this->Array[0][0] == this->Array[0][2]) &&
			(this->Array[0][0] != ' ') &&
			this->Array[0][1] == ' '
		){this->move(0,1);}
		else if(
			(this->Array[0][1] == this->Array[0][2]) &&
			(this->Array[0][1] != ' ') &&
			this->Array[0][0] == ' '
		){this->move(0,0);}
		// 2nd Row
		else if(
			(this->Array[1][0] == this->Array[1][1]) &&
			(this->Array[1][0] != ' ') &&
			this->Array[1][2] == ' '
		){this->move(1,2);}
		else if(
			(this->Array[1][1] == this->Array[1][2]) &&
			(this->Array[1][1] != ' ') &&
			this->Array[1][0] == ' '
		){this->move(1,0);}
		// 3rd Row
		else if(
			(this->Array[2][0] == this->Array[2][1]) &&
			(this->Array[2][0] != ' ') &&
			this->Array[2][2] == ' '
		){this->move(2,2);}
		else if(
			(this->Array[2][0] == this->Array[2][2]) &&
			(this->Array[2][0] != ' ') &&
			this->Array[2][1] == ' '
		){this->move(2,1);}
		else if(
			(this->Array[2][1] == this->Array[2][2]) &&
			(this->Array[2][2] != ' ') &&
			this->Array[2][0] == ' '
		){this->move(2,0);}
		// 1st column
		else if(
			(this->Array[0][0] == this->Array[1][0]) &&
			(this->Array[0][0] != ' ') &&
			this->Array[2][0] == ' '
		){this->move(2,0);}
		else if(
			(this->Array[1][0] == this->Array[2][0]) &&
			(this->Array[0][0] != ' ') &&
			this->Array[0][0] == ' '
		){this->move(0,0);}
		else if(
			(this->Array[0][0] == this->Array[2][0]) &&
			(this->Array[0][0] != ' ') &&
			this->Array[1][0] == ' '
		){this->move(1,0);}
		// 2nd column
		else if(
			(this->Array[0][1] == this->Array[1][1]) &&
			(this->Array[0][1] != ' ') &&
			this->Array[2][1] == ' '
		){this->move(2,1);}
		else if(
			(this->Array[1][1] == this->Array[2][1]) &&
			(this->Array[1][1] != ' ') &&
			this->Array[0][1] == ' '
		){this->move(0,1);}
		// 3rd column
		else if(
			(this->Array[0][2] == this->Array[1][2]) &&
			(this->Array[0][2] != ' ') &&
			this->Array[2][2] == ' '
		){this->move(2,2);}
		else if(
			(this->Array[1][2] == this->Array[2][2]) &&
			(this->Array[2][2] != ' ') &&
			this->Array[0][2] == ' '
		){this->move(0,2);}
		else if(
			(this->Array[0][2] == this->Array[2][2]) &&
			(this->Array[0][2] != ' ') &&
			this->Array[1][2] == ' '
		){this->move(1,2);}
		// Top left to bottom right
		else if(
			(this->Array[1][1] == this->Array[0][0]) &&
			(this->Array[0][0] != ' ') &&
			this->Array[2][2] == ' '
		){this->move(2,2);}
		else if(
			(this->Array[1][1] == this->Array[2][2]) &&
			(this->Array[1][1] != ' ') &&
			this->Array[0][0] == ' '
		){this->move(0,0);}
		// Top right to bottom left
		else if(
			(this->Array[1][1] == this->Array[0][2]) &&
			(this->Array[1][1] != ' ') &&
			this->Array[2][0] == ' '
		){this->move(2,0);}
		else if(
			(this->Array[1][1] == this->Array[2][0]) &&
			(this->Array[1][1] != ' ') &&
			this->Array[0][2] == ' '
		){this->move(0,2);}
		// Random
		else{
			int x_cor, y_cor;
			while(true){
				x_cor = rand()%3;
				y_cor = rand()%3;
				if(this->isInputValid(x_cor,y_cor)){
					this->move(x_cor, y_cor);
					break;
				}else{continue;}
			}
		}
	}
};