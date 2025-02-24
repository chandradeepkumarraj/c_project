#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BOLD     "\x1b[1m"
#define COLOR_RED     "\x1b[31;1m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define HIGHLIGHT_BLACK_FG_GREEN_BG  "\x1b[102;30m"
#define HIGHLIGHT_HEADING  "\x1b[103;30m"
#define HIGHLIGHT_ERROR  "\x1b[1;37;41m"
#define HIGHLIGHT_OPTION  "\x1b[106;30m"
#define HIGHLIGHT_SUB_HEADING  "\x1b[107;30m"
#define COLOR_RESET   "\x1b[0m"

const char teamlist[10][13]= {"Afghanistan","Australia","Bangladesh","England","India","Nepal","New Zealand","Pakistan","South Africa","Sri Lanka"};
char batting_team[13],bowling_team[13];


struct Team
{
    char team_name[13];
    int score;
    int ball;
    int wicket;
    int six;
    int four;
    char player_scored_highest_run[30];
    int inning;


} teamA,teamB;

int selectteam()
{
    int choose_team_name=0;
    for(int i=0; i<10; i++)
    {
        printf("\n\t %d. %s",i+1,teamlist[i]);
    }
    printf("\n");
    printf("\n");
    printf( HIGHLIGHT_OPTION "Choose the Team name:" COLOR_RESET);
    scanf("%d",&choose_team_name);
    while(choose_team_name>10) {
        printf( HIGHLIGHT_OPTION "Choose the Team name Again:" COLOR_RESET);
        scanf("%d",&choose_team_name);
        printf("\n");
    }
    return choose_team_name-1;
}
int toss_check()
{
    int toss_value;
    printf("\n");
    printf( HIGHLIGHT_SUB_HEADING "-------Who Win the TOSS-------" COLOR_RESET);
    printf("\n");
    printf("\n\t 1.%s",teamA.team_name);
    printf("\n\t 2.%s",teamB.team_name);
     printf("\n");
     printf("\n");
    printf( HIGHLIGHT_OPTION "Choose the Team:" COLOR_RESET);
    scanf("%d",&toss_value);

    return toss_value;
}

// Toss winning team select batting or bowling function
int choice_after_toss_win(int toss_value)
{
    int choice_after_toss_win_value;
    if(toss_value==1)
    {   printf("\n");
        printf( HIGHLIGHT_SUB_HEADING "-------%s choosed-------" COLOR_RESET ,teamA.team_name);
        printf("\n\t 1. Batting");
        printf("\n\t 2. Bowling");
         printf("\n");
         printf("\n");
        printf(  HIGHLIGHT_OPTION "Enter the option:" COLOR_RESET);
        scanf("%d",&choice_after_toss_win_value);
    }
    else
    {   printf("\n");
        printf( HIGHLIGHT_SUB_HEADING "-------%s choosed-------" COLOR_RESET,teamB.team_name);
        printf("\n\t 1. Batting");
        printf("\n\t 2. Bowling");
         printf("\n");
         printf("\n");
        printf( HIGHLIGHT_OPTION "Enter the option:" COLOR_RESET );
        scanf("%d",&choice_after_toss_win_value);
    }
    return choice_after_toss_win_value;
}

