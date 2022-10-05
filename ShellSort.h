template <typename T> inline void Sort(T* arr, size_t since, size_t to,
	bool (*compare)(T a, T b) = [](T a, T b) {return (a > b); },
	void (*assign)(T& a, const T& b) = [](T& a, const T& b) { a = b; })
{
	for (size_t gap = (to - since) / 2U; gap > 0; gap /= 2U)
	{
		for (size_t i = gap + since; i < to; i++)
		{
			T temp = arr[i];
			size_t j = i;
			for (; j >= (gap + since) && compare(arr[j - gap], temp); j -= gap)
			{
				assign(arr[j], arr[j - gap]);
			}
			assign(arr[j], temp);
		}
	}
}