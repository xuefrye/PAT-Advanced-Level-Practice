#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

struct Student
{
	char number[20];
	int score;
	int location;
	int local_rank = 1;
	int final_rank = 1;
};

bool compare(Student &a, Student &b)
{
	if (a.score != b.score)
		return a.score > b.score;
	else 
		return strcmp(a.number,b.number) < 0; //字典序排列.
}
 
int main()
{	
	vector<Student> students;
	Student student;
	int n,m,total = 0;//n考场数(1-100),m考场学生数(1-300),总人数
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		student.location = i;
		scanf("%d", &m);
		for (int j = 0; j < m; j++)
		{ 
			scanf("%s %d", student.number, &student.score);
			students.push_back(student);
			total++; //每路一个人+1
		}

		//注意这一句用vs运行时会产生assertion failed,因为第二个参数指针越界(尾后指针).但是这个sort函数必须要填入尾后指针...,
		//所以逻辑上是没有错误的,也并不会产生风险,解决方法使用vs的release模式,或者其他编译器.
		//实在不行用数组替代vector...不会越界检查.
		//sort(&students[total - m], &students[total], compare);

		sort(students.begin()+(total - m), students.end(), compare);

		for (int j = total - m + 1; j < total; j++)
		{
			students[j-1].score == students[j].score ?
				students[j].local_rank = students[j-1].local_rank :
				students[j].local_rank = j - (total - m) + 1;
		}
	}

	sort(students.begin(), students.end(), compare);

	int size = students.size();
	for (int i = 1; i < size; i++)
	{
		students[i].score == students[i-1].score ?
			students[i].final_rank = students[i-1].final_rank : //后者的排名等于前者.
			students[i].final_rank = i + 1;
	}

	printf("%d\n", total);
	for (int i = 0; i < size; i++)
		printf("%s %d %d %d\n", students[i].number,students[i].final_rank,students[i].location, students[i].local_rank);

	system("pause");
}