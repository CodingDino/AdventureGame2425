#include <iostream>

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

int main()
{
    bool play = true;

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


