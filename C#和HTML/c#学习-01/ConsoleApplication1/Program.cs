using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program  //这个类中 有一个 Main方法 是入口的方法
    {
        static void Main(string[] args) //程序运行时，从这里开始执行代码
        {




        }
    }
}
#region 当想返回一个数组的时候 就需要在返回值类型 写： 数组的类型+[] 然后return +数组名；
//public static int[] Method(int[] num)
//return num;
#endregion

#region 冒泡排序的方法
            //int tmp = 0;                    //0   1     2     3     4    5  6   7  8   9  10  11  12  13
            //int[] num = new int[14] { 10, 23, 684, 321, 12, 2, 56, 1, 35, 0, 47, 98, 24, 64 };//数组中的元素表示为n
            //for (int i = 0; i < num.Length - 1; i++) //表明第几趟 t
            //{
            //    for (int j = 0; j < num.Length - (i + 1); j++) //第t躺需要运算n-t次
            //    {
            //        if (num[j] > num[j + 1]) 
            //        {
            //            tmp = num[j];
            //            num[j] = num[j + 1];
            //            num[j + 1] = tmp;
            //        }
            //    }
            //}
            //for (int i = 0; i < num.Length; i++) 
            //{
            //    Console.WriteLine(num[i]);
            //}
            //Console.ReadLine();
#endregion

#region 数组的申请方法，这里是申明了一个叫score的数组，长度为6，所以计算的时候从0开始,0,1,2,3,4,5，这些就是数组所储存的6个变量，需要注意的是，int类型数组，一旦被申明后，里面的变量全都初始化为0，如果不进行赋值，那么变量就是0
            //int[] score = new int[6];
            //score[0] = 10;
            //score[1] = 30;
            //score[5] = 40;
            //score[4] = 100;
            //Console.WriteLine(score[5]);
            //Console.ReadLine();
#endregion

#region 字符串转化为枚举的方法
//(你定义的枚举)(Enum.Parse(typeof(你定义的枚举), 想转换的字符串));
#endregion

#region  常量的用法
            //const int pi = 3.14;
#endregion

#region if else的用法，也能这样用，但是不推荐，太乱，这个方法就if-else-if用法的复杂版，了解就好，能明白单纯的if-else能这样用
           //System.Console.WriteLine("请输入您的考试成绩");            题目：对学员的成绩评测
           // int score = int.Parse(System.Console.ReadLine());                成绩 >= 90 ：A
           // if (score >= 90)                                                           90> 成绩 >= 80 ：B
           // {                                                                                  80> 成绩 >= 70 ：C
           //     System.Console.WriteLine("A");                                70> 成绩 >= 60 ：D
           // }                                                                                          成绩 < 60    ：E
           // else
           // {
           //     if (score >= 80)   //程序进入到这里说明程序<90
           //     {
           //         System.Console.WriteLine("B");
           //     }
           //     else
           //     {
           //         if (score >= 70)  //程序进入到这里说明程序<80
           //         {
           //             System.Console.WriteLine("C");
           //         }
           //         else
           //         {
           //             if (score >= 60)  //程序进入到这里说明程序<70
           //             {
           //                 System.Console.WriteLine("D");
           //             }
           //             else
           //             {
           //                 System.Console.WriteLine("E");  //程序进入到这里说明程序<60
           //             }
           //         }
           //     }
           // }
           //         System.Console.ReadLine();
#endregion

#region  关系表达式中的一些注意问题
//int score = 85;
//if (80 < score < 90)  因为在优先级计算问题中 两个小于号属于同级，在同级情况下，系统默认从左-右开始运算，这时候是先运算 80 < score(85),这时候系统得到的结论为 true，这时候再计算 true < 90 这时候就出现问题了，所以这时候需要用到逻辑表达式（逻辑与 逻辑或）
//{
//System.Console.WriteLine();
//}
#endregion

#region ToSrting的用法，可以把一切类型转换成string类型 即字符串类型
//int a = 3;
//string a1 = Convert.ToString(a);
//System.Console.WriteLine(a1);
//System.Console.ReadLine();

//int a = 3;
//Console.WriteLine(a.ToString());
#endregion

#region 逻辑与 或 短路问题
//逻辑与短路：逻辑与的表达式要求两个都成立才能完成运算，系统识别要识别两个关系表达式是否为 true，所以当++a > 5为 true 的时候才会运算后面的++b > 7，所以a=11 b=6，反之，如果改成++a> 50的时候则为 false，那么后面的++b > 7 也不会计算，所以a=11 b = 5
//int a = 10, b = 5;
//bool isRight = ++a > 5 && ++b > 7;
//System.Console.WriteLine("a = {0}  b = {1}",a,b);
//System.Console.ReadLine();
//逻辑或短路：逻辑或的表达式要求只用一个成立就能完成计算，系统识别只用识别一个关系式（从左 - 右）是否为true就能完成运算，所以 当++a > 5的时候，系统就识别为 true 了，从而输出 true，而不看后面的++b>7，所以这时候a=11 b = 5，返之，当++a > 50（false）的时候，系统会识别下一个关系式，从而得出++b，所以这时候a=11，b=6
//int a = 10, b = 5;
//bool isRight = ++a > 5 || ++b > 7;
//System.Console.WriteLine("a = {0}  b = {1}", a, b);
//System.Console.ReadLine();
#endregion

#region 算术运算符 (+=) (-=)( *=)( /=)( %=)  使用方法都如下
//int a =1;
//a /= 3;
//System.Console.WriteLine(a);
//System.Console.ReadLine();
#endregion

