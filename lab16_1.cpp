#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *p,int N, int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << p[i];
        if((i+1)%M==0) cout << endl;
        else cout << " ";
    }
}

void randData(double *p, int N, int M){
    for(int i = 0; i < N*M; i++){
        p[i] = static_cast<double>(rand()) / RAND_MAX;
    }
}

void findRowSum(const double *a,double *b,int x,int y){
    
    for(int i = 0; i<x ; i++){
        double sum = 0 ;
        for(int j = 0; j<y ; j++){
            sum += a[i * y + j];
        }
        b[i] = sum ;
    }
}

void findColSum(const double *a,double *b,int x,int y){
    
   
    for(int i = 0; i<y ; i++){
        double sum = 0 ;
        for(int j = 0; j<x ; j++){
            sum += a[j * y + i];
        }
        b[i] = sum ;
    }
    
    
    
}