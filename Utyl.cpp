#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;



// SORT ALGORITHM:

// 2. Selection Sort:
void SelectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[min] > a[j]) min = j;
		}
		swap(a[min], a[i]);
	}
}

// 3. Insertion Sort:
void insertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int x = a[i];
		int pos = i - 1;
		while (pos >= 0 && a[pos] > x)
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}

// 4. binary insertion sort:
int binarySearch(int a[], int k, int x)
{
    int mid;
    int left = 0, right = k;
    do {
        mid = (left + right) / 2;
        if (x <= a[mid]) right = mid - 1;
        else left = mid + 1;
    } while (left <= right);
    if (x > a[mid]) return mid + 1;
    return mid;
}

// 5. Bubble Sort:
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{			
		for (int j = n-1; j >i; j--)
		{
			if (a[j] < a[j-1]) swap(a[j], a[j-1]);
		}		
	}
}

// 6. Shaker Sort:
void ShakerSort(int a[], int n)
{
    int surface = 0, bottom = n - 1, k = n - 1;
    while (surface < bottom)
    {
        for (int i = bottom; i > surface; i--)
        {
            if (a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                k = i;
            }
        }
        surface = k;

        for (int i = surface; i < bottom; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                k = i;
            }
        }
        bottom = k;
    }
}

// 7. Heap Sort:
void heapify(int a[], int parentIndex, int lastIndex)
{
	int left = parentIndex * 2 + 1;
	int right = parentIndex * 2 + 2;
	int biggest = parentIndex;

	if (left < lastIndex && a[left] > a[biggest])
		biggest = left;
	if (right < lastIndex && a[right] > a[biggest])
		biggest = right;
	if (biggest != parentIndex)
	{
		swap(a[biggest], a[parentIndex]);
		heapify(a, biggest, lastIndex);
	}

}

void HeapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(a, i, n - 1);
	}

	for (int i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		heapify(a, 0, i);
	}
}


// 8. Merge Sort:
void merge(int a[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (int i = 0; i < n2; i++)
		R[i] = a[m + 1 + i];
	int i = 0, j = 0;

	for (int k = l; k <= r; k++)             
	{
		if (i < n1 && (j >= n2 || L[i] < R[j]))
		{
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
	}
	delete[] L;
	delete[] R;
}

void MergeSort(int a[], int l, int r)
{
	if (l >= r)  return;
	int mid = l + (r - l) / 2;
	MergeSort(a, l, mid);
	MergeSort(a, mid + 1, r);
	merge(a, l, mid, r);
}

// 9. Quick Sort:
void quickSort(int a[], int left, int right)
{
    int i = left, j = right;
    int pivot = (a[right]+ a[left])/2;

    while (i <= j)
    {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;    j--;
        }
    }
    if (left < j) quickSort(a, left, j);
    if (right > i) quickSort(a, i, right);
}


// 10. Shell Sort:
void shellSort(int a[], int n)
{
    int h[10] = {100,75, 50, 25, 10, 5, 4, 3, 2, 1};
    
    for (int step = 0; step<10;step++)
    {
        int len = h[step];
        for (int i = len; i < n; i = i++)
        {
            int x = a[i];
            int pos = i - len;
            while (pos >= 0 && a[pos] > x)
            {
                a[pos + len] = a[pos];
                pos = pos - len;
            }
            a[pos + len] = x;
        }
    }
}

// 11. Radix Sort:
void radixSort(int a[], int n)
{
    queue<int> B[10];

    int mDigit = findNumDigit(a, n);

    for (int exp = 0; exp < mDigit; exp++)
    {
        for (int i = 0; i < n; i++)
        {
            int digit = a[i] / (int)pow(10, exp) % (10);
            B[digit].push(a[i]);
        }
        int i = 0;
        for (int j = 0; j <= 9; j++)
        {
            while (!B[j].empty())
            {
                a[i++] = B[j].front();
                B[j].pop();
            }
        }
    }
}






// PROBLEM USE SORT:

// 2d ARRAY: 
void sort2D(int a[][3], int n)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n-1;j++)
            for (int k = j+1; k<n;k++)
                if (a[i][j]>a[i][k])  swap(a[i][j],a[i][k]);
    }
}

