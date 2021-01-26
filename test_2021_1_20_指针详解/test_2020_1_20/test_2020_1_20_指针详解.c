#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//指针的进阶
//1. 字符指针
//2. 数组指针
//3. 指针数组
//4. 数组传参和指针传参
//5. 函数指针
//6. 函数指针数组
//7. 指向函数指针数组的指针
//8. 回调函数
//9. 指针和数组面试题的解析

//
//1. 指针就是个变量，用来存放地址，地址唯一标识一块内存空间。
//2. 指针的大小是固定的4 / 8个字节（32位平台 / 64位平台）。
//3. 指针是有类型，指针的类型决定了指针的 + -整数的步长，指针解引用操作的时候的权限。
//4. 指针的运算
//
//void test(int arr[])//首元素地址本质上是一个指针，指针大小为4或者8
//{
//	printf("%d\n", sizeof(arr) / sizeof(arr[0]));
//	//打印的结果是1或者2
//}
//int main()
//{
//	int arr[10] = { 0 };
//	test(arr);//数组名传过去是首元素地址
//
//	return 0;
//}

//字符指针
//在指针的类型中我们知道有一种指针类型为字符指针 char*
//一般使用:
//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;
//
//	return 0;
//}

//还有一种使用方式如下：

//int main()
//{
//	char arr[] = "abcdef";
//	char* pc = arr;//数组名为首元素地址
//	printf("%s\n", arr);//abcdef
//	printf("%s\n", pc);//abcdef
//	return 0;
//}

////还有一种写法：
//int main()
//{
//	char* pc = "abcdef";//"abcdef"是一个常量字符串，本质是把字符串abcdef首字符的地址放到了pc中
//	printf("%s\n", pc);//abcdef
//	return 0;
//}


//int main()
//{
//	char* p = "abcdef";//"abcdef"是一个常量字符串，不能被修改
//	//p是首元素地址
//	//*p = 'W';//"abcdef"是一个常量字符串，不能被修改
//	printf("%s\n", p);
//	return 0;
//}
////修改为：
//int main()
//{
//	const char* p = "abcdef";//最准确的写法 
//	//p是首元素地址
//	//*p = 'W';//"abcdef"是一个常量字符串，不能被修改
//	printf("%s\n", p);
//	return 0;
//}



//曾经的面试题

//int main()
//{
//	char str1[] = "hello bit.";
//	char str2[] = "hello bit.";
//	char* str3 = "hello bit.";//常量字符串
//	char* str4 = "hello bit.";
//	if (str1 == str2)
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//	return 0;
//}

//str1 and str2 are not same
//为了存储abcdef创建两个数组arr1, arr2,在内存中一定是有两个空间的，
//两个不同的数组不同数组名是首元素的地址



//str3 and str4 are same
//常量字符串abcdef，没有必要在内存中存两份

//这里str3和str4指向的是一个同一个常量字符串。C / C++会把常量字符串存储到单独的一个内存区域，
//当几个指针。指向同一个字符串的时候，他们实际会指向同一块内存。但是用相同的常量字符串去初始
//化不同的数组的时候就会开辟出不同的内存块。所以str1和str2不同，str3和str4不同。
//




//指针数组，是数组，用来存放指针的
//指针数组是一个存放指针的数组。
//int main()
//{
//	int arr[10] = { 0 };//整形数组
//	char ch[5] = { 0 };//字符数组
//	int* parr[4];//存放整型指针的数组，简称指针数组
//	char* pch[5];//存放字符指针的数组，简称指针数组
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int d = 40;
//	int* arr[4] = { &a, &b, &c, &d };
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d\n", *arr[i]);
//	}
//	system("pause");
//	return 0;
//}
//指针数组不是这么用的


////指针数组的用处//指针数组就是这么用的
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	//数组名是首元素地址，arr1,arr2,arr3,其实就是arr1,arr2,arr3的地址
//	int* parr[] = { arr1,arr2,arr3 };//整型指针
//
//	//打印三个数组
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", *(parr[i]+j));
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}

//int* arr1[10]; //整形指针的数组
//char* arr2[4]; //一级字符指针的数组
//char** arr3[5];//二级字符指针的数组


