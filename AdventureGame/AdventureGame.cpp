#include <iostream>
#include <string>

int DisplayAndReadPlayerAction()
{
    std::cout << "What would you like to do?\n";
    std::cout << "\t1.\tLook\n";
    std::cout << "\t2.\tMove\n";
    std::cout << "\t3.\tQuit\n";

    int choice;
    std::cin >> choice;
    // TODO: input validation stuff

    return choice;
}

void Look()
{
    std::cout << "LOOK not yet implemented\n";
}

void Move()
{
    std::cout << "MOVE not yet implemented\n";
}

void Quit()
{
    std::cout << "You have chosen to quit.\n";
    std::cout << "Thanks for playing!\n";
}

void DisplayPlayer(std::string name, std::string desc, int stam)
{
    std::cout << "You are " << name << ", " << desc << "\n";
    std::cout << "You have " << stam << " stamina.\n";
}

int main()
{
    std::string playerName = "Steve";
    std::string playerDescription = "A brave warrior";
    int playerStamina = 100;

    bool play = true;

    std::cout << "Please enter your name.\n";
    std::getline(std::cin, playerName);

    std::cout << "Welcome!\n";
    DisplayPlayer(playerName, playerDescription, playerStamina);

    while (play)
    {
        int choice = DisplayAndReadPlayerAction();

        switch (choice)
        {
        case 1:
            Look();
            break;
        case 2:
            Move();
            break;
        case 3:
            Quit();
            play = false;
            break;
        }
    }

}


