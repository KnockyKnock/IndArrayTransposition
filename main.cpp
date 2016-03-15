//??????? ???? ?????????, ???-403
//??????? ?????????? ????? ? ???????, ?????????? ????????????? ????? ?? 1 ?? N

#include <iostream>
#include <fstream>

using namespace std;

void printArray (int **array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < arraySize; j++)
            cout << array[i][j] << "  ";
        cout << endl;
    }
}

void inputFromConsole (int **array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        cout << "Enter elements of " << i+1 << " row of array: ";
        for (int j = 0; j < arraySize; j++)
            cin >> array[i][j];
    }
    //printArray(array, arraySize);
}

void inputFromFile (int **array, int arraySize, char* path[])
{
    ifstream fin(path[1]);
    fin >> arraySize;
    for (int i = 0; i < arraySize; i++)
        for (int j = 0; j < arraySize; j++)
            fin >> array[i][j];
    fin.close();
}

void bubbleSort (int **array, int arrayLenght)
{
    int temp = 0;
    bool exit = false;
    while (!exit)
    {
        exit = true;
        for (int i = 0; i < arrayLenght; i++)
            for (int j = 0; j < arrayLenght; j++)
                if (array[i][j] > array[i][j+1])
                {
                    temp = array [i][j];
                    array [i][j] = array [i][j+1];
                    array [i][j+1] = temp;
                    exit = false;
                }
    }
    //cout << "Bubble Sort " << endl;
    //printArray(array,arrayLenght);
}

int quantityOfRightStrings (int **array, int arrayLenght)
{
    int counterOfRightStrings = 0;
    bool checkString = false;
    bubbleSort(array, arrayLenght);
    for (int i = 0; i < arrayLenght; i++)
    {
        for (int j = 0; j < arrayLenght; j++)
        {
            if ( j+1 == array[i][j])
                checkString = true;
            else {
                checkString = false;
                break;
            }
        }
        if (checkString)
        counterOfRightStrings ++;
    }
    return counterOfRightStrings;
}

int main(int argc, char* argv[])
{
    int arraySize, counter;
    int **mainArray;
    if (argc == 0) {
        cout << "Enter size of array:  ";
        cin >> arraySize;
        mainArray = new int *[arraySize];
        for (int i = 0; i < arraySize; i++)
            mainArray[i] = new int[arraySize];
        inputFromConsole(mainArray, arraySize);
    } else if (argc > 1)
    {
        inputFromFile(mainArray, arraySize, argv);
    }
    counter = quantityOfRightStrings(mainArray, arraySize);
    cout << endl << counter << endl;
    for (int i = 0; i < arraySize; i++)
        delete[] mainArray[i];
    return 0;
}
