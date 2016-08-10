#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>
#include<time.h>
using namespace std;
//#include"Heap.h"
#include "HuffmanTree.h"
#include "FileCompress.h"
void TestHuffmanTree()
{
	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	HuffmanTree<int> hf;
	hf.CreatTree(a, 10, -1);
}
void TestFileCompress()
{
	double T1, T2;

	FileCompress<FileInfo> fc;
	//fc.Compress("test.txt");//С�ļ�
	fc.Compress("Input.txt");
	T1 = clock();
	printf("ѹ���ļ���Ҫ��ʱ��: %f s \n", T1 / CLOCKS_PER_SEC);
	//fc.UnCompresss("test.txt");//С�ļ�
	fc.UnCompresss("Input.txt");
	T2 = clock();
	printf("ѹ���ļ���Ҫ��ʱ��: %f s \n", T2 / CLOCKS_PER_SEC);
	

}



int main()
{
	//Test2();
	//TestHeapSort();
	//TestHuffmanTree();
	TestFileCompress();
	getchar();
	return 0;
}