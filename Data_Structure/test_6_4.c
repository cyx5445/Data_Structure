#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//typedef struct com
//{
//	float realpart;		/*定义实部*/
//	float imagpart;		/*定义虚部*/
//}Complex;				/*虚数类型创建*/
//
// /*声明虚数*/
//void assign(Complex* A, float real, float imag)	
//{
//	A->imagpart = real;
//	A->realpart = imag;
//}
//
// /*虚数相加*/
//void add(Complex* C, const Complex A, const Complex B)
//{
//	C->realpart = A.realpart + B.realpart;
//	C->imagpart = A.imagpart + B.imagpart;
//}
//
// /*虚数相减*/
//void sub(Complex* C, const Complex A, const Complex B)
//{
//	C->realpart = A.realpart - B.realpart;
//	C->imagpart = A.imagpart - B.imagpart;
//}
//
// /*虚数相乘*/
//void mul(Complex* C, const Complex A, const Complex B)
//{
//	C->realpart = A.realpart * B.realpart;
//	C->imagpart = A.imagpart * B.imagpart;
//}
//
// /*虚数相除*/
//void division(Complex* C, Complex A, Complex B)		/*div是库函数，不得自定义*/
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

