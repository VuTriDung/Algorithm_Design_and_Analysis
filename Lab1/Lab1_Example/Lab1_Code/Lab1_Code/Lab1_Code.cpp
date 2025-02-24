#include <iostream>
using namespace std;
int N;
int X[50];
int K;
int arrUsed[50];

void printResultBin()
{
	for (int i = 1; i <= N; i++)
	{
		cout << X[i];
	}
}

void generateBin(int i)
{
	for (int j = 0; j <= 1; j++)
	{
		X[i] = j;
		if (i == N)
		{
			printResultBin();
			cout << endl;
		}
		else
		{
			generateBin(i + 1);
		}
	}
}
void printResultComb()
{
	for (int i = 1; i <= K; i++)
	{
		cout << X[i];
	}
}

void generateCombination(int i)
{
	for (int j = X[i - 1] + 1; j <= N - K + i; j++)
	{
		X[i] = j;
		if (i == K)
		{
			printResultComb();
			cout << endl;
		}
		else
		{
			generateCombination(i + 1);
		}
	}
}
void printResultPer()
{
	for (int i = 1; i <= N; i++)
	{
		cout << X[i];
	}
}

void generatePerComb(int i)
{
	for (int j = 1; j <= N; j++)
	{
		if (arrUsed[j] == 0)
		{
			X[i] = j;
			arrUsed[j] = 1;
			if (i == N)
			{
				printResultPer();
				cout << endl;
			}
			else
			{
				generatePerComb(i + 1);
			}
			arrUsed[j] = 0;
		}
	}
}
void handleOption(int choice)
{
	switch (choice)
	{
	case 1:
		generateBin(1);
		break;
	case 2:
		generateCombination(1);
		break;
	case 3:
		generatePerComb(1);
		break;
	default:
		std::cout << "Invalid choice. Please try again.\n";
		break;
	}
}

int main()
{
	cout << "N=";
	cin >> N;
	cout << endl;
	cout << "K=";
	cin >> K;
	cout << endl;
	int choice = 0;
	do
	{
		cout << "1: Nhi phan" << endl;
		cout << "2: To hop chap K cua N" << endl;
		cout << "3: Hoan vi" << endl;
		cout << "Vui long chon: ";
		cin >> choice;
		handleOption(choice);

	} while (choice < 1 || choice > 4);

	return 0;
}