  #include <fstream>
  #include <iostream>
  #include <string>
  #include <windows.h>
  #include <conio.h>
  #include <limits>
  using namespace std;

  void gotoxy(int x, int y)
  {
      COORD coord;
      coord.X = x;
      coord.Y = y;
      SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), coord);
  }

  void systemTitle() {
    gotoxy(24,7);   cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * *";
    gotoxy(24,8);   cout << "*                                                     *";
    gotoxy(24,9);   cout << "*                                                     *";
    gotoxy(38,9);   cout << "STUDENT COUNCIL VOTING SYSTEM";
    gotoxy(24,10);  cout << "*                                                     *";
    gotoxy(24,11);  cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * *";
    gotoxy(35,15);  cout << "========= BY: Code-X =========\n\t\t\t\t\t(Course Code and Title)";
    gotoxy(35,19);  cout << "===============================";
    gotoxy(36,23);  cout << "Press Enter to continue... ";
    _getch();
  }

  int displayMenu(int choice) {
    system("cls");
    gotoxy(25,8);   cout<< "=====================================================";
    gotoxy(37,9);   cout << ":::::::::: MAIN MENU ::::::::::";
    gotoxy(25,10);  cout << "=====================================================";
    gotoxy(25,12);  cout << " [1] Admin Panel";
    gotoxy(25,13);  cout << " [2] Students' Voting Panel";
    gotoxy(25,14);  cout << " [3] E-Poll Results";
    gotoxy(25,15);  cout << " [4] Exit";
    gotoxy(25,17);  cout << "=====================================================";
    gotoxy(25,19);  cout << "Enter your choice (1-4): "; cin >> choice;
    return choice;
  }

  void adminLogin (char adminUsern[50], char adminPass[50]){
      system("cls");
      gotoxy(25,9);  cout << "=====================================================";
      gotoxy(48,10); cout << "LOG IN";
      gotoxy(25,11); cout << "=====================================================";
      gotoxy(25,16); cout << "=====================================================";
      gotoxy(40,13); cout << "Username: "; cin >> adminUsern;
      gotoxy(40,14); cout << "Password: "; cin >> adminPass;

      while(strcmp(adminUsern,"admin")!=0 || strcmp(adminPass,"adminpass")!=0)
      {
        system("cls");
        gotoxy(25,9);  cout<< "=====================================================";
        gotoxy(48,10); cout << "LOG IN" << endl << endl;
        gotoxy(25,11); cout<< "=====================================================";
        gotoxy(25,16); cout<< "=====================================================";
        gotoxy(30,12); cout << "Incorrect login information. Try Again.";
        gotoxy(40,13); cout << "Username: "; cin >> adminUsern;
        gotoxy(40,14); cout << "Password: "; cin >> adminPass;
      }
  }

  int adminMenu(int adminChoice) {
    system("cls");
    gotoxy(25,4);   cout<< "=====================================================";
    gotoxy(36,6);   cout << ":::::::::: ADMIN MENU ::::::::::";
    gotoxy(25,8);   cout<< "=====================================================";
    gotoxy(35,10);  cout << " [1] Input candidates";
    gotoxy(35,11);  cout << " [2] Go back to main menu";
    gotoxy(25,13);  cout << "=====================================================";
    gotoxy(40,15);  cout <<"Enter your choice (1-2): "; cin >> adminChoice;
    return adminChoice;
  }

  int main(){
      int menuChoice, adminChoice;
      char adminUsern[50], adminPass[50];
      int NumCan,i,j, NumStu=0, VoteFor[10], Vote, max;
      char CanName[10][1000], confirm, officerPos[50];

      system("cls");
      systemTitle();

      mainmenu:
      menuChoice = displayMenu(menuChoice);
      switch (menuChoice){

        case 1://admin
        adminLogin(adminUsern, adminPass);
        admenu:
        adminChoice = adminMenu(adminChoice);
        switch(adminChoice){

          case 1://input details of poll

              begin:system("cls");
              gotoxy(25,4);   cout<< "=====================================================" << endl;
              gotoxy(35,6);   cout << ":::::::::: ADMIN PANEL ::::::::::" << endl;
              gotoxy(25,8);   cout<< "=====================================================" << endl;
                              cin.ignore();
              gotoxy(28,10);  cout << "Officer position: ";
                              cin.getline (officerPos,50);
              gotoxy(28,11);  cout << "Enter the number of candidates: ";
                              cin >> NumCan;
                              cout << endl;

                if(NumCan>1)
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    for(i=1; i<=NumCan; i++)
                    {
                        cout  << "\t\t\t    Candidate-" << i << " Name: ";
                        cin.getline (CanName[i], 1000);
                        VoteFor[i]=0;
                    }
                    cout << endl  << "\t\t\t    Number of student voters: ";
                    cin >> NumStu;
                }

                else
                {
                gotoxy(27,14);  cout << "Error! Number of candidates must be more than one." <<endl;
                gotoxy(33,16);  cout << "Do you want to continue (y/n): ";
                                cin >> confirm;

                    if (confirm == 'y'){
                      system("cls");
                      goto begin;
                    }
                    }

            cout << endl << endl << "\t\t\t\tPress ENTER to go back to main menu... ";
            _getch();
            goto mainmenu;
          break;

          case 2://go back to main main menu
          system("cls");
          goto mainmenu;
          break;

          default://error message
          gotoxy(25,17);   cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * *";
          gotoxy(30,18); cout << "Invalid choice! Please choose using 1-2 only.\n\n\t\t\t\t\tPress ENTER to retry... ";
          _getch();
          goto admenu;
          break;
        }

        break;

        case 2://student panel

        if(NumStu!=0){
              for (i=1; i<=NumStu; i++)
                  {
                  system("cls");
                  gotoxy(25,4);   cout << "=====================================================" << endl;
                  gotoxy(28,6);   cout << ":::::::::: STUDENTS' VOTING PANEL ::::::::::" << endl;
                  gotoxy(25,8);   cout << "=====================================================" << endl;
                  gotoxy(29,9);   cout << "Choose your preferred candidate. Vote wisely!" << endl << endl;

                  char srcode[10];
                  gotoxy(25,11);  cout << " Enter your SR-Code: ";
                                  cin >> srcode;
                                  strcat(srcode," - ");

                      cout << endl << "\t\t\t =====================================================" << endl << endl << endl;

                      for (j=1; j<=NumCan; j++)
                      {
                          cout << "\t\t\t\tPress " << j << " for " << CanName[j] << endl;
                      }
                      cout << endl;
                      cout << endl << "\t\t\t =====================================================" << endl;
                      cout << endl << "\t\t\t\t\tPlease input your vote: ";
                      cin >> Vote;
  //write the data of student such as sr code and who they votes
                      FILE *filepointer1;
                      char datatobewrite2[50];
                      strcpy(datatobewrite2,srcode);
                      strcat(datatobewrite2,CanName[Vote]);
                      strcat(datatobewrite2,"\n");
                      filepointer1 = fopen("VoteDetails.txt","a");
                      if ( strlen (  datatobewrite2  ) > 0 )
                      {
                          fputs(datatobewrite2, filepointer1) ;
                      }

                      fclose(filepointer1) ;
  //vote will increment when each student will vote
                      for (j=1; j<=NumCan; j++)
                      {
                          if (Vote==j)
                          {
                              VoteFor[j]++;
                              break;
                          }
                      }
//after voting
                      cout << endl << "\t\t\tYour vote has been recorded. Press ENTER to continue...";
                      _getch();
                      system("cls");
//when all the student voters have voted
                      if(NumStu==i){
                      system("cls");
                      gotoxy(20,4);   cout << "==========================================================" << endl;
                      gotoxy(28,6);   cout << ":::::::::: STUDENTS' VOTING PANEL ::::::::::" << endl;
                      gotoxy(20,8);   cout << "==========================================================" << endl << endl << endl;
                      gotoxy(40,11);  cout << "Voting is now closed.\n\n\n\t\t\t        Press ENTER to go back to main menu...";
                      _getch();
                      goto mainmenu;
                      }
                  }
//when the admin have not inputted the poll details
                }else{
                  system("cls");
                  gotoxy(20,4);   cout << "==========================================================" << endl;
                  gotoxy(28,6);   cout << ":::::::::: STUDENTS' VOTING PANEL ::::::::::" << endl;
                  gotoxy(20,8);   cout << "==========================================================" << endl << endl << endl;
                  gotoxy(33,11);  cout << "No candidates as of the moment. \n\n\n\t\t\t     Press ENTER to go back to main menu...";
                  _getch();
                  goto mainmenu;
                }
        break;
//results
        case 3:

        if(NumStu!=0){
            system("cls");
            gotoxy(23,4);   cout << "==========================================================" << endl;
            gotoxy(36,6);   cout << ":::::::::: VOTING RESULTS ::::::::::" << endl;
            gotoxy(23,8);   cout << "==========================================================" << endl << endl << endl;
//to display the candidates and their garnered votes
              for(j=1; j<=NumCan; j++)
              {
                  cout << "\t\t\t" << CanName[j] << " received a total of " << VoteFor[j] << " vote/s." << endl;
                  float percentage = VoteFor[j]*100/NumStu;
                  cout << "\t\t\t\t Percentage of votes : " << percentage << " %" <<endl << endl;
              }
//determine the maximum vote
              max = 0;
              for (j=1; j<=NumCan; j++)
              {
                  if(max<VoteFor[j])
                  {
                      max=VoteFor[j];
                  }
              }
              //if no students have been voted
              for (j=1; j<=NumCan; j++)
              {
                if(max==0)
                {
                    cout << "\t\t\t\t    No winner as of the moment... " << endl;
                    break;
                }
                //if the maximum vote is determined, the program will generate the winner
                 else if (max==VoteFor[j])
                  {
                      cout << endl << "\t\t\t  " << CanName[j] << " is elected as " << officerPos << ". \n\t\t\t\t\tCongratulations!." << endl;
                      break;
                  }
              }
              cout  << endl << "\t\t      ==========================================================" << endl;
              cout << endl << "\t\t\t\tPress ENTER to go back to main menu... ";
              _getch();
              goto mainmenu;
//when the admin have not inputted the poll details
        } else {
              system("cls");
              gotoxy(23,4);   cout << "==========================================================" << endl;
              gotoxy(36,6);   cout << ":::::::::: VOTING RESULTS ::::::::::" << endl;
              gotoxy(23,8);   cout << "==========================================================" << endl << endl << endl;
              gotoxy(36,11);  cout << "No candidates as of the moment. \n\n\n\t\t\t     Press ENTER to go back to main menu...";
              _getch();
              goto mainmenu;
            }

        break;
//exit
        case 4:
        exit(0);
        break;
//error message
        default:
        gotoxy(25,22); cout << "Invalid choice! Please choose using 1-4 only.\n\nPress ENTER to retry... ";
        _getch();
        goto mainmenu;
        break;

      }

    return 0;
  }
