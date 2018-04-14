#include <ctime>
#include <unistd.h>
#include <sys/resource.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>   /* rand(), srand(), RAND_MAX */
#include <time.h>     /* time(), clock()           */
using namespace std;
long long num = pow(10,8);
int main(int argc, char* argv[])
{
	long long i;
	unsigned long long temp;
	srand( time(NULL) );

	ofstream ofs(argv[1]);
	ofs << num << endl;
	for( i = 0; i < num; i++)
	{
		temp = rand()*rand();
		ofs << temp <<" " << endl;
	}    
	return 0;
}