// dictionary sort:

struct WORD
{
	string word;
	string definition;
};

void loadData(string filename, vector<WORD>& dict)
{
	ifstream fi;
	fi.open(filename);
	if (!fi.is_open())	return;

	while (!fi.eof())
	{
		string s;
		WORD w;
		getline(fi, s);
		int pos = s.find(":");
		w.word = s.substr(0, pos);
		w.definition = s.substr(pos + 1);
		dict.push_back(w);
	}
	fi.close();
}

void sortDict(vector<WORD>& dict, int left, int right)
{
	int i = left, j = right;
	int mid = left + (right - left) / 2;
	while (i <= j)
	{
		while (dict[i].word < dict[mid].word) i++;
		while (dict[j].word > dict[mid].word) j--;

		if (i <= j)
		{
			swap(dict[i], dict[j]);
			i++; j--;
		}
	}
	if (left < j) sortDict(dict, left, j);
	if (i < right) sortDict(dict, i, right);
}

void printDict(vector<WORD> dict, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << dict[i].word << ": " << dict[i].definition << endl;
	}
	cout << endl;
}



// 	odd_even sort:
void interchangeSort(int a[], int n)
{
    for (int i = 0; i<n-1;i++)
    {
        if (a[i]%2==0)
        {
            for (int j = i+1;j<n;j++)
                if (a[j]%2==0 && a[i]>a[j])
                {
                    swap(a[i],a[j]);
                }
        } 
        else { 
            for (int j = i+1;j<n;j++)
                if (a[j]%2!=0 && a[i]<a[j])
                {
                    swap(a[i],a[j]);
                }
        }
    }
}

void selectionSort(int a[], int n)
{
    for (int i = 0; i<n-1;i++)
    {
        if (a[i]%2==0)
        {
            int min = i;
            for (int j = i+1; j<n;j++)
            {
                if (a[j]%2==0 && a[j]<a[min]) min = j;
            }
            swap(a[i], a[min]);
        }
        else {
            int max = i;
            for (int j = i+1; j<n;j++)
            {
                if (a[j]%2!=0 && a[j]>a[max]) max = j;
            }
            swap(a[i], a[max]);
        }
    }
}


// odd_even sort 2:

void twoWaySort2(int arr[], int n) 
{ 
    // Make all odd numbers negative 
    for (int i = 0; i < n; i++) 
        if (arr[i]%2!=0) // Check for odd 
            arr[i] = -arr[i]; 
  
    // Sort all numbers 
    sort(arr, arr + n); 
  
    // Retaining original array 
    for (int i = 0; i < n; i++) 
        if (arr[i] & 1) 
            arr[i] *= -1; 
}

void twoWaySort(int a[], int n)
{
    int l = 0, r = n-1;
    int k = 0;  // count odd number.

    // Partition the input array such that all odd elements are moved to left and all even elements on right. 
    while (l<=r)
    {
        // find the first even number from left side:
        while (a[l]%2!=0)
        {
            l++;
            k++;
        }
        // find the fisrt odd number fromt right side:
        while (l<=r && a[r]%2==0)
        {
            r--;
        }
        if (l<r)    swap(a[l], a[r]);
    }
    // Sort odd number in descending order 
    sort(a, a + k, greater<int>()); 
  
    // Sort even number in ascending order 
    sort(a + k, a + n); 
}






																	// STACK:
// Sort Stack:

struct Node
{
	int key;
	Node* next;
};

struct Stack
{
	Node* top;
	int count;
};

Node* createNode(int& data)
{
	Node* pNew = new Node;
	if (!pNew) return NULL;
	pNew->key = data;
	pNew->next = NULL;
	return pNew;
}

void initialize(Stack& st)
{
	st.top = NULL;
	st.count = 0;
}

