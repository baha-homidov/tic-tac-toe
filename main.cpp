#include <iostream>
#include <stdlib.h>
using namespace std;



struct Board {
	Board();  //default constructor to initialize the gaming board;
	void draw();    // draw/re-draw function
	char board_data[3][3];   // 2D array to hold game data
	void input();      //input loop
	int winner = 0;    //0==games is being played; 1==player wins; 2==player 2 wins; 3==draw;
	void check_board();   //check games condition for win or draw
	char* field(int n);   //helper function to return a pointer to a specific field
	bool first_check = true;   //first check loop
	char front_board[8][11]{ {' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ',},
					   {' ','1',' ','|',' ','2',' ','|',' ','3',' ',},
					   {'-','-','-','-','-','-','-','-','-','-','-'},
					   {' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ',},
					   {' ','4',' ','|',' ','5',' ','|',' ','6',' ',},
					   {'-','-','-','-','-','-','-','-','-','-','-'},
					   {' ','7',' ','|',' ','8',' ','|',' ','9',' ',},
					   {' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ',} };;   //gaming board which is showed to the user
	void front_board_input(int n, char sign);   //get input and modify the front_board
	void restart();


};

//***********************************************

Board::Board()
//defaut constructor to initialize the board;
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board_data[i][j] = '*';
		}
	}
	cout << "Player 1 is 'X' -|- Player 2 is 'O'\n\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << board_data[i][j];
		}
		cout << '\n';
	}
}

//***********************************************

void Board::draw()
{
	system("CLS");

	cout << "Player 1 is 'X' -|- Player 2 is 'O'\n\n";
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 11; j++) {
			cout << front_board[i][j];
		}
		cout << '\n';
	}
	check_board();
	if (winner != 0) {     //check winner flag's condition and declare the winner or the draw, restart the game
		if (winner == 1) { cout << "**********************PLAYER 1 WINS**********************\n";
		winner = 0; system("pause"); restart();
		}
		else if (winner == 2) {
			cout << "**********************PLAYER 2 WINS.********************** \n"; winner = 0; system("pause"); restart();
		}
		else if (winner == 3) {
			cout << "**********************DRAW**********************\n"; winner = 0; system("pause"); restart();
		}
	}

	
}

//***********************************************

void Board::input()
//member function to handle input from the user
{
	draw();
	while (winner == 0||winner==3) {
		
		
		while (winner==0) {      //input loop for player 1;
			int p1;
			cout << "\nPlayer 1's move: ";
			cin >> p1;
			if (p1 < 1 || p1>9) { cout << "Input should an integer number 1-9: "; cin.clear();  continue; };
			if (*field(p1) != '*') { cout << "Field is already filled.\n"; continue; }    //check if field has been used
			switch (p1)
			{
			case 1: *field(1) = 'x'; front_board_input(1,'x'); draw(); break;
			case 2: *field(2) = 'x'; front_board_input(2, 'x'); draw(); break;
			case 3: *field(3) = 'x'; front_board_input(3, 'x'); draw(); break;
			case 4: *field(4) = 'x'; front_board_input(4, 'x'); draw(); break;
			case 5: *field(5) = 'x'; front_board_input(5, 'x'); draw(); break;
			case 6: *field(6) = 'x'; front_board_input(6, 'x'); draw(); break;
			case 7: *field(7) = 'x'; front_board_input(7, 'x'); draw(); break;
			case 8: *field(8) = 'x'; front_board_input(8, 'x'); draw(); break;
			case 9: *field(9) = 'x'; front_board_input(9, 'x'); draw(); break;
			};
			break;
		}

		while (winner==0) {      //input loop for player 2;
			int p2;
			cout << "\nPlayer 2's move: ";
			cin >> p2;
			if (p2 < 1 || p2>9) { cout << "Input should an integer number 1-9 "; continue; }; 
			if (*field(p2) != '*') { cout << "Field is already filled.\n"; continue; }    //check if field has been used
			switch (p2)
			{
			case 1: *field(1) = 'o'; front_board_input(1, 'o'); draw(); break;
			case 2: *field(2) = 'o'; front_board_input(2, 'o'); draw(); break;
			case 3: *field(3) = 'o'; front_board_input(3, 'o'); draw(); break;
			case 4: *field(4) = 'o'; front_board_input(4, 'o'); draw(); break;
			case 5: *field(5) = 'o'; front_board_input(5, 'o'); draw(); break;
			case 6: *field(6) = 'o'; front_board_input(6, 'o'); draw(); break;
			case 7: *field(7) = 'o'; front_board_input(7, 'o'); draw(); break;
			case 8: *field(8) = 'o'; front_board_input(8, 'o'); draw(); break;
			case 9: *field(9) = 'o'; front_board_input(9, 'o'); draw(); break;
			default: cout << "Invalid input. Input should be 1-9.\n"; break;
			};
			break;
		}
	}
}