// update the code
void update_score_data(struct Team *teamX)
{
    int option2=0;
    while (option2 != 6)
    {
        int selection=0;
        printf("\n");
        printf( HIGHLIGHT_SUB_HEADING "----------Updating Cricket Score Database----------"COLOR_RESET);
        printf("\n");
        printf(COLOR_GREEN "\n \t### %s ###\n"COLOR_RESET,teamX->team_name);
        printf(BOLD"1.Update Score and Ball\n");
        printf("2.Update Out Player count\n");
        printf("3.Update 6's and 4's \n");
        printf("4.Update which Player Scored Highest \n");
        printf("5.Update Team %s Innings Status\n",teamX->team_name);
        printf("6.Exit \n" COLOR_RESET);
        printf("\n");
        printf( HIGHLIGHT_OPTION "Select the option:" COLOR_RESET );
        scanf("%d",&selection);
        switch(selection)
        {
        case 1:
        {
            printf(COLOR_GREEN "\n \t### %s ###\n"COLOR_RESET,teamX->team_name);
            printf("\n Enter the Latest Runs Scored by %s :",teamX->team_name);
            scanf("%d",&teamX->score);
            do
            {
                if(teamX->ball > 120)
                {
                    printf(HIGHLIGHT_ERROR "Invalid Input ! Enter Again !" COLOR_RESET);
                    printf("\n");
                }
                printf("\nEnter the count of Balls played by %s (Maxmimun = 120):",teamX->team_name);
                scanf("%d",&teamX->ball);
            }
            while(teamX->ball > 120);
            break;
        }

        case 2:
        {
            do
            {
                if(teamX->wicket > 9)
                {
                    printf(HIGHLIGHT_ERROR "Invalid Input ! Enter Again !" COLOR_RESET);
                    printf("\n");
                }
                printf(COLOR_GREEN "\n \t### %s ###\n"COLOR_RESET,teamX->team_name);
                printf("\n Enter the count of Out Player in %s :",teamX->team_name);
                scanf("%d",&teamX->wicket);
            }
            while(teamX->wicket > 9);


            break;
        }

        case 3:

        {

             do {
                    if (teamX->score < teamX->six*6+teamX->four*4) {
                printf("\n\t");
                printf( HIGHLIGHT_ERROR "Improper Data provided !..Input exceeds more than the run scored by %s" COLOR_RESET,teamX->team_name);
                printf("\n");
            }
            printf(COLOR_GREEN "\n \t### %s ###\n"COLOR_RESET,teamX->team_name);
            printf("\n Enter the count of Sixes Hitted by %s :",teamX->team_name);
            scanf("%d",&teamX->six);
            printf("\n Enter the count of Fours Hitted by %s :",teamX->team_name);
            scanf("%d",&teamX->four);

        } while((teamX->score) < (teamX->six*6+teamX->four*4));
        printf("\n");
        printf("\n");

            break;
        }

        case 4:
        {

            printf(COLOR_GREEN "\n \t### %s ###\n"COLOR_RESET,teamX->team_name);
            printf("\nEnter the name of the Player which Highest Run Scorer on behalf of Team %s\n",teamX->team_name);
            printf( HIGHLIGHT_OPTION "Name:"COLOR_RESET);
            getchar();
            //gets(teamX->player_scored_highest_run);
            scanf("%[^\n]s",teamX->player_scored_highest_run);

            break;
        }

        case 5:
        {
            printf(COLOR_GREEN "\n \t### %s ###\n"COLOR_RESET,teamX->team_name);
            int temp_option=0;
            printf("\n Is this Inning completed :");
            printf("\n \t 1. YES");
            printf("\n \t 2. No or Ongoing");
             printf("\n");
             printf("\n");
            printf( HIGHLIGHT_OPTION "Select the option:" COLOR_RESET);
            scanf("%d",&temp_option);
            switch (temp_option)
            {
            case 1:
            {
                teamX->inning=1;
                break;
            }
            case 2:
            {
                teamX->inning=0;
                break;
            }
            default :
            {
                printf("\n Invalid Input");
            }

            }
            break;
        }

        case 6:
        {
            option2=6;
            printf("\n Back to main menu\n");
            break;
        }

        default :
        {
            printf("\n");
            printf( HIGHLIGHT_ERROR "Invalid Input" COLOR_RESET );
            printf("\n");
        }
        }

    }


}


void print_run_scored(struct Team teamX)
{
    printf(COLOR_GREEN "\n\n\t #####\t %s \t#####\n" COLOR_RESET, teamX.team_name);
    printf( COLOR_MAGENTA "\t----------------------" COLOR_RESET);
    printf(BOLD "\n\t| Runs scored :: " COLOR_RESET);
    printf(COLOR_GREEN "%d " COLOR_RESET,teamX.score);
    printf( BOLD "|\n" COLOR_RESET);
    printf( COLOR_MAGENTA "\t----------------------" COLOR_RESET );
     printf("\n");
}

void print_match_statistics(struct Team team)
{
    printf("\n");
    printf(HIGHLIGHT_SUB_HEADING "Match Statistics for %s" COLOR_RESET, team.team_name);
    printf("\n");
    printf(COLOR_GREEN "\n #####\t %s \t#####\n" COLOR_RESET, team.team_name);
    printf("Score: %d\n", team.score);
    printf("Balls Faced: %d/120\n", team.ball);
    printf("Wickets Lost: %d/11\n", team.wicket);
    printf("Sixes Hit: %d\n", team.six);
    printf("Fours Hit: %d\n", team.four);
    printf("Highest Run Scorer: ");
    if(strlen(team.player_scored_highest_run) == 0)
    {
        printf( HIGHLIGHT_ERROR "Input not Provided" COLOR_RESET );
        printf(" \n" );
    }

    else if(strlen(team.player_scored_highest_run) != 0)
    {
        printf("%s", team.player_scored_highest_run);
        printf(" \n" );

    }


}

