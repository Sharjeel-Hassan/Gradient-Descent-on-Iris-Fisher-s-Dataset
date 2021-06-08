#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int datasize = 150;
const int cols = 5;
const double training_rate = 0.001;
int cutoff = 75;

int main()
{
	double** dataset = new double* [datasize];
	ifstream fin;
	fin.open("randomized dataset.txt");
	if (!fin) { cout << "whoops"; }
	for (int i = 0;i < datasize;i++) {
		dataset[i] = new double[cols];
		fin >> dataset[i][0];
		fin >> dataset[i][1];
		fin >> dataset[i][2];
		fin >> dataset[i][3];
		fin >> dataset[i][4];
		cout << dataset[i][0] << " " << dataset[i][1] << " " << dataset[i][2] << " " << dataset[i][3] << " " << dataset[i][4] << endl;
	}
	fin.close();

	double* W = new double[cols];

	double cost = 1000, prevcost = 2000;
	int max_iterations = 0;
	double y, yHat;
	double summation;

	W[0] = 0.00001;
	W[1] = 0.00001;
	W[2] = 0.00002;
	W[3] = 0.00003;
	W[4] = 0.00001;
	while (cost != 0.0 && max_iterations <= 1000) {
		summation = 0;
		for (int i = 0;i < cutoff;i++) {
			yHat = (W[0]) + (W[1] * dataset[i][0]) + (W[2] * dataset[i][1]) + (W[3] * dataset[i][2]) + (W[4] * dataset[i][3]);
			y = dataset[i][4];
			summation += ((y - yHat) * 1.0);
		}
		W[0] = W[0] - (training_rate * (-1) * (summation));

		summation = 0;
		for (int i = 0;i < cutoff;i++) {
			yHat = (W[0]) + (W[1] * dataset[i][0]) + (W[2] * dataset[i][1]) + (W[3] * dataset[i][2]) + (W[4] * dataset[i][3]);
			y = dataset[i][4];
			summation += ((y - yHat) * dataset[i][0]);
		}
		W[1] = W[1] - (training_rate * (-1) * (summation));

		summation = 0;
		for (int i = 0;i < cutoff;i++) {
			yHat = (W[0]) + (W[1] * dataset[i][0]) + (W[2] * dataset[i][1]) + (W[3] * dataset[i][2]) + (W[4] * dataset[i][3]);
			y = dataset[i][4];
			summation += ((y - yHat) * dataset[i][1]);
		}
		W[2] = W[2] - (training_rate * (-1) * (summation));

		summation = 0;
		for (int i = 0;i < cutoff;i++) {
			yHat = (W[0]) + (W[1] * dataset[i][0]) + (W[2] * dataset[i][1]) + (W[3] * dataset[i][2]) + (W[4] * dataset[i][3]);
			y = dataset[i][4];
			summation += ((y - yHat) * dataset[i][2]);
		}
		W[3] = W[3] - (training_rate * (-1) * (summation));

		summation = 0;
		for (int i = 0;i < cutoff;i++) {
			yHat = (W[0]) + (W[1] * dataset[i][0]) + (W[2] * dataset[i][1]) + (W[3] * dataset[i][2]) + (W[4] * dataset[i][3]);
			y = dataset[i][4];
			summation += ((y - yHat) * dataset[i][3]);
		}
		W[4] = W[4] - (training_rate * (-1) * (summation));

		//CALCULATING THE COST OF USING THIS PARTICULAR SET OF WEIGHTS
		summation = 0;
		for (int i = 0;i < cutoff;i++) {
			yHat = (W[0]) + (W[1] * dataset[i][0]) + (W[2] * dataset[i][1]) + (W[3] * dataset[i][2]) + (W[4] * dataset[i][3]);
			y = dataset[i][4];
			summation += (pow((y - yHat), 2));
		}
		prevcost = cost;
		cost = summation * 0.5;
		if (max_iterations % 100 == 0) {
			cout << max_iterations << " : " << fixed << cost << endl;
		}
		max_iterations++;
	}

	//APPLYING TRAINED MODEL ON REST OF DATASET
	int mismatch_count = 0;
	for (int i = cutoff;i < datasize;i++) {
		yHat = (W[0]) + (W[1] * dataset[i][0]) + (W[2] * dataset[i][1]) + (W[3] * dataset[i][2]) + (W[4] * dataset[i][3]);
		//ROUNDING OFF
		if (yHat <= 1.5) { yHat = 1; }
		else if (yHat <= 2.5) { yHat = 2; }
		else { yHat = 3; }
		///////////////
		if (yHat != dataset[i][4]) {
			mismatch_count++;
		}
	}
	cout << mismatch_count << endl;
}