bool isEmptyStack(Stack& st)
{
	return st.count == 0;
}

void push(Stack& st, int data)
{
	Node* p = createNode(data);
	if (p == NULL) return;

	if (isEmptyStack(st))
		st.top = p;
	else {
		p->next = st.top;
		st.top = p;
	}
	st.count++;
}

void pop(Stack& st, int& value)
{
	if (isEmptyStack(st))	return;

	value = st.top->key;
	Node* temp = st.top;
	st.top = st.top->next;
	delete temp;
	st.count--;
}

void top(Stack& st, int value)
{
	if (st.top == NULL) return;
	value = st.top->key;
}

void printStack(const Stack& st)
{
	Node* cur = st.top;
	while (cur)
	{
		cout << cur->key << endl;
		cur = cur->next;
	}
}

void destroyStack(Stack& st)
{
	while (st.top)
	{
		Node* temp = st.top;
		st.top = st.top->next;
		delete temp;
	}
	st.top = nullptr;
	st.count = 0;
}

void loadData(string filename, Stack& st)
{
	ifstream fi;
	fi.open(filename);
	if (!fi.is_open())	return;

	while (!fi.eof())
	{
		string s;
		fi >> s;
		push(st, stoi(s));
	}
	fi.close();
}

void selectionSort(Stack& st)
{
	Node* cur, * fast;
	cur = fast = st.top;

	for (cur = st.top;cur->next; cur = cur->next)
		for (fast = cur->next; fast; fast = fast->next)
		{
			if (cur->key > fast->key)
			{
				int temp = cur->key;
				cur->key = fast->key;
				fast->key = temp;
			}
		}
}





// Student Sort:

struct Student
{
	string name;
	int age;
};

void input(string filename, vector<Student>& stu)
{
	ifstream fi;
	fi.open(filename);
	if (!fi.is_open())	return;

	while (!fi.eof())
	{
		string s;
		getline(fi, s);
		int pos = s.find(" - ");
		Student newbie;
		newbie.name = s.substr(0, pos);
		newbie.age = stoi(s.substr(pos + 3));
		stu.push_back(newbie);
	}
	fi.close();	
}

void printStu(vector<Student> stu)
{
	for (int i = 0; i < stu.size(); i++)
	{
		cout << stu[i].name << " - " << stu[i].age << endl;
	}
	cout << endl;
}

bool operator<(const Student& a, const Student& b)
{
	string name1, name2;
	int pos = a.name.rfind(" ");
	name1 = a.name.substr(pos + 1);
	pos = b.name.rfind(" ");
	name2 = b.name.substr(pos + 1);
	if (name1 == name2) return a.age < b.age;
	return name1 < name2;
}

bool operator>(const Student& a, const Student& b)
{
	return b < a;
}

void interchangeSortStu(vector<Student> &stu)
{
	int n = stu.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (stu[i] > stu[j]) swap(stu[i], stu[j]);
	}
}

void merge(vector<Student> &stu, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	Student* list1 = new Student[n1];
	Student* list2 = new Student[n2];

	int k = 0, l = 0;
	for (int i = left; i <= mid; i++)
		list1[k++] = stu[i];
	for (int j = mid + 1; j <= right; j++)
		list2[l++] = stu[j];
	k = 0, l = 0;
	for (int i = left; i <= right; i++)
	{
		if (k < n1 && (l >= n2 || list1[k] < list2[l]))
		{
			stu[i] = list1[k++];
		}
		else if (l < n2)
		{
			stu[i] = list2[l++];
		}
	}
	delete[] list1;
	delete[] list2;
}

void mergeSortStu(vector<Student>& stu, int left, int right)
{
	if (left >= right) return;
	int mid = left + (right - left) / 2;
		
	mergeSortStu(stu, left, mid);
	mergeSortStu(stu, mid + 1, right);
	merge(stu, left, mid, right);
}

