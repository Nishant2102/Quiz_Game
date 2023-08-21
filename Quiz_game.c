#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int generalKnowledge();
int history();
int geography();
char category;
int level, M = 0;
int finalscore;
char name;
void storeParticipantData(const char *name, int score)
{
    FILE *file = fopen("score.txt", "a"); // Open the file in append mode


    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }


    fprintf(file, "Name: %s, Score: %d\n", name, score);
    fclose(file);
}


void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    printf("\033[2J\033[1;1H"); // ANSI escape sequence to clear screen
#endif
}


int maingame()
{
    int score = 0;
    clearScreen();
    printf("Enter the category:\n");
    printf("H - History\n");
    printf("G - General Knowledge\n");
    printf("E  - Geography\n");
    scanf(" %c", &category);


    if (category == 'H' || category == 'h')
        score += history();
    else if (category == 'G' || category == 'g')
        score += generalKnowledge();
    else if (category == 'E' || category == 'e')
        score += geography();
    else
        printf("Invalid category");


    return score;
   // storeParticipantData(name, finalscore);
}
int changeQuestion()
{
    clearScreen();
    int c = 0;
    printf("Question changed!\n");
    if (category == 'h' || category == 'H')
    {
        time_t startTime, endTime;
        if (level == 1)
        {
            char option;
            printf("Your new question according to level 1 is-\n");
            printf("Which battle marked the beginning of Mughal rule in India?\n");
            printf("a) Battle of Plassey \nb) Battle of Haldighati \nc) Battle of Panipat \nd) Battle of Talikota\n");
            startTime = time(NULL);
            scanf(" %c", &option);
            endTime = time(NULL);


            if ((option == 'c' || option == 'C') && difftime(endTime, startTime) <= 10)
            {
                c++;
                printf("\a");
            }
        }
        else if (level == 2)
        {
            char option;
            printf("Your new question according to level 2 is-\n");
            printf("Which Mughal emperor imposed the jizya tax on non-Muslims?\n");
            printf("a) Akbar \nb) Aurangzeb \nc) Babur \nd) Shah Jahan\n");
            startTime = time(NULL);
            scanf(" %c", &option);
            endTime = time(NULL);


            if ((option == 'b' || option == 'B') && difftime(endTime, startTime) <= 10)
            {
                c++;
                printf("\a");
            }
        }
        return c;
    }
    if (category == 'g' || category == 'G')
    {
        time_t startTime, endTime;
        if (level == 1)
        {
            char option;
            printf("Your new question according to level 1 is-\n");
            printf("Which Indian city is famous for its Mysore Palace and silk production?\n");
            printf("a) Jaipur \nb) Mysore \nc) Udaipur \nd) Jodhpur\n");
            startTime = time(NULL);
            scanf(" %c", &option);
            endTime = time(NULL);


            if ((option == 'b' || option == 'B') && difftime(endTime, startTime) <= 10)
            {
                c++;
                printf("\a");
            }
        }
        else if (level == 2)
        {
            char option;
            printf("Your new question according to level 2 is-\n");
            printf("Which is the largest city in India by population?\n");
            printf("a) Mumbai \nb) Delhi \nc) Kolkata \nd) Chennai\n");
            startTime = time(NULL);
            scanf(" %c", &option);
            endTime = time(NULL);


            if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
            {
                c++;
                printf("\a");
            }
        }
        return c;
    }
    if (category == 'e' || category == 'E')
    {
        time_t startTime, endTime;
        if (level == 1)
        {
            char option;
            printf("Your new question according to level 1 is-\n");
            printf("Which is the largest delta in India?\n");
            printf("a) Sundarbans Delta \nb) Godavari Delta \nc) Krishna Delta \nd) Kaveri Delta\n");
            startTime = time(NULL);
            scanf(" %c", &option);
            endTime = time(NULL);


            if ((option == 'c' || option == 'C') && difftime(endTime, startTime) <= 10)
            {
                c++;
                printf("\a");
            }
        }
        else if (level == 2)
        {
            char option;
            printf("Your new question according to level 2 is-\n");
            printf("Which is the largest freshwater lake in the northeastern region of India?\n");
            printf("a) Loktak Lake \nb) Umiam Lake \nc) Dhekiakhowa Lake \nd) Chandubi Lake\n");
            startTime = time(NULL);
            scanf(" %c", &option);
            endTime = time(NULL);


            if ((option == 'b' || option == 'B') && difftime(endTime, startTime) <= 10)
            {
                c++;
                printf("\a");
            }
        }
        return c;
        clearScreen();
    }
}


