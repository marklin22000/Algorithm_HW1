#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <unistd.h>
#include <sys/resource.h>
using namespace std;

int num;
int digit = 0;
long long factor = 10^digit;

void swap(long long *x,long long *y)
{
	long long temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void printarray(long long *a)
{
	for (int ii = 0; ii < num-1; ii++)		
			cout << a[ii] << " -> ";
		cout<< a[num-1]<<endl;
}

void quicksort(int p, long long *a, int l, int r)
{
	long long x;
	int i;
	int j;
	long long d = factor^(p);
	if(l<r)
	{
		x = (a[r]/d)%factor;
		i = l-1;
		for(j=l; j<r;j++)
		{
			if( (a[j]/d)%factor <= x)
			{
				i++;
				swap(&a[i],&a[j]);
			}
		}
		swap(&a[i+1],&a[r]);
		printarray(a);
		quicksort(p,a,l,i);
		quicksort(p,a,i+2,r);
	}
}

void sort(int num,long long *a){

	int looptime = 1;
	int loopcount = 0;
	while(loopcount<looptime)
	{
		quicksort(loopcount,a,0,num-1);
		loopcount++;
	}
}

int main(int argc, char* argv[]){
	/* Input check */
	if (argc < 3){
		cout << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
		return -1;
	}
	
	/* File check */
	ifstream ifs(argv[1]);
	if (!ifs.is_open()){
		cout << "Input file: " << argv[1] << " cannot be opened." << endl;
		return -1;
	}
	
	ofstream ofs(argv[2]);
	if (!ofs.is_open()){
		cout << "Output file: " << argv[2] << " cannot be opened." << endl;
		return -1;
	}
	
	/* Input data from the file */
	
	ifs >> num;
	long long a[num];
	int i=0;
	while (!ifs.eof()){
		long long tmp_num;
		ifs >> tmp_num;
		a[i] = tmp_num;
		i++;
	}
	ifs.close();
	
	
	/* Function */
	
	const clock_t start_time = clock();
	sort(num,a);
	double run_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;

	struct rusage r_usage;
	getrusage(RUSAGE_SELF,&r_usage);
	printf("Memory usage: %ld k-bytes\n",r_usage.ru_maxrss);
	
	cout << "=====  Answer Report  =====" << endl;
	cout << "CPU Run time: " << run_time << endl;
	cout << "Mem Usage:    " << r_usage.ru_maxrss << endl;
	cout << "ans: ";
	printarray(a);
	
	
	
	ofs << "=====  Answer Report  =====" << endl;
	ofs << "CPU Run time: " << run_time << endl;
	ofs << "Mem Usage:    " << r_usage.ru_maxrss << endl;
	ofs << "ans: ";
	for (int i = 0; i < num; i++)		
		ofs << a[i] << " -> ";
		
	ofs.close();
	
	return 0;
}