//数组指针
//数组指针的定义
//数组指针是指针？还是数组？
//答案是：指针。
//我们已经熟悉： 整形指针： int* pint; 能够指向整形数据的指针。 浮点型指针： float* pf; 能够
//指向浮点型数据的指针




//数组指针
//实际上是指针
//int main()
//{
//	int* p = NULL;//p是整形指针-指向整形的指针 - 可以存放整形的地址
//	char* pc = NULL;//pc是字符指针-指向字符的指针 - 可以存放字符的地址
//
//	//数组指针 -  指向数组的指针 - 可以存放数组的地址
//	int arr[10] = { 0 };
//	//arr - 首元素的地址
//	//&arr[0] - 首元素的地址
//	//&arr - 数组的地址
//
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//&arr1;//数组的地址要存起来
//	int(*p)[10] = &arr;//p先和*结合，说明是一个指针，再和外面int[10]结合，说明是一个指针数组
//	//上面的p就是数组指针
//	system("pause");
//	return 0;
//}
//注：int *p[10]:中[]的结合性的优先级更高

//下面代码哪个是数组指针？
//int* p1[10];
//int(*p2)[10];
//p1, p2分别是什么？
////指针数组
////数组指针

//解释：
//int(*p)[10];
////解释：p先和*结合，说明p是一个指针变量，然后指针指向的是一个大小为10个整型的数组。所以p是一个
//指针，指向一个数组，叫数组指针。
////这里要注意：[]的优先级要高于*号的，所以必须加上（）来保证p先和*结合




//int main()
//{
//	char* arr[5];//arr中有5个元素，每个元素是char*
//	char* (*pa)[5] = &arr;//数组的地址用数组指针存放，本质上是一个指针
//	//pa是指针变量的名字，*说明pa是指针，[5]说明pa指向的数组是5个元素的,(每个元素的类型是char*)
//	//char*说明pa指向的数组的元素类型是char*的
//
//	int arr2[10] = { 0 };//arr2中有10个元素，每个元素是int
//	int (*pa2)[10] = &arr2;//数组的地址用数组指针存放，本质上是一个指针
//	//pa2是指针变量的名字，*说明pa2是指针，[10]说明pa指向的数组是10个元素的
//	//int说明pa2指向的数组的元素类型是int的
//
//	system("pause");
//	return 0;
//}



//数组指针怎么用,至少到二维数组及以上才好用
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*pa)[10] = &arr;
//	
//	//通过指针将数组中的元素全部打印出来
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		//*pa,pa是数组的地址，*pa数组解引用操作，相当于拿到了整个数组
//		//*pa = arr
//		printf("%d ", (*pa)[i]);
//	}
//	printf("\n");
//	//另一种写法
//	//*pa = arr,数组名arr是首元素地址，首元素地址+i就是向后跳了i个元素
//	//((*pa)+i)相当于arr+i,首元素地址+i就是向后跳了i个元素，再解引用
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(*pa+i));
//	}
//	printf("\n");
//	
//	//别扭
//	int* p = arr;//指针p指向第一个元素
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//		printf("%d ", *(arr + i));
//		printf("%d ", arr[i]);//arr[i] = *(arr+i) = *(p+i) = p[i]
//	}
//
//	system("pause");
//	return 0;
//}



////数组指针在二维数组中的应用
//void print1(int arr[3][5], int x, int y)//参数是数组的形式
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
////传过来的arr是首元素的地址，首元素是第一行，是第一行的地址
////第一行是一个一维数组，所以传过来的是一维数组的地址，
////一维数组的地址，数组的地址应该放在数组指针里面去
////就应该写一个数组指针，只不过这个数组指针指向的不是一个二维数组，
////而是指向的是第一行的一维数组，这个一维数组有5个元素，
////每个元素是整形
//print2(int(*p)[5], int x, int y)//参数是指针的形式
//{
//	int  i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			//*(p + i)拿到这一行
//			//printf("%d ", (*(p + i))[j]);//i行j列的元素
//			//arr[i] = *(arr+i) = *(p+i) = p[i]
//			printf("%d ", *(*(p + i)+j));
//			//printf("%d ", *(p[i]+j));
//			//printf("%d ", p[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	//打印二维数组
//	print1(arr, 3, 5);//arr - 数组名 - 首元素地址
//
//	//对于二维数组，数组名是首元素地址，首元素并不是第一个元素
//	//把二维数组看成是一维数组，把第一行当成是一个元素，把第二行当成一个元素，第三行当成一个元素
//	//每行当成一个元素，那么arr其实有三个元素，每一行是一个元素
//	//第一行是第一个元素
//
//	//那么数组名是首元素的地址，就是第一行的地址，而第一行又是一个一维数组，
//	//这个数组有5个元素，每个元素是int.
//
//	print2(arr, 3, 5);
//
//	system("pause");
//	return 0;
//}






