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
		return strcmp(a.number,b.number) < 0; //�ֵ�������.
}
 
int main()
{	
	vector<Student> students;
	Student student;
	int n,m,total = 0;//n������(1-100),m����ѧ����(1-300),������
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		student.location = i;
		scanf("%d", &m);
		for (int j = 0; j < m; j++)
		{ 
			scanf("%s %d", student.number, &student.score);
			students.push_back(student);
			total++; //ÿ·һ����+1
		}

		//ע����һ����vs����ʱ�����assertion failed,��Ϊ�ڶ�������ָ��Խ��(β��ָ��).�������sort��������Ҫ����β��ָ��...,
		//�����߼�����û�д����,Ҳ�������������,�������ʹ��vs��releaseģʽ,��������������.
		//ʵ�ڲ������������vector...����Խ����.
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
			students[i].final_rank = students[i-1].final_rank : //���ߵ���������ǰ��.
			students[i].final_rank = i + 1;
	}

	printf("%d\n", total);
	for (int i = 0; i < size; i++)
		printf("%s %d %d %d\n", students[i].number,students[i].final_rank,students[i].location, students[i].local_rank);

	system("pause");
}