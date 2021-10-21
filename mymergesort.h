
#include <vector>

template <typename T> void merge(std::vector<T> &data, unsigned int firstToSort, unsigned int middle, unsigned int lastToSort)
{
    std::vector<T> temp;
    unsigned int i = firstToSort;
    unsigned int j = middle + 1;
    while (i <= middle && j <= lastToSort)
    {
        if (data[i] <= data[j])
        {
            temp.push_back(data[i]);
            i++;
        }
        else
        {
            temp.push_back(data[j]);
            j++;
        }
    }
    while (i <= middle)
    {
        temp.push_back(data[i]);
        i++;
    }
    while (j <= lastToSort)
    {
        temp.push_back(data[j]);
        j++;
    }
    for (i = firstToSort; i <= lastToSort; i++)
    {
        data[i] = temp[i - firstToSort];
    }
}

template <typename T>
void mergeSort(std::vector<T> &data, unsigned int firstToSort, unsigned int lastToSort)
{

    if (firstToSort < lastToSort)
    {
        unsigned int middle = (firstToSort + lastToSort) / 2;
        mergeSort(data, firstToSort, middle);
        mergeSort(data, middle + 1, lastToSort);
        merge(data, firstToSort, middle, lastToSort);
    }
}

