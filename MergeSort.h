template <typename T> void inline Merge(
	T arr[], size_t since,
	size_t medium, size_t to,
	bool (*compare)(T a, T b) = [](T a, T b) {return (a <= b); },
	void (*copy)(T* a, const T* b) = [](T* a, const T* b) { *a = *b; })
{
	size_t len1 = medium - since + 1U;
	size_t len2 = to - medium;
	T *L = (T*) malloc(sizeof(T)* len1), *R = (T*)malloc(sizeof(T) * len2);
	for (size_t i = 0; i < len1; i++)
		copy(L + i, arr + since + i);
	for (size_t j = 0; j < len2; j++)
		copy(R + j, arr + medium + j + 1U);
	size_t k = since, i = 0, j = 0;
	while (i < len1 && j < len2)
	{
		if (compare(L[i], R[j]))
		{
			copy(arr + k, L + i);
			i++;
		}
		else
		{
			copy(arr + k, R + j);
			j++;
		}
		k++;
	}
	for (; i < len1; i++, k++)
	{
		copy(arr + k, L + i);
	}
	free(L);
	for (; j < len2; j++, k++)
	{
		copy(arr + k, R + j);
	}
	free(R);
}
template <typename T> void inline MergeSort(T arr[],
	size_t since, size_t to,
	bool (*compare)(T a, T b) = [](T a, T b) {return (a <= b); },
	void (*copy)(T* a, const T* b) = [](T* a, const T* b) { *a = *b; })
{
	if (since < to) {
		size_t m = since + (to - since) / 2U;
		MergeSort<T>(arr, since, m, compare, copy);
		MergeSort<T>(arr, m + 1U, to, compare, copy);
		Merge<T>(arr, since, m, to, compare, copy);
	}
}