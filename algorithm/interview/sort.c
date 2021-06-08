#include <iostream>
#include <vector>

#define SWAP(x, y) \
  if (x != y) {    \
    x = x ^ y;     \
    y = x ^ y;     \
    x = x ^ y;     \
  }

static std::vector<int> arrary;

void print_arrary() {
  std::cout << "-------------------------------" << std::endl;  
  for (auto val = arrary.begin(); val != arrary.end(); ++val) {      
    std::cout << *val << std::endl;                            
  }                                                            
  std::cout << "-------------------------------" << std::endl << std::endl; 
}
void reset_arrary() {
  std::vector<int> temp = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };
  temp.swap(arrary);
}

void bucket_sort() {
  std::cout << "start bucket sort" << std::endl;

  int max_val = arrary[0];
  for (int i = 1; i < arrary.size(); ++i) {
    if (arrary[i] > max_val)
      max_val = arrary[i];
  }
  max_val += 1;

  std::vector<int> counting_arr(max_val, 0);
  for (int i = 0; i < arrary.size(); ++i) {
    counting_arr[arrary[i]] += 1;
  }

  int idx = 0;
  for (int i = 0; i < max_val; ++i) {
    for (int j = counting_arr[i]; j > 0; --j) {
      arrary[idx++] = i;
    }
  }
}


void counting_sort() {
  std::cout << "start counting sort" << std::endl;

  int max_val = arrary[0];
  for (int i = 1; i < arrary.size(); ++i) {
    if (arrary[i] > max_val)
      max_val = arrary[i];
  }
  max_val += 1;

  std::vector<int> counting_arr(max_val, 0);
  std::vector<int> sorted_arr(arrary.size(), 0);

  for (int i = 0; i < arrary.size(); ++i) {
    counting_arr[arrary[i]] += 1;
  }
  for (int i = 1; i < max_val; ++i) {
    counting_arr[i] += counting_arr[i - 1];
  }

  for (int i = 0; i < arrary.size(); ++i) {
    counting_arr[arrary[i]] -= 1;
    sorted_arr[counting_arr[arrary[i]]] = arrary[i];
  }

  arrary.swap(sorted_arr);
}


void quick_sort(int left, int right) {
  if (left > right) {
    return;
  }

  int i = left, j = right, pivot = arrary[left];
  while (i != j) {
    while (i < j && arrary[j] >= pivot) --j;
    while (i < j && arrary[i] <= pivot) ++i;
    if (i < j) {
      SWAP(arrary[i], arrary[j]);
    }
  }

  int mid = i;
  arrary[left] = arrary[mid];
  arrary[mid] = pivot;

  quick_sort(left, mid - 1);
  quick_sort(mid + 1, right);
}


void heapify(int last_idx, int cur_node_idx) {
  int max = cur_node_idx;

  int c_1 = cur_node_idx * 2 + 1;
  if (c_1 <= last_idx && arrary[c_1] > arrary[max]) {
    max = c_1;
  }

  int c_2 = cur_node_idx * 2 + 2;
  if (c_2 <= last_idx && arrary[c_2] > arrary[max]) {
    max = c_2;
  }

  if (max != cur_node_idx) {
    SWAP(arrary[max], arrary[cur_node_idx]);
    heapify(last_idx, max);
  }
}
void built_heap() {
  int last_idx = arrary.size() - 1;
  int parent = (last_idx - 1) / 2;

  for (; parent >= 0; --parent) {
    heapify(last_idx, parent);
  }
}
void heap_sort() {
  std::cout << "start heap sort" << std::endl;

  built_heap();

  int last_idx = arrary.size() - 1;
  for (; last_idx > 0; --last_idx) {
    SWAP(arrary[0], arrary[last_idx]);
    heapify(last_idx - 1, 0);
  }
}


void merge_sort(int L, int M, int R) {
  int left_size = M - L;
  std::vector<int> left(left_size);
  for (int i = L; i < M; ++i) {
    left[i - L] = arrary[i];
  }

  int right_size = R - M + 1;
  std::vector<int> right(right_size);
  for (int i = M; i <= R; ++i) {
    right[i - M] = arrary[i];
  }

  int i = 0, j = 0, k = L;
  while (i < left_size && j < right_size) {
    if (left[i] < right[j]) {
      arrary[k++] = left[i++];
    } else {
      arrary[k++] = right[j++];
    }
  }

  while (i < left_size) {
    arrary[k++] = left[i++];
  }
  while (j < right_size) {
    arrary[k++] = right[j++];
  }
}
void merge_split(int low_idx, int high_idx) {
  if (low_idx == high_idx) {
    return;
  } else {
    int mid = (low_idx + high_idx) / 2;
    merge_split(low_idx, mid);
    merge_split(mid + 1, high_idx);
    merge_sort(low_idx, mid + 1, high_idx);
  }
}


void shell_sort(void) {
  std::cout << "start shell sort" << std::endl;

  for (int inc = arrary.size() / 2; inc > 0; inc /= 2) {

    for (int i = inc; i < arrary.size(); ++i) {
      int pivot = arrary[i];
      int j = i;
      for (; j >= inc && arrary[j - inc] > pivot; j -= inc) {
        arrary[j] = arrary[j - inc];
      }
      arrary[j] = pivot;
    }

  }
}


void insert_sort(void) {
  std::cout << "start insert sort" << std::endl;

  for (int i = 1; i < arrary.size(); ++i) {
    int pivot = arrary[i];
    int j = i - 1;
    for (; j >= 0 && arrary[j] > pivot; --j) {
      arrary[j + 1] = arrary[j];
    }
    arrary[j + 1] = pivot;
  }
}


void select_sort(void) {
  std::cout << "start select sort" << std::endl;

  for (int i = 0; i < arrary.size(); ++i) {
    int min = i;
    for (int j = i + 1; j < arrary.size(); ++j) {
      if (arrary[j] < arrary[min]) {
        min = j;
      }
    }

    if (min != i) {
      SWAP(arrary[min], arrary[i]);
    }
  }
}


void bubble_sort(void) {
  std::cout << "start bubble sort" << std::endl;

  for (int i = 0; i < arrary.size(); ++i) {
    for (int j = 0; j < arrary.size() - i - 1; ++j) {
      if (arrary[j + 1] < arrary[j]) {
        SWAP(arrary[j + 1], arrary[j]);
      }
    }
  }
}

int main(int argc, char *argv[]) {
  reset_arrary();

  bubble_sort();
  print_arrary(); reset_arrary();

  select_sort();
  print_arrary(); reset_arrary();

  insert_sort();
  print_arrary(); reset_arrary();

  shell_sort();
  print_arrary(); reset_arrary();

  std::cout << "start merge sort" << std::endl;
  merge_split(0, arrary.size() - 1);
  print_arrary(); reset_arrary();

  heap_sort();
  print_arrary(); reset_arrary();

  std::cout << "start quick sort" << std::endl;
  quick_sort(0, arrary.size() - 1);
  print_arrary(); reset_arrary();

  counting_sort();
  print_arrary(); reset_arrary();

  bucket_sort();
  print_arrary(); reset_arrary();

  return EXIT_SUCCESS;
}