int main()
{
    int finalscore = 0;
    char name[50];
    int age;


    clearScreen();
    printf("\t\t\t\t\t\t\tWELCOME TO QUIZ COMPETITION\n");
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    clearScreen();
    printf("Please enter your age-");
    scanf("%d", &age);
   // storeParticipantData(name, finalscore);
    clearScreen();
    if (age > (15))
    {
        printf("we would recommned you to play level 2 of the quiz.\n\n");
    }
    else
    {
        printf("we would recommned you to play level 1 of the quiz\n\n");
    }
     //storeParticipantData(name, finalscore);


    printf("\t\t\t\tPLEASE FOLLOW THE INSTRUCTIONS GIVEN BELOW\n\n");
    printf("RULE3: YOU WILL BE GIVEN 1 MARK FOR EACH CORRECT ANSWER\n");
    printf("RULE4: NO MARKS WILL BE DEDUCTED FOR WRONG ANSWERS\n");
    printf("RULE5: YOU WILL HAVE TO ANSWER 8 QUESTIONS CORRECTLY TO PASS THIS QUIZ\n");
    printf("RULE6: PRESS S TO START THE QUIZ\n");
    printf("RULE7: PRESS E TO EXIT THE QUIZ\n");
    printf("RULE8: PRESS ENTER TO CONTINUE\n");
    printf("RULE9: YOU WILL HAVE 10 SECONDS TO ANSWER EACH QUESTION.AFTER 10 SECONDS YOUR RESPONCE WILL NOT BE EVALUATED IN THE FINAL SCORE.\n");


    char input;
    scanf(" %c", &input);
    getchar();
    if (input == 'S' || input == 's')
    {
        clearScreen();
        finalscore = maingame();
        clearScreen();
        printf("%syour final Score is: %d", name, finalscore);
       storeParticipantData(name, finalscore);
    }
    else if (input == 'E' || input == 'e')
    {
        return 0;
    }
    else
    {
        clearScreen();
        printf("Invalid input");
    }
    return 0;
   storeParticipantData(name, finalscore);
}