void show_match_result(struct Team teamA, struct Team teamB)
{   printf("\n");
    printf(HIGHLIGHT_SUB_HEADING "----------Match Result----------" COLOR_RESET);
    printf("\n");
    printf(COLOR_GREEN "\n\n\t%s",teamA.team_name);
        printf( COLOR_RESET );

        printf( HIGHLIGHT_BLACK_FG_GREEN_BG "\t\tVS"COLOR_RESET);

        // team B print
        printf(COLOR_GREEN "\t\t%s",teamB.team_name);
        printf( COLOR_RESET );
        printf("\n");
        printf("\n");

    printf("\tScore: %d/%d\t\t",teamA.score, teamA.wicket);
    printf("\t\tScore: %d/%d",teamB.score, teamB.wicket);
      printf("\n");

    if(teamA.inning == 0 && teamB.inning == 0 ) {
        printf("\n\t");
        printf( HIGHLIGHT_ERROR "Match is Ongoing!!!" COLOR_RESET);
        printf("\n");
    }
    else if(teamA.inning == 0 && teamB.inning == 1){
            printf("\n\t");
        printf( HIGHLIGHT_ERROR "Match is Ongoing!!!" COLOR_RESET);
        printf("\n");

    }
    else if(teamA.inning == 1 && teamB.inning == 0){
            printf("\n\t");
        printf( HIGHLIGHT_ERROR "Match is Ongoing!!!" COLOR_RESET);
        printf("\n");

    }
    else if(teamA.score > teamB.score)
    {
        printf("\n\t");
        printf( HIGHLIGHT_BLACK_FG_GREEN_BG "%s wins the match by %d runs! and %d wickets" COLOR_RESET, teamA.team_name, teamA.score - teamB.score,10 - teamA.wicket);
        printf("\n");
    }
    else if (teamA.score < teamB.score)
    {
        printf("\n\t");
        printf(HIGHLIGHT_BLACK_FG_GREEN_BG "%s wins the match by %d runs and %d wickets" COLOR_RESET, teamB.team_name, teamB.score - teamA.score,10 - teamB.wicket);
        printf("\n");
    }
    else
    {
        printf("\n");
        printf( HIGHLIGHT_BLACK_FG_GREEN_BG "The match is a tie!" COLOR_RESET);
        printf("\n");
    }
     printf("\n");

}



