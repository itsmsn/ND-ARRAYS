#include <iostream>
#include "ndarr.h"
using namespace std;


int main()
{
	cout << "-----------------------------------------ASSUMING BOUNDARY CHECKS ALREADY DONE--------------------------------------";
	cout << "--------------ND ARRAYS---------------\n";
	int size = 0;
	int nd = 0;
	//ndarr arr;

	int dim = 0;
	cout << "ENTER DIMENTIONS OF THE ARRAY : ";
	cin >> dim;

	int temp = 1;
	int* dim_coordinates = new int[dim];
	for (int i = 0; i < dim; i++)
	{
		cout << "ENTER " << i << " COORDINATE OF THE ARRAY : ";
		cin >> dim_coordinates[i];
		temp = temp * dim_coordinates[i];

	}
	cout << endl;
	int choicee = 0;
	cout << "\n1-INT\n2-CHAR\n3-DOUBLE\n4-FLOAT\n";
	cout << "ENTER CHOICE TO SELECT DATA TYPE : "<<endl;
	cin >> choicee;
	if (choicee == 1)
	{
		ndarr <int> ndarras(dim, dim_coordinates, temp);
		cout << "INITIALLY ARRAY IS : \n";
		cout << ndarras;
	//print(size);
	cout << "\n";
	cout << "\n1-INSERT ELEMENT\n2-DELETE ELEMENT\n3-EXTEND ARRAY\n4-SHRINK ARRAY\n5-RETRIVE ELEMENT\n6-PRINT ARRAY\n7-EXIT\n";
	int choice = 0;
	cout << "\nENTER CHOICE : ";
	cin >> choice;
	while (choice != 7) {
		if (choice == 1)
		{
			ndarras.insert();
		}
		else if (choice == 2)
		{
			ndarras.delete_elem();
		}
		else if (choice == 3)
		{
			ndarras.extend();
		}
		else if (choice == 4)
		{
			ndarras.shrink();
		}
		else if (choice == 5)
		{
			ndarras.retrive();
		}
		else if (choice == 6)
		{
			cout << "UPDATED ARRAY IS : \n";
			cout << ndarras;
			cout << "\n";
		}
		else if (choice == 7)
		{
			exit(0);
		}
		else {
			cout << "\nINVALID CHOICE\n";
		}

		cout << "\n1-INSERT ELEMENT\n2-DELETE ELEMENT\n3-EXTEND ARRAY\n4-SHRINK ARRAY\n5-RETRIVE ELEMENT\n6-PRINT ARRAY\n7-EXIT\n";
		cout << "\nENTER CHOICE : ";
		cin >> choice;

	}
	}
	else if(choicee == 2)
	{
		ndarr <char> ndarras(dim, dim_coordinates, temp);
		cout << "INITIALLY ARRAY IS : \n";
		//print(size);
		cout << ndarras;
		cout << "\n";
		cout << "\n1-INSERT ELEMENT\n2-DELETE ELEMENT\n3-EXTEND ARRAY\n4-SHRINK ARRAY\n5-RETRIVE ELEMENT\n6-PRINT ARRAY\n7-EXIT\n";
		int choice = 0;
		cout << "\nENTER CHOICE : ";
		cin >> choice;
		while (choice != 7) {
			if (choice == 1)
			{
				ndarras.insert();
			}
			else if (choice == 2)
			{
				ndarras.delete_elem();
			}
			else if (choice == 3)
			{
				ndarras.extend();
			}
			else if (choice == 4)
			{
				ndarras.shrink();
			}
			else if (choice == 5)
			{
				ndarras.retrive();
			}
			else if (choice == 6)
			{
				cout << "UPDATED ARRAY IS : \n";
				cout << ndarras;
				cout << "\n";
			}
			else if (choice == 7)
			{
				exit(0);
			}
			else {
				cout << "\nINVALID CHOICE\n";
			}

			cout << "\n1-INSERT ELEMENT\n2-DELETE ELEMENT\n3-EXTEND ARRAY\n4-SHRINK ARRAY\n5-RETRIVE ELEMENT\n6-PRINT ARRAY\n7-EXIT\n";
			cout << "\nENTER CHOICE : ";
			cin >> choice;

		}
	}
	else if (choicee == 3)
	{
		ndarr <double> ndarras(dim, dim_coordinates, temp);
		cout << "INITIALLY ARRAY IS : \n";
		//print(size);
		cout << ndarras;
		cout << "\n";
		cout << "\n1-INSERT ELEMENT\n2-DELETE ELEMENT\n3-EXTEND ARRAY\n4-SHRINK ARRAY\n5-RETRIVE ELEMENT\n6-PRINT ARRAY\n7-EXIT\n";
		int choice = 0;
		cout << "\nENTER CHOICE : ";
		cin >> choice;
		while (choice != 7) {
			if (choice == 1)
			{
				ndarras.insert();
			}
			else if (choice == 2)
			{
				ndarras.delete_elem();
			}
			else if (choice == 3)
			{
				ndarras.extend();
			}
			else if (choice == 4)
			{
				ndarras.shrink();
			}
			else if (choice == 5)
			{
				ndarras.retrive();
			}
			else if (choice == 6)
			{
				cout << "UPDATED ARRAY IS : \n";
				cout << ndarras;
				cout << "\n";
			}
			else if (choice == 7)
			{
				exit(0);
			}
			else {
				cout << "\nINVALID CHOICE\n";
			}

			cout << "\n1-INSERT ELEMENT\n2-DELETE ELEMENT\n3-EXTEND ARRAY\n4-SHRINK ARRAY\n5-RETRIVE ELEMENT\n6-PRINT ARRAY\n7-EXIT\n";
			cout << "\nENTER CHOICE : ";
			cin >> choice;

		}
	}
	else if (choicee == 4)
	{
		ndarr <float> ndarras(dim, dim_coordinates, temp);
		cout << "INITIALLY ARRAY IS : \n";
		//print(size);
		cout << ndarras;
		cout << "\n";
		cout << "\n1-INSERT ELEMENT\n2-DELETE ELEMENT\n3-EXTEND ARRAY\n4-SHRINK ARRAY\n5-RETRIVE ELEMENT\n6-PRINT ARRAY\n7-EXIT\n";
		int choice = 0;
		cout << "\nENTER CHOICE : ";
		cin >> choice;
		while (choice != 7) {
			if (choice == 1)
			{
				ndarras.insert();
			}
			else if (choice == 2)
			{
				ndarras.delete_elem();
			}
			else if (choice == 3)
			{
				ndarras.extend();
			}
			else if (choice == 4)
			{
				ndarras.shrink();
			}
			else if (choice == 5)
			{
				ndarras.retrive();
			}
			else if (choice == 6)
			{
				cout << "UPDATED ARRAY IS : \n";
				cout << ndarras;
				cout << "\n";
			}
			else if (choice == 7)
			{
				exit(0);
			}
			else {
				cout << "\nINVALID CHOICE\n";
			}

			cout << "\n1-INSERT ELEMENT\n2-DELETE ELEMENT\n3-EXTEND ARRAY\n4-SHRINK ARRAY\n5-RETRIVE ELEMENT\n6-PRINT ARRAY\n7-EXIT\n";
			cout << "\nENTER CHOICE : ";
			cin >> choice;

		}
	}





	return 0;
}