//int arr[5];	//arr是一个数组，数组5个元素，每个元素整型（arr是一个5个元素的整形数组）
//int* parr1[10];	//arr是一个数组，数组10个元素，每个元素的类型是int*（parr1是指针数组）
//int(*parr2)[10];	//parr2是一个指针，该指针指向了一个数组，数组有10个元素，每个元素的类型为int(parr2水数组指针)
//int(*parr3[10])[5];	//parr3是一个数组，



//int arr[10]
//arr是数组名，[10]是元素个数，除了数组名和元素个数，其他的就是元素类型
//

//int(*parr3[10])[5];	//parr3是一个数组，
//parr3是数组名，[10]是元素个数，除了数组名和元素个数，其他的就是元素类型
//为int (*) [5]::::数组指针---指向数组的指针
//从而int(*parr3[10])[5]
//parr3是一个数组，十个元素，每个元素是一个数组指针，这个指针能够指向5个元素的数组，每个元素是int


//parr3是一个数组，该数组有十个元素，每个元素是一个数组指针，该数组指针指向的数组有5个元素，每个元素是int



////字符指针
//int main()
//{
//	char ch = 'w';
//	char* p = &ch;
//	//char* p2 = "abcdef";//字符串"abcdef"首字符a的地址交给p2,p2存的是a的地址。是一个常量字符串，它的内容不允许被修改
//	//最合理的方式
//	const char* p2 = "abcdef";
//	return 0;
//}

////指针数组 --- 是数组，存放指针，存放指针的数组叫指针数组
//int main()
//{
//	int* arr[10];
//	char* ch[5];//ch数组，5个元素，每个元素是char*(字符指针)
//
//	return 0;
//}


////数组指针  --- 
//int main()
//{
//	int* p3;//整型指针 -- 指向整型的指针
//	char* p4;//字符指针 -- 指向字符的指针
//	int(*p5)[10];//数组指针 -- 指向数组的指针；，取出数组的地址
//	//p5是一个指针，指向一个数组，该数组有10个元素，每个元素为int型
//	//去掉pa,就是他的类型，数组指针类型
//
//	return 0;
//}





//数组参数、指针参数

//在写代码的时候难免要把【数组】或者【指针】传给函数，那函数的参数该如何设计呢？
//一维数组传参
//
//void test(int arr[])//ok?//ok
//{}
//void test(int arr[10])//ok?//0k
//{}
//void test(int* arr)//ok?//ok
//{}
//void test2(int* arr[20])//ok?//ok,20可省略
//{}
//void test2(int** arr)//ok?//ok
//{}
//int main()
//{
//	int arr[10] = { 0 };
//	int* arr2[20] = { 0 };//arr2是一个数组，数组有20个元素，每个元素是int*(整形指针)
//	
//	test(arr);//数组名是首元素地址，首元素是int型，int型的地址是int*
//	test2(arr2);//数组名是首元素地址，首元素是int*型，int*型的地址是int**
//}



//二维数组传参

////二维数组传参，参数写成数组
//void test(int arr[3][5])//ok？//ok
//{}
//void test(int arr[][])//ok？//no
//{}
//void test(int arr[][5])//ok？//ok
//{}
////总结：二维数组传参，函数形参的设计只能省略第一个[]的数字。
////因为对一个二维数组，可以不知道有多少行，但是必须知道一行多少元素。
////这样才方便运算。(行可以省略，列不可以省略)
//
////二维数组传参，参数写成指针
//void test(int* arr)//ok？//no
//{}
//void test(int* arr[5])//ok？//no
//{}
//void test(int(*arr)[5])//ok？//ok//arr是一个指针，指向一个数组，数组有5个元素，每个元素是int
//{}
//void test(int** arr)//ok？///no//二级指针是用来存放一级指针的地址的,传过来的是数组的地址，不能放到二级指针里面去
//{}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);//二维数组传参
//}