void main()
{

    int toss_value=0,exit;

    printf( HIGHLIGHT_HEADING "----------Cricket Score Display----------\n"COLOR_RESET);

    printf(COLOR_RED "\n Initializing Information...\n"COLOR_RESET);
    printf("\n");
    printf( HIGHLIGHT_SUB_HEADING "-------Select Team A name-------" COLOR_RESET);
    printf("\n");
    strcpy(teamA.team_name,teamlist[selectteam()]);
    //printf("\n\t  %s",teamA.team_name);

    printf("\n");
    printf( HIGHLIGHT_SUB_HEADING "-------Select Team B name-------" COLOR_RESET);
    printf("\n");
    strcpy(teamB.team_name,teamlist[selectteam()]);

    //printf("\n\t  %s",teamB.team_name);

    // checking team name conflict
    while (strcmp(teamA.team_name,teamB.team_name) == 0 )
    {
        printf( COLOR_RED "\n Reselect Team B" COLOR_RESET);
        printf("\n");
        printf( HIGHLIGHT_SUB_HEADING "-------Select Team B name-------" COLOR_RESET);
        printf("\n");
        strcpy(teamB.team_name,teamlist[selectteam()]);
    }
    // checking toss win team selection error
    toss_value=toss_check();
    while (toss_value != 1 && toss_value != 2)
    {
        printf( HIGHLIGHT_ERROR "\n Enter Wrong Choice" COLOR_RESET);
        toss_value=toss_check();
    }

    // Toss winning team select batting or bowling
    int choice_after_toss_win_value=choice_after_toss_win(toss_value);
    while (choice_after_toss_win_value != 1 && choice_after_toss_win_value != 2)
    {
        printf( COLOR_RED "\n Invalid Choice" COLOR_RESET);
        choice_after_toss_win_value=choice_after_toss_win(toss_value);
    }
    // batting and bowling team name deciding
    if(toss_value==1)
    {
        if(choice_after_toss_win_value==1)
        {
            strcpy(batting_team,teamA.team_name);
            strcpy(bowling_team,teamB.team_name);
        }
        else if(choice_after_toss_win_value==2)
        {
            strcpy(batting_team,teamB.team_name);
            strcpy(bowling_team,teamA.team_name);
        }
    }
    else if(toss_value==2)
    {
        if(choice_after_toss_win_value==1)
        {
            strcpy(batting_team,teamB.team_name);
            strcpy(bowling_team,teamA.team_name);
        }
        else if(choice_after_toss_win_value==2)
        {
            strcpy(batting_team,teamA.team_name);
            strcpy(bowling_team,teamB.team_name);
        }
    }

    printf("\n");
    printf( HIGHLIGHT_BLACK_FG_GREEN_BG " Initialization Completed..." COLOR_RESET);
    printf("\n");
    printf("\n");
    printf("\n");


    do
    {
        int option=0;
        printf("\n");
        printf( HIGHLIGHT_HEADING "----------Cricket Score Display----------"COLOR_RESET);
        printf("\n");


        //team A print
        printf(COLOR_GREEN "\n\n\t%s",batting_team);
        printf( COLOR_RESET );

        printf( HIGHLIGHT_BLACK_FG_GREEN_BG "\t\tVS"COLOR_RESET);

        // team B print
        printf(COLOR_GREEN "\t\t%s",bowling_team);
        printf( COLOR_RESET );
        printf("\n");
        printf("\n");

        printf(BOLD"1.Update Score Data\n");
        printf("2.Print Run Scored\n");
        printf("3.Print Match Statistic\n");
        printf("4.Show Match Result\n");
        printf("5.Exit\n"COLOR_RESET);
        printf( HIGHLIGHT_BLACK_FG_GREEN_BG "Choose option:: "COLOR_RESET);
        scanf("%d",&option);

        switch (option)
        {

        case 1 : // update score data
        {
            if(toss_value==1)
            {
                if(choice_after_toss_win_value==1)
                {
                    if(teamA.inning==0)
                    {
                        // Update score for Team A
                        update_score_data(&teamA);
                    }
                    else if(teamA.inning==1)
                    {
                        // Update score for Team B
                        update_score_data(&teamB);
                    }

                }
                else if(choice_after_toss_win_value==2)
                {
                    if(teamB.inning==0)
                    {
                        // Update score for Team A
                        update_score_data(&teamB);
                    }
                    else if(teamB.inning==1)
                    {
                        // Update score for Team B
                        update_score_data(&teamA);
                    }

                }
            }
            else if(toss_value==2)
            {
                if(choice_after_toss_win_value==1)
                {
                    if(teamB.inning==0)
                    {
                        // Update score for Team A
                        update_score_data(&teamB);
                    }
                    else if(teamB.inning==1)
                    {
                        // Update score for Team B
                        update_score_data(&teamA);
                    }

                }
                else if(choice_after_toss_win_value==2)
                {
                    if(teamA.inning==0)
                    {
                        // Update score for Team A
                        update_score_data(&teamA);
                    }
                    else if(teamA.inning==1)
                    {
                        // Update score for Team B
                        update_score_data(&teamB);
                    }

                }
            }
            break;
        }
        case 2 : //Printing Run Scored by Teams
        {
            printf( HIGHLIGHT_HEADING "----------Printing Run Scored by the Team----------"COLOR_RESET);
            printf("\n");
            // Print runs scored by Team A
            print_run_scored(teamA);
            // Print runs scored by Team B
            print_run_scored(teamB);
            break;
        }
        case 3 :
        {
            printf(HIGHLIGHT_HEADING "----------Cricket Match Statistic----------"COLOR_RESET);
            printf("\n");
            // Print match statistics for Team A
            print_match_statistics(teamA);
            // Print match statistics for Team B
            print_match_statistics(teamB);
            break;
        }
        case 4 :
        {
            printf( HIGHLIGHT_HEADING "----------Show Final Result ----------"COLOR_RESET);
            printf("\n");
            // Show the final result of the match
            show_match_result(teamA, teamB);
            printf("\n");
            printf("\n");
            break;
        }
        case 5 :
        {
            exit=5;
            printf("\n");
            printf( HIGHLIGHT_ERROR"\tExiting the Program\t" COLOR_RESET);
            printf("\n");
            break;
        }
        default:
        {
            printf("\n");
            printf( HIGHLIGHT_ERROR "Invalid Input" COLOR_RESET );
            printf("\n");
        }
        }
        printf("\n");
        printf("\n");
    }while (exit != 5);
}
