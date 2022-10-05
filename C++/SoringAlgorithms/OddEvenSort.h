template <typename T> inline void OddEvenSort(T* arr, size_t start, size_t end,
	bool (*compare)(T a, T b) = [] (T a, T b) {return (a > b);},
	void (*swap)(T* a, T* b) = [](T* a, T* b) { T c = *a; *a = *b; *b = c; })
{
	bool comapred = true;
    size_t startindex = 1U, len = end - 1U;
    while (comapred)
    {
        compared = false;
        for (size_t i = startindex + start; i < len; i += 2U)
        {
            if (compare(arr[i], arr[i + 1U]))
            {
                swap(arr[i], arr[i + 1U]);
                compared = true;
            }
        }
        startindex = 1U - startindex;
    }
}