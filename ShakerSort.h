template <typename T> inline void ShakerSort(T* arr, size_t start, size_t end,
	bool (*compare)(T a, T b) = [](T a, T b) {return (a > b); },
	void (*swap)(T* a, T* b) = [](T* a, T* b) { T c = *a; *a = *b; *b = c; })
{
	size_t len = end - start;
	for (size_t p = 1U + start; p <= len / 2; p++)
	{
		for (size_t i = p - 1U; i < len - p; i++)
			if (compare(arr[i], arr[i + 1U]))
				swap(&arr[i], &arr[i + 1U]);
		for (size_t i = len - p - 1U; i >= p; i--)
			if (!compare(arr[i], arr[i - 1U]))
				swap(&arr[i], &arr[i - 1U]);
	}
}