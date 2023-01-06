#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

static void Swap(int* pa, int* pb)
{
	assert(pa && pb);

	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void PrintArr(int* a, int n)
{
	assert(a);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)
{
	assert(a);

	for (int i = 0; i < n - 1; i++)
	{
		// [0,end]有序，插入end+1位置的数据
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	assert(a);

	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;

		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

// 升序建大堆
static void AdjustDown(int* a, int n, int parent)
{
	assert(a);

	int child = parent * 2 + 1;
	while (child < n)
	{
		// 选出较大的子节点
		if (child + 1 < n && a[child + 1] > a[child])
			child++;

		if (a[child] > a[parent])
		{
			Swap(a + parent, a + child);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	assert(a);

	// 向下建堆
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	// 把堆顶的数换到后面
	int end = n - 1;
	while (end > 0)
	{
		Swap(a, a + end);
		AdjustDown(a, end--, 0);
	}
}

void SelectSort(int* a, int n)
{
	assert(a);

	int begin, end;
	for (begin = 0, end = n - 1; begin < end; ++begin, --end)
	{
		// 找出最大、最小元素的下标
		int maxi, mini;
		maxi = mini = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		// 把最小的换前面去
		Swap(a + begin, a + mini);

		// 如果最大的和最前面的重叠，则最大的会被换走，需要修正
		if (maxi == begin)
		{
			maxi = mini;
		}

		// 把最大的换后面去
		Swap(a + maxi, a + end);
	}
}

void BubbleSort(int* a, int n)
{
	assert(a);

	for (int i = 0; i < n - 1; i++)
	{
		bool flag = true; // 假设已经有序
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				flag = false;
				Swap(a + j, a + j + 1);
			}
		}
		if (flag)
		{
			return;
		}
	}
}

// 三数取中
static int GetMidIndex(int* a, int begin, int end)
{
	assert(a);

	int mid = begin + (end - begin) / 2;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return end;
		}
		else
		{
			return begin;
		}
	}
	else // a[begin] >= a[mid]
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return end;
		}
		else
		{
			return begin;
		}
	}
}

// 单趟快排的3种思路

// Hoare
static int PartSort1(int* a, int begin, int end)
{
	assert(a);

	int left = begin;
	int right = end;
	int keyi = left;

	int midi = GetMidIndex(a, begin, end);
	Swap(a + keyi, a + midi);

	while (left < right)
	{
		// 右边找小
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}

		// 左边找大
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}

		Swap(a + left, a + right);
	}

	Swap(a + keyi, a + left);
	keyi = left;

	return keyi;
}

// 挖坑法
static int PartSort2(int* a, int begin, int end)
{
	assert(a);

	int midi = GetMidIndex(a, begin, end);
	Swap(a + begin, a + midi);

	int key = a[begin];
	int piti = begin;

	while (begin < end)
	{
		// 右边找小，填左边坑，该位置形成新坑
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		a[piti] = a[end];
		piti = end;

		// 左边找大，填右边坑，该位置形成新坑
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}
		a[piti] = a[begin];
		piti = begin;
	}

	a[piti] = key;
	return piti;
}

// 双指针法
static int PartSort3(int* a, int begin, int end)
{
	assert(a);

	int prev = begin;
	int cur = prev + 1;
	int keyi = begin;

	int midi = GetMidIndex(a, begin, end);
	Swap(a + keyi, a + midi);

	while (cur <= end)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(a + prev, a + cur);
		}

		++cur;
	}

	Swap(a + prev, a + keyi);
	keyi = prev;

	return keyi;
}

static void _QuickSort(int* a, int begin, int end)
{
	assert(a);

	// 区间只有一个数或者不存在时返回
	if (begin >= end)
		return;

	if (end - begin > 10)
	{
		int keyi = PartSort3(a, begin, end);
		// [begin, keyi-1] keyi [keyi+1, end]
		_QuickSort(a, begin, keyi - 1);
		_QuickSort(a, keyi + 1, end);
	}
	else // 小区间优化
	{
		// 插入排序
		InsertSort(a + begin, end - begin + 1);
	}
}

int CmpByInt(const void* e1, const void* e2)
{
	assert(e1 && e2);

	return *(int*)e1 - *(int*)e2;
}

void QuickSort(int* a, int n)
{
	assert(a);

	_QuickSort(a, 0, n - 1);

	// 调用库函数
	//qsort(a, n, sizeof(a[0]), CmpByInt);
}

void QuickSortNonR(int* a, int n)
{
	assert(a);

	ST st;
	StackInit(&st);
	StackPush(&st, n - 1);
	StackPush(&st, 0);

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);

		int right = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort3(a, left, right);
		// [left, keyi-1] keyi [keyi+1, right]

		if (keyi + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, keyi + 1);
		}
		if (left < keyi - 1)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, left);
		}
	}

	StackDestroy(&st);
}

static void _MergeSort(int* a, int begin, int end, int* tmp)
{
	assert(a && tmp);

	if (begin >= end)
		return;

	int mid = (begin + end) / 2;
	// [begin, mid] [mid+1, end]
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	// 归并
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	// 把归并数组拷贝回原数组
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

void MergeSort(int* a, int n)
{
	assert(a);

	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("MergeSort::malloc");
		return;
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
	tmp = NULL;
}

// 非递归版本的2种思路

// 一次性拷贝tmp数组
void MergeSortNonR1(int* a, int n)
{
	assert(a);

	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("MergeSort::malloc");
		return;
	}

	for (int gap = 1; gap < n; gap *= 2)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			// 归并 [i, i+gap-1] [i+gap, i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			// end1, begin2, end2都有可能越界
			// 修正边界
			if (end1 >= n)
			{
				end1 = n - 1;

				// [begin2, end2]不存在
				begin2 = n;
				end2 = n - 1;
			}
			else if (begin2 >= n)
			{
				// [begin2, end2]不存在
				begin2 = n;
				end2 = n - 1;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}

			int j = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
		}

		memcpy(a, tmp, sizeof(int) * n);
	}

	free(tmp);
	tmp = NULL;
}

// 分小段拷贝tmp数组
void MergeSortNonR(int* a, int n)
{
	assert(a);

	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("MergeSort::malloc");
		return;
	}

	for (int gap = 1; gap < n; gap *= 2)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			// 归并 [i, i+gap-1] [i+gap, i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			// end1, begin2, end2都有可能越界
			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}

			int m = end2 - begin1 + 1; // 归并数据的个数
			int j = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}

			memcpy(a + i, tmp + i, sizeof(int) * m);
		}
	}

	free(tmp);
	tmp = NULL;
}

void CountSort(int* a, int n)
{
	int min, max;
	min = max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	int range = max - min + 1;
	int* count = (int*)calloc(range, sizeof(int));
	if (count == NULL)
	{
		perror("CountSort::calloc");
		return;
	}

	// 统计次数
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}

	// 回写-排序
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		// 出现几次就回写几个i+min
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}

	free(count);
	count = NULL;
}