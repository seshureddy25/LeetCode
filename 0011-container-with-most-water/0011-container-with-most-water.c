int maxArea(int* arr, int size)
{
    int max = 0;
    int right = size - 1;
    int left = 0;
    while (left < right)
    {
        int h = arr[left] < arr[right] ? arr[left] : arr[right];
        int diff = (right - left) * h;
        if (diff > max)
            max = diff;

        if (arr[left] < arr[right])
            left++;
        else
            right--;
    }
    return max;
}