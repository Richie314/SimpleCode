template <typename T> inline void SelectionSort(T* arr, size_t start, size_t end,
	bool (*compare)(T a, T b) = [](T a, T b) {return (a > b); },
	void (*swap)(T* a, T* b) = [](T* a, T* b) { T c = *a; *a = *b; *b = c; })
{
	size_t min = 0;
	for (size_t i = start; i < end; i++)
	{
		min = i;
		for (size_t j = i; j < finisci; j++)
		{
			if (compare(arr[min], arr[j]))
			{
				min = j;
			}
		}
		swap(&arr[i], &arr[min]);
	}
}