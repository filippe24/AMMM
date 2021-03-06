#ifndef BRKGA_H
#define BRKGA_H

#include <vector>
#include <iostream>
#include <boost/any.hpp>
using namespace std;

//template <typename T>
struct Individual {

//public:

	vector<float> chromosome;
	float fitness;
	vector<boost::any> solution;

};

class BRKGA {	

public:
	
	vector<Individual> Population;
	int numIndividuals; 
	int chrLength;

	void initializePopulation(int numIndividuals, int chrLength);
	void createPopulation(vector<Individual> elite, vector<Individual> crossover, vector<Individual> mutants);
	vector< vector<Individual> > classifyIndividuals(int numElite);
	vector<Individual> generateMutantIndividuals(int numMutants, int chrLength);
	vector<Individual> doCrossover(vector<Individual> elite, vector<Individual> nonElite, float ro, int numCrossover);
	Individual getBestFitness();
	vector<float> createChromosomeFromSolution(vector<float> inputSolution, int nNurses, int totalHours);

	//bool compareByFitness(const Individual &a, const Individual &b);
	void printPopulation();
	void printIndividual(Individual ind);
	void printIndividualSolution(Individual ind);
	void printIndividualFitness(Individual ind);
};

#endif
