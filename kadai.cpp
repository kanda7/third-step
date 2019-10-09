#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <iostream>
#include <algorithm>

using namespace std;

// 合計の計算
double sum(double data[], int n)
{
	int i;                  // 変数の宣言
	double total = 0.0;

	for (i = 0; i < n; i++) {
		total += data[i];   // 合計を計算
	}

	return total;           // 合計を返す
}

// 平均の計算
double ave(double data[], int n)
{
	double total = sum(data, n);    // 合計
	return total / n;             	// 平均=合計/データ数
}

// 分散の計算
double var(double data[], int n) {
	int i;
	double a = ave(data, n);	// 平均値
	double v = 0.0;				// 分散
	// 分散を計算
	for (i = 0; i < n; i++)
		v += (data[i] - a) * (data[i] - a);
	return v / n;					// 分散の平均
}

// 標準偏差の計算
double st(double data[], int n) {
	return sqrt(var(data, n));			// 標準偏差=分散の平方根
}

double hensachi(double data[], int n, int num, int ave,int hensa) {
	return 10.0*(data[num] - ave) / hensa + 50.0;
}

// Main
int main(void)
{
	double sci[] = { 65, 80,67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 2,58.5, 46, 42, 78, 62, 84, 70 };  // 配列の宣言
	double eng[] = { 44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84 };  // 配列の宣言

	double hensa[20] = { 0 };
	double ave_sci = 0.0;
	double ave_eng = 0.0;

	double hensa_sci = 0.0;
	double hensa_eng = 0.0;


	int n = 20;     // 配列の要素数(データ数)

	printf("理科\n");
	ave_sci = ave(sci, n);
	printf("平均:%f", ave_sci);
	printf("合計:%f", sum(sci, n));
	hensa_sci = st(sci, n);
	printf("標準偏差:%f\n", hensa_sci);		// 計算結果を出力

	printf("英語\n");
	ave_eng = ave(eng, n);
	printf("平均:%f", ave(eng, n));
	printf("合計:%f", sum(eng, n));
	hensa_eng = st(eng, n);
	printf("標準偏差:%f\n", hensa_eng);		// 計算結果を出力

	for (int i = 0; i < 20; i++)
	{
		printf("%d人目の偏差値: 科学:%.3f", i+1, hensachi(sci, n, i, ave_sci, hensa_sci));
		printf("英語:%.3f\n", hensachi(eng, n, i, ave_eng, hensa_eng));
	}
	
	sort(sci, sci + 20);
	sort(eng, eng + 20);

	
	printf("科学の点数を降順にソート\n");
	for (int i = 19; i >= 0; i--)
	{
		printf("%.3f\n", sci[i]);
	}

	printf("\n英語の点数を降順にソート\n");
	for (int i = 19; i >= 0; i--)
	{
		printf("%.3f\n", eng[i]);
	}

	return 0;
}