void quickSortStu(vector<Student>& stu, int left, int right)
{
	int i = left, j = right;
	int mid = left + (right - left) / 2;

	while (i <= j)
	{
		while (stu[i] < stu[mid]) i++;
		while (stu[j] > stu[mid]) j--;

		if (i <= j)
		{
			swap(stu[i], stu[j]);
			i++; j--;
		}
	}
	if (left < j) quickSortStu(stu, left, j);
	if (right > i) quickSortStu(stu, i, right);
}

void heapify(vector<Student>& a, int parentIndex, int lastIndex)
{
	int left = parentIndex * 2 + 1;
	int right = parentIndex * 2 + 2;
	int biggest = parentIndex;

	if (left < lastIndex && a[left] > a[biggest])
		biggest = left;
	if (right < lastIndex && a[right] > a[biggest])
		biggest = right;
	if (biggest != parentIndex)
	{
		swap(a[biggest], a[parentIndex]);
		heapify(a, biggest, lastIndex);
	}
}

void heapSortStu(vector<Student>& stu, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(stu, i, n - 1);
	}
	for (int i = n - 1; i > 0; i--)
	{
		swap(stu[0], stu[i]);
		heapify(stu, 0, i);
	}
}







// FRACTION SORT:

struct Phanso
{
	int tu;
	int mau;
};

struct Node
{
	Phanso ps;
	Node* next;
};

Node* createNode(Phanso& p)
{
	Node* pNew = new Node;
	if (pNew == NULL)	return NULL;
	pNew->ps = p;
	pNew->next = NULL;
	return pNew;
}

void addHead(Node*& pHead, Phanso &p)
{
	Node* newNode = createNode(p);
	if (newNode == NULL) return;

	if (pHead == NULL)
		pHead = newNode;
	else {
		newNode->next = pHead;
		pHead = newNode;
	}
}

void addTail(Node*& pHead, Phanso& p)
{
	Node* newNode = createNode(p);
	if (newNode == NULL) return;

	if (pHead == NULL)
		pHead = newNode;
	else {
		Node* cur = pHead;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

void printList(Node* pHead)
{
	while (pHead)
	{
		if (pHead->ps.mau == 1) cout << pHead->ps.tu<<"  ";
		else cout << pHead->ps.tu << "/" << pHead->ps.mau<<"  ";
		pHead = pHead->next;
	}
	cout << endl;
}

void destroyList(Node* &pHead)
{
	while (pHead)
	{
		Node* temp = pHead;
		pHead = pHead->next;
		delete temp;
	}
	pHead = nullptr;
}

void loadData(string filename, Node*& pHead)
{
	ifstream fi;
	fi.open(filename);
	if (!fi.is_open()) return;

	while (!fi.eof())
	{
		string s;
		Phanso p;
		fi >> s;
		int pos = s.find("/");
		if (pos == -1)
		{
			p.tu = stoi(s);
			p.mau = 1;
		}
		else {
			p.tu = stoi(s.substr(0, pos));
			p.mau = stoi(s.substr(pos + 1));
		}
		
		//addHead(pHead, p);
		addTail(pHead, p);
	}
	fi.close();
}


bool operator<(const Phanso& p, const Phanso& q)
{
	return (double)p.tu / p.mau < (double)q.tu / q.mau;
}

bool operator>(const Phanso& p, const Phanso& q)
{
	return q < p;
}


void swapPS(Phanso& p, Phanso& q)
{
	Phanso temp;
	temp = q;
	q = p;
	p = temp;
}

void sortLinklist(Node*& pHead)
{
	if (pHead == NULL) return;
	for (Node* iter1 = pHead; iter1->next; iter1 = iter1->next)
		for (Node* iter2 = iter1->next; iter2; iter2 = iter2->next)
		{
			if (iter1->ps > iter2->ps)	swapPS(iter1->ps, iter2->ps);
		}
}

																						// SORT LINKED LIST






























// SEARCH SORT:
int sentinelSearch(int a[], int n, int x)
{
    int last = a[n-1];
    a[n-1] = x;
    int i = 0;
    while (a[i]!=x)
        i++;
    a[n-1] = last;
    if (i<n-1 || a[n-1]==x)
        return i;  
    return -1; 
}

int binarySearch(int a[], int n, int x)
{    
    int left = 0, right = n-1;

    while (left<=right)
    {
        int mid = left + (right - left)/2;
        if (a[mid]==x) return mid;
        if (a[mid]>x) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}







































// LAB 1:
// Pointer:

void inputArray(int*& a, int& n)
{
	cout << "n = ";	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> *(a + i);
	}
}

void dellocateArray(int*& a)
{
	delete[] a;
}


void printArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(a + i) << " ";
	}
}

