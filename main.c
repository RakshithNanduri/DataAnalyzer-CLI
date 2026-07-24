#include <stdio.h>
#define MAX_SIZE 100

int numofentries = 0;
int Dataset[MAX_SIZE];

void checkdatasetsize()
{
    if (numofentries == 0)
    {
        printf("Your dataset is empty.\n");

        printf("How many elements does this dataset contain?\n");
        scanf("%d", &numofentries);

        if (numofentries <= 0 || numofentries > MAX_SIZE)
        {
            printf("Dataset size must be between 1 and %d.\n", MAX_SIZE);
            numofentries = 0;
            return;
        }

        for (int i = 0; i < numofentries; i++)
        {
            printf("Enter data element %d: ", i + 1);
            scanf("%d", &Dataset[i]);
        }
    }
}

float sum()
{
    int Sum = 0;

    for (int i = 0; i < numofentries; i++)
    {
        Sum = Sum + Dataset[i];
    }

    return Sum;
}
float avg(){
    sum();
    float avg;
    avg=sum()/numofentries;
    return avg;
    
}

int min(){
    int Min=Dataset[0];
    for (int i = 0; i < numofentries; i++)
    {
        if (Dataset[i] < Min)
        {
            Min = Dataset[i];
        }
    }
    return Min;
}

int max()
{
    int max = Dataset[0];
    for (int i = 0; i < numofentries; i++)
    {
        if (Dataset[i] > max)
        {
            max = Dataset[i];
        }
    }
    return max;
}

int LinearSearch(int value)
{
    for (int i = 0; i < numofentries; i++)
    {
        if (value == Dataset[i])
        {
            return i;
        }
    }

    return -1;
}

void BubbleSortAscending()
{
    for (int i = 0; i < numofentries - 1; i++)
    {
        for (int j = 0; j < numofentries - i - 1; j++)
        {
            if (Dataset[j] > Dataset[j + 1])
            {
                int temp = Dataset[j];
                Dataset[j] = Dataset[j + 1];
                Dataset[j + 1] = temp;
            }
        }
    }
}

void BubbleSortDescending(){
    for (int i = 0; i < numofentries - 1; i++)
    {
        for (int j = 0; j < numofentries - i - 1; j++)
        {
            if (Dataset[j] < Dataset[j + 1])
            {
                int temp = Dataset[j];
                Dataset[j] = Dataset[j + 1];
                Dataset[j + 1] = temp;
            }
        }
    }
}

int Range(){
    int Max;
    int Min;
    int Range;
    Max=max();
    Min=min();
    Range=Max-Min;
    return Range;
}

float Median(){
    BubbleSortAscending();
    if ((numofentries%2)==0)
    {
        int rightmiddle=numofentries/2;
        int leftmiddle=rightmiddle-1;
        return (Dataset[rightmiddle]+Dataset[leftmiddle])/2.0f;
    }
    else{
        int middle=numofentries/2.0;
        return Dataset[middle];
    }
}

int main()
{
    int menu;
    int result;
    checkdatasetsize();
    printf("\nThe dataset is:\n");

    for (int i = 0; i < numofentries; i++)
    {
        printf("%d ", Dataset[i]);
    }

    while (1)
    {
        printf("\n");
        printf("--------------- Menu ---------------\n");
        printf("1. Sum\n");
        printf("2. Average\n");
        printf("3. Minimum\n");
        printf("4. Maximum\n");
        printf("5. Search\n");
        printf("6. Bubblesort\n");
        printf("7. Descending Order\n");
        printf("8. Range of given dataset\n");
        printf("9. Median of given dataset\n");
        printf("10. Exit\n");

        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            printf("Sum is %.2f\n", sum());
            break;
        case 2:
            printf("average is %.2f\n",avg());
            break;
        case 3:
            printf("Minimum is %d\n",min());
            break;
        case 4:
            printf("Maximum is %d\n", max());
            break;
        case 5:{
            int value;
            printf("Type your desired value: ");
            scanf("%d", &value); 
            result=LinearSearch(value);
            if (result == -1){
                printf("Value %d was not found.\n", value);
            }
            else{
                printf("Value %d was found at index %d.\n", value, result);
            }
            break;
        }
        case 6:
            BubbleSortAscending();
            printf("Dataset sorted: ");
            for (int i = 0; i < numofentries; i++) {
                printf("%d ", Dataset[i]);
            }
            printf("\n");
            break;
        case 7:
            BubbleSortDescending();
            printf("Dataset sorted: ");
            for (int i = 0; i < numofentries; i++) {
                printf("%d ", Dataset[i]);
            }
            printf("\n");
            break;
        case 8:{
            int Result;
            Result=Range();
            printf("The Range of given Data is %d", Result);
            break;
        }
        case 9:{
            int Result;
            Result=Median();
            printf("The median for given Dataset is %d",Result);
            break;
        }
        case 10:
            return 1;
            break;

        default:
            printf("Invalid option.\n");
            break;
        }
    }
}