////一级指针传参
//void print(int* p, int sz)//指针变量传参，接收它的时候也应该写成指针
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", *(p + i));
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//一级指针p，传给函数
//	print(p, sz);//指针变量传参，接收它的时候也应该写成指针
//	return 0;
//}
//



//当一个函数的参数部分为一级指针的时候，函数能接收什么参数


//void test1(int* p)
//{}
////test1函数能接收什么参数？ 
//void test2(char* p)
//{}
////test2函数能接收什么参数？
////函数能接收什么参数呢？
//int main()
//{
//	int a = 10;
//	int* p1 = &a;
//	test1(&a);//关于void test1(int* p)，指针变量，可以传地址过去
//	rest1(p1);//关于void test1(int* p)，p是指针变量，可以把p本身传过去
//
//	char ch = 'w';
//	char* pc = &ch;
//	test2(&ch);
//	test2(pc);
//}






//二级指针传参
//void test(int** ptr)//二级指针传参,参数部分直接是一个二级指针
//{
//	printf("num = %d\n", **ptr);
//}
//int main()
//{
//	int n = 10;
//	int* p = &n;
//	int** pp = &p;
//	test(pp);
//	test(&p);
//	return 0;
//}




//当函数的参数为二级指针的时候，可以接收什么参数？

//void test(char** p)
////函数的参数为二级指针的时候，可以接收二级指针本身没有问题，
////可以传一级指针变量的地址，也是没有问题的
//{ }
//int main()
//{
//	char c = 'b';
//	char* pc = &c;
//	char** ppc = &pc;
//	char* arr[10];//arr是一个数组，数组有10个元素，每个元素是char*
//	test(&pc);//一级指针变量的地址
//	test(ppc);//二级指针
//	test(arr);//Ok?//此时此刻数组名是首元素地址，首元素是char*,一级指针的地址
//	//如果函数的参数是二级指针，你如果传一个数组，这个数组是指针数组，也是可以的
//	return 0;
//}




//函数指针

//数组指针 -- 是指向数组的指针
//函数指针 -- 指向函数的指针

//函数指针，是一个指针，指向函数的指针，是存放函数地址的一个指针

//int Add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("%d\n", Add(a, b));
//	printf("%p\n", &Add);//函数的地址//00007FF61E8A13C0
//	printf("%p\n", Add);//函数的地址//00007FF62EFE13C0
//	//对于函数来说，Add=&Add
//	//&函数名和函数名都是函数的地址
//
//	//函数的地址怎么存储，肯定是指针
//	int(*pa)(int, int) = Add;
//	//(*pa)说明pa是一个指针，向外一看，一对圆括号，说明这个指针指向一个函数，
//	//函数的参数是两个整型，指向函数的返回类型是int
//
//	//怎么验证
//	//pa里面如果存放的是函数的地址，那么*pa找到那个函数，
//	printf("%d\n", (*pa)(2, 3));//5
//	return 0;
//}





//不同函数的地址如果要存起来，定义的函数指针也不相同
//void print(char* str)
//{
//	printf("%s", str);
//}
//
//int main()
//{
//	//希望把print这个函数的函数地址存放起来
//	//存到p里面去，p就应该是一个函数指针(*P),指向的是函数，函数参数是char*,返回类型是void
//	void (*p)(char*) = print;
//
//	//通过p调用函数，怎么调用
//	(*p)("hello");
//	return 0;
//}



////函数的地址要想保存起来，怎么保存？下面我们看代码
//void test()
//{
//	printf("hehe\n");
//}
////下面pfun1和pfun2哪个有能力存放test函数的地址？
//void (*pfun1)();
//void* pfun2();
////首先，能给存储地址，就要求pfun1或者pfun2是指针，那哪个是指针？ 答案是：
////pfun1可以存放。pfun1先和*结合，说明pfun1是指针，指针指向的是一个函数，
////指向的函数无参数，返回值类型为void。
//至于pfun2,首先和()结合，说明是一个函数，这是一个函数声明，函数参数是无，返回类型是void
//pfun2不是一个指针，是一个函数名




