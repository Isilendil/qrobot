//CharacterRecognition.h
//class CharacterRecognition

#ifndef _CHARACTERRECOGNITION_H_
#define _CHARACTERRECOGNITION_H_

#include "common.h"


class CharacterRecognition
{
public:
  static CharacterRecognition* Instance();

  int recognize(int vec[]);
	void readTheta();

	void testReadTheta();
	void testRecognize();

protected:
  CharacterRecognition();

private:
  static CharacterRecognition *instance;

  //matrix3 = matrix1 * matrix2
	void matrixMultiple(double matrix1p[], double matrix2[], double matrix3[], int x, int y, int z);
  
	int maxIndex(double array[], int n);

	//sigmoid(x) = 1 / (1 + exp(-x) )
	void sigmoid(double input[], double output[], int n);

	static const int arrayDimension = 1024;

	//隐藏层行数
	static const int theta1RowNumber = 70;
	//隐藏层列数
	static const int theta1ColumnNumber = 1025;
	//输出层行数
	static const int theta2RowNumber = 10;
	//输出层列数
	static const int theta2ColumnNumber = 71;

	double theta1[theta1RowNumber*theta1ColumnNumber];
	double theta2[theta1RowNumber*theta1ColumnNumber];

	//int vec[arrayDimension];
};

#endif

