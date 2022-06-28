#include <iostream>
using namespace std;
int MatrixMultiplicationChains(int *p, int a, int b)
{
	if (a == b)
		return 0;
	int m = INT_MAX;
	for (int i = a; i < b; i++)
	{
		m = min((MatrixMultiplicationChains(p, a, i) + MatrixMultiplicationChains(p, i + 1, b) + p[a - 1] * p[i] * p[b]) , m);
	}

	return m;
}

int main()
{
	int n;
	cout<<"Enter the no. of matrices: "; cin>>n;
	int *arr=new int [n+1];
	cout<<"Enter the dimensions of each matrix:"<<endl;
	int d1,d2;
	int z=0;
	for(int i=0;i<n;i++)
    {
        cout<<"Enter the dimension of matrix "<<i+1<<" : ";
        cin>>d1>>d2;
        if(i!=0)
        {
            if(d1 != arr[z-1]){
                cout<<"Multiplication is not possible"<<endl;
                exit(0);
            }
            else{
                arr[z++]=d2;
            }
        }
        else{
            arr[z++]=d1;
            arr[z++]=d2;
        }
    }
    cout<<"Array of unique dimensions used for finding matrix multiplication chains is:"<<endl;
    for(int i=0;i<=n;i++)
        cout<<arr[i]<<" ";
	cout << "\nMinimum number of multiplications is "
		<< MatrixMultiplicationChains(arr, 1, n);
}


