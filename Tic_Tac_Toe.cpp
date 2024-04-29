#include "GameFunctions.cpp"

//Function to replace (A,B,C) to (1,2,3) respectively
int alphToNum(char cordinate){
	if(cordinate=='A'||cordinate=='a'){return 0;}
	else if(cordinate=='B'||cordinate=='b'){return 1;}
	else if(cordinate=='C'||cordinate=='c'){return 2;}
};

int main(){
	Game Tx3;	// Tx3 defined as a class object

	int option;	// option is used to tell the mode (1p or 2p)
	int x_cor;	// x cordinate (1,2,3)
	char y_cor;	// y cordinate (A,B,C)
	int y2_cor;	// Make (A,B,C) to (0,1,2) Respectively
	string player;	//Player prompt

	/* Interface */
	system("cls");	// Clearing the screen
	cout << "=== Tic Tac Toe ===\n\n1)\tPlay 1P\n2)\tPlay 2P\n3)\tExit\n\nOption : ";
	cin >> option;
	if(option == 1){	// 1P mode, Playing with AI
		player = "Enter player's ";	// Prompt

		while(!Tx3.isGameEnd()){	// Continuing until game end
			cout << Tx3;	// Printing grid

			if(Tx3.turn == 1){	// 1st player turn
				while(true){	// Again choices if enterd is invalid.
					cout << player << "Columns (A,B,C): ";
					cin >> y_cor;	// Input column
					cout << player << "Row (1,2,3): ";
					cin >> x_cor;	// Input row
					y2_cor = alphToNum(y_cor);

					/* Checking Validity and make move*/
					if(Tx3.isInputValid(x_cor-1, y2_cor)){
						Tx3.move(x_cor-1, y2_cor);
						break;
					}
					else{	// Generating error on invalid input
						cout<<"Grid Error!\nYou have entered invalid input.\n";
						continue;
					}
				}
			}
			else{	// 2nd Player turn
				Tx3.AI_move();
			}
		}
	}
	else if (option == 2){	// 2p mode, 2 persons playing
		while (!Tx3.isGameEnd()){	// Continuing until game end
			cout << Tx3;	// Printing grid

			if(Tx3.turn == 1){player = "Enter 1st player's ";}
			else{player = "Enter 2nd player's ";}

			while(true){	// Again choices if enterd is invalid.
				cout<<player<<"Column (A,B,C): ";
				cin>>y_cor;		// Input column
				cout<<player<<"Row (1,2,3): ";
				cin>>x_cor;     // Input row
				y2_cor = alphToNum(y_cor);
				
				/* Checking Validity and make move*/
				if(Tx3.isInputValid(x_cor-1, y2_cor)){
					Tx3.move(x_cor-1, y2_cor);
					break;
				}
				else{	// Generating error on invalid input
					cout<<"Grid Error!\nYou have entered invalid input.\n";
					continue;
				}
			}
		}
	}
	return 0;
}