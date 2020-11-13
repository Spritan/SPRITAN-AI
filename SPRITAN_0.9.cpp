#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <ctime>                                                                //to get time
#include <stdio.h>
using namespace std;
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};                    //game1
void telljoke(char ar[]);                                                       //joke
void tictactoe();                                                               //game
int checkwin();                                                                 //game1
void board();                                                                   //game1
void highlow(); 
void extra(char Q[]);                                                           //memory fuctionality
void singsong();
void sudoku();
void webser(char ip[]);
void start();
void getwether();
//void launchapp(char ch);
//void sayfunny();                                                              //sudo apt-get install funny
struct resource
    {
	    char que[80];
	    char answ[80];
    }stud1;
int main()
    {
        char input[80],tinput[80];
        char ch;
        int i=0,randam=1,flag=0;
        start();
        while(input!="exit")
            {
            flag=0;
            cout<<"\nYou     => ";
            cin.getline(input,60);
            for (i=0; i<strlen(input); ++i)
                {
                    tinput[i]=tolower(input[i]);
                }
            tinput[i]='\0';
            randam=rand()%3;
            if((!strcmp(tinput,"sing a song"))||(!strcmp(tinput,"please sing me a song"))
                ||(!strcmp(tinput,"sing a song."))||(!strcmp(tinput,"please sing me a song.")))
                {
                    cout<<"\nSPRITAN => I am not very good in singing if i were to sing, you will have to\n";
                    cout  <<"           hear the complete song do you agree?(y/n)\n";
                    system("espeak \"I am not very good in singin \" ");
                    system("espeak \" if i were to sing, you will have to\" ");
                    system("espeak \"hear the complete song do you agree \" ");
                    while(flag==0)
                        {
                            cout<<"OPTION  =>";
                            cin>>ch;
                            if(ch=='y'||ch=='Y')
                            {
                                singsong();
                                cout<<"\nSPRITAN => Hopefully you are satisfied .\n\tMean while what shall i do next?\n";
                                system("espeak \"Hopefully you are satisfied \"");
                                system("espeak \"Mean while what shall i do next \"");
                                flag++;
                            }
                            else if(ch=='n'||ch=='N')
                            {
                                cout<<"\nSPRITAN => I am sorry for not being able to live upto your hopes.\n";
                                 system("espeak \"I am sorry for not being able to live upto your hopes \"");
                                 cin.get();
                                flag++;
                            }
                            else
                            {
                                cout<<"\nSPRITAN => Wrong option!! enter the option again\n";
                                 system("espeak \"Wrong option!! \"");
                                 system("espeak \" enter the option again\"");
                            }
                            
                        }
                }
            if((!strcmp(tinput,"how is the weather?")))
                {
                    system("espeak \"The weather record is\"");    
                    getwether();  
                        flag++;
                }
            if((!strcmp(tinput,"who are you?"))||(!strcmp(tinput,"what are you?"))
                ||(!strcmp(tinput,"who are you"))||(!strcmp(tinput,"what are you"))
                ||(!strcmp(tinput,"what is this?"))||(!strcmp(tinput,"what is this")))
                {
                  cout<<"\nSPRITAN => ";
                  cout<<"I am SPRITAN 0.01 a chatbot(simple talking AI) created by Proyash.\n";
                  system("espeak \"I am SPRITAN 0.01 a chatbot created by Proyash\"");
                  cout<<"\tI hope you will like me.\n";
                  system("espeak \"I hope you will like me\"");
                  flag++;
                }
            if ((!strcmp(tinput,"hi"))||(!strcmp(tinput,"hi."))
                ||(!strcmp(tinput,"hi spritan"))||(!strcmp(tinput,"hi spritan."))
                ||(!strcmp(tinput,"hello spritan"))||(!strcmp(tinput,"hello spritan."))
                ||(!strcmp(tinput,"hello"))||(!strcmp(tinput,"hellow")))
              {
                  randam=rand()%3;
                  cout<<"\nSPRITAN => ";
                  switch(randam)
                    {
                        case 0:cout << "Hello there ";
                                system("espeak \"Hello there\"");
                            break;
                        case 1:cout << "What's up, dude. ";
                                system("espeak \"What's up, dude.\"");
                            break;
                        case 2:cout << "Yo Amigo. ";
                                system("espeak \"Yo Amigo.\"");
                    }
                   cout<<endl;
                   flag++;
              }
            if ((!strcmp(tinput,"how are you?"))||(!strcmp(tinput,"how are you")))
                {
                    randam=rand()%2;
                    cout<<"\nSPRITAN => ";
                    switch(randam)
                        {
                            case 0:cout << "I am good, how are you";
                                        system("espeak \"I am good, how are you\"");
                                break;
                            case 1:cout << "I am fine thank you,\n\t  By the way how are you?";
                                        system("espeak \"I am fine thank you\"");
                                        system("espeak \"By the way how are you?\"");
                                break;
                        }
                    cout<<endl;
                    flag++;
                }
            if (!strcmp(tinput,"i am fine")||!strcmp(tinput,"i am fine too")
                ||!strcmp(tinput,"fine fine")||!strcmp(tinput,"good"))
                {
                    randam=rand()%2;
                    cout<<"\nSPRITAN => ";
                    switch(randam)
                        {
                            case 0:cout << "Thats good to know, command me something";
                                        system("espeak \"Thats\"");
                                        system("espeak \"good to know\"");
                                        system("espeak \"command me something\"");
                                    break;
                            case 1:cout << "Pleasured to know, now what can i do for you.";
                                        system("espeak \"Pleasured to know\"");
                                        system("espeak \"now what can i do for you\"");
                                    break;
                        }
                     cout<<endl;
                     flag++;
                }
            if (!strcmp(tinput,"exit")||!strcmp(tinput,"bye")|!strcmp(tinput,"seeya"))
                {
                    cout<<"\nSPRITAN => ";
                    cout<<"Goodbye, take care.....\n";
                    system("espeak \"Goodbye, take care\"");
                    exit(1);
                }
            if (!strcmp(tinput,"tell a joke")||!strcmp(tinput,"tell me a joke")||!strcmp(tinput,"a joke please"))
               {
                   telljoke(tinput);
                   cout<<endl;
                   flag++;
               }
            if (!strcmp(tinput,"play a game")||!strcmp(tinput,"launch a game"))
                {
                     int k=0;
                     while(k==0)
                     {
                     cout<<"\nSPRITAN =>    Which game would you like to play select the number:";
                     system("espeak \"Which game would you like to play select the number\"");
                     cout<<"\n           [ ]-------------------------------------------------[ ]";
                     cout<<"\n            | 1. Tic-Tac-Toe                                    |";
                     cout<<"\n            | (The classic)                                     |";
                     cout<<"\n            | 2. High-low                                       |";
                     cout<<"\n            | (Number guessing game)                            |";
                     cout<<"\n            | 3. Sudoku                                         |";
                     cout<<"\n            | (No one needs its description)                    |";
                     cout<<"\n           [ ]-------------------------------------------------[ ]";
                     cout<<"\nOPTION => ";
                     cin >>randam;
                    switch(randam)
                          {
                            case 1:tictactoe();k++;
                                  break;
                            case 2:highlow();k++;
                                  break;
                            case 3:sudoku();k++;
                                  break;
                            default:cout<<"\nWrong input enter again.";
                                    system("espeak \" wrong input enter again \"");
                          }
                     }
                    cout<<endl;
                    flag++;
                }
            if (!strcmp(tinput,"play tic-tac-toe")||!strcmp(tinput,"play tictactoe")
                ||!strcmp(tinput,"let's play tic-tac-toe")||!strcmp(tinput,"let's play tictactoe"))
                {
                  tictactoe();
                  cout<<endl;
                  flag++;
                }
             if (!strcmp(tinput,"play sudoku"))
                  {
                  sudoku();
                  cout<<endl;
                  flag++;
                }
            if (!strcmp(tinput,"play high-low")||!strcmp(tinput,"play highlow")
                ||!strcmp(tinput,"let's play high-low")||!strcmp(tinput,"let's play highlow"))
                {
                  flag++;
                  highlow();
                  cout<<endl;
                  continue;
                }
        /*    if(!strcmp(tinput,"play a desktop game"))
                {
                    launchapp('g');
                    start();
                    cout<<"\nSPRITAN => What shall i do for you next?\n";
                    system("espeak \"What shall i do for you next\"");
                   
                    flag++;
                    
                }*/
            if (!strcmp(tinput,"what time is it")||!strcmp(tinput,"what is the time")
                ||!strcmp(tinput,"what time is it?")||!strcmp(tinput,"what is the time?")
                ||!strcmp(tinput,"tell me the time")||!strcmp(input,"tell me the time?")
                ||!strcmp(tinput,"tell me the current time")||!strcmp(input,"tell me the current time?")
                ||!strcmp(tinput,"tell me the date")||!strcmp(input,"tell me the date?")
                ||!strcmp(tinput,"what is the date")||!strcmp(tinput,"what is the date?"))
               {
                   cout<<"\nSPRITAN => ";
                   // Declaring argument for time()
                     time_t tt;
                   // Declaring variable to store return value of
                   // localtime()
                     struct tm * ti;
                   // Applying time()
                     time (&tt);
                   // Using localtime()
                     ti = localtime(&tt);
                     cout << "Current Day, Date and Time is = "<< asctime(ti);
                     system("espeak \"Current Day\"");
                     system("espeak \"Date and Time is\"");
                     cout<<endl;
                     flag++;
               }
            if (!strcmp(tinput,"search the web")||!strcmp(tinput,"open the browser")
                ||!strcmp(tinput,"open firefox")||!strcmp(tinput,"open firefox")
                ||!strcmp(tinput,"browse the web"))
                {
                    system("firefox");
                    start();
                    cout<<"\nSPRITAN => Brower(firefox) is closed.\n";
                    system("espeak \"Brower is closed\"");
                    flag++;
                }
            if(flag==0)
                {
                  extra(tinput) ;
                  cout<<endl;
                }
            }
    return 0;
    }
