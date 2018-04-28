#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define innode 2        //��������
#define hidenode 3    //���������
#define hidelayer 1     //��������
#define outnode 1       //��������
#define learningRate 0.9	//ѧϰ���ʣ�alpha

// --- -1~1 ����������� --- 
inline double get_11Random()    // ����-1--1֮������С������ȷ��С�����һλ�� 
{
	return ((2.0*(double)rand() / RAND_MAX) - 1);
}

// --- sigmoid ���� --- 
inline double sigmoid(double x)
{
	double ans = 1 / (1 + exp(-x));
	return ans;
}

// --- �����ڵ㡣�������·�����--- 
// 1.value:     �̶�����ֵ�� 
// 2.weight:    ��Ե�һ��������ÿ���ڵ㶼��Ȩֵ�� 
// 3.wDeltaSum: ��Ե�һ��������ÿ���ڵ�Ȩֵ��deltaֵ�ۻ�   delta��ʾ����
typedef struct inputNode
{
	double value;
	vector<double> weight, wDeltaSum;
}inputNode;

// --- �����ڵ㡣����������ֵ��--- 
// 1.value:     �ڵ㵱ǰֵ�� 
// 2.delta:     ����ȷ���ֵ֮���deltaֵ��   ���򴫲����
// 3.rightout:  ��ȷ���ֵ	�������ֵ
// 4.bias:      ƫ����	������
// 5.bDeltaSum: bias��deltaֵ���ۻ���ÿ���ڵ�һ��
typedef struct outputNode   // �����ڵ�
{
	double value, delta, rightout, bias, bDeltaSum;
}outputNode;

// --- ������ڵ㡣����������ֵ��--- 
// 1.value:     �ڵ㵱ǰֵ�� 
// 2.delta:     BP�Ƶ�����deltaֵ��
// 3.bias:      ƫ����
// 4.bDeltaSum: bias��deltaֵ���ۻ���ÿ���ڵ�һ��
// 5.weight:    �����һ�㣨������/����㣩ÿ���ڵ㶼��Ȩֵ�� 
// 6.wDeltaSum�� weight��deltaֵ���ۻ��������һ�㣨������/����㣩ÿ���ڵ���Ի���
typedef struct hiddenNode   // ������ڵ�
{
	double value, delta, bias, bDeltaSum;
	vector<double> weight, wDeltaSum;
}hiddenNode;

// --- �������� --- 
typedef struct sample
{
	vector<double> in, out;
}sample;

// --- BP������ --- 
class BpNet
{
public:
	BpNet();    //���캯��
	void forwardPropagationEpoc();  // ��������ǰ�򴫲�
	void backPropagationEpoc();     // �����������򴫲�

	void training(static vector<sample> sampleGroup, double threshold);// ���� weight, bias
	void predict(vector<sample>& testGroup);                          // ������Ԥ��

	void setInput(static vector<double> sampleIn);     // ����ѧϰ��������
	void setOutput(static vector<double> sampleOut);    // ����ѧϰ�������

public:
	double error;  //ʵ������Ҫ�����СĿ�����
	inputNode* inputLayer[innode];                      // ����㣨��һ�㣩
	outputNode* outputLayer[outnode];                   // ����㣨��һ�㣩
	hiddenNode* hiddenLayer[hidelayer][hidenode];       // �����㣨�����ж�㣩
};