// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Project 1 - Problem # 4-7
#include <iostream>
#include <string>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Question 4 - calcSimScore
double calcSimScore(string fs, string ss)
{
    double fsLength = fs.length();
    double ssLength = ss.length();
    double length = (fsLength + ssLength) / 2;
    
    double hamming_distance = 0;
    double similarity_score;

    // Checks if first string length equals second string length and that both strings does not equal zero
    if(fsLength == ssLength && fsLength != 0 && ssLength != 0)
    {
        
        //Checks each character in each string if they match, if they don't hamming_ds increase by 1
        for(double x = 0; x <= length; x++)
        {
            if(fs[x] != ss[x])
            {
                hamming_distance += 1;
            }
        }
        //similarity score is calculated ranging from 0 to 1
        similarity_score = (length - hamming_distance) / length;
    }
    else
    {
        similarity_score = 0;
    }
    return similarity_score;
}

////////////////////////////////////////////////////////////////////////////////
// Question 5 - findBestSimScore
double findBestSimScore(string genome, string sequence)
{
    double sequenceLength = sequence.length();
    double genomeLength = genome.length();
    double bestScore = 0;

    if(sequenceLength > genomeLength)
    {
        //The sequence length is bigger than the genome length. We need to have sequence length smaller than genome length for comparison
        return 0;
    }
    else
    {
        //Determines how many times to iterate for a genome sub
        for(int i = 0; i <= (genomeLength - sequenceLength); i++)
        {
            string subGenome = genome.substr(i, sequenceLength);
            double compare = calcSimScore(subGenome, sequence);
            //Determines if the previous bestscore is better than the new comparison score
            if(compare > bestScore)
            {
                bestScore = compare;
            }
        }
        return bestScore;
    }
}

////////////////////////////////////////////////////////////////////////////////
// Question 6 - findMatchedGenome
void findMatchedGenome(string genome1, string genome2, string genome3, string sequence)
{
    int genomeL1 = genome1.length();
    int genomeL2 = genome2.length();
    int genomeL3 = genome3.length();
    int sequenceL = sequence.length();

    string bestMatch;
    //Checks if any genome or sequence is empty
    if(genomeL1 == 0 || genomeL2 == 0 || genomeL3 == 0 || sequenceL == 0)
    {
        cout << "Genomes or sequence is empty." << endl;
    }
    //Checks if all genomes are the same length
    else if(genomeL1 != genomeL2 || genomeL1 != genomeL3 || genomeL2 != genomeL3)
    {
        cout << "Lengths of genomes are different." << endl;
    }
    //Determines the best similarity
    else
    {
        //Calls the function findBestSimScore to calculate the best score, matched by the sequence on a genome
        double compare1 = findBestSimScore(genome1, sequence);
        double compare2 = findBestSimScore(genome2, sequence);
        double compare3 = findBestSimScore(genome3, sequence);

        //Compares which genome is better
        if(compare1 >= compare2 && compare1 >= compare3)
        {
            cout << "Genome 1 is the best match." << endl;
        }
        if(compare2 >= compare1 && compare2 >= compare3)
        {
            cout << "Genome 2 is the best match." << endl;
        }
        if(compare3 >= compare1 && compare3 >= compare2)
        {
            cout << "Genome 3 is the best match." << endl;
        }

    }
}

////////////////////////////////////////////////////////////////////////////////
// Problem 7 -- Menu
int main()
{
    int userInput;
    string fs, ss;
    string genome, sequence;
    string genome1, genome2, genome3;
    double score;
    do
    {
        cout << "Select a numerical option:" << endl << "=== menu ===" << endl;
        cout << "1. Find similarity score" << endl;
        cout << "2. Find the best similarity score" << endl;
        cout << "3. Analyze the genome sequences" << endl;
        cout << "4. Quit" << endl;
        cin >> userInput;

        if(userInput == 1 || userInput == 2 || userInput == 3)
        {
            switch(userInput)
            {
                case 1:
                    
                    cout << "Enter sequence 1: " << endl;
                    cin >> fs;
                    cout << "Enter sequence 2: " << endl;
                    cin >> ss;
        
                    score = calcSimScore(fs, ss);
                    cout << "Similarity score: " << score << endl;
                    break;
                case 2:
                    
                    cout << "Enter genome: " << endl;
                    cin >> genome;
                    cout << "Enter sequence: " << endl;
                    cin >> sequence;
        
                    score = findBestSimScore(genome, sequence);
                    cout << "Best similarity score: " << score << endl;
                    break;
                case 3:
                    cout << "Enter genome 1:" << endl;
                    cin >> genome1;
                    cout << "Enter genome 2:" << endl;
                    cin >> genome2;
                    cout << "Enter genome 3:" << endl;
                    cin >> genome3;
                    cout << "Enter sequence:" << endl;
                    cin >> sequence;

                    findMatchedGenome(genome1, genome2, genome3, sequence);

                    break;

            }
        }
        else if(userInput == 4)
        {
            cout << "Good bye!" << endl;
        }
        else
        {
            cout << "Invalid option." << endl;
        }
    }while(userInput != 4);

    
    return 0;
}