void start()
    {
   system("clear");
   system("toilet -f mono12 -F metal    SPRITAN");                                                        //sudo apt-get install toilet
   cout << "=> Hello, This is SPRITAN a chatbot AI made by Proyash" << endl ;
   cout << "=> Feel free to say hi or command to do something." << endl ;
   cout << "-------------------------------------------------------------------------------------\n";
    }
void telljoke(char ar[])
    {
       int num=0;
       num=rand()%2;
       cout<<"\nSPRITAN => ";
       switch(num)
        {
            case 0:{
                    cout<<"Teacher      : 'Anyone who thinks he's stupid may stand up!'";
                    system("espeak \"Teacher      Anyone who thinks he's stupid may stand up\"");
                    cout<<"\n\t\t   *Nobody stands up*";
                    system("espeak \"Nobody stands up\"");
                    cout<<"\n\t   Teacher      : 'Im sure there are some stupid students over here!!'";
                    system("espeak \"Teacher      Im sure there are some stupid students over here\"");
                    cout<<"\n\t\t   *Little Johnny stands up*";
                    system("espeak \"Little Johnny stands up\"");
                    cout<<"\n\t   Teacher      : 'Ohh, Johnny you think you're stupid?'";
                    system("espeak \"Teacher      Ohh, Johnny you think you're stupid\"");
                    cout<<"\n\t   Little Johnny: 'No... i just feel bad that you're standing alone...'";
                    system("espeak \"Little Johnny  No i just feel bad that you're standing alone\"");
                    break;
                  }
            case 1:{
                    cout<<"Three drunken guys entered a taxi. The taxi driver knew that they\n";
                    system("espeak \"Three drunken guys entered a taxi. The taxi driver knew that they\"");
                    cout<<"\t   were drunk so he started the engine and turned it off again. Then\n";
                    system("espeak \"were drunk so he started the engine and turned it off again. Then\"");
                    cout<<"\t   said,  'We have reached your destination' .  The 1st guy gave him \n";
                    system("espeak \"said,  'We have reached your destination' .  The 1st guy gave him \"");
                    cout<<"\t   money  and the 2nd guy said  'Thank you'. The 3rd guy slapped the \n";
                    system("espeak \"money  and the 2nd guy said  'Thank you'. The 3rd guy slapped the \"");
                    cout<<"\t   driver.The driver was shocked thinking the 3rd drunk knew what he\n";
                    system("espeak \"driver.The driver was shocked thinking the 3rd drunk knew what he\"");
                    cout<<"\t   did. But then he asked 'What was that for?'  The 3rd guy replied, \n";
                    system("espeak \"did. But then he asked 'What was that for?'  The 3rd guy replied, \"");
                    cout<<"\t   'Control your speed next time, you nearly killed us!'";
                    system("espeak \"Control your speed next time, you nearly killed us\"");
                    break;
                  }
            case 2:{
                    cout<<"I was in in the public restroom\
                    \n\t   I was barely sitting down when I heard a voice in the other stall:\
                    \n\t'Hi, how are you?'\
                    \n\tMe   : (embarrassed)'Doin' fine!'\
                    \n\tStall:'So what are you up to?'\
                    \n\tMe   :'Uhhh, I'm like you, just sitting here.\
                    \n\tStall: 'can I come over?'\
                    \n\tMe   : (attitude) 'No, I'm a little busy right now!!'\
                    \n\tStall:'Listen, I'll have to call you back. There's an idiot in the other stall\
                    \n\t       who keeps answering all my questions!";
                    break;
                  }
        }
    }
