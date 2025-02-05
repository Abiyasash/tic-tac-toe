#include <iostream>
#include <algorithm>
#include <ctime>

namespace ticTacToe
{
  char board[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  const int BOARD_SIZE = sizeof(board) / sizeof(char);
  const char PLAYER_1 = 'X';
  const char PLAYER_2 = 'O';
  char winner;
  bool tie = false;
  char playAgain;
}

void displayBoard(char *board);
void playerMove(char *board, char player);
void computerMove(char *board);
bool checkWinner(char *board, char player1, char player2);
bool checkTie(char *board);
void resetVariables(char *board, char &winner, bool &tie, char &playAgain);

int main()
{
  using namespace ticTacToe;

  std::cout << '\n'
            << "Welcome to Tic Tac Toe!" << '\n';
  std::string playerTwoInput;

  do
  {
    do
    {
      std::cout << "Would you like to play against a friend or computer?: ";
      std::cin >> playerTwoInput;
      std::transform(playerTwoInput.begin(), playerTwoInput.end(), playerTwoInput.begin(), ::tolower);
    } while (playerTwoInput != "friend" && playerTwoInput != "computer");

    resetVariables(board, winner, tie, playAgain);

    while (true)
    {
      displayBoard(board);
      std::cout << "It's X's turn!" << '\n';
      playerMove(board, PLAYER_1);
      if (checkWinner(board, PLAYER_1, PLAYER_2) || checkTie(board))
        break;
      displayBoard(board);
      std::cout << "It's O's turn!" << '\n';
      playerTwoInput == "friend" ? playerMove(board, PLAYER_2) : computerMove(board);
      if (checkWinner(board, PLAYER_1, PLAYER_2) || checkTie(board))
        break;
    }

    displayBoard(board);

    if (playerTwoInput == "computer")
    {
      if (winner == PLAYER_1)
      {
        std::cout << "You win! Congratulations!" << '\n';
      }
      else
      {
        std::cout << "You lose! Better luck next time!" << '\n';
      }
    }
    else
    {
      winner ? std::cout << "Congratulations! " << winner << " wins!" << '\n' : std::cout << "It's a tie!" << '\n';
    }

    std::cout << "Would you like to play again? (y/n): ";
    std::cin >> playAgain;
    playAgain = tolower(playAgain);
  } while (playAgain == 'y');

  std::cout << '\n'
            << "Thanks for playing!" << '\n';

  return 0;
}

void displayBoard(char *board)
{
  using namespace ticTacToe;

  std::cout << '\n';
  std::cout << "     |     |     " << '\n';
  std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << '\n';
  std::cout << "_____|_____|_____" << '\n';
  std::cout << "     |     |     " << '\n';
  std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << '\n';
  std::cout << "_____|_____|_____" << '\n';
  std::cout << "     |     |     " << '\n';
  std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << '\n';
  std::cout << "     |     |     " << '\n';
  std::cout << '\n';
}

void playerMove(char *board, char player)
{
  using namespace ticTacToe;

  int pos;

  do
  {
    std::cout << "Enter a position you would like to play in (1-9): ";
    std::cin >> pos;
  } while (board[pos - 1] != ' ');

  board[pos - 1] = player;
}

void computerMove(char *board)
{
  using namespace ticTacToe;
  srand(time(NULL));
  int pos;

  while (board[pos] != ' ')
  {
    pos = rand() % 9;
  }

  board[pos] = PLAYER_2;
  std::cout << "The computer played their move!" << '\n';
}

bool checkWinner(char *board, char player1, char player2)
{
  using namespace ticTacToe;

  if ((board[0] == player1 && board[1] == player1 && board[2] == player1) ||
      (board[3] == player1 && board[4] == player1 && board[5] == player1) ||
      (board[6] == player1 && board[7] == player1 && board[8] == player1))
  {
    winner = player1;
    return true;
  }
  else if ((board[0] == player2 && board[1] == player2 && board[2] == player2) ||
           (board[3] == player2 && board[4] == player2 && board[5] == player2) ||
           (board[6] == player2 && board[7] == player2 && board[8] == player2))
  {
    winner = player2;
    return true;
  }

  else if ((board[0] == player1 && board[3] == player1 && board[6] == player1) ||
           (board[1] == player1 && board[4] == player1 && board[7] == player1) ||
           (board[2] == player1 && board[5] == player1 && board[8] == player1))
  {
    winner = player1;
    return true;
  }
  else if ((board[0] == player2 && board[3] == player2 && board[6] == player2) ||
           (board[1] == player2 && board[4] == player2 && board[7] == player2) ||
           (board[2] == player2 && board[5] == player2 && board[8] == player2))
  {
    winner = player2;
    return true;
  }

  else if ((board[0] == player1 && board[4] == player1 && board[8] == player1) ||
           (board[2] == player1 && board[4] == player1 && board[6] == player1))
  {
    winner = player1;
    return true;
  }
  else if ((board[0] == player2 && board[4] == player2 && board[8] == player2) ||
           (board[2] == player2 && board[4] == player2 && board[6] == player2))
  {
    winner = player2;
    return true;
  }

  return false;
}

bool checkTie(char *board)
{
  using namespace ticTacToe;

  if (!winner)
  {
    for (int i = 0; i < BOARD_SIZE; i++)
    {
      if (board[i] == ' ')
        return false;
    }
  }

  tie = true;
  return true;
}

void resetVariables(char *board, char &winner, bool &tie, char &playAgain)
{
  using namespace ticTacToe;

  for (int i = 0; i < BOARD_SIZE; i++)
  {
    board[i] = ' ';
  }

  winner = '\0';
  tie = false;
  playAgain = '\0';
}