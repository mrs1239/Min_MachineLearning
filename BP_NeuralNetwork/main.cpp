#include "BPNetwork.h"

#define TRAINSAMPLENUM 15
#define TESTSAMPLENUM 4

int main()
{
	BpNet testNet;

	//ѧϰ�������� 15��
	vector<double> samplein[TRAINSAMPLENUM];
	vector<double> sampleout[TRAINSAMPLENUM];

	samplein[0].push_back(1.78); samplein[0].push_back(1.14); sampleout[0].push_back(0.9);
	samplein[1].push_back(1.96); samplein[1].push_back(1.18); sampleout[1].push_back(0.9);
	samplein[2].push_back(1.86); samplein[2].push_back(1.20); sampleout[2].push_back(0.9);
	samplein[3].push_back(1.72); samplein[3].push_back(1.24); sampleout[3].push_back(0.1);
	samplein[4].push_back(2.00); samplein[4].push_back(1.26); sampleout[4].push_back(0.9);
	samplein[5].push_back(2.00); samplein[5].push_back(1.28); sampleout[5].push_back(0.9);
	samplein[6].push_back(1.96); samplein[6].push_back(1.30); sampleout[6].push_back(0.9);
	samplein[7].push_back(1.74); samplein[7].push_back(1.36); sampleout[7].push_back(0.1);
	
	samplein[8].push_back(1.64); samplein[8].push_back(1.38); sampleout[8].push_back(0.1);
	samplein[9].push_back(1.82); samplein[9].push_back(1.38); sampleout[9].push_back(0.1);
	samplein[10].push_back(1.90); samplein[10].push_back(1.38); sampleout[10].push_back(0.1);
	samplein[11].push_back(1.70); samplein[11].push_back(1.40); sampleout[11].push_back(0.1);
	samplein[12].push_back(1.82); samplein[12].push_back(1.48); sampleout[12].push_back(0.1);
	samplein[13].push_back(1.82); samplein[13].push_back(1.54); sampleout[13].push_back(0.1);
	samplein[14].push_back(2.08); samplein[14].push_back(1.56); sampleout[14].push_back(0.1);
	
	sample sampleInOut[TRAINSAMPLENUM];
	for (int i = 0; i < TRAINSAMPLENUM; i++)
	{
		sampleInOut[i].in = samplein[i];
		sampleInOut[i].out = sampleout[i];
	}
	vector<sample> sampleGroup(sampleInOut, sampleInOut + TRAINSAMPLENUM);

	//ѵ����������
	testNet.training(sampleGroup, 0.1); //Ϊ��ʹ����ʱ���Щ������Ŀ�����Ϊ0.1���������ø�С��ֵ

	//������������  ����0.9 ����0.1
	vector<double> testin[TESTSAMPLENUM];
	vector<double> testout[TESTSAMPLENUM];
	testin[0].push_back(1.78);   testin[0].push_back(1.14);
	testin[1].push_back(1.96);  testin[1].push_back(1.18);
	testin[2].push_back(1.82);   testin[2].push_back(1.38);
	testin[3].push_back(1.70);  testin[3].push_back(1.40);

	sample testInOut[TESTSAMPLENUM];
	for (int i = 0; i < TESTSAMPLENUM; i++) testInOut[i].in = testin[i];
	vector<sample> testGroup(testInOut, testInOut + TESTSAMPLENUM);

	// Ԥ��������ݣ���������
	testNet.predict(testGroup);
	for (int i = 0; i < testGroup.size(); i++)
	{
		for (int j = 0; j < testGroup[i].in.size(); j++) cout << testGroup[i].in[j] << "\t";
		cout << "-- Ԥ���� :";
		for (int j = 0; j < testGroup[i].out.size(); j++) {		//cout << testGroup[i].out[j] << "\t";
			
			if (testGroup[i].out[j] >0 && testGroup[i].out[j] <0.3)  //������ֵ��0��0.3֮�䣬Ԥ����������ΪAf
			{
				cout << testGroup[i].out[j] << "\t" << "�����������Af" << "\t";
			}
			else if (testGroup[i].out[j] >0.7 && testGroup[i].out[j] <1.1)	//������ֵ��0.7��1.1֮�䣬Ԥ����������ΪAf
			{
				cout << testGroup[i].out[j] << "\t" << "�����������Apf" << "\t";
			}
			else
			{
				cout << testGroup[i].out[j] << "\t" << "�������������" << "\t";
			}
		}
			
		
		cout << endl;
	}

	system("pause");
	return 0;
}