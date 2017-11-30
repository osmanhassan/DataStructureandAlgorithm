#include<iostream>
using namespace std;
class mystack{
public:
    int n;
	int top;
	mystack(){
		top = -1;
		cout << "how many values you want to push" << endl;
		cin>>n;
	}
	int arr[10];
	void push(int value){
		{
			if (top < n-1)
			{
				top++;
				arr[top] = value;
			}
			else
			{
				cout << "Cannot push, Stack Full" << endl;
			}
		}
	}
	void pop()
	{
		if (top == -1)
		{
			cout << "Cannot pop, Stack Empty" << endl;
		}
		else
		{
			top--;
		}
	}
	void topelement(){
		{
			cout << "top element is : " << arr[top] << endl;
			cout << "Current Stack: "<<endl;
			for (int i = top; i >= 0; i--)
			{
				cout << arr[i] << "  ";
			}
			cout << endl;
		}
	}

};

void main(){
	mystack s;
	s.push(1);
	s.topelement();
	s.push(2);
	s.topelement();
	s.push(3);
	s.topelement();
	s.push(4);
	s.topelement();
	s.push(5);
	s.topelement();
	s.push(6);
	s.topelement();
	s.push(7);
	s.topelement();
	s.push(8);
	s.topelement();
	s.push(9);
	s.topelement();
	s.push(10);
	s.topelement();
	s.push(11);
	
	s.topelement();
	

}