using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 吴鹏_面向过程02
{
    public enum sex
    {
        男,
        女,
    }
    public struct Person
    {
        public string name;
        public sex gender;
        public int age;
    }
    class Program
    {
        static void Main(string[] args)
        {
            //int[] score = new int[6];
            //score[0] = 10;
            //score[1] = 30;
            //score[5] = 40;
            //score[4] = 100;
            //score[6] = 2;
            //Console.WriteLine(score[5]);
            //Console.ReadLine();

            //int sum = 0;
            //int[] score = new int[10];
            //for (int i = 0; i < score.Length; i++) 
            //{
            //    Console.WriteLine("请输入第{0}个学生的成绩",i+1);
            //    score[i] = int.Parse(Console.ReadLine());
            //}
            //for (int i = 0; i < score.Length; i++) 
            //{
            //    sum += score[i];
            //    int a = 3;
            //    int b = 4;
            //    int c;
            //}
            //Console.WriteLine("{0}个人的平均分为{1}",score.Length,sum/score.Length);

            //for (int i = 0; i < score.Length; i++)
            //{
            //    Console.WriteLine("第{0}个人的分数为{1}",i+1,score[i]);
            //}
            //Console.ReadLine();

            //int b = 0;
            //int c = 0;
            //for (int i = 0; i < 5; i++) 
            //{
            //    Console.WriteLine("请输入数字");
            //    b = int.Parse(Console.ReadLine());
            //    c = c + b;
            //}
            //Console.WriteLine(c);
            //Console.ReadLine();

           
            //int[] num = new int[8]{1,10,20,50,2,30,70,100};
            //int max = num[0];
            //for (int i = 1; i < num.Length; i++) 
            //{
            //    if (num[i] > max) 
            //    {
            //        max = num[i];
            //    }
            //}
            //Console.WriteLine(max);
            //Console.ReadLine();

            //int[] num = new int[] { 12, 32, 654, 12158, 321, 68, 135, 654, 318,1 };
            //int max = num[0];
            //int min = num[0];
            //int all = 0;
            //for (int i = 0; i < num.Length; i++)
            //{
            //    all = all + num[i];
            //    if (num[i] > max)
            //    {
            //        max = num[i];
            //    }
            //    if (num[i] < min) 
            //    {
            //        min = num[i];
            //    }
            //}
            //Console.WriteLine(max);
            //Console.WriteLine(all);
            //Console.WriteLine(min);
            //Console.ReadLine();

            //string str = "";
            ////string[] name = new string[] { "a","b","c","d","e","f"};  //有疑问，怎么让最后一个字符串不带 |
            //for (int i = 0; i < name.Length; i++) 
            //{
            //    if (i == name.Length - 1) 
            //    {
            //        break;
            //    }
            //    str = str + name[i] + "|";
            //}
            //str = str + name[name.Length - 1];
            //Console.WriteLine(str);
            //Console.ReadLine();

            //string str = "";
            //string[] name = new string[] { "张三", "李四", "王五", "赵六", "刘七", "吴八", "钱九", "孙十" };
            //for (int i = 0; i < name.Length; i++)
            //{
            //    if (i <= name.Length - 2)
            //    {
            //        str = str + name[i] + "|";
            //    }
            //    else
            //    {
            //        str = str + name[i];
            //    }
            //}
            //Console.WriteLine(str);
            //Console.ReadLine();


            //string str = "";
            //string[] name = new string[]{ "张三", "李四", "王五", "赵六", "刘七", "吴八" ,"钱九","孙十"};
            //for (int i = 0; i < name.Length; i++) 
            //{
            //    str = str + name[i] + "|";
            //    if (i == name.Length - 1) 
            //    {
            //        str = str + name[i];
            //    }
            //}
            //Console.WriteLine(str);
            //Console.ReadLine();

            //double[] num = new double[] { 100, 0, -3.14, 30.2, 00 , -105 ,46.0};
            //for (int i = 0; i < num.Length; i++) 
            //{
            //    if (num[i] > 0) 
            //    {
            //        num[i] += 1;
            //    }
            //    if (num[i] < 0) 
            //    {
            //        num[i] -= 1;
            //    }
            //    if (num[i] == 0) 
            //    {
            //    }
            //}
            //for (int i = 0; i < num.Length; i++) 
            //{
            //    Console.WriteLine(num[i]);
            //}
            //Console.ReadLine();


            //                                               // 6
            //string[] str = new string[] { "3", "a", "8", "haha","111","2222"}; //有疑问，不知道是不是这个意思
            //string change = "0";
            //for (int i = 0; i < str.Length; i++)
            //{
            //    if (i < str.Length/2)
            //    {
            //        change = str[i];
            //        str[i] = str[str.Length - i - 1];
            //        str[str.Length - i - 1] = change;
            //        Console.WriteLine("第{0}次交换的结果为：\nstr[0] = {1}\nstr[1] = {2}\nstr[2] = {3}\nstr[3] = {4}\nstr[4] = {5}\nstr[5] = {6}"
            //                                         , i + 1, str[0], str[1], str[2], str[3],str[4],str[5]);
            //    }
            //    else 
            //    {
            //        break;
            //    }
            //}
            //Console.ReadLine();


            //int tmp = 0;
            //int[] num = new int[9] { 10, 32, 15, 8, 69, 72, 41, 39, 2 };
            //for (int i = 0; i < num.Length - 1; i++)
            //{
            //    for (int j = 0; j < num.Length - i - 1; j++)
            //    {
            //        if (num[j] < num[j + 1])
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


            //int tmp = 0;                    //0   1     2     3     4    5  6   7  8   9  10  11  12  13
            //int[] num = new int[14] { 10, 23, 684, 321, 12, 2, 56, 1, 35, 0, 47, 98, 24, 64 };
            //for (int i = 0; i < num.Length - 1; i++)
            //{
            //    for (int j = 0; j < num.Length - (i + 1); j++)
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

            //Console.WriteLine("你确定要关机？(y/n)");
            //string str = Console.ReadLine();
            //string strResult = Program.result(str);
            //if (strResult == "y")
            //{
            //    Console.WriteLine("正在关机");
            //}
            //else 
            //{
            //    Console.WriteLine("正在退回桌面");
            //}
            //Console.ReadLine();


            //bool flag = true;
            //bool flag1;
            //Console.WriteLine("请输入一个年份是否为闰年");
            //while (flag == true)
            //{
            //    try
            //    {
            //        int years = int.Parse(Console.ReadLine());
            //        flag1 = Program.method(years);
            //        if (flag1)
            //        {
            //            Console.WriteLine("该年为闰年");
            //        }
            //        else 
            //        {
            //            Console.WriteLine("该年不是闰年");
            //        }
            //        flag = false;
            //    }
            //    catch
            //    {
            //        Console.WriteLine("您输入的有误，只能输入数字，请重新输入");
            //        flag = true;
            //    }
            //}
            //Console.ReadLine();


            //Console.WriteLine("请输入一个数字");
            //string num = Console.ReadLine();
            //int numMethod = Program.method(num);
            //Console.WriteLine("你刚刚输入的是{0}",numMethod);
            //Console.ReadLine();


            //Console.WriteLine("这道题你会做了吗?(y/n)");
            //string answer = Console.ReadLine();
            //string realAnswer = Program.Method(answer);
            //while (realAnswer == "n") 
            //{
            //    Console.WriteLine("那我给你讲一遍");
            //}
            //Console.WriteLine("你可以回家了");
            //Console.ReadLine();


            //string num1 = "";
            //string num2 = "";
            //int maxMethod = Program.Method(num1,num2);
            //Console.WriteLine("最大值为{0}",maxMethod);
            //Console.ReadLine();


            //int Add = Program.Add();
            //Console.WriteLine("总和为{0}", Add);
            //Console.ReadLine();


            //int year = Program.Method();
            //Console.WriteLine(year);
            //Console.ReadLine();


            //Program.Method(1,2,3);

            //int number ;
            //int b = Program.Method(out number);
            //Console.WriteLine(b);
            //Console.WriteLine(number);
            //Console.ReadLine();


            //int[] num = new int[9]{10,6,66,156,12,64,32,14,75};
            //int add, max, min;
            //Program.Method(num, out add, out max, out min);
            //Console.WriteLine("最大值为{0}", max);
            //Console.WriteLine("总和为{0}",add);
            //Console.WriteLine("最小值为{0}",min);
            //Console.ReadLine();


            //Console.WriteLine("请输入一个字符串"); ////TryParse();的原理 简易版
            //string str = Console.ReadLine();
            //int number;
            //bool result = Program.MyTryParse(str, out number);
            //Console.WriteLine(result);
            //Console.WriteLine(number);
            //Console.ReadLine();


            //int number = 100;
            //Test(ref number);
            //Console.WriteLine(number);
            //Console.ReadLine();
            


            //能被自己和1整除的数

            //do
            //{
            //    Console.WriteLine("请输入一个数");
            //    string num = Console.ReadLine();

            //}
            //while (true);

        //    Console.WriteLine("请输入一个数字判断是不是素数");
        //    int num = int.Parse(Console.ReadLine());
        //    bool flag = true;
        //    for (int i = 2; i < num; i++)
        //    {
        //        if (num % i == 0)
        //        {
        //            Console.WriteLine("不是素数");
        //            flag = false;
        //            break;
        //        }
        //    }
        //    if (flag == true) 
        //    {
        //        Console.WriteLine("{0}是素数", num);
        //    }

        //    Console.ReadLine();
        //}

            //int result;
            //int nums;
            //do
            //{
            //    Console.WriteLine("请输入一个数字，判断是否为素数");
            //    string num = Console.ReadLine();
            //    result = Program.Method(num, out nums);
            //    if (result == 1)
            //    {
            //        Console.WriteLine("{0}为素数", nums);
            //    }
            //    else if (result == 2)
            //    {
            //        Console.WriteLine("{0}不是素数", nums);
            //    }
            //}
            //while (result != 3);
            //Console.WriteLine("程序即将结束，按任意键退出");
            //Console.ReadLine();

            //string[] name = new string[] { "张三", "李四", "王五", "赵六", "刘七", "吴八", "钱九", "孙十" };
            //string newName = Method(name);
            //Console.WriteLine(newName);
            //Console.ReadLine();


            //int[] num = new int[10];
            //int[] numResult = Program.Method(num);
            //Console.ReadLine();


            //double[] dimension1 = { 0.1536, 0.2534, 0.1235, 0.5343, 0.6437, 0.4536, 0.6582, 0.4536, 0.1536 };
            //double[] dimension2 = { 0.5631, 0.5315, 0.3436, 0.5674, 0.7832, 0.3134, 0.3253, 0.3134, 0.5631 };
            //double[] dimension3 = { 0.7853, 0.4735, 0.9813, 0.8753, 0.1235, 0.3342, 0.9231, 0.4353, 0.7853 };

            //bool flag1 = true;
            //bool flag2 = true;
            //bool flag3 = true;

            //for (int i = 0; i < dimension1.Length -1; i++) 
            //{
            //    for (int j = 0; j < dimension1.Length - 1 - i; j++) 
            //    {
            //        if (dimension1[i] <= dimension1[i] + 1 || dimension1[i] < dimension1[i + 1])
            //        {
            //            if (dimension1[i] <= dimension1[i] + 1 == true && dimension1[i] < dimension1[i + 1] == false)
            //            {
            //                flag1 = false;
            //            }
            //            else 
            //            {
            //                flag1 = true;
            //            }
            //        }
            //    }
            //}

            


        }

        ////*************************************************************************************************************************************
        ///**************************************************************************************************************************************
        ///***********************************************这里是方法****************************************************************************
        ///**************************************************************************************************************************************
        ///**************************************************************************************************************************************

        //public static int[] Method(int[] num) //当想返回一个数组的时候 方法前面的返回的数据类型需要+[]
        //{
        //    int result;
        //    for (int i = 0; i < num.Length; i++)
        //    {
        //        Console.WriteLine("请为第{0}个赋值", i + 1);
        //        string stringNum = Console.ReadLine();
        //        bool flag = int.TryParse(stringNum, out result);
        //        if (flag == true)
        //        {
        //            num[i] = result;
        //        }
        //        else
        //        {
        //            do
        //            {
        //                Console.WriteLine("您的输入有误，请重新为第{0}个数据赋值",i+1);
        //                stringNum = Console.ReadLine();
        //                bool flag1 = int.TryParse(stringNum, out result);
        //                if (flag1 == true)
        //                {
        //                    num[i] = result;
        //                    break;
        //                }
        //            }
        //            while (true);
        //        }
        //    }
        //    Console.WriteLine(num[1]);
        //    Console.WriteLine("按任意键开始计算数组长度、最大值和最小值");
        //    Console.ReadLine();
        //    int max = 0;
        //    int min = num[0];
        //    for (int i = 0; i < num.Length; i++)
        //    {
        //        if (num[i] > max)
        //        {
        //            max = num[i];
        //        }
        //        else if (num[i] < min)
        //        {
        //            min = num[i];
        //        }
        //    }
        //    Console.WriteLine("你输入了{0}个数据\n最大值为{1}\n最小值为{2}", num.Length, max, min);
        //    return num;
        //}




        //public static string Method(string[] name) //让人的名字前面+ |  的方法
        //{
        //    string str = "";
        //    for (int i = 0; i < name.Length; i++)
        //    {
        //        str = str + name[i] + "|";
        //        if (i == name.Length - 1)
        //        {
        //            str += name[i];
        //        }
        //    }
        //    return str;
        //}

        //public static int Method(string num,out int number)  //判断输入的数是不是素数的方法
        ////当输出1 为素数 2 不是素数 3为end
        //{
        //    bool flag = int.TryParse(num, out number);
        //    int n = 3;
        //    if (num == "end")
        //    {
        //        return n;
        //    }
        //    while (flag == false)
        //    {
        //        if (num == "end")
        //        {
        //            return n;
        //        }
        //        Console.WriteLine("您的输入有误请重新输入，只能输入数字");
        //        num = Console.ReadLine();
        //        flag = int.TryParse(num, out number);
        //    }
        //    for (int i = 2; i < number; i++)
        //    {
        //        if (number % i == 0)
        //        {
        //            n = 2;
        //            return n;
        //        }
        //    }
        //    n = 1;
        //    return n;
        //}

        //static void Test(ref int a) 
        //{
        //    int b = a;
        //    a = 500;
        //}


        //public static bool MyTryParse(string str, out int number) ////TryParse();的原理 简易版
        //{
        //    try
        //    {
        //        number = int.Parse(str);
        //        return true;
        //    }
        //    catch 
        //    {
        //        number = 0;
        //        return false;
        //    }
        //}


        //public static void Method(int[] num, out int add, out int max, out int min) //求数组中最大值最小值和的方法
        //{
        //    add = 0;
        //    max = 0;
        //    min = num[0];
        //    for (int i = 0; i < num.Length; i++) 
        //    {
        //        add += num[i];
        //    }
        //    for (int i = 0; i < num.Length; i++) 
        //    {
        //        if (num[i] > max) 
        //        {
        //            max = num[i];
        //        }
        //    }
        //    for (int i = 1; i < num.Length; i++) //int[] num = new int[9]{10,6,66,156,12,64,32,14,75};
        //    {
        //        if ( num[i]<min ) 
        //        {
        //            min = num[i];
        //        }
        //    }

        //}



        //public static int Method(out int a ) 
        //{
        //    a = 10;
        //    return 200;
        //}

        //public static void Method(int a, int b) 
        //{ 
        
        //}


        //public static void Method(int a ,int b, int v) 
        //{
        
        //}


        //public static string result(string str)  //判定输入是否为yn的方法
        //{
        //    while (str != "y" && str != "n") 
        //    {
        //        Console.WriteLine("输入错误，请重新输入");
        //        str = Console.ReadLine();
        //        if (str == "y" || str == "n") 
        //        {
        //            break;
        //        }
        //    }
        //    return str;
        //}

        //public static bool method(int years)  //判断年份方法 返回的是bool类型
        //{
        //    if (years % 400 == 0 || years % 4 == 0 && years % 100 != 0)
        //    {
        //        return true;
        //    }
        //    else
        //    {
        //        return false;
        //    }
        //}


        //public static int method(string num) //读取输入的整数，定义成方法，多次调用(如果用户输入的是数字,则返回,否则提示用户重新输入)
        //{
        //    int numInt = 0;
        //    bool flag = true;
        //    while (flag == true)
        //    {
        //        try
        //        {
        //            numInt = int.Parse(num);
        //            flag = false;
        //        }
        //        catch
        //        {
        //            Console.WriteLine("您输入的有误，只能输入数字，请重新输入");
        //            num = Console.ReadLine();
        //            flag = true;
        //        }
        //    }
        //    return numInt;
        //}


        //public static string Method(string answer)  //让用户只能输入y/n 的方法
        //{
        //    bool flag = true;
        //    while (flag)
        //    {
        //        if (answer == "y" || answer == "n")
        //        {
        //            flag = false;
        //        }
        //        else
        //        {
        //            Console.WriteLine("输入有误！只能输入y/n，请重新输入");
        //            answer = Console.ReadLine();
        //            flag = true;
        //        }
        //    }
        //    return answer;
        //}

        //public static int Method(string num1,string num2) //计算两个数的最大值的方法
        //{
        //    bool flag = true;
        //    int numInt1 = 0;
        //    int numInt2 = 0;
        //    int max = 0;
        //    do
        //    {
        //        try
        //        {
        //            Console.WriteLine("请输入第一个数字");
        //            num1 = Console.ReadLine();
        //            numInt1 = int.Parse(num1);
        //            Console.WriteLine("请输入第二个数字");
        //            num2 = Console.ReadLine();
        //            numInt2 = int.Parse(num2);
        //            flag = false;
        //        }
        //        catch
        //        {
        //            Console.WriteLine("您的输入有误，只能输入数字，请重新输入");
        //            do
        //            {
        //                try
        //                {
        //                    Console.WriteLine("请输入第一个数字");
        //                    num1 = Console.ReadLine();
        //                    numInt1 = int.Parse(num1);
        //                    Console.WriteLine("请输入第二个数字");
        //                    num2 = Console.ReadLine();
        //                    numInt2 = int.Parse(num2);
        //                    flag = false;
        //                }
        //                catch 
        //                {
        //                    Console.WriteLine("您的输入有误，请重新输入");
        //                    flag = true;
        //                }
        //            }
        //            while (flag);
        //        }
        //    }
        //    while (flag);
        //    int[] num = new int[] { numInt1, numInt2 };
        //    for (int i = 0; i < 2; i++) 
        //    {
        //        if (num[i] > max) 
        //        {
        //            max = num[i];
        //        }
        //    }
        //    return max;
        //}


        //public static int Add() //int[] num = new int[] { 30, 50, 68, 64, 31, 94, 65, 34 };
        //{
        //    int[] num = new int[] { 30, 50, 68, 64, 31, 94, 65, 34 };

        //}

        //public static int Add()  //计算输入数组的和 的方法
        //{
        //    int sum = 0;
        //    int[] num = new int[7];
        //    for (int i = 0; i < num.Length; i++)
        //    {
        //        Console.WriteLine("请输入num[{0}]的值", i);
        //        num[i] = int.Parse(Console.ReadLine());
        //    }
        //    for (int i = 0; i < num.Length; i++)
        //    {
        //        sum += num[i];
        //    }
        //    return sum;
        //}



        //public static int Method()
        //{
        //    int number = 0;
        //    while (true)
        //    {
        //        try
        //        {
        //            number = int.Parse(Console.ReadLine());
        //            return number;
        //        }
        //        catch
        //        {
        //            Console.WriteLine("输入有误");
        //        }
        //    }
        //}


    }
}