int findMin(int* a, int n)
{
	if (a != nullptr)
	{
		int min = a[0];
		for (int i = 0; i < n; i++)
			if (min > a[i])
			{
				min = a[i];
			}
		return min;
	}
}


int findMaxModulus(int* a, int n)
{
	if (a != nullptr)
	{
		int m = abs(a[0]);
		for (int i = 0; i < n; i++)
			if (m < abs(a[i]))
			{
				m = abs(a[i]);
			}
		return m;
	}
}


bool isAscending(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i + 1] < a[i])	return false;
	}
	return true;
}

int sumOfArray(int* a, int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
		s = s + a[i];
	return s;
}

int countPrime(int* a, int n)
{
	int d = 0;
	for (int i = 0; i < n; i++)
	{
		bool isPrime = true;
		if (a[i] < 2) isPrime = false;
		else for (int j = 2; j <= sqrt(a[i]); j++)
		{
			if (a[i] % j == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime) d++;
	}
	return d;
}

int reverseArray(int*& a, int* b, int n)
{
	if (b == nullptr) return 0;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = b[n - 1 - i];
	}

	return 1;
}

int LinearSearch(int* a, int n, int key)
{
	int pos = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == key)
		{
			pos = i;
			break;
		}
	}
	return pos;
}

int SentinelLinearSearch(int* a, int n, int key)
{
	if (a == nullptr || n == 0) return -1;
	int last = a[n - 1];
	a[n - 1] = key;

	int i = 0;
	while (a[i] != key)
	{
		i++;
	}
	if ((i < n - 1) || (key == a[n - 1]))
		return i;
	else
		return -1;

}


int BinarySearch(int* a, int n, int key)
{
	int pos = -1;
	int left = 0, right = n - 1;
	/*int mid = (left + right) / 2;*/

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] == key)
		{
			pos = mid;
			break;
		}
		else if (key < a[mid]) right = mid - 1;
		else left = mid + 1;
	}

	return pos;
}

int RecursiveBinarySearch(int* a, int left, int right, int key)
{
	if (left > right)	return -1;
	int mid = (left + right) / 2;
	if (a[mid] == key)
	{
		return mid;
	}
	if (key < a[mid]) return RecursiveBinarySearch(a, left, mid - 1, key);
	else return RecursiveBinarySearch(a, mid + 1, right, key);
}



// Recursion:
int sumOfSquares(int n)
{
	if (n < 1) return 0;
	if (n == 1)	return 1;
	return sumOfSquares(n - 1) + n * n;
}

int GCD(int a, int b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}

int palindrome(int arr[], int begin, int end)
{
	if (begin >= end) return 1;
	if (arr[begin] == arr[end]) 
		return palindrome(arr, begin + 1, end - 1);
	else return 0;
}

bool isPalindrome(int a[], int n)
{
	static int i = n;
	if (n < i / 2) return true;
	if (a[n - 1] != a[i - n]) return false;
	return isPalindrome(a, n - 1);	
}

int Factorial(int n)
{
	if (n == 1 || n == 0)	return 1;
	return Factorial(n - 1) * n;
}

int countDigit(int n)
{
	if (n <= 0) return 0;
	return 1 + countDigit(n / 10);
}

int Fib(int n)
{
	if (n == 0)	return 0;
	if (n == 1) return 1;
	return Fib(n - 2) + Fib(n - 1);
}