#region  a++ 和 ++a 的区别在于 a++在算完之后再自加一 ++a再算的之前就自加1 如(1)(2)(3)情况的区分 同理--a和a-- 属于一元算术运算符，优先度比二元的高，需要注意的是 单独表示a++ 为 a++;，也可以a=a++,a=++a，但是要想清楚，在a=a++中，因为a++属于表达式完成后才会自增，所以这里的a值是不变的，但是a=++a;中，a值就改变了
//(1)   int a = 1;
//       a++;
//(2)   int a =1,b=2,c;
//       c = a++ +b;
//       System.Console.WriteLine(c); c=3
//(3)   int a=1,b=2,c;
//       c = ++a +b;
//       System.Console.WriteLine(c); c=4
#endregion

#region 两道有意思的题目 抽时间看看 逻辑的顺序
//System.Console.Write("请输入你想转换的秒数");
//int second = int.Parse(System.Console.ReadLine());   秒:107653
//int day = second / (3600 * 24);
//int mod = second % (3600 * 24); //107653秒减去mod 还剩下21253秒
//int hour = mod / (60 * 60);
//mod = mod % (60 * 60);//减去hour的秒还剩下多少3253秒
//int min = mod / 60;
//int second1 = mod % 60;
//System.Console.WriteLine("{0}秒钟包含了{1}天{2}小时{3}分钟{4}秒",second,day,hour,min,second1);
//System.Console.ReadLine();

//Console.Write("请输入你想计算的天数");   40天
//int day = Convert.ToInt32(Console.ReadLine());
//int month = day / 30;
//int mod = day % 30;
////int week = (day - month * 30) / 7;
//int week = mod / 7;
////int days = day - month * 30 - week * 7;
//int days = mod % 7;
//Console.WriteLine("{0}天，是{1}个月{2}周零{3}天", day, month, week, days);
//Console.ReadLine();
#endregion

#region try-catch的应用与方法，如果try中的代码没有出现错误则正常运行，如果出现错误则输出catch中的代码
//try
//{
//System.Console.Write("请输入你的语文成绩：");
//var chinese = Convert.ToDouble(System.Console.ReadLine());
//System.Console.Write("请输入你的数学成绩：");
//var match = Convert.ToDouble(System.Console.ReadLine());
//System.Console.WriteLine("您的成绩总和为{0}", chinese + match);


//}
//catch
//{
//System.Console.WriteLine("您输入的结果有误，请重新运行程序");
//}
//System.Console.ReadLine();
#endregion

#region  将字符串转化为数据类型 如 int、double等 的语法，与Parse()类似，需要注意的是，可以转换的为变量也可以是字符串，如"90"
//System.Console.Write("请输入你的语文成绩");
//var chinese = System.Console.ReadLine();
//System.Console.Write("请输入你的数学成绩");
//var math = System.Console.ReadLine();

//double a1 = Convert.ToDouble(chinese);
//int a2 = Convert.ToInt32(math);

//var all = a1 + a2;
//System.Console.WriteLine("您的总成绩为{0}",all);
//System.Console.ReadLine();
#endregion

#region 强制类型转换语法：数据类型名a = (数据类型名a)待转换的值b 属于显式转换， 高往低走
//int a = 3;
//double b = 4.12541;
//a = (int)b;
//System.Console.WriteLine(a);
//System.Console.ReadLine();
#endregion

#region  这个region为下面的例外详解，如代码，a为int b为double（且为小数），按照二元运算符（正常的加减乘除）的要求是不成立的，但是这里存在“隐式类型”，当两者兼容（同类型，都是数字），并且目标类型大于源类型（如：double>int）系统则自动往大的类型上转换，并且不丢失精度
//int a = 3;
//double b = 2.1654;
//var duo = a * b;
//System.Console.WriteLine(duo);
//System.Console.ReadLine();
#endregion

#region 在算数的时候要求两个操作数的类型相同，如下为两个int类型相加，而得出的结果也是与操作类型相同，但也有例外，见一个region

//int a = 1;
//int b = 2;
//var duo = a + b;
//System.Console.WriteLine(duo);
#endregion

#region 因为@的存在所以转义符失去作用，这时候如果想在字符串中输入引号的话需要两个引号""
//正确：System.Console.WriteLine(@"xxxxxx""xxxxxxx");
//错误：System.Console.WriteLine(@"xxxxxx"xxxxxxx"); //只打一个引号 那么他就会跟前面的字符串连在一起 后面就不行了
#endregion

#region 交换两者变量的值，需要另外申明一个变量
//int a = 10, b = 5, c, d;
//c = a;
//d = c;
//d = b;
//b = a;
//System.Console.WriteLine(a);
//System.Console.ReadLine();
#endregion

#region c#系统 小数点的数字默认归为double数据类型（隐式类型） 所以在赋值的值后面+个m就可以避免被系统默认
//            decimal a = 1000.256m;
//checked的用法
//            int a;
//            checked 
//            {
//                a = int.MaxValue;
//                a = a + 1;

//            }
//            System.Console.WriteLine(a);
 #endregion

#region 第一个c#程序
            //System.Console.WriteLine("*********************************\n*\t这是我的第一个c#程序\t*\n*********************************\a");
            //System.Console.WriteLine("*******************************"); 
            //System.Console.WriteLine("*    这是我的第一个c#程序     *");
            //System.Console.WriteLine("*******************************");
            //System.Console.ReadLine();
            #endregion

#region Parse()的表示方法，Parse()的作用在于解析，解析字符串
//int a1 = int.Parse(str1);
//int a2 = int.Parse(str2);

//var str1 = system.console.readline();
//var str2 = system.console.readline();

//system.console.writeline(a1+a2);
#endregion