#include<stdio.h>
// 打印结果
void Show(int  arr[], int n)
{
    int i;
    for ( i=0; i<n; i++ )
        printf("%d  ", arr[i]);
    printf("\n");
}
 
// 交换数组元素位置
void Swap( int *num_a, int *num_b )
{
    int temp = *num_b;
    *num_b = *num_a;
    *num_a = temp;
}
 
// array是待调整的堆数组,i是待调整的数组元素的位置,nlength是数组的长度
void HeapAdjust(int array[], int i, int nLength)
{
    int nChild, nTemp;
    for (nTemp = array[i]; 2 * i + 1 < nLength; i = nChild)
    {
        // nChild:左子结点的位置是 父结点位置 * 2 + 1  nChild + 1： 右子结点 
        nChild = 2 * i + 1;
        // 得到子结点中较大的结点
        if (nChild != nLength - 1 && array[nChild + 1] > array[nChild])
            ++nChild;
        // 如果较大的子结点大于父结点那么把较大的子结点往上移动,替换它的父结点
        if (nTemp < array[nChild])
        {
            array[i] = array[nChild];
        }
        else  // 否则退出循环
        {
            break;
        }
    }
    // 最后把需要调整的元素值放到合适的位置
    array[i] = nTemp;
}
// 堆排序算法
void HeapSort(int array[], int length)
{
    // 调整序列的前半部分元素,（即每个有孩子的节点）调整完之后是一个大顶堆，第一个元素是序列的最大的元素
    for (int i = length / 2 - 1; i >= 0; --i)
    {
        HeapAdjust(array, i, length);
    }
    // 从最后一个元素开始对序列进行调整,不断的缩小调整的范围直到第一个元素
    for (int i = length - 1; i > 0; --i)
    {
        // 把第一个元素和当前的最后一个元素交换,
        // 保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
        Swap(&array[0], &array[i]);
        // 不断缩小调整heap的范围,每一次调整完毕保证第一个元素是当前序列的最大值
        HeapAdjust(array, 0, i);
    }
}
 
int main()
{   //测试数据
    int arr_test[15] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 48, 50 };
    //排序前数组序列
    Show( arr_test, 15 );
    HeapSort( arr_test, 15 );
    //排序后数组序列
    Show( arr_test, 15 );
    return 0;
}
