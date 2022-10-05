template <typename T> inline void InsertionSort(T* arr, size_t start, size_t end,
	bool (*compare)(T a, T b) = [](T a, T b) {return (a < b); },
	void (*swap)(T* a, T* b) = [](T* a, T* b) { T c = *a; *a = *b; *b = c; })
{
	for (size_t i = start + 1U; i < end; i++)
	{
		size_t j = i;
		while (j > start)
		{
			if (compare(arr[j], arr[j - 1U]))
			{
				swap(&arr[j], &arr[j - 1U]);
				j--;
			}
			else {
				j = start;
			}
		}
	}
}