//****************************************************************

void Board::check_board() //check the board for a winner
{
	
	

	/*****   check if 'X' has a winning combination          ********/
	if ((*field(1) == 'x' && *field(2) == 'x' && *field(3) == 'x')         //check for (1,2,3)  (4,5,6) (7,8,9) win combinations
		|| (*field(4) == 'x' && *field(5) == 'x' && *field(6) == 'x')
		|| (*field(7) == 'x' && *field(8) == 'x' && *field(9) == 'x')) {
		winner = 1; return;
	};
	if ((*field(1) == 'x' && *field(4) == 'x' && *field(7) == 'x')       //check for (1,4,7)  (2,5,8) (3,6,9) win combinations
		|| (*field(2) == 'x' && *field(5) == 'x' && *field(8) == 'x')
		|| (*field(3) == 'x' && *field(6) == 'x' && *field(9) == 'x')) {
		winner = 1; return;
	};
	if ((*field(1) == 'x' && *field(5) == 'x' && *field(9) == 'x')           //check for (1,5,9)  (3,5,7) win combinations
		|| (*field(3) == 'x' && *field(5) == 'x' && *field(7) == 'x')) {
		winner = 1; return;
	};


	/*****   check if 'O' has a winning combination          ********/

	if ((*field(1) == 'o' && *field(2) == 'o' && *field(3) == 'o')         //check for (1,2,3)  (4,5,6) (6,7,9) win combinations
		|| (*field(4) == 'o' && *field(5) == 'o' && *field(6) == 'o')
		|| (*field(7) == 'o' && *field(8) == 'o' && *field(9) == 'o')) {
		winner = 2; return;
	};
	if ((*field(1) == 'o' && *field(4) == 'o' && *field(7) == 'o')       //check for (1,4,7)  (2,5,8) (3,6,9) win combinations
		|| (*field(2) == 'o' && *field(5) == 'o' && *field(8) == 'o')
		|| (*field(3) == 'o' && *field(6) == 'o' && *field(9) == 'o')) {
		winner = 2; return;
	};
	if ((*field(1) == 'o' && *field(5) == 'o' && *field(9) == 'o')           //check for (3,5,7)  (3,5,7) win combinations
		|| (*field(3) == 'o' && *field(5) == 'o' && *field(7) == 'o')) {
		winner = 2; return;
	};
	//-----------------------------------------------------------------------------
	

	if (first_check==false) {
	
		//in the case if it's not a first loop check for the draw 
		bool draw = true;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				if (board_data[i][j] == '*') draw = false;
			};
		
		if (draw == true) winner = 3;
	}
	first_check = false;
}

//****************************************************************

char* Board::field(int n)
//returns a pointer to specific field according to n;
{
	switch (n)
	{
	case 1: return &board_data[0][0]; break;
	case 2: return &board_data[0][1]; break;
	case 3: return &board_data[0][2]; break;
	case 4: return &board_data[1][0]; break;
	case 5: return &board_data[1][1]; break;
	case 6: return &board_data[1][2]; break;
	case 7: return &board_data[2][0]; break;
	case 8: return &board_data[2][1]; break;
	case 9: return &board_data[2][2]; break;
	default: return nullptr;  break;
	}
	return nullptr;
}

//******************************************************************

void Board::restart()
//clean the playing board, set first_check flag to 'true' and redraw
{
	system("CLS");
	first_check = true;
	for (int i = 0; i < 3; i++) {      //reset the board_data
		for (int j = 0; j < 3; j++) {
			board_data[i][j] = '*';
		}
	}
	for (int i = 0; i < 9; i++) { front_board_input(i + 1, '0' + (i + 1)); }
	cout << "Player 1 is 'X' -|- Player 2 is 'O'\n\n";
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 11; j++) {
			cout << front_board[i][j];
		}
		cout << '\n';
	}
}

//*********************************************************************

void Board::front_board_input(int n, char sign) 
//get input and modify the front_board
{
	switch (n)
	{
	case 1: front_board[1][1] = sign; break;
	case 2: front_board[1][5] = sign; break;
	case 3: front_board[1][9] = sign; break;
	case 4: front_board[4][1] = sign; break;
	case 5: front_board[4][5] = sign; break;
	case 6: front_board[4][9] = sign; break;
	case 7: front_board[6][1] = sign; break;
	case 8: front_board[6][5] = sign; break;
	case 9: front_board[6][9] = sign; break;
	default: cout << "Invalid input\n"; exit(1); break;
	}
}





int main() {
	//driver code
	Board game;
	game.input();
	
	

	return 0;
}