void tictactoe()
    {
        cout<<"\nSPRITAN => ";
        cout<<"You may play tic-tac-toe PvP...\n\tShall i launch tic-tac-toe(y/n)?";
        system("espeak \"You may play tic-tac-toe\"");
        system("espeak \"Shall i launch\"");
        system("espeak \"tic-tac-toe\"");
        char ch='x';
        while(ch!='Y'&&ch!='y'&&ch!='n'&&ch!='N')
        {
            cout<<"\nOPTION  => ";
             cin>>ch;            
            while(ch=='Y'||ch=='y')
            {
                int player = 1,i,choice;
                char mark;
                do
                {
                    board();
                    player=(player%2)?1:2;
                    cout << "\tPLAYER " << player << " enter a number:  ";
                    cin >> choice;
                    mark=(player == 1) ? 'X' : 'O';
                    if (choice == 1 && square[1] == '1')
                    square[1] = mark;
                    else if (choice == 2 && square[2] == '2')
                        square[2] = mark;
                    else if (choice == 3 && square[3] == '3')
                        square[3] = mark;
                    else if (choice == 4 && square[4] == '4')
                        square[4] = mark;
                    else if (choice == 5 && square[5] == '5')
                        square[5] = mark;
                    else if (choice == 6 && square[6] == '6')
                        square[6] = mark;
                    else if (choice == 7 && square[7] == '7')
                        square[7] = mark;
                    else if (choice == 8 && square[8] == '8')
                        square[8] = mark;
                    else if (choice == 9 && square[9] == '9')
                        square[9] = mark;
                    else
                    {
                        cout<<"------------------------------!!Invalid move !!------------------------------\n";
                        player--;
                        cout<<"--------------------------!!!Press y to continue!!!--------------------------\n";
                        cin.ignore();
                        cin.get();
                    }
                    i=checkwin();
                    player++;
                }while(i==-1);
                board();
                if(i==1)
                    cout<<"\a-------------------------------||PLAYER "<<--player<<" WINS||------------------------------\n";
                else
                    cout<<"\a--------------------------------||GAME DRAW||---------------------------------\n";
                cin.ignore();
                cout<<"-------------------------||Do you want to play again?||------------------------\n ";
                cout<<"\nOPTION  => ";
                cin>>ch;
            }
            if(ch=='n'||ch=='N')
                {
                    cin.get();
                    cout<<"\nSPRITAN => Some day i will learn to play too.\n\tMeanwhile what shall i do next?";//add to answer if requested for other games
                    system("espeak \"Some day i will learn\"");
                    system("espeak \"to play too Meanwhile\"");
                    system("espeak \"what shall i do next\"");
                }
            else if(ch!='y'||ch!='Y')
                cout<<"\nGAME    => Inaccurate input plese re-enter!!";
        }
    }
