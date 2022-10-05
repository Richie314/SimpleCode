template <typename T> inline void BubbleSort(T* arr, size_t start, size_t end,
	bool (*compare)(T a, T b) = [] (T a, T b) {return (a > b);},
	void (*swap)(T* a, T* b) = [](T* a, T* b) { T c = *a; *a = *b; *b = c; })
{
	for (size_t i = end; i > start; i--)
	{
		for (size_t j = start; j < i - 1U; j++)
		{
			if (compare(arr[j], arr[j + 1U]))
			{
				swap(&arr[j], &arr[j + 1U]);
			}
		}
	}
}