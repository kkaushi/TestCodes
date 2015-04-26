#include<iostream>
#include<fstream>
using namespace std;


int main(){
	fstream fs;
	//simple open
	//fs.open("kk_1.txt", fstream::in | fstream::out|fstream::app );
	fs.open("kk_1.txt", fstream::out);
	//write to file
	fs << "Hello There!";
	//close file here
	fs.close();

	//open to append
	fs.open("kk_1.txt", fstream::app);
	fs << "\nAgain!";
	fs.close();

	//read the file now
	//I CHAR BY CHAR
	fs.open("kk_1.txt", fstream::in);
	char c;
	while (fs.get(c))
		cout << c;
	cout << endl;
	fs.close();
	
	//II read complete file at once
	fs.open("kk_1.txt", fstream::in);
	fs.seekg(0, fs.end);//set pointer to end
	int length = fs.tellg();//get length
	fs.seekg(0, fs.beg);//set pointer to beg again
	char *buffer = new char[length];
	fs.read(buffer, length);
	for (int i = 0; i < length; i++)
		cout << buffer[i];
	cout << endl;
	delete[] buffer;
	fs.close();
	return 0;
}