int checkwin()
    {
        if      (square[1] == square[2] && square[2] == square[3])
            return 1;
        else if (square[4] == square[5] && square[5] == square[6])
            return 1;
        else if (square[7] == square[8] && square[8] == square[9])
            return 1;
        else if (square[1] == square[4] && square[4] == square[7])
            return 1;
        else if (square[2] == square[5] && square[5] == square[8])
            return 1;
        else if (square[3] == square[6] && square[6] == square[9])
            return 1;
        else if (square[1] == square[5] && square[5] == square[9])
            return 1;
        else if (square[3] == square[5] && square[5] == square[7])
            return 1;
        else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
                && square[4] != '4' && square[5] != '5' && square[6] != '6'
                && square[7] != '7' && square[8] != '8' && square[9] != '9')
            return 0;
        else
            return -1;
    }
void board()
    {

        cout << "\n------------------------------||Tic Tac Toe||---------------------------------\n";
        cout << "_____________________||Player 1 (X)  -  Player 2 (O)||________________________" << endl;
        cout << endl;
        cout << "\t     |     |     " << endl;
        cout << "\t  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
        cout << "\t_____|_____|_____" << endl;
        cout << "\t     |     |     " << endl;
        cout << "\t  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
        cout << "\t_____|_____|_____" << endl;
        cout << "\t     |     |     " << endl;
        cout << "\t  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
        cout << "\t     |     |     " << endl << endl;
    }
