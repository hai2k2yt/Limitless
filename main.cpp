#include "CommonFunction.h"

//print menu
void print_menu()
{
    showText("Menu.txt");
}

//print instructions
void print_instructions()
{
    showText("Instruction.txt");
    char is_back;
    cin >> is_back;
    if (is_back == 'n' || is_back == 'N')
    {
        system("cls");
        print_instructions();
    }
}

//choose max and min of number
//choose start number
void chooseMaxMin(int& num, int& max_num, int& min_num, int& random_range)
{
    cout << "Choose your max number:";
    cin >> max_num;
    cout << "Choose your min number:";
    cin >> min_num;
    while (min_num >= max_num)
    {
        gotoxy(0, 3);
        cout << "Min number is invalid! Try again.               ";
        gotoxy(33,3);
        cin >> min_num;
    }
    gotoxy(0, 3);
    cout << "                                           ";
    gotoxy(24, 2);
    cout << "                ";
    gotoxy(24, 2);
    cout << min_num;
    gotoxy(0, 2);
    cout << "Choose your random range:";
    cin >> random_range;

    gotoxy(0, 5);
    cout << "\nYour start number is:";
    num = rand() % (max_num - min_num) + min_num;
    cout << num;
    Sleep(2000);
    system("cls");

    //setup time to ready
    cout << "Ready!";
    for (int i = 3; i > 0; i--)
    {
        gotoxy(0, 1);
        cout << i;
        Sleep(1000);
    }
    gotoxy(0, 1);
    cout << "GO!";
    Sleep(1000);
    system("cls");
}

//Set up game to start
void createGameBegin(int& num, int& max_num, int& min_num, int& random_range, int& add1, int& add2, int& choose_add)
{
    chooseMaxMin(num, max_num, min_num, random_range);
    randomAdd(add1, random_range);
    randomAdd(add2, random_range);
    choose_add = 0;
    //create game zone
    // 1.Tutorial
    draw_box(BOX_WIDTH, BOX_HEIGHT);
    gotoxy(0, BOX_HEIGHT + 2);
    cout << "Press A to choose add1";
    gotoxy(0, BOX_HEIGHT + 3);
    cout << "Press D to choose add2";
    gotoxy(0, BOX_HEIGHT + 4);
    cout << "Press S to put add to number";
    gotoxy(3, 1);
    cout << "While playing, press ESC to exit game";
    // 2.Rule
    gotoxy(BOX_WIDTH - 10, BOX_HEIGHT + 2);
    cout << "Max number: " << max_num;
    gotoxy(BOX_WIDTH - 10, BOX_HEIGHT + 3);
    cout << "Min number: " << min_num;
    gotoxy(BOX_WIDTH - 10, BOX_HEIGHT + 4);
    cout << "Random range: " << random_range;

    //Print number
    gotoxy(BOX_WIDTH / 2, BOX_HEIGHT - 2);
    cout << "Number:";
    gotoxy(BOX_WIDTH / 2, BOX_HEIGHT - 4);
    cout << num;

    //Print add1
    gotoxy(4, 4);
    cout << "Add1:";
    gotoxy(4, 6);
    cout << add1;

    //Print add2
    gotoxy(BOX_WIDTH - 10, 4);
    cout << "Add2:";
    gotoxy(BOX_WIDTH - 10, 6);
    cout << add2;

    gotoxy(BOX_WIDTH / 2, BOX_HEIGHT / 2);
    cout << "Number you choose:";
}


void game_loop()
{
    int num, max_num, min_num, random_range, add1, add2, choose_add;
    createGameBegin(num, max_num, min_num, random_range, add1, add2, choose_add);


    //Choose add and put to number
    char key;
    bool continued = true;
    while (continued)
    {
        if (_kbhit())
        {
            key = _getch();

            //Take the left add
            if (key == 'a' || key == 'A')
            {
                choose_add = add1;
                gotoxy(BOX_WIDTH / 2, BOX_HEIGHT / 2 + 1);
                cout << "      ";
                gotoxy(BOX_WIDTH / 2, BOX_HEIGHT / 2 + 1);
                cout << choose_add;

                gotoxy(BOX_WIDTH / 2, BOX_HEIGHT / 2 + 2);
                cout << "      ";
                gotoxy(BOX_WIDTH / 2, BOX_HEIGHT / 2 + 2);
                cout << "<<---";
            }

            //Take the right add
            if (key == 'd' || key == 'D')
            {
                choose_add = add2;
                gotoxy(BOX_WIDTH / 2, BOX_HEIGHT / 2 + 1);
                cout << "      ";
                gotoxy(BOX_WIDTH / 2, BOX_HEIGHT / 2 + 1);
                cout << choose_add;

                gotoxy(BOX_WIDTH / 2, BOX_HEIGHT / 2 + 2);
                cout << "      ";
                gotoxy(BOX_WIDTH / 2, BOX_HEIGHT / 2 + 2);
                cout << "--->>";
            }

            //Put add to number
            if (key == 's' || key == 'S')
            {
                if (choose_add == 0)continue;
                num += choose_add;
                gotoxy(BOX_WIDTH / 2, BOX_HEIGHT - 4);
                cout << "          ";
                gotoxy(BOX_WIDTH / 2, BOX_HEIGHT - 4);
                cout << num;

                //Show choose_add and number
                gotoxy(BOX_WIDTH / 2, BOX_HEIGHT - 5);
                if (choose_add > 0)cout << "+";
                cout << choose_add;
                Sleep(500);
                gotoxy(BOX_WIDTH / 2, BOX_HEIGHT - 5);
                cout << "         ";

                gotoxy(BOX_WIDTH / 2, BOX_HEIGHT / 2 + 2);
                cout << "          ";
                gotoxy(BOX_WIDTH / 2, BOX_HEIGHT / 2 + 2);
                cout << "-----";

                //Ckeck game over
                if (num > max_num || num < min_num)
                {
                    continued = false;
                    break;
                }

                //Show new adds after put
                randomAdd(add1, random_range);
                randomAdd(add2, random_range);
                gotoxy(4, 6);
                cout << "        ";
                gotoxy(BOX_WIDTH - 10, 6);
                cout << "        ";
                gotoxy(4, 6);
                cout << add1;
                gotoxy(BOX_WIDTH - 10, 6);
                cout << add2;
                choose_add = 0;
                gotoxy(BOX_WIDTH / 2, BOX_HEIGHT / 2 + 1);
                cout << "         ";
            }
            //Press ESC to quit game
            if (key == 27)
            {
                system("cls");
                exit(0);
            }
        }
    }
    
    //Continue/Exit game
    gotoxy(BOX_WIDTH / 2, BOX_HEIGHT / 2 + 6);
    cout << "You lost.Exit to main menu?(y/n):";
    char s;
    cin >> s;
    if (s == 'n' || s == 'N')
    {
        system("cls");
        game_loop();
    }
}

int main()
{
    srand(time(NULL));
    bool return_menu = false;
    int choose;
    do
    {
        system("cls");
        print_menu();
        cin >> choose;
        switch (choose)
        {
        case 1:
            system("cls");
            print_instructions();
            break;
        case 2:
            system("cls");
            //choose_mode();
            break;
        case 3:
            system("cls");
            game_loop();
            break;
        case 4:
            system("cls");
            exit(0);
        default:
            cout << "Error: Invalid choice." << endl;
            Sleep(1000);
            break;
        }
    } while (!return_menu);
    return 0;
}