// File Handling:
Examinee readExaminee(string line_info) {
    Examinee stu;
    vector<float> point(11);
    int d = 0;
    int positionFirstComma = line_info.find(",");
    stu.id = line_info.substr(0, positionFirstComma);
    for (size_t i = positionFirstComma + 1; i < line_info.size(); i++)   
    {
        if (d == 11) break;
        if (line_info[i] == ',')
        {
            if (line_info[i + 1] == ',') point[d++] = 0;
            else
            {
                int nextComma = line_info.find(",", i + 1);
                string sub = line_info.substr(i + 1, nextComma - 1);
                point[d++] = stof(sub);
            }
        }
    }

    stu.math = point[0];    stu.literature = point[1];  stu.physic = point[2];  stu.chemistry = point[3];
    stu.biology = point[4]; stu.history = point[5]; stu.geography = point[6]; stu.civic_education = point[7];
    stu.foreign_language = point[8];

    stu.natural_science = stu.physic + stu.chemistry + stu.biology;
    stu.social_science = stu.history + stu.geography + stu.civic_education;

    return stu;

}

vector<Examinee> readExamineeList(string file_name)
{
    fstream fi;
    vector<Examinee> list;
    fi.open(file_name);
    if (fi.is_open())
    {
        fi.ignore(1000, '\n');
        while (!fi.eof())
        {
            string s;
            getline(fi, s);
            list.push_back(readExaminee(s));
        }
    }

    return list;
}

void writeTotal(vector<Examinee> examinee_list, string out_file_name)
{
    ofstream fo;
    float sum = 0;
    fo.open(out_file_name);
    if (fo.is_open())
    {
        for (size_t i = 0; i < examinee_list.size(); i++)
        {
            sum = examinee_list[i].math + examinee_list[i].literature + examinee_list[i].foreign_language + examinee_list[i].natural_science + examinee_list[i].social_science;
            fo << examinee_list[i].id << " " << sum << endl;
        }
    }
    //cout << "Successful" << endl;
}


// Linked List:
NODE* createNode(int data)
{
	NODE* newNode = new NODE;
	if (newNode == NULL)	return nullptr;
	newNode->key = data;
	newNode->next = nullptr;
	return newNode;
}

List* createList(NODE* p_node)
{
	List* newList = new List;
	if (newList == NULL)	return nullptr;
	newList->head = newList->tail = p_node;
	return newList;
}

bool addHead(List*& L, int data)
{
	NODE* newNode = createNode(data);
	if (newNode == nullptr)	return false;

	if (L == nullptr)
	{
		L = createList(newNode);
		if (L == NULL)	return false;
	}
	else {
		newNode->next = L->head;
		L->head = newNode;
	}
	return true;
}

bool addTail(List*& L, int data)
{
	NODE* newNode = createNode(data);
	if (newNode == nullptr)	return false;

	if (L == nullptr)
	{
		L = createList(newNode);
		if (L == NULL)	return false;
	}
	else {
		L->tail->next = newNode;
		L->tail = newNode;		
	}
	return true;
}

void removeHead(List*& L)
{
	if (L->head == NULL)	return;
	if (L->head == L->tail)
	{
		delete L->head;
		L->head = L->tail = nullptr;
	}
	else {
		NODE* temp = L->head;
		L->head = L->head->next;
		delete temp;
	}
	return;
}

void removeTail(List*& L)
{
	if (L->head == NULL)	return;
	if (L->head == L->tail)
	{
		delete L->tail;
		L->head = L->tail = nullptr;
	}
	else {
		NODE* cur = L->head;
		while (cur->next != L->tail)
		{
			cur = cur->next;
		}
		delete L->tail;
		L->tail = cur;		
		L->tail->next = nullptr;
	}
	return;
}

void removeAll(List*& L)
{
	while (L->head != NULL)
	{
		NODE* temp = L->head;
		L->head = L->head->next;
		delete temp;
	}
	L->head = L->tail = nullptr;
}