void highlow()
    {
      cout<<"\nSPRITAN => ";
      cout<<"You may play high-low...\n\tShall i launch high-low(y/n)?\n";
      system("espeak \"You may play high-low\"");
      system("espeak \" Shall i launch high-low\"");
      cout<<"\nOPTION  => ";
      char ch='y';
      cin>>ch;
      char ans;
      if(ch=='Y'||ch=='y')
        {
         const int totchan=5;
         int number;        //the computer's random number
         int guess;         //the user's guess
         int chances=0,score=0,chanscor;        //chanscor stores score for 1
       //successful chance.
        do
        { //clrscr();
          chances=score=0;
          cout<<"-----------------------||Welcome to the High/Low game.||---------------------\n";
          cout<<"----------------||I will pick a random number from 0 to 20||-----------------\n";
          cout<<"--------------------||You must try to guess the number||---------------------\n";
          cout<<"----------------------||You have 5 chances to guess||------------------------\n";
         // randomize();
          number=(int)(rand()%20);
          chanscor=20/totchan;        //score for each successful chance
          do
          {
            cout<<"Game    => What is your guess? (0 to 20) ";
            cout<<"\nYou     => ";
            cin>>guess;
            cout<<"Game    => ";
            if((guess<0)||(guess>20))
            {
         cout<<"Sorry, but your guess "<<guess<<"must be from 0 to 20.";
            }
            else if(guess < number)
            {
         cout<<guess<<" is low.Try a higher number.";
            }
            else if(guess > number)
            {
         cout<<guess<<" is high.Try a lower number.";
            }
            else		//if correct number is guessed
            {			//number is correct, and the "do" loop will end below
         cout<<guess<<" is correct. Congratulations!";
         score=chanscor*(totchan-chances);   //score calculated for number of
       //chances left
         cout<<"\nGame    => ";
         cout<<"	Your score is "<<score<<endl;
               break;
            }
          chances++;
          if(guess!=number)
          cout<<"Game    => ";
          cout<<"Now you have "<<totchan-chances<<"chances left."<<endl;

            if(chances==totchan)
          { cout<<"Game    => ";
            cout<<"Only "<<totchan<<"chances are allowed.Better luck next time";
            cout<<"\nGame    => ";
            cout<<"The actual number was "<<number<<endl;
            break;
          }
            }while (guess!=number);
            cout<<"Game    => ";
            cout<<"Thank you for playing High/Low!\n";
            cout<<"Game    => ";
            cout<<"Want to play it again? (y/n)\n";
            cout<<"\nOPTION  => ";
            cin>>ans;
            //cin.get();
          }while(ans=='y' || ans=='Y');
        }
        if(ch=='n'||ch=='N')
            {
                cin.get();
                cout<<"\nSPRITAN => Hopefully you are satisfied .\n\tMeanwhile what shall i do next?";
                 system("espeak \"Hopefully you are satisfied\"");
                 system("espeak \"Meanwhile what shall i do next\"");
                return;
            }
        if(ans=='n'||ans=='N')
                {
                    cin.get();
                    cout<<"\nSPRITAN => What should i do next?";
                    system("espeak \"Meanwhile what should i do next\"");
                }
    }
