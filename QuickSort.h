template <typename T> inline size_t QuickSortDivision(T* arr, size_t since, size_t to,
	bool (*compare)(T a, T b) = [](T a, T b) {return (a <= b); },
	void (*swap)(T* a, T* b) = [](T* a, T* b) { T c = *a; *a = *b; *b = c; })
{
	T pivot = arr[to];
	size_t i = since - 1U;
	for (size_t j = since; j <= (to - 1U); j++)
    {
		if (compare(arr[j], pivot))
        {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1U], &arr[to]);
	return (i + 1U);
}
template <typename T> inline void QuickSort(T* arr, size_t since, size_t to,
	bool (*compare)(T a, T b) = [](T a, T b) {return (a <= b); },
	void (*swap)(T* a, T* b) = [](T* a, T* b) { T c = *a; *a = *b; *b = c; })
{
	if (since < to)
    {
		size_t Middle_ = QuickSortDivision<T>(arr, since, to, compare, swap);
		QuickSort<T>(arr, since, Middle_ - 1U, compare, swap);
		QuickSort<T>(arr, Middle_ + 1U, to, compare, swap);
	}
}