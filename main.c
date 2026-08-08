#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int *Dataset = NULL;
int numofentries = 0;

void checkdatasetsize(){
    if (numofentries == 0){
        printf("Your dataset is empty.\n");
        printf("How many elements does this dataset contain?\n");
        scanf("%d", &numofentries);
        if (numofentries <= 0){
            printf("Dataset size must be greater than 0.\n");
            numofentries = 0;
            return;
        }
        Dataset = malloc(numofentries * sizeof(int));
        if (Dataset == NULL){
            printf("Memory allocation failed.\n");
            numofentries = 0;
            return;
        }
        for (int i = 0; i < numofentries; i++){
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

void Savedata()
{
    FILE *ptr = fopen("Database.txt", "w");

    if (ptr == NULL)
    {
        printf("The file could not be opened.\n");
        return;
    }

    fprintf(ptr, "%d\n", numofentries);

    for (int i = 0; i < numofentries; i++)
    {
        fprintf(ptr, "%d ", Dataset[i]);
    }

    fprintf(ptr, "\n");
    fclose(ptr);
}
void Loaddata(){
    FILE *ptr = fopen("Database.txt", "r");
    if (ptr == NULL){
        printf("The file could not be opened.\n");
        return;
    }
    int newSize;
    fscanf(ptr, "%d", &newSize);
    int *temporary = realloc(Dataset, newSize * sizeof(int));
    if (temporary == NULL){
        printf("Memory reallocation failed.\n");
        fclose(ptr);
        return;
    }
    Dataset = temporary;
    numofentries = newSize;
    for (int i = 0; i < numofentries; i++){
        fscanf(ptr, "%d", &Dataset[i]);
    }
    fclose(ptr);
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
        int middle=numofentries/2;
        return Dataset[middle];
    }
}

int mode()
{
    int modeValue = Dataset[0];
    int highestCount = 0;
    for (int i = 0; i < numofentries; i++){
        int count = 0;
        for (int j = 0; j < numofentries; j++){
            if (Dataset[i] == Dataset[j]){
                count++;
            }
        }

        if (count > highestCount){
            highestCount = count;
            modeValue = Dataset[i];
        }
    }
    return modeValue;
}

int BinarySearch(){
    int Search;
    printf("Enter the number you desire for Binary Search: ");
    scanf("%d", &Search);
    int low = 0;
    int high = numofentries - 1;
    while (low <= high){
        int middle = (low + high) / 2;
        if (Dataset[middle] == Search){
            return middle;
        }
        else if (Dataset[middle] > Search){
            high = middle - 1;
        }
        else{
            low = middle + 1;
        }
    }

    return -1;
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
        printf("10. Mode of given dataset\n");
        printf("11. Save dataset\n");
        printf("12. Load dataset\n");
        printf("13. Binary Search\n");
        printf("15. Exit\n");

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
            float Result;
            Result = Median();
            printf("The Median for given Dataset is %.2f\n", Result);
            break;
        }
        case 10:{
            int Result=mode();
            printf("The Mode for given Dataset is %d", Result);
            break;
        }
        case 11:{
            char confirmation;
            printf("Are you sure you want to save this dataset? (y/n): ");
            scanf(" %c", &confirmation);
            if (tolower((unsigned char)confirmation) == 'y'){
                Savedata();
                printf("The given dataset is saved.\n");
            }
            else{
                printf("Save cancelled.\n");
            }
            break;
        }
        case 12:
        {
            Loaddata();
            printf("Here is your loaded dataset:\n");
            for (int i = 0; i < numofentries; i++){
                printf("%d ", Dataset[i]);
            }
            printf("\n");
            break;
        }
        case 13:
        {
            BubbleSortAscending();
            int Result = BinarySearch();
            if (Result == -1)
            {
                printf("Value was not found.\n");
            }
            else
            {
                printf("Value was found at index %d in the sorted dataset.\n", Result);
            }
            break;
        }
        case 15:
            free(Dataset);
            Dataset = NULL;
            return 0;

        default:
            printf("Invalid option.\n");
            break;
        }
    }
}