int generalKnowledge()
{
    clearScreen();
    printf("WHICH LEVEL YOU WANT TO TRY\nFOR LEVEL 1 TYPE 1.\nFOR LEVEL 2 TYPE 2.\n");
    scanf("%d", &level);
    clearScreen();
    int score = 0;
    char option;
    time_t startTime, endTime;
    if (level == 1)
    {
        clearScreen();
        printf("General Knowledge:\n");
        printf("Q1- Which planet is known as the 'Red Planet'?\n");
        printf("a) Venus\nb) Mars\nc) Jupiter\nd) Saturn\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'b' || option == 'B') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }
        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }
        printf("General Knowledge:\n");
        printf("Q2- Who painted the famous artwork \"Mona Lisa\"?\n");
        printf("a) Leonardo da Vinci\nb) Vincent van Gogh\nc) Pablo Picasso\nd) Michelangelo\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("General Knowledge:\n");
        printf("Q3- Which is the largest ocean on Earth?\n");
        printf("a) Pacific Ocean\nb) Atlantic Ocean\nc) Indian Ocean\nd) Arctic Ocean\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            printf("\a");
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("General Knowledge:\n");
        printf("Q4- Who invented the telephone?\n");
        printf("a) Alexander Graham Bell\nb) Thomas Edison\nc) Isaac Newton\nd) Albert Einstein\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            printf("\a");
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("General Knowledge:\n");
        printf("Q5- What is the largest organ in the human body?\n");
        printf("a) Liver\nb) Heart\nc) Brain\nd) Skin\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'd' || option == 'D') && difftime(endTime, startTime) <= 10)
        {
            score++;
            printf("\a");
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("General Knowledge:\n");
        printf("Q6- Which country is famous for the Taj Mahal?\n");
        printf("a) India\nb) China\nc) Egypt\nd) Brazil\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("We will proceed to the next question.\n");
            }
        }


        printf("General Knowledge:\n");
        printf("Q7- Who wrote the play 'Romeo and Juliet'?\n");
        printf("a) William Shakespeare\nb) Mark Twain\nc) Charles Dickens\nd) Jane Austen\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("General Knowledge:\n");
        printf("Q8- What is the chemical symbol for the element gold?\n");
        printf("a) Au\nb) Ag\nc) Fe\nd) Cu\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        return score;
        clearScreen();
    }
    if (level == 2)
    {
        clearScreen();
        printf("General Knowledge:\n");
        printf("Q1- Which country is the largest producer of coffee in the world?\n");
        printf("a) Brazil\nb) Colombia\nc) Vietnam\nd) Ethiopia\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("General Knowledge:\n");
        printf("Q2- Which country is famous for its tulips and windmills?\n");
        printf("a) Italy\nb) Germany\nc) Netherlands\nd) France\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'c' || option == 'C') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("General Knowledge:\n");
        printf("Q3- Who is the author of the Harry Potter book series?\n");
        printf("a) J.R.R. Tolkien\nb) J.K. Rowling\nc) Stephen King\nd) George R.R. Martin\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'b' || option == 'B') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("General Knowledge:\n");
        printf("Q4- Which famous scientist developed the theory of evolution by natural selection?\n");
        printf("a) Charles Darwin\nb) Albert Einstein\nc) Isaac Newton\nd) Marie Curie\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }
        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("General Knowledge:\n");
        printf("Q5- Which city hosted the 2016 Summer Olympics?\n");
        printf("a) Beijing, China\nb) London, United Kingdom\nc) Rio de Janeiro, Brazil\nd) Sydney, Australia\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'c' || option == 'C') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }
        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("General Knowledge:\n");
        printf("Q6- Which planet is known as the 'Morning Star' or 'Evening Star'?\n");
        printf("a) Venus\nb) Mars\nc) Mercury\nd) Jupiter\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("General Knowledge:\n");
        printf("Q7- Which country is home to the famous ancient monument Stonehenge?\n");
        printf("a) England\nb) Scotland\nc) Ireland\nd) Wales\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("General Knowledge:\n");
        printf("Q8- Which country is known as the 'Land of the Rising Sun'?\n");
        printf("a) China\nb) South Korea\nc) Japan\nd) Thailand\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'c' || option == 'C') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }
    }
    return score;
    clearScreen();
}
int history()
{
    clearScreen();
    printf("WHICH LEVEL YOU WANT TO TRY\nFOR LEVEL 1 TYPE 1.\nFOR LEVEL 2 TYPE 2.\n");
    scanf("%d", &level);
    clearScreen();
    int score = 0;
    char option;
    time_t startTime, endTime;


    if (level == 1)
    {
        clearScreen();
        printf("History:\n");
        printf("Q1- Who was the first President of the United States?\n");
        printf("a) George Washington\nb) Abraham Lincoln\nc) Thomas Jefferson\nd) Benjamin Franklin\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("History:\n");
        printf("Q2- In which year did World War II end?\n");
        printf("a) 1945\nb) 1939\nc) 1918\nd) 1941\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("History:\n");
        printf("Q3- Who is known as the 'Father of the Indian Nation'?\n");
        printf("a) Mahatma Gandhi\nb) Jawaharlal Nehru\nc) Subhash Chandra Bose\nd) Bhagat Singh\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("History:\n");
        printf("Q4- In which year did Christopher Columbus discover America?\n");
        printf("a) 1492\nb) 1776\nc) 1588\nd) 1620\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("History:\n");
        printf("Q5- Who was the first woman to win a Nobel Prize?\n");
        printf("a) Marie Curie\nb) Mother Teresa\nc) Amelia Earhart\nd) Rosa Parks\n");


        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("History:\n");
        printf("Q6- Who was the first Prime Minister of Great Britain?\n");
        printf("a) Robert Walpole\nb) Winston Churchill\nc) Margaret Thatcher\nd) Tony Blair\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("History:\n");
        printf("Q7- Which famous scientist developed the theory of relativity?\n");
        printf("a) Albert Einstein\nb) Isaac Newton\nc) Galileo Galilei\nd) Nikola Tesla\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("History:\n");
        printf("Q8- What was the ancient capital of Japan?\n");
        printf("a) Kyoto\nb) Tokyo\nc) Osaka\nd) Hiroshima\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        return score;
        clearScreen();
    }
    if (level == 2)
    {
        clearScreen();
        printf("History:\n");
        printf("Q1- Which country was ruled by Adolf Hitler during World War II?\n");
        printf("a) Germany\nb) Italy\nc) Japan\nd) Russia\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("History:\n");
        printf("Q2- The Maurya Empire was established by which ruler?\n");
        printf("a) Ashoka\nb) Chandragupta Maurya\nc) Samudragupta\nd) Harsha\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'b' || option == 'B') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("History:\n");
        printf("Q3- Who is known as the Iron Man of India for his pivotal role in the integration of princely states into the Indian Union?\n");
        printf("a) Jawaharlal Nehru\nb) Sardar Vallabhbhai Patel\nc) Bhimrao Ambedkar\nd) Mohandas Gandhi\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'b' || option == 'B') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("History:\n");
        printf("Q4- The partition of India in 1947 led to the creation of which country?\n");
        printf("a) India and Sri Lanka\nb) India and Nepal\nc) India and Bangladesh\nd) India and Pakistan\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'd' || option == 'D') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("History:\n");
        printf("Q5- The ancient university of Nalanda, known for its Buddhist teachings, was located in present-day:\n");
        printf("a) Bihar\nb) Uttar Pradesh\nc) Madhya Pradesh\nd) Gujarat\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("History:\n");
        printf("Q6- Which Indian leader famously led the Salt March as a part of the civil disobedience movement?\n");
        printf("a) Jawaharlal Nehru\nb) Mahatma Gandhi\nc) Subhas Chandra Bose\nd) Bhimrao Ambedkar\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'b' || option == 'B') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("History:\n");
        printf("Q7- Who was the first Indian astronaut to travel into space?\n");
        printf("a) Kalpana Chawla\nb) Rakesh Sharma\nc) Sunita Williams\nd) Abdul Kalam\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'b' || option == 'B') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("History:\n");
        printf("Q8- Who was the first woman to receive the Bharat Ratna, India's highest civilian award?\n");
        printf("a) Mother Teresa\nb) Indira Gandhi\nc) Sarojini Naidu\nd) M.S. Subbulakshmi\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'd' || option == 'D') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        return score;
        clearScreen();
    }
}
int geography()
{
    clearScreen();
    printf("WHICH LEVEL YOU WANT TO TRY\nFOR LEVEL 1 TYPE 1.\nFOR LEVEL 2 TYPE 2.\n");
    scanf("%d", &level);
    clearScreen();
    int score = 0;
    char option;
    time_t startTime, endTime;


    if (level == 1)
    {
        clearScreen();
        printf("Geography:\n");
        printf("Q1- Which is the longest river in the world?\n");
        printf("a) Nile River\nb) Amazon River\nc) Yangtze River\nd) Mississippi River\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("Geography:\n");
        printf("Q2- Which country is known as 'The Land of the Rising Sun'?\n");
        printf("a) Japan\nb) China\nc) South Korea\nd) Thailand\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("Geography:\n");
        printf("Q3- Mount Everest, the highest peak in the world, is located in which mountain range?\n");
        printf("a) Himalayas\nb) Andes\nc) Alps\nd) Rockies\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("Geography:\n");
        printf("Q4- Which is the largest desert in the world?\n");
        printf("a) Sahara Desert\nb) Gobi Desert\nc) Kalahari Desert\nd) Arabian Desert\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }


        printf("Geography:\n");
        printf("Q5- What is the capital of Australia?\n");
        printf("a) Canberra\nb) Sydney\nc) Melbourne\nd) Brisbane\n");


        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);


        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }


        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }
            printf("Geography:\n");
printf("Q6 - The city of Istanbul is located in which two continents?\n");
printf("a) Europe and Asia\nb) Europe and Africa\nc) Asia and Africa\nd) Europe and Australia\n");


startTime = time(NULL);
scanf(" %c", &option);
endTime = time(NULL);


if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
{
    score++;
    clearScreen();
}
else if (option == 'l')
{
    M++;
    if (M == 1)
    {
        score = score + changeQuestion();
        clearScreen();
    }
    if (M != 1)
    {
        printf("You have already used the lifeline\n");
        printf("We will proceed to the next question.\n");
    }
}
    printf("Geography:\n");
printf("Q7 - Which country is known as the 'Land of the Midnight Sun'?\n");
printf("a) Norway\nb) Canada\nc) Sweden\nd) Russia\n");


startTime = time(NULL);
scanf(" %c", &option);
endTime = time(NULL);


if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
{
    score++;
    clearScreen();
}
else if (option == 'l')
{
    M++;
    if (M == 1)
    {
        score = score + changeQuestion();
        clearScreen();
    }
    if (M != 1)
    {
        printf("You have already used the lifeline\n");
        printf("We will proceed to the next question.\n");
    }
}
printf("Geography:\n");
printf("Q8 - The Great Barrier Reef, the world's largest coral reef system, is located off the coast of which country?\n");
printf("a) Australia\nb) Indonesia\nc) Mexico\nd) Brazil\n");


startTime = time(NULL);
scanf(" %c", &option);
endTime = time(NULL);


if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
{
    score++;
    clearScreen();
}
else if (option == 'l')
{
    M++;
    if (M == 1)
    {
        score = score + changeQuestion();
        clearScreen();
    }
    if (M != 1)
    {
        printf("You have already used the lifeline\n");
        printf("We will proceed to the next question.\n");
    }
}


 }


        if (level == 2)
        {
            printf("Geography:\n");
        printf("Q1- Which country is known as the 'Land of Lakes'?\n");
        printf("a) Canada\nb) Finland\nc) Sweden\nd) New Zealand\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);




        if ((option == 'b' || option == 'B') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }




        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }




        printf("Geography:\n");
        printf("Q2- Which is the wettest place in India, known for its high annual rainfall?\n");
        printf("a) Mawsynram\nb) Cherrapunji\nc) Agumbe\nd) Mahabaleshwar\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);




        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }




        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }




        printf("Geography:\n");
        printf("Q3- Which city is located on the banks of the River Ganges?\n");
        printf("a) Varanasi\nb) Lucknow\nc) Patna\nd) Kanpur\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);




        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }




        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }




        printf("Geography:\n");
        printf("Q4- Which state in India is known as the 'Land of the Gods'?\n");
        printf("a) Himachal Pradesh\nb) Uttarakhand\nc) Jammu and Kashmir\nd) Sikkim\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);




        if ((option == 'b' || option == 'B') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }




        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }




        printf("Geography:\n");
        printf("Q5- Which is the largest freshwater lake in India?\n");
        printf("a) Dal Lake\nb) Chilika Lake\nc) Vembanad Lake\nd) Wular Lake\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);




        if ((option == 'd' || option == 'D') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }




        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }




        printf("Geography:\n");
        printf("Q6- Which union territory of India is an archipelago comprising 36 islands?\n");
        printf("a) Andaman and Nicobar Islands\nb) Lakshadweep\nc) Daman and Diu\nd) Puducherry\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);




        if ((option == 'b' || option == 'B') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }




        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }




        printf("Geography:\n");
        printf("Q7- Which is the longest beach in India?\n");
        printf("a) Marina Beach\nb) Puri Beach\nc) Varkala Beach\nd) Radhanagar Beach\n");
        startTime = time(NULL);
        scanf(" %c", &option);
        endTime = time(NULL);




        if ((option == 'a' || option == 'A') && difftime(endTime, startTime) <= 10)
        {
            score++;
            clearScreen();
        }
        else if (option == 'l')
        {
            M++;
            if (M == 1)
            {
                score = score + changeQuestion();
                clearScreen();
            }
            if (M != 1)
            {
                printf("You have already used the lifeline\n");
                printf("we will proceed to the next question.\n");
            }
        }




        return score;
        clearScreen();
    }


}
