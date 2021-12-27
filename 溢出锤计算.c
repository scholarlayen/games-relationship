//此软件用于求解文明5溢出锤问题
//经计算，存在更优解的条件为：
//	1)           1.5nt > 106
//  2)  1.5nt - 1.5gap < 106
//  3)             gap < t
//	4)   0.5n - 1.5gap > 0

#include<stdio.h>
#include<math.h>

//全局变量声明
float n;		//最大生产力（加成前）
int t;			//最大生产力所用时间
int gap;		//减产回合数
float expro;	//溢出锤

void parameters()
{
	printf("请输入最大生产力（加成前）：");
	scanf_s("%f", &n);
	return 0;
}

int main()
{
	//收集参数   n —— 最大生产力（加成前）
	parameters();
	//计算参数   t —— 最大生产力所用时间 
	t = ceil(106 / 1.5 / n);
	//计算参数 gap —— 减产回合数 
	gap = ceil((1.5 * n * t - 106) / 1.5);
	//计算溢出锤
	if (gap >= t)
	{
		expro = 1.5 * n * t - 106;
		printf("最优方案为：使用最大生产力%d回合完成移民，此时溢出锤为：%f", t, expro);
	}
	else
	{
		expro = 1.5 * n * t - 1.5 * gap + 1.5 * n - 106;
		printf("最优方案为：使用最大生产力%d回合，减少1点生产力%d回合完成移民\n共计使用%d回合，此时溢出锤为：%f\n", (t - gap), gap, t, expro);
	}
	getch();
	return 0;
}