void printList(List* L)
{
	if (L->head == NULL)
	{
		cout << "List is empty" << endl;	return;
	}
	else {
		NODE* temp = L->head;
		while (temp != NULL)
		{
			cout << temp->key << "  ";
			temp = temp->next;
		}
		cout << endl;
	}
}

int countElements(List* L)
{
	int d = 0;
	if (L->head == NULL)
	{
		d = 0;
	}
	else {
		NODE* temp = L->head;
		while (temp != NULL)
		{
			d++;
			temp = temp->next;
		}	
	}
	return d;
}

List* reverseList(List* L)
{
	List* rvList = createList(L->head);
	if (rvList == NULL)	return nullptr;
	NODE* cur = L->head->next;
	while (cur)
	{
		addHead(rvList, cur->key);
		cur = cur->next;
	}
	return rvList;
}

void RemoveDuplicate(List*& L)
{
	NODE *ptr1, *ptr2, *temp; 
    ptr1 = L->head; 
  
    while (ptr1 != NULL && ptr1->next != NULL) 
    { 
        ptr2 = ptr1;  
        while (ptr2->next != NULL) 
        { 
            if (ptr1->key == ptr2->next->key) 
            { 
                temp = ptr2->next; 
                ptr2->next = ptr2->next->next; 
                delete temp; 
            } 
            else ptr2 = ptr2->next; 
        } 
        ptr1 = ptr1->next; 
    } 
}

bool RemoveElement(List*& L, int key)
{
	if (L->head == NULL)	return false;
	NODE* cur = L->head, * prevNode = nullptr;
	if (cur->key == key)
	{
		L->head = cur->next;
		delete cur;
		return true;
	}
	else {
		while (cur != NULL && cur->key != key)
		{
			prevNode = cur;
			cur = cur->next;
		}
		if (cur != NULL)
		{
			prevNode->next = cur->next;
			delete cur;
			return true;
		}
	}
	return false;
}


// Stack:
void Initialize(NODE* &top, int k)
{
	top = new NODE;
	if (top == NULL) return;
	top->key = k;
	top->next = nullptr;
}

void Push(NODE*& top, int k)
{
	NODE* newNode = new NODE;
	newNode->key = k;
	
	if (isEmpty(top))
	{
		top = newNode;
	    newNode->next = nullptr;
	}
	else {
		newNode->next = top;
		top = newNode;
	}
}


void Pop(NODE*& top, int& value)
{
	NODE* temp = nullptr;
	if (isEmpty(top))
	{
		cout << "The stack is empty.\n";
	}
	else {
		value = top->key;
		temp = top->next;
		delete top;
		top = temp;
	}
}

bool isEmpty(NODE* top)
{
	bool status;
	if (!top) status = true;
	else status = false;
	return status;
}

int Count(NODE* top)
{
	int d = 0;
	if (top == NULL)
	{
		d = 0;
	}
	else {
		NODE* temp = top;
		while (temp != NULL)
		{
			d++;
			temp = temp->next;
		}
	}
	return d;
}


// Queue:

void Initialize(NODE*& front, int data)
{
	front = new NODE;
	front->key = data;
	front->next = nullptr;
}

void Enqueue(NODE *&front, int data)
{
	NODE* newNode = new NODE;
	if (newNode == nullptr)	return;
	newNode->key = data;
	newNode->next = nullptr;

	if (front == nullptr)
	{
		front = newNode;
	}
	else {
		NODE* cur = front;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}	
}

void Dequeue(NODE*& front, int& value)
{
	if (front == nullptr) return;
	NODE* temp = front;
	front = front->next;
	value = temp->key;
	delete temp;
}

int Coount(NODE* front)
{
	int d = 0;
	if (front == nullptr)
	{
		d = 0;
	}
	else {
		NODE* temp = front;
		while (temp != nullptr)
		{
			d++;
			temp = temp->next;
		}
	}
	return d;
}

bool isEmpty(NODE* front)
{
	bool status;
	if (!front) status = true;
	else status = false;
	return status;
}




																								// POSFIX BALAN


