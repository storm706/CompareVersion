//This program will allow you to determine which version is newer.
//You can also compare versions with any number of points.
#include <iostream>
#include <string>
using namespace std;

int CountOfPoint(const string &a)
{
	int count = 0;
for (int i=0;i<a.size();i++)
	{
	if (a[i] == '.')
		count++;
	}
return count;
}

void PassToFloatArray(float *array ,const string&a,const int sizeForFloat, const int sizeForString)
{
	string temp;
	int j = 0;
	
	for (int i = 0; i < sizeForFloat; i++)
	{
		for (j; a[j] != '.' && j != sizeForString; j++)//if (j == a.size()) break;
		{
			if (a[0] == '0')
				temp = "0.";
			else
				temp = temp + a[j];
		}
		array[i] = stof(temp); 
		temp = "";		//clear string value
		j++;			// to skip the value "."
	}
}

void OutputArray(const float a[],const int &size)
 {
	 for (int i = 0; i < size; i++)
	 {
		 cout << i << " #\t" <<a[i]<<endl;
	 }
	 cout << endl;
 }

void Compare(float *array, float *array2,const int&size,const int&size2)
{
	bool change = false;	 //variable to check the event
	int LessSize;		// border of address space for the cycle
	
	if (size > size2)		
		LessSize = size2;
	else
		LessSize = size;
	for (int i = 0; i < LessSize; i++)
	{
		if (array[i] > array2[i])
		{
			cout << "Version_B is older" << endl;//First version newer
			 change = true;						
			 break;
		}
		if (array[i] < array2[i])
		{
			cout << "Version_A is older" << endl;//Second version newer
			change = true;
				break;
		}
	}
	if(change==false)
	{
	if(size>size2)
		cout << "Version_B is older" << endl;
	else
		cout << "Version_A is older" << endl;
	}
}
int main()
{
	string Version_A = "8.1.13.41";
	//string Version_A = "8.3.13.41";	 //for checks
	//string Version_B = "8.1.13.41.01"; 	//for checks
	//string Version_B = "9.1.009.125";	 //for checks
	string Version_B = "8.1.009.125";
	
	
	int countPoint1 = CountOfPoint(Version_A); //creating a variable to store the number of points in a  (string Version_A)
	int countPoint2 = CountOfPoint(Version_B); //creating a variable to store the number of points in a  (string b)
	int Sting_A_Size = countPoint1+1;
	int Sting_B_Size = countPoint2 + 1;
	
	float *array_A = new float[Sting_A_Size];
	float *array_B = new float[Sting_B_Size];
	
	PassToFloatArray(array_A, Version_A, Sting_A_Size, Version_A.size());
	PassToFloatArray(array_B, Version_B, Sting_B_Size, Version_B.size());

	cout << "Version_A : " << Version_A << "\t\tString's size : " << Version_A.size() << "\tValue's size :" << countPoint1 << endl;
	OutputArray(array_A, Sting_A_Size);
	cout << "Version_B : " << Version_B << "\t\tString's size : " << Version_B.size() << "\tValue's size :" << countPoint2 << endl;
	OutputArray(array_B, Sting_B_Size);
	Compare(array_A, array_B, Sting_A_Size, Sting_B_Size);
	
	delete[] array_A;
	delete[] array_B;
	array_A = nullptr;
	array_B = nullptr;
}