void extra(char Q[])
    {
      ifstream fii("reso.dat", ios::in|ios::binary);
      char ch='y';
      fii.seekg(0);
      int found=0;
      if(!fii)
      {
          cout<<"\nSPRITAN => Sorry, i am not feeling well i have to get rest..";
          system("espeak \"Sorry\"");
          system("espeak \"i am not feeling well i have to get rest\"");
          exit(1);
      }
      while(!fii.eof())
    	{
            fii.read((char *)&stud1, sizeof(stud1));
    	    if(!strcmp(Q,stud1.que))
    	    {
    		    char we[80];
                strcpy(we,"espeak \"");
                strcat(we,stud1.answ);
                strcat(we,"\"");
                cout<<"\nSPRITAN => ";
    		    for(int i=0;stud1.answ[i]!='\0';i++)
    		    {
                    cout<<stud1.answ[i];
    		    }
    		    system(we);
    		    //cout<<endl;
    		    found++;
    		    break;
    	    }
	    }
	    fii.close();
	    ofstream fio("reso.dat", ios::out|ios::app|ios::binary);
        if(!fio)
        {
            cout<<"\nSPRITAN => Sorry, i am not feeling well i have to get rest..";
            system("espeak \"Sorry\"");
            system("espeak \"i am not feeling well i have to get rest\"");
            exit(1);
        }
        fio.seekp(0);
        if(found==0)
        {
    	    cout<<"\nSPRITAN => ";
            int randam=rand()%2;
            switch(randam)
            {
                case 0:cout<<"I don't yet know that\n";
                        system("espeak \"I don't yet know that\"");
                        break;
                case 1:cout<<"Oops, never encountered that before\n";
                        system("espeak \"Oops, never encountered that before\"");
                        break;
            }
            cout<<"\nSPRITAN => Would you like to tell how i should have answered ?(y/n)";
            system("espeak \"Would you like to tell how i should have answered\"");
    	    cout<<"\nOPTION  => ";
    	    cin>>ch;
            cin.get();
            if(ch=='n'||ch=='N')
            {
                char option='n';
                cout<<"\nSPRITAN => Do want to search the web to get your answer?(y/n)\n";
                system("espeak \"Do want to search the web to get your answer\"");
                cout<<"OPTION  => ";
                cin>>option;
                if(option=='y'||option=='Y')
                {
                    char Ques[50];
                    strcpy(Ques,"sr google ");
                    strcat(Ques,Q);
                    webser(Ques);
                    start();
                    cout<<"\nSPRITAN => Hopefully you got your answer.";
                    system("espeak \"Hopefully you got your answer\"");
                }
                cout<<"\nSPRITAN => What shall i do next?";
                system("espeak \"What shall i do next\"");
                cin.get();
            }
            if(ch=='y'||ch=='Y')
              {
               strcpy(stud1.que,Q);
               cout<<"\nSPRITAN => Please tell me the answer...\n";
               system("espeak \"Please tell me the answer\"");
               cout<<"\nYou     => ";
               cin.getline(stud1.answ,80);
               fio.write((char *)&stud1, sizeof(stud1));
               cout<<"\nSPRITAN => Thanks for teaching me...";
               system("espeak \"Thanks for teaching me\"");
             }
        }
        fio.close();
    }