//
//int arr[10] = { 0 };
//int(*p)[10] = &arr;
////p是一个指针变量，指向一个数组，数组10个元素，每个元素是int
////把p名字去掉，剩下的是它的类型，int(*)[10]是数组指针类型，


//	void (*p)(char*) = print;
//把p去掉，void (*)(char*)是一个指针，指向一个函数，




////阅读两段有趣的代码：
////代码1
//(*(void (*)())0)();
////代码2
//void (*signal(int, void(*)(int)))(int);
//
//代码2太复杂，如何简化：
//typedef void(*pfun_t)(int);
//pfun_t signal(int, pfun_t);





////代码1
//(*(void (*)())0)();

//void (*)()
//函数指针类型
//(void (*)())0
//把整型数字0强制类型转换为函数指针类型，这样0就是一个函数地址，
//再解引用，得到函数，那个函数是无参，调用这个函数(*(void (*)())0)()

//所以这段代码其实是一次函数调用，调用的是0地址处的参数为无参，返回类型为void的那个函数





////代码2
//void (*signal(int, void(*)(int)))(int);
//是一次函数声明：signal是函数名，有两个参数，int型， 函数指针类型，去掉函数名和参数
//如int Add(int, int),剩余的就是函数返回类型，
//所以最后的返回类型是void(*)(int),是一个函数指针类型
//可以这样认为：void(*)(int) signal(int, void(*)(int))
//实际上不允许这样写，函数指针返回类型是不能这样写的，*要靠近我们的名字
//void (*signal(int, void(*)(int)))(int);
//
//
//
//void (*signal(int, void(*)(int)))(int);
//代码2太复杂，如何简化：
//typedef void(*pfun_t)(int);  可以这样认为typedef void(*)(int) pfun_t；但是不能这样写
//pfun_t signal(int, pfun_t);
//


//解释void(*signal(int, void(*)(int)))(int);
//signal是一个函数声明
//signal的函数参数有两个 ，第一个是int类型，第二个是函数指针，
//该函数指针指向的函数的参数是int, 返回类型是void,
//signal函数的返回类型也是一个函数指针，该函数指针指向的函数的参数是int, 返回类型是void,



//简化之后：
//typedef void(*pfun_t)(int);  可以这样认为typedef void(*)(int) pfun_t；但是不能这样写
//pfun_t signal(int, pfun_t);



//int Add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}
//int main()
//{
//	int (*pa)(int, int) = Add;
//	printf("%d\n", (*pa)(2, 3));//*pa相当于找到这个函数
//	printf("%d\n", (**pa)(2, 3)); 
//	printf("%d\n", (***pa)(2, 3));
//	printf("%d\n", pa(2, 3));
//	//说明这个*没有什么影响
//	//如果pa是一个函数指针，我在调用函数指针的时候，常用
//	printf("%d\n", (*pa)(2, 3));//*pa相当于找到这个函数
//	printf("%d\n", pa(2, 3));//pa是函数指针，指向函数的地址，直接去调用这个地址，也是可以的
//	return 0;
//}




//函数指针数组
//数组是一个存放相同类型数据的存储空间，那我们已经学习了指针数组， 比如：
//int* arr[10];
//数组的每个元素是int*，为指针数组
//那要把函数的地址存到一个数组中，那这个数组就叫函数指针数组，那函数指针的数组如何定义呢？
//int (*parr1[10])();//parr是一个数组，数组有10个元素，剩下的就是元素类型，
//剩下的是一个指针，指针指向的是函数，参数无参，返回类型为int
//int* parr2[10]();
//int (*)() parr3[10]
//答案是：parr1 parr1 先和[] 结合，说明parr1是数组，数组的内容是什么呢？ 是 int (*)() 类型的
//函数指针
//函数指针数组的用途：转移表
//



