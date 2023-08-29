#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void loadData(int array[][7], int numberOfReviewers);
void chooseMovies(int array[]);
void rateMovies(int array[]);
int closestMatch(int reviewers[][7], int numberOfReviewers, int movieChoices[], int ratings[]);
void predictInterests(int reviewers[][7], int critiqueMatchID, int movieChoices[]);

int main()
{
    const int NUMBER_OF_REVIEWERS = 4, NUMBER_OF_REVIEWS = 7,  NUMBER_OF_MOVIES = 3;;
    int reviewData[NUMBER_OF_REVIEWERS][NUMBER_OF_REVIEWS], userReviewChoices[NUMBER_OF_MOVIES], userRatings[NUMBER_OF_MOVIES];
    int match;
    
    loadData(reviewData, NUMBER_OF_REVIEWERS);
    chooseMovies(userReviewChoices);
    rateMovies(userRatings);
    match = closestMatch(reviewData, NUMBER_OF_REVIEWERS, userReviewChoices, userRatings);

    cout << "\nYour closest match is reviewer " << match << endl;
    predictInterests(reviewData, match, userReviewChoices);

    return 0;
}


void loadData(int array[][7], int numberOfReviewers)
{
    ifstream inputStream;
    inputStream.open("moviescores.txt");

    for(int i=0; i<numberOfReviewers; i++)
    {
        for(int j=0; j< 7; j++)
        {
           inputStream >> array[i][j];
        }
    }

    inputStream.close();

    return;
}
void chooseMovies(int array[])
{
    int counter = 0;
    int movieNumber = 0;
    bool finishedChoosing = false;
    
    
    do
    {
        cout << "Enter a movie number (1 through 6 only): ";
        cin >> movieNumber;
        if(movieNumber > 6 || movieNumber < 1)
        {
            cout << "Must provide a number between 1 and 6.\n";
            continue;
        }

        array[counter] = movieNumber;
        counter++;
        finishedChoosing = true;
    } while (!finishedChoosing);
    
    finishedChoosing = false;

    do
    {
        cout << "Enter your second movie choice: ";
        cin >> movieNumber;
        if(movieNumber > 6 || movieNumber < 1)
        {
            cout << "Must provide a number between 1 and 6." << endl;
            continue;
        }
        else if(movieNumber == array[0])
         {
            cout << "Already selected that film! Choose a different movie." << endl;
            continue;
        }

        array[counter] = movieNumber;
        counter++;
        finishedChoosing = true;
    } while (!finishedChoosing);

    finishedChoosing = false;

    do
    {
        cout << "Enter your third movie choice: ";
        cin >> movieNumber;
        if(movieNumber > 6 || movieNumber < 1)
        {
            cout << "Must provide a number between 1 and 6." << endl;
            continue;
        }
        else if(movieNumber == array[0] || movieNumber == array[1])
         {
            cout << "Already selected that film! Choose a different movie." << endl;
            continue;
        }

        array[counter] = movieNumber;
        counter++;
        finishedChoosing = true;
    } while (!finishedChoosing);
}
void rateMovies(int array[])
{
    int rating = 0, counter = 0;
    bool finishedRating = false;
    do
    {
        cout << "Enter your rating (1 through 5, 5 being the best) for movie #1:";
        cin >> rating;
        if(rating < 1 || rating > 5)
        {
            cout << "Please enter a valid rating, 1 through 5 only!\n";
            continue;
        }
        array[counter] = rating;
        counter++;
        finishedRating = true;
    }while (!finishedRating);

    finishedRating = false;
    do
    {
        cout << "Enter your rating (1 through 5, 5 being the best) for movie #2:";
        cin >> rating;
        if(rating < 1 || rating > 5)
        {
            cout << "Please enter a valid rating, 1 through 5 only!\n";
            continue;
        }
        array[counter] = rating;
        counter++;
        finishedRating = true;
    }while (!finishedRating);

    finishedRating = false;
    do
    {
        cout << "Enter your rating (1 through 5, 5 being the best) for movie #3:";
        cin >> rating;
        if(rating < 1 || rating > 5)
        {
            cout << "Please enter a valid rating, 1 through 5 only!\n";
            continue;
        }
        array[counter] = rating;
        counter++;
        finishedRating = true;
    }while (!finishedRating);

    return;
}
int closestMatch(int reviewers[][7], int numberOfReviewers, int movieChoices[], int ratings[])
{
    int reviewer = -1;
    double distances[4], results[4];
    double sum = 0, minimum;
    
    for (int i = 0; i < numberOfReviewers; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            distances[j]= pow(ratings[j]-reviewers[i][movieChoices[j]], 2);
            sum += distances[j];
        }

        results[i] = sqrt(sum);
        sum = 0;
    }
    
    minimum = results[0];
    for (int i = 0; i < 4; i++)
    {
        if (results[i] <= minimum)
        {
            reviewer = i;
            minimum = results[i];
        }
    }
    return reviewer;
}
void predictInterests(int reviewers[][7], int critiqueMatchID, int movieChoices[])
{
    int movies[6] = {1,2,3,4,5,6};
    
    int skipmovie1 = movieChoices[0], skipmovie2 = movieChoices[1], skipmovie3 = movieChoices[2];

    for (int i = 1; i <=6; i++)
    {
        if(i == skipmovie1 || i == skipmovie2 || i == skipmovie3)
            continue;
        else
        {
            cout << "prediction for movie " << i << " is " << reviewers[critiqueMatchID][i] << endl;
        }
    }
}