#pragma once
#include <iostream>
using namespace std;

template <typename T>
class ndarr
{
private:
	int size;
	int dim;
	int* dim_coordinates;
	int* dim_iterations;
	int index;
	T* data;
public:
	ndarr()
	{
		size = 0;
		dim = 0;
		dim_coordinates = nullptr;
		dim_iterations = nullptr;
		index = 0;
		data = nullptr;
	}

	ndarr(int dimen, int* dim_coordinatees, int sizee)
	{
		dim = dimen;
		dim_coordinates = new int[dim];
		for (int i = 0; i < dim; i++)
		{
			dim_coordinates[i] = dim_coordinatees[i];
		}
		size = sizee;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = 0;
		}
		index = 0;
		dim_iterations = new int[dim];
	}

	ndarr(const ndarr &obj)
	{
		this->dim = obj.dim;
		dim_coordinates = new int[dim];
		for (int i = 0; i < dim; i++)
		{
			dim_coordinates[i] = obj.dim_coordinatees[i];
		}
		size = obj.size;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = obj.data[i];
		}
		index = obj.index;
		dim_iterations = new int[dim];
		for (int i = 0; i < dim; i++)
		{
			dim_iterations[i] = obj.dim_iterations[i];
		}

	}

	int return_index(int* dim_iterations)
	{
		int calculated = 1;
		int sum = 0;
		for (int i = 0; i < dim; i++)
		{
			for (int j = 1 + i; j < dim; j++)
			{
				calculated = calculated * dim_coordinates[j];
			}
			calculated = calculated * dim_iterations[i];
			sum = sum + calculated;
			calculated = 1;
		}
		return sum;
	}

	~ndarr()
	{
		cout << "DISTRUCTOR CALLED";
		delete data;
		delete dim_coordinates;
		delete dim_iterations;
	}
	void insert()
	{
		cout << "-------------------NOW SELECT INDEX OF THE ARRAY TO INSERT DATA-------------------\n";
		for (int i = 0; i < dim; i++)
		{
			cout << "ENTER " << i << " ITERATION OF THE ARRAY : ";
			cin >> dim_iterations[i];
		}

		int index = return_index(dim_iterations);
		cout << "SELECTED INDEX IN LEANIER TYPE IS : " << index;
		T key = 0;
		cout << "\nENTER ELEMENT TO INSERT : ";
		cin >> key;
		data[index] = key;
		cout << "\n----------------------KEY INSERTED---------------------------\n";
		cout << "UPDATED ARRAY IS : \n";
		print(size);
		cout << "\n";
	}

	void print(int size)
	{
		if (dim == 2)
		{
			int k = 0;
			for (int i = 0; i < dim_coordinates[0]; i++)
			{
				for (int j = 0; j < dim_coordinates[1]; j++)
				{
					cout << data[k] << " ";
					k++;
				}
				cout << endl;
			}

		}
		else if (dim == 3)
		{
			int x = 0;
			for (int i = 0; i < dim_coordinates[0]; i++)
			{
				for (int j = 0; j < dim_coordinates[1]; j++)
				{
					for (int k = 0; k < dim_coordinates[2]; k++)
					{
						cout << data[x] << " ";
						x++;
					}
					cout << endl;
				}
				cout << endl;
			}
		}
		else
			for (int i = 0; i < size; i++)
			{
				cout << data[i] << " ";
			}
	}

	void delete_elem()
	{
		cout << "-------------------NOW SELECT INDEX OF THE ARRAY TO DELETE DATA-------------------\n";
		for (int i = 0; i < dim; i++)
		{
			cout << "ENTER " << i << " ITERATION OF THE ARRAY : ";
			cin >> dim_iterations[i];
		}

		int index = return_index(dim_iterations);
		cout << "SELECTED INDEX IN LEANIER TYPE IS : " << index;
		data[index] = -1;
		cout << "\n----------------------KEY DELETED---------------------------\n";
		cout << "UPDATED ARRAY IS : \n";
		print(size);
		cout << "\n";
	}

	void extend()
	{
		int sizei = size * 2;
		T* temp = new T[sizei];
		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}



		for (int i = size; i < sizei; i++)
		{
			temp[i] = 0;
		}
		size = sizei;
		delete[]data;
		data = temp;
		cout << "ARRAY EXTENDED\n";
		if (dim_coordinates[0] != 0)
			dim_coordinates[0] = dim_coordinates[0] * 2;
		else
			dim_coordinates[0] = 1;


		cout << "UPDATED ARRAY IS : \n";
		print(size);
		cout << "\n";

	}

	void retrive()
	{
		/*cout << "-------------------NOW SELECT INDEX OF THE ARRAY TO INSERT DATA-------------------\n";
		for (int i = 0; i < dim; i++)
		{
			cout << "ENTER " << i << " ITERATION OF THE ARRAY : ";
			cin >> dim_iterations[i];
		}
		int index = return_index(dim_iterations);
		cout << "SELECTED INDEX IN LEANIER TYPE IS : " << index;
		cout << endl << "SELECTED KEY IS : "<< data[index];
		cout << endl << "------------------ELEMENT RETRIVED----------------";*/
		T key = 0;
		cout << "\nENTER THE ELEMENT TO FIND : ";
		cin >> key;
		int count = 0, x = 0, siz = 1;
		bool flag = 0;
		while (flag == 0)
		{
			if (data[x] == key)
			{
				flag = 1;
				count = x;
				/*int index = return_index(dim_iterations);
				cout << "SELECTED INDEX IN LEANIER TYPE IS : " << index;
				cout << endl << "SELECTED KEY IS : " << data[index];
				cout << endl << "------------------ELEMENT RETRIVED----------------"; */
			}
			else x++;
		}
		if (flag == 0)
			cout << " \nELEMENT DOES NOT EXIST :\n ";
		for (int i = 0; i < dim; i++)
		{
			for (int j = i + 1; j < dim; j++)
			{
				siz = siz * dim_coordinates[j];
			}
			cout << "ELEMENT " << i << " << INDEX IS : " << count / siz << endl;
			count = count % siz;
			siz = 1;
		}


	}

	void shrink()
	{
		dim_coordinates[0] = dim_coordinates[0] / 2;
		int temp_size = 1;
		for (int i = 0; i < dim; i++)
		{
			temp_size = temp_size * dim_coordinates[i];
		}
		T* new_arr = new T[temp_size];
		for (int i = 0; i < temp_size; i++)
		{
			new_arr[i] = data[i];
		}
		size = temp_size;
		delete[] data;
		data = new_arr;
		cout << "ARRAY SHRINKED SUCCESSFULLY : \n";

		cout << "UPDATED ARRAY IS : \n";
		print(size);
		cout << "\n";

	}

	/*void run()
	{
		cout << "INITIALLY ARRAY IS : \n";
		print(size);
		cout << "\n";
		cout << "\n1-INSERT ELEMENT\n2-DELETE ELEMENT\n3-EXTEND ARRAY\n4-SHRINK ARRAY\n5-RETRIVE ELEMENT\n6-PRINT ARRAY\n7-EXIT\n";
		int choice = 0;
		cout << "\nENTER CHOICE : ";
		cin >> choice;
		while (choice != 7) {
			if (choice == 1)
			{
				insert();
			}
			else if (choice == 2)
			{
				delete_elem();
			}
			else if (choice == 3)
			{
				extend();
			}
			else if (choice == 4)
			{
				shrink();
			}
			else if (choice == 5)
			{
				retrive();
			}
			else if (choice == 6)
			{
				cout << "UPDATED ARRAY IS : \n";
				print(size);
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
	}*/

	int& operator[] (int i) {
		return data[i];
	}


	int& operator()(int i, int j) {
		return data[i + j];
	}


	int& operator()(int i, int j, int k) {
		return data[i + j + k];
	}
	int& operator()(int arr[]) {
		return data[arr[1]];
	}

	friend ostream& operator <<(ostream& out, const ndarr& obj)
	{
		if (obj.dim == 2)
		{
			int k = 0;
			for (int i = 0; i < obj.dim_coordinates[0]; i++)
			{
				for (int j = 0; j < obj.dim_coordinates[1]; j++)
				{
					out << obj.data[k] << " ";
					k++;
				}
				out << endl;
			}

		}
		else if (obj.dim == 3)
		{
			int x = 0;
			for (int i = 0; i < obj.dim_coordinates[0]; i++)
			{
				for (int j = 0; j < obj.dim_coordinates[1]; j++)
				{
					for (int k = 0; k < obj.dim_coordinates[2]; k++)
					{
						out << obj.data[x] << " ";
						x++;
					}
					out << endl;
				}
				out << endl;
			}
		}
		else
			for (int i = 0; i < obj.size; i++)
			{
				out << obj.data[i] << " ";
			}
		return out;
	}

};