////函数指针数组
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//
//	int* arr[5];//指针数组
//	int (*pa)(int, int) = Add;//Sub,Mul,Div
//	//需要一个数组，这个数组可以存放4个函数的地址，这个数组就是函数指针数组
//	//int (*pa[4])(int, int)//pa是一个数组，数组有4个元素，数组名，[4]去掉就是元素类型
//	//元素类型为int (*)(int, int)即函数指针类型
//	//函数指针数组
//	int (*parr[4])(int, int) = { Add,Sub, Mul,Div };//parr就是函数指针数组
//	//怎么用呢
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d\n", parr[i](2, 3));//5,-1,6,0
//	}
//	return 0;
//}


//对于char* my_strcpy(char* dest, const char* src)

	//1.写一个函数指针pf,能够指向my_strcpy
	//2.写一个函数指针数组pfArr，能够存放4个my_strcpy函数的地址

	//1.char* (*pf)(char*, const char*)
	//2.char* (*pfArr[4])(char*, const char*)





//函数指针数组的应用
//实现一个计算器

//void menu()
//{
//	printf("##################################\n");
//	printf("#######   1.Add    2.Sub   #######\n");
//	printf("#######   3.Mul    4.Div   #######\n");
//	printf("#######       0.exit       #######\n");
//	printf("##################################\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//		printf("请输入两个操作数");
//		scanf("%d%d", &x, &y);
//		switch (input)
//		{
//		case 1:
//			printf("%d\n", Add(x, y));
//			break;
//		case 2:
//			printf("%d\n", Sub(x, y));
//			break;
//		case 3:
//			printf("%d\n", Mul(x, y));
//			break;
//		case 4:
//			printf("%d\n", Div(x, y));
//			break;
//		case 0:
//			printf("退出\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//
//	} while (input);
//
//	return 0;
//}


//如果这样的话，输入0的时候，就会还让你输入两个操作数，有点尬
//修正

//void menu()
//{
//	printf("##################################\n");
//	printf("#######   1.Add    2.Sub   #######\n");
//	printf("#######   3.Mul    4.Div   #######\n");
//	printf("#######       0.exit       #######\n");
//	printf("##################################\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个操作数");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Add(x, y));
//			break;
//		case 2:
//			printf("请输入两个操作数");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Sub(x, y));
//			break;
//		case 3:
//			printf("请输入两个操作数");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Mul(x, y));
//			break;
//		case 4:
//			printf("请输入两个操作数");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Div(x, y));
//			break;
//		case 0:
//			printf("退出\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//
//	} while (input);
//
//	return 0;
//}


//代码重复冗余太多，怎么修改呢
//void menu()
//{
//	printf("##################################\n");
//	printf("#######   1.Add    2.Sub   #######\n");
//	printf("#######   3.Mul    4.Div   #######\n");
//	printf("#######       0.exit       #######\n");
//	printf("##################################\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	//加减乘除函数的地址构成一个数组//函数指针数组
//	int (*pfArr[5])(int, int) = { 0,Add,Sub,Mul,Div };
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("请输入两个操作数：");
//			scanf("%d%d", &x, &y);
//			int ret = pfArr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出\n");
//		}
//		else
//		{
//			printf("选择错误\n");
//		}
//	} while (input);
//
//	return 0;
//}



//这样会非常方便
////如果再增加一个按位异或函数
//void menu()
//{
//	printf("##################################\n");
//	printf("#######   1.Add    2.Sub   #######\n");
//	printf("#######   3.Mul    4.Div   #######\n");
//	printf("#######   5.Xor    0.exit  #######\n");
//	printf("##################################\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int Xor(int x, int y)
//{
//	return x ^ y;
//}
//
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	//pfArr是函数指针数组--又叫转移表
//	int (*pfArr[])(int, int) = { 0,Add,Sub,Mul,Div, Xor };
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 5)
//		{
//			printf("请输入两个操作数：");
//			scanf("%d%d", &x, &y);
//			int ret = pfArr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出\n");
//		}
//		else
//		{
//			printf("选择错误\n");
//		}
//	} while (input);
//
//	return 0;
//}



//回调函数
//回调函数就是一个通过函数指针调用的函数。

