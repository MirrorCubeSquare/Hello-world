#include <stdio.h>
#include<math.h>
double cosbyedge(double x,double y,double z)
{
	double temp;
		temp=(pow(x,2)+pow(y,2)-pow(z,2))/(2*x*y);
	return temp;
}

void main()
{
	double a,b,c,area,p,yxc,yxb,yxa;
	printf("请输入三角形的三条边：\n");
	scanf("%lf%lf%lf",&a,&b,&c);
	if(c<b){p=c;c=b;b=p;}
	if(c<a){p=a;a=c;c=p;}
	if(b<a){p=b;b=c;c=p;}
	if (a+b<c)
	{
		printf("不能构成三角形\n");
		return;
	}
	p=(a+b+c)/2.0;
	area=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("三角形的面积=%.2f\n",area);
		if(a==b&&b==c)printf("三角形为等边三角形\n");
	if(a==b&&b!=c||a==c&&b!=c||b==c&&a!=b)printf("三角形是等腰三角形（非等边）\n");
	if(fabs(sqrt(pow(a,2)+pow(b,2))-c)<1e-6)printf("三角形是直角三角形\n");
    else
	{
		yxc=cosbyedge(a,b,c);
		if (yxc<0)printf("三角形为钝角三角形\n");else printf("三角形是锐角三角形\n");
	}

}

