#include <iostream>
#include <string>

char board[10] = {'x', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

bool checkWin();
bool checkChoice(std::string choice);
void printBoard();

int main(int argc, char const *argv[])
{
    int player = 1;
    bool runningGame = true;
    std::string choice;

    do
    {

        do 
        {
            printBoard();
            std::cout << "Player" << player << " enter a number: ";
            std::cin >> choice;

        } while (!(checkChoice(choice)));        

        if (player == 1) 
        {
            board[std::stoi(choice)] = 'X';
            player++;
        }
        else 
        {
            board[std::stoi(choice)] = 'O';
            player--;
        }

        if(checkWin())
        {
            printBoard();
            std::cout << "Player" << player << " won!" << std::endl;
            runningGame = false;
        }


    } while (runningGame);

    return 0;
}

/***************************************************************
 * The function checks if the win condition is fulfilled       *
 * on the board, if yes the function returns true if not false *  
 * *************************************************************/

bool checkWin()
{

    // Check horizontally for victory
    if ((board[1] == board[2]) && (board[2] == board[3]))
    {
        return true;
    }

    if ((board[4] == board[5]) && (board[5] == board[6]))
    {
        return true;
    }

    if ((board[7] == board[8]) && (board[8] == board[9]))
    {
        return true;
    }

    // Check vertically for victory
    if ((board[1] == board[4]) && (board[4] == board[7]))
    {
        return true;
    }

    if ((board[2] == board[5]) && (board[5] == board[8]))
    {
        return true;
    }

    if ((board[3] == board[6]) && (board[6] == board[9]))
    {
        return true;
    }

    // Check diagonally for victory
    if ((board[1] == board[5]) && (board[5] == board[9]))
    {
        return true;
    }

    if ((board[7] == board[5]) && (board[5] == board[3]))
    {
        return true;
    }

    return false;
}

/***************************************************
 * The function checks if the input is valid.      *
 * Teturns true if valid, else false.              *
 ***************************************************/

bool checkChoice(std::string str_choice)
{
    
    try
    {
        int choice = std::stoi(str_choice);


        if(choice > 9 || choice < 1) {
            std::cout << "Invalid input...Try again!" << '\n';
            return false;
        }

        if ((choice == 1) && (board[1] == '1'))
        {
            return true;
        }
        if ((choice == 2) && (board[2] == '2'))
        {
            return true;
        }
        if ((choice == 3) && (board[3] == '3'))
        {
            return true;
        }
        if ((choice == 4) && (board[4] == '4'))
        {
            return true;
        }
        if ((choice == 5) && (board[5] == '5'))
        {
            return true;
        }
        if ((choice == 6) && (board[6] == '6'))
        {
            return true;
        }
        if ((choice == 7) && (board[7] == '7'))
        {
            return true;
        }
        if ((choice == 8) && (board[8] == '8'))
        {
            return true;
        }
        if ((choice == 9) && (board[9] == '9'))
        {
            return true;
        }
    } 
    
    catch (std::invalid_argument const &e)
    {
        std::cout << "Invalid input...Try again!" << '\n';
        return false;
    }
    
    catch (std::out_of_range const &e)
    {
        std::cout << "Invalid input...Try again!" << '\n';
        return false;
    }
   
    std::cout << "Invalid move...Try again!" << std::endl;
    return false;
}

void printBoard()
{
    std::cout << "Tic Tac Toe\n" << std::endl;
    std::cout << "Player1(X) - Player2(O)\n" << std::endl;

    std::cout << "     |     |     " << std::endl;
    std::cout << " " << board[1] << "   |  " << board[2] << "  |  " << board[3] << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << " " << board[4] << "   |  " << board[5] << "  |  " << board[6] << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << " " << board[7] << "   |  " << board[8] << "  |  " << board[9] << std::endl;
    std::cout << "     |     |     " << std::endl << std::endl;
}