//void menu()
//{
//	printf("##################################\n");
//	printf("#######   1.Add    2.Sub   #######\n");
//	printf("#######   3.Mul    4.Div   #######\n");
//	printf("#######       0.exit       #######\n");
//	printf("##################################\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//
////如果你把函数的指针（地址）作为参数传递给另一
////个函数，当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。回调函数不是由该
////函数的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或
////条件进行响应
//
//
////把一个函数的地址传递给指针，在函数内部通过指针去调用那个函数，
////那个被调用的函数就叫做回调函数
//void calc(int (*pf)(int, int))//传的参数为函数地址，即函数指针接收
//{
//	int x = 0;
//	int y = 0;
//	printf("请输入两个操作数");
//	scanf("%d%d", &x, &y);
//	printf("%d\n", pf(x, y));
//}
//int main()
//{
//	int input = 0;
//
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			//三个函数冗余,封装成calc()函数，再把Add,Sub,Mul,Div传给calc()函数
//			calc(Add);
//			break;
//		case 2:
//			calc(Sub);
//			break;
//		case 3:
//			calc(Mul);
//			break;
//		case 4:
//			calc(Div);
//			break;
//		case 0:
//			printf("退出\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//
//	} while (input);
//
//	return 0;
//}






//指向函数指针数组的指针
//指向函数指针数组的指针是一个 指针 指针指向一个 数组 ，数组的元素都是 函数指针;

//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int (*p)[10]=&arr;//取出数组的地址//数组指针
//
//	int (*pfArr[4])(int, int);//pfArr是数组，数组的每个元素是函数指针
//	//pfArr是函数指针的数组，它也有地址,也应该有一个指针指向这个函数指针的数组，
//	//叫指向函数指针数组的指针
//	int (*(*ppfArr)[4])(int, int) = &pfArr;
//	//ppfArr是一个指针，它指向一个数组，数组有4个元素，
//	//剩下的是元素类型：int (*)(int, int)，元素类型是函数指针
//	//ppfArr是一个数组指针，指针指向的数组有4个元素，
//	//指向的数组的每个元素的类型是一个函数指针int(*)(int,int)
//
//
//
//
//	int (*pf)(int, int);//函数指针
//	int (*pfArr[4])(int, int);//得到函数指针数组，只需要在pf后面加一个[]就可以了
//	int (*(*ppfArr)[4])(int, int) = &pfArr;//ppfArr是一个指向函数指针数组的指针，
//	                                       //只需要把pfArr括起来加个*就可以了，即(*ppfArr)
//}
//指向函数指针数组的指针了解下概念，未来能不能用到两回事




//回调函数

//void print(char*str)
//{
//	printf("hehe：%s", str);
//
//}
//void test(void (*p)(char*))//test传过来的是函数地址，应用函数指针接收
//{
//	printf("test\n");
//	p("bit");
//}
//int main()
//{
//
//	test(print);
//	return 0;
//}


//复习
int Add(int x, int y)
{
	return x + y;
}
int main()
{
	//指针数组
	int* arr[10];
	//数组指针
	int* (*pa)[10] = &arr;
	//函数指针(存放函数的地址，存放函数地址的指针)
	int (*pAdd)(int, int)=Add;//pAdd为函数指针  &Add亦可
	
	//如何调用函数指针
	int sum = (*pAdd)(2, 3);//Add(2,3)
	int sum1 = pAdd(2, 3);
	printf("%d\n", sum);
	printf("%d\n", sum1);


	//函数指针的数组//直接在函数指针int (*pArr)(int, int)上面改造
	int (*pArr[5])(int, int);//pArr是一个数组，数组中有5个元素，
	                       //去掉数组名和[5],剩余的就是元素类型：函数指针
							//从而pArr是一个函数指针的数组

	//指向函数指针数组的指针，从int (*pArr[5])(int, int);上面改造
	int (*(*ppArr)[5])(int, int) = &pArr;
	return 0;
}

//回调函数的应用实例

//void BubbleSort(int arr[], int sz)
//{
//	;
//}
//int main()
//{
//	//冒泡排序函数
//	////冒泡排序函数----只能排序整形数组
//	int arr[10] = { 1,3,5,7,9,2,4,6,8,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	BubbleSort(arr, sz);
//
//}
//对于冒泡排序，只能排序整形数组，对于浮点型数据不能排，
//对于学生数据，按照成绩来排，，或者按照身高来排不能排，


//对于库函数qsort---可以排序任意类型数据，只要这两个数据能比较


