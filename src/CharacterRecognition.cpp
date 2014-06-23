//CharacterRecognition.cpp

#include "CharacterRecognition.h"

#include <cmath>
#include <string>
#include <fstream>

using namespace std;

CharacterRecognition *CharacterRecognition::instance = 0;

CharacterRecognition::CharacterRecognition()
{
}

CharacterRecognition* CharacterRecognition::Instance()
{
	if (instance == 0)
	{
		instance = new CharacterRecognition;
	}
	return instance;
}

void CharacterRecognition::matrixMultiple(double matrix1[], double matrix2[], double matrix3[], int x, int y, int z)
{
	for(int i = 0; i < x; i ++)
	{
		for(int j = 0; j < z; j++)
		{
			matrix3[i*z+j] = 0;
			for(int k = 0; k < y; k++)
			{
				matrix3[i*z+j] += matrix1[i*y+k] * matrix2[k*z+j];
			}
		}
	}
}

int CharacterRecognition::maxIndex(double array[], int n)
{
	int index = 0;
	double maxElement = array[0];
	for(int i = 1; i < n; i++)
	{
		if(array[i] > maxElement)
		{
			maxElement = array[i];
			index = i;
		}
	}
	return index;
}

void CharacterRecognition::sigmoid(double input[], double output[], int n)
{
	for(int i = 0; i < n; i++)
	{
		output[i] = 1.0 / ( 1.0 + exp(-input[i]) );
	}
}

void CharacterRecognition::readTheta()
{
	ifstream inputTheta1("theta1", ios::in);
	ifstream inputTheta2("theta2", ios::in);

	string str;
	for(int i = 0; i < 5; i++)
	{
		getline(inputTheta1, str);
	}

	for(int i = 0; i < theta1RowNumber; i++)
	{
		for(int j = 0; j < theta1ColumnNumber; j++)
		{
			inputTheta1 >> theta1[i*theta1ColumnNumber+j];
		}
	}

	for(int i = 0; i < 5; i++)
	{
		getline(inputTheta2, str);
	}

	for(int i = 0; i < theta2RowNumber; i++)
	{
		for(int j = 0; j < theta2ColumnNumber; j++)
		{
			inputTheta2 >> theta2[i*theta2ColumnNumber+j];
		}
	}

	inputTheta1.close();
	inputTheta2.close();

  //testReadTheta();
	//testRecognize();

}

int CharacterRecognition::recognize(int vec[arrayDimension])
{
	double inputVec[arrayDimension+1];
	inputVec[0] = 1;
	for(int i = 1; i < arrayDimension+1; i++)
	{
		inputVec[i] = vec[i-1];
	}

  double tempMatrix1[theta1RowNumber*1];
	matrixMultiple(theta1, inputVec, tempMatrix1, theta1RowNumber, theta1ColumnNumber, 1);

	double tempMiddleVec[theta1RowNumber];
	sigmoid(tempMatrix1, tempMiddleVec, theta1RowNumber);

	double middleVec[theta1RowNumber+1];
	middleVec[0] = 1;
	for(int i = 1; i < theta1RowNumber+1; i++)
	{
		middleVec[i] = tempMiddleVec[i-1];
	}

  double tempMatrix2[theta2RowNumber*1];
	matrixMultiple(theta2, middleVec, tempMatrix2, theta2RowNumber, theta2ColumnNumber, 1);

	double outputVec[theta2RowNumber];
	sigmoid(tempMatrix2, outputVec, theta2RowNumber);

	int index = maxIndex(outputVec, theta2RowNumber);

  return index;

}

void CharacterRecognition::testReadTheta()
{
	ofstream outputTheta1("outputTheta1", ios::out);
	ofstream outputTheta2("outputTheta2", ios::out);

	for(int i = 0; i < theta1RowNumber; i++)
	{
		for(int j = 0; j < theta1ColumnNumber; j++)
		{
			outputTheta1 << theta1[i*theta1ColumnNumber+j];
		}
	}

	for(int i = 0; i < theta2RowNumber; i++)
	{
		for(int j = 0; j < theta2ColumnNumber; j++)
		{
			outputTheta2 << theta2[i*theta2ColumnNumber+j];
		}
	}

  outputTheta1.close();
	outputTheta2.close();

}

void CharacterRecognition::testRecognize()
{
	ifstream input("0", ios::in);

	int array[arrayDimension];

	for(int t = 0; t < 50; t++)
	{
		for(int i = 0; i < arrayDimension; i++)
		{
			input >> array[i];
			int result = recognize(array);
		}
	}

  input.close();
}



