#include<stdio.h>
#include"InfixToPostfix.h"
#include"PostCalculdator.h"

int main() {
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	printf("%d\n", sizeof(exp1));
	ConvToRPNExp(exp1);
	ConvToRPNExp(exp2);
	ConvToRPNExp(exp3);

	printf("%s = %d\n", exp1,EvalPRNExp(exp1));
	printf("%s = %d\n", exp2, EvalPRNExp(exp2));
	printf("%s = %d\n", exp3, EvalPRNExp(exp3));

	
}