bool operator <(char& c1, string& c2)
{
	return ((c1 == '+' || c1 == '-') && (c2 == "*" || c2 == "/"));
}

bool operator ==(char& c1, string& c2)
{
	return ((c1 == '+' && c2 == "-") || (c1 == '-' && c2 == "+")
		|| (c1 == '*' || c2 == "/") || (c1 == '/' || c2 == "*"));
}

bool operator <=(char& c1, string& c2)
{
	return (c1 < c2) || (c1 == c2);
}


bool detectNumber(string s, int& index, double &number)
{
	bool isNum = false;
	if ('0' <= s[index] && s[index] <= '9')
	{
		int j = 0;
		double temp = 0;
		while ('0' <= s[index + j] && s[index + j] <= '9')
		{
			temp = temp * 10 + ((double)s[index + j] - 48);
			j++;
		}
		index = index + j - 1;
		isNum = true;
		number = temp;
	}
	return isNum;
}

bool checkIsValid(string inStr)
{
	int s = 0, numbers = 0, operations = 0;
	double tempNumber;
	for (int i = 0; i < inStr.size(); i++)
	{
		if (s < 0)
		{
			return false;
		}
		if (inStr[i] == '(') s++;
		else if (inStr[i] == ')') s--;
		else if (detectNumber(inStr, i, tempNumber)) numbers++;
		else if (inStr[i] == '+' || inStr[i] == '-' || inStr[i] == '*' || inStr[i] == '/') operations++;
	}
	if (s == 0 && operations == numbers - 1) return true;
	else return false;
}

bool Postfix_Creation(string s, string &result)
{
	bool isSuccess = true;
	Stack<string> Operators;
	Queue<char> posStr;
	for (int i = 0; i < s.length(); i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			posStr.enqueue(s[i]);
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{			
			string tempOper;
			tempOper += s[i];			
			if (Operators.isEmpty())
			{
				posStr.enqueue(' ');
				Operators.push(tempOper);
			}
			else {
				string topOper = Operators.top();
				while ((topOper == "+" || topOper == "-" || topOper == "*" || topOper == "/") && s[i] <= topOper && topOper != "(")
				{
					string temp;
					Operators.pop(temp);	
					posStr.enqueue(' ');
					posStr.enqueue(temp[0]);
					if (Operators.size() != 0) topOper = Operators.top();
					else break;
				}
				posStr.enqueue(' ');
				Operators.push(tempOper);
			}
		}				
		else if (s[i] == '(')	Operators.push("(");
		else if (s[i] == ')')
		{
			string temp;
			while (Operators.top() != "(")
			{
				Operators.pop(temp);
				posStr.enqueue(' ');
				posStr.enqueue(temp[0]);
			}
			Operators.pop(temp);
		}		
	}
	while (Operators.isEmpty() == 0)
	{
		string temp;
		Operators.pop(temp);
		posStr.enqueue(' ');
		posStr.enqueue(temp[0]);
	}
	while (posStr.isEmpty()==0)
	{
		char temp;
		posStr.dequeue(temp);	
		result = result + temp;
	}
	return isSuccess;
}

double Postfix_Evalution(string posStr)
{
	Stack<double> stack;
	double result = 0;
	double number, num1, num2;
	for (int i = 0; i < posStr.size(); i++)
	{
		if (detectNumber(posStr, i, number))
		{
			stack.push(number);
		}
		else if (posStr[i] == '+')
		{
			stack.pop(num2);
			stack.pop(num1);
			stack.push(num1 + num2);
		}
		else if (posStr[i] == '-')
		{
			stack.pop(num2);
			stack.pop(num1);
			stack.push(num1 - num2);
		}
		else if (posStr[i] == '*')
		{
			stack.pop(num2);
			stack.pop(num1);
			stack.push(num1 * num2);
		}
		else if (posStr[i] == '/')
		{
			stack.pop(num2);
			stack.pop(num1);
			stack.push(num1 / num2);
		}
	}
	stack.pop(number);
	return number;

}




























