void sudoku()
    {

      cout<<"\nSPRITAN => ";
      cout<<"You may play sudoku...\n\tShall i launch sudoku(y/n)?\n";
      system("espeak \"You may play sudoku\"");
      system("espeak \"Shall i launch sudoku\"");
      cout<<"\nOPTION  => ";
      char ch='y';
      cin>>ch;
      char ans;
      if(ch=='Y'||ch=='y')
      {
          do
          {
              system("nudoku");
              cout<<"\nGame    => ";
              cout<<"Want to play it again? (y/n)\n";
              cout<<"OPTION  => ";
              cin>>ans;
          }while(ans=='y' || ans=='Y');
       if(ch=='n'||ch=='N')
            {
                cin.get();
                cout<<"\nSPRITAN => Hopefully you are satisfied .\n\tMeanwhile what shall i do next?";
                system("espeak \"Hopefully you are satisfied\"");
                system("espeak \"Meanwhile what shall i do next\"");
                return;
            }
       if(ans=='n'||ans=='N')
                {
                    cin.get();
                    cout<<"\nSPRITAN => What should i do next?";
                    system("espeak \" what should i do next\"");
                }
    }
    }
void singsong()
    {
    system("aplay media.io_Crying_in_the_Club.wav");
    cin.get();
    }
void webser(char ip[])
    {
    system(ip);
    }
void getwether()
    {
    system("curl wttr.in");
    }
/*void launchapp(char ch)
    {
        int in;
        switch(ch)
        {
            case 'G':
            case 'g':int k=0;
                    while(k==0)
                    {
                     cout<<"\nSPRITAN =>    All available games on your system are shown below :";
                     cout<<"\n              Which game would you like to play select the number:";
                     system("espeak \"All available games on your system are shown below: \"");
                     system("espeak \"Which game would you like to play select the number\"");
                     cout<<"\n           [ ]-------------------------------------------------[ ]";
                     cout<<"\n            | 1. Xonotic                                        |";
                     cout<<"\n            | (online, multiplayer sharp shooter game)          |";
                     cout<<"\n            | 2. 0 A.D.                                         |";
                     cout<<"\n            | (Strategy games,involing grestness of the old age |";
                     cout<<"\n            | 3. Runescape(new)                                 |";
                     cout<<"\n            | (One of the greatest MMORPG ever)                 |";
                     cout<<"\n            | 4. Minetest                                       |";
                     cout<<"\n            | (Not a minecraft clone but better than it )       |";
                     cout<<"\n           [ ]-------------------------------------------------[ ]";
                     cout<<"\nOPTION  => ";
                     cin>>in;
                        switch(in)
                        {
                            case 1:system("xonotic");
                                    k++;
                                    break;
                            case 2:system("0ad");
                                    k++;
                                    break;
                            case 3:system("runescape");
                                    k++;
                                    break;
                            case 4:system("minetest");
                                    k++;
                                    break;
                            default:cout<<"\nSPRITAN => Wrong input enter again.";
                                    system("espeak \"Wrong input enter again \"");
                        }
                    }
                    cin.get();
                     break;
        }
    }*/
