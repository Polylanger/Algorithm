#include "Common.h"

using namespace std;

/* ð������
 * �Ƚϴ��������ʼ����˳���޹أ����۳�ʼ�б�ʲô˳�򣬶���Ҫ�Ƚ� O(n^2) �β��ܽ���
 * �����������������ǳ�ʼ�б��������У���Ҫ���� O(n^2)
 *           ���������ǳ�ʼ��˳�����У���������Ϊ 0
 */
void bubbleSort(int list[], int left, int right) {
  for (int i = left + 1; i <= right; i++) {
    // exchange = false;  // Ϊ�Ż���������Ч�ʣ����壺�Ƿ���������־
    for (int j = right; j >= i; j--) {
      if (list[j - 1] > list[j]) {
        // exchange = true; // �����δ����������־��Ϊ�н���״̬
        int temp = list[j - 1];
        list[j - 1] = list[j];
        list[j] = temp;
      }
    }
    // if (!exchange) return; // ����־Ϊδ����״̬��˵����β��ͷһ������û�����������б������������
  }
}

/* ֱ�Ӳ�������
 * ��������˳���б��Ƚ� n-1 �Σ��ƶ� 0 �Ρ����ص㣡��������ֱ�Ӳ�������Գ�ʼ˳�������У��������� Shell �����˼��
 * �����������б�O(n^2)
 */
void insertSort(int list[], int left, int right) {
  int temp, i, j;
  for (i = left + 1; i <= right; i++) {
    temp = list[i]; 
    for (j = i; j > left && list[j - 1] > temp; j--) {
      list[j] = list[j - 1];
    }
    list[j] = temp;
  }
}

/* �۰��������
 * �Ƚϴ������б��ʼ˳���޹أ���Ҫ�Ƚ� O(nlogn) ��
 * �ƶ�������ֱ�Ӳ������������ͬ��O(n^2)
 */
void binaryInsertSort(int list[], int left, int right) {
  int temp, i, j;
  int middle, low, high;
  for (i = left + 1; i <= right; i++) {
    temp = list[i];

    // ���ֲ��ң�δ�鵽ʱȷ�� low ָ��ʵ��λ���ұߵ�һ��Ԫ��
    low = left; high = i - 1;
    while (low <= high) { // ����ȡ����Ӧ�ԣ�ʵ��λ��λ�ڱ任��� high �ұߵĳ���
      middle = (low + high) / 2; 
      if (list[middle] > temp) high = middle - 1;
      else low = middle + 1;
    }

    for (j = i; j > low; j--) list[j] = list[j - 1];

    list[low] = temp;
  }
}

/* Shell ����
 * ���ȶ��������㷨
 * ��ʼʱ gap �ϴ�ÿ��������Ԫ�ؽ��٣������ٶȽϿ죻
 * ���� gap ��С��������Ԫ�ر�࣬������֮ǰ�Ĺ�����ʹ��ÿ�������л������򣬹������ٶ����ɺܿ졣
 */
void shellSort(int list[], int left, int right) {
  int temp, i, j, gap = right - left + 1;
  do {
    gap = (gap / 3) + 1;
    // ֱ����������ѭ���Ǵ���ߵڶ���Ԫ�ؿ�ʼ
    // ��Shell��������ѭ����ÿ�������еĵڶ���Ԫ�ؿ�ʼ������left + gap
    for (i = left + gap; i <= right; i++) {
      temp = list[i];
      // ͬһ������������Ԫ���±�֮��Ϊ gap
      for (j = i; j > left && list[j - gap] > temp; j -= gap) {
        list[j] = list[j - gap];
      }
      list[j] = temp;
    }
  } while (gap > 1);
}

int main() {
  int n = 17;
  int list[] = {77, 5, 29, 52, 4, 6, 31, 2, 21, 9, 10, 11, 8, 7, 33, 3, 1};

  //bubbleSort(list, 0, n - 1);
  //insertSort(list, 0, n - 1);
  //binaryInsertSort(list, 0, n - 1);
  shellSort(list, 0, n - 1);

  for (int i = 0; i < n; i++) {
    cout << list[i] << ", ";
  }
  return 0;
}

