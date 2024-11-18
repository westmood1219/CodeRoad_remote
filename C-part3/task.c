int findMaxIndex(int arr[], int sz)
{
    int Index = 0;
    int max = arr[0];
    for(int i = 0;i<sz;i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            Index = i;

        }
    }
    return Index;
}