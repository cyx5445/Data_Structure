#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//typedef struct com
//{
//	float realpart;		/*����ʵ��*/
//	float imagpart;		/*�����鲿*/
//}Complex;				/*�������ʹ���*/
//
// /*��������*/
//void assign(Complex* A, float real, float imag)	
//{
//	A->imagpart = real;
//	A->realpart = imag;
//}
//
// /*�������*/
//void add(Complex* C, const Complex A, const Complex B)
//{
//	C->realpart = A.realpart + B.realpart;
//	C->imagpart = A.imagpart + B.imagpart;
//}
//
// /*�������*/
//void sub(Complex* C, const Complex A, const Complex B)
//{
//	C->realpart = A.realpart - B.realpart;
//	C->imagpart = A.imagpart - B.imagpart;
//}
//
// /*�������*/
//void mul(Complex* C, const Complex A, const Complex B)
//{
//	C->realpart = A.realpart * B.realpart;
//	C->imagpart = A.imagpart * B.imagpart;
//}
//
// /*�������*/
//void division(Complex* C, Complex A, Complex B)		/*div�ǿ⺯���������Զ���*/
//{
//	C->realpart = A.realpart / B.realpart;
//	C->imagpart = A.imagpart / B.imagpart;
//}
//
//int main()
//{
//	Complex z1, z2, z3, z4, z;
//	float realpart, imagpart;
//	float a = 8.0;
//	float b = 6.0;
//	float c = 4.0;
//	float d = 3.0;
//	assign(&z1, a, b);
//	assign(&z2, c, d);
//	add(&z3, z1, z2);
//	mul(&z4, z1, z2);
//	division(&z, z4, z3);
//	realpart = z.realpart;
//	imagpart = z.imagpart;
//	printf("%.2f %.2fi\n", realpart, imagpart);
//	return 0;
//}

