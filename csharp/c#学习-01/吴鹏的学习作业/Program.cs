using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 吴鹏的学习作业
{
    class Program
    {
        static void Main(string[] args)
        {
            //var name = "张三";
            //int age = 28;
            //decimal money = 7600.33m;
            //System.Console.WriteLine("我叫"+name);
            //System.Console.WriteLine("今天"+age+"岁了");
            //System.Console.WriteLine("我的工资是"+money+"元");
            //System.Console.ReadLine();


            //int age = 18;
            //System.Console.WriteLine("您好，您今年"+age+"岁了吗？");
            //System.Console.Write("YES or NO :");
            //System.Console.ReadLine();
            //System.Console.Write("那您今年几岁了呢？");
            //var age = System.Console.ReadLine();
            //System.Console.WriteLine("好的，你今年"+age);
            //System.Console.ReadLine();


            //string name = "zhangsan";
            //int age = 28;


            //System.Console.WriteLine("我叫"+name,"今年");
            //System.Console.ReadLine();


            //var name = "吴鹏";
            //char sex = '男';
            //int age = 20;
            //long phone = 13622223260;
            //System.Console.WriteLine(name+"\n"+sex+"\n"+age+"\n"+phone);
            //System.Console.ReadLine();


            //var phone = "philips";
            //var number = "998";
            //int money = 1500;
            //double weight = 0.3;
            //System.Console.WriteLine("我的手机是{0}，型号：{1}，价格为：{2}，手机重量：{3}kg",phone,number,money,weight);
            //System.Console.ReadLine();


            //int a = 10, b = 5, c, d;
            //c = a;
            //d = c;
            //d = b;
            //b = a;
            //System.Console.WriteLine(a);
            //System.Console.ReadLine();


            //double chinese = 90;
            //double match = 80;
            //double english = 93;
            //double pjcj = (chinese + match + english) / 3;
            //double zcj = chinese + match + english;
            //System.Console.WriteLine("你的平均分为：{0}\n你的总成绩为{1}", pjcj, zcj);
            //System.Console.ReadLine();


            //int a = 10, b = 20;
            //System.Console.WriteLine("a与b的和为{0}",a+b);
            //System.Console.ReadLine();


            //int r = 5;
            //double PI = 3.1415926;
            //double S = PI * (r * r);
            //System.Console.WriteLine("圆的面积为{0}", S);
            //System.Console.ReadLine();


            //double c1 = 35;
            //double c2 = 120;
            //double dz = (3 * c1 + 2 * c2) * 0.88;
            //double totalmoney = 3 * c1 + 2 * c2;
            //System.Console.WriteLine("小明应付：{0}", totalmoney);
            //System.Console.WriteLine("如果打折需要支付：{0}", dz);
            //System.Console.ReadLine();


            //double a = 10.1231512313156;
            //int b = 3;
            //long c = 4;
            //var duo = a * b * c;
            //System.Console.WriteLine(duo);
            //System.Console.ReadLine();


            //System.Console.Write("请输入你的语文成绩");
            //var chinese = System.Console.ReadLine();
            //System.Console.Write("请输入你的数学成绩");
            //var math = System.Console.ReadLine();


            //double a1 = Convert.ToDouble(chinese);
            //int a2 = Convert.ToInt32(math);


            //var all = a1 + a2;
            //System.Console.WriteLine("您的总成绩为{0}",all);
            //System.Console.ReadLine();


            //double a = 1.8,b = 0.7;
            //double mod = a % b;
            //double quo = a / b;
            //System.Console.WriteLine(mod);
            //System.Console.WriteLine(quo);
            //System.Console.ReadLine();


            //string a = "90";
            //int ia = Convert.ToInt32("90");
            //int b = 80;
            //System.Console.WriteLine(ia+b);
            //System.Console.ReadLine();


            //int chinese = int.Parse(System.Console.ReadLine());
            //int match = int.Parse(System.Console.ReadLine());
            //System.Console.WriteLine(chinese+match);
            //System.Console.ReadLine();


            //double chinese = Convert.ToDouble(System.Console.ReadLine());
            //double match = Convert.ToDouble(System.Console.ReadLine());
            //System.Console.WriteLine(chinese+match);
            //System.Console.ReadLine();


            //try
            //{
            //    System.Console.Write("请输入你的语文成绩：");
            //    var chinese = Convert.ToDouble(System.Console.ReadLine());
            //    System.Console.Write("请输入你的数学成绩：");
            //    var match = Convert.ToDouble(System.Console.ReadLine());
            //    System.Console.WriteLine("您的成绩总和为{0}", chinese + match);
            //}
            //catch
            //{
            //    System.Console.WriteLine("您输入的结果有误，请重新运行程序");
            //}
            //    System.Console.ReadLine();


            //try
            //{
            //    System.Console.Write("请输入您的姓名：");
            //    string name = System.Console.ReadLine();
            //    System.Console.Write("请输入您的语文成绩：");
            //    double chinese = double.Parse(System.Console.ReadLine());
            //    System.Console.Write("请输入您的数学成绩：");
            //    double match = double.Parse(System.Console.ReadLine());
            //    System.Console.Write("请输入您的英语成绩：");
            //    double english = double.Parse(System.Console.ReadLine());
            //    System.Console.Write("您的总分为{0}\n您的平均分为{1}", chinese + match + english, (chinese + match + english) / 3);

            //    System.Console.ReadLine();
            //}
            //catch
            //{
            //    System.Console.WriteLine("您输出的有误，请重启程序后重新输入");
            //    System.Console.ReadLine();
            //}


            //System.Console.Write("请输入你想计算星期周期的天数：");
            //string day = System.Console.ReadLine();
            //int sday = Convert.ToInt32(day);
            //System.Console.WriteLine("为{0}周零{1}天", sday / 7, sday % 7);
            //System.Console.ReadLine();


            //System.Console.Write("请输入你想转换的秒数");
            //int second = int.Parse(System.Console.ReadLine());
            //int day = second / (3600 * 24);
            //int mod = second % (3600 * 24); //107653秒减去mod 还剩下21253秒
            //int hour = mod / (60 * 60);
            //mod = mod % (60 * 60);//减去hour的秒还剩下多少3253秒
            //int min = mod / 60;
            //int second1 = mod % 60;
            //System.Console.WriteLine("{0}秒钟包含了{1}天{2}小时{3}分钟{4}秒",second,day,hour,min,second1);
            //System.Console.ReadLine();



            //Console.Write("请输入你想计算的天数");
            //int day = Convert.ToInt32(Console.ReadLine());
            //int month = day / 30;
            //int mod = day % 30;
            ////int week = (day - month * 30) / 7;
            //int week = mod / 7;
            ////int days = day - month * 30 - week * 7;
            //int days = mod % 7;
            //Console.WriteLine("{0}天，是{1}个月{2}周零{3}天", day, month, week, days);
            //Console.ReadLine();


            //int a = 1;
            //int b = 2;
            //int c;
            //c = a++ + --b;
            //c = a + b;


            //int a = 1;
            //++a;
            //System.Console.WriteLine(a);
            //System.Console.ReadLine();


            //int elepWeight = 1500;
            //int rabbWeigiht = 1;
            //bool isRight = elepWeight > rabbWeigiht;
            //System.Console.WriteLine(isRight);
            //System.Console.ReadLine();


            //int tortOld = 1000;
            //int rabbOld = 3;
            //bool isRight = tortOld < rabbOld;
            //System.Console.WriteLine(isRight);
            //System.Console.ReadLine();


            //bool isRight = 39 < 18;
            //System.Console.WriteLine(isRight);
            //System.Console.ReadLine();


            //int myOld = 20;
            //int yourOld = 20;
            //bool isRight = myOld == yourOld;
            //System.Console.WriteLine(isRight);
            //System.Console.ReadLine();


            //int old = 20, weight = 120;
            //var isRight = old > 30 && weight > 100;
            //System.Console.WriteLine(isRight);
            //System.Console.Read();


            //System.Console.WriteLine("本火车站规定，当您的身高>120cm，体重>50KG则需要买票");
            //System.Console.Write("请输入您的身高");
            //int height = Convert.ToInt32(System.Console.ReadLine());
            //System.Console.Write("请输入您的体重");
            //int weight = Convert.ToInt32(System.Console.ReadLine());
            //bool isRight =height > 120 || weight >= 50;
            //System.Console.WriteLine(isRight);
            //System.Console.Write("根据系统的检查，您需要购买火车票");
            //System.Console.Read();


            //System.Console.Write("请输入您的语文成绩"); //语文和数学成绩都大于90分    语文和数学成绩至少有一门大于90分
            //int chinese = int.Parse(System.Console.ReadLine());
            //System.Console.Write("请输入您的数学成绩");
            //int mat = int.Parse(System.Console.ReadLine());
            //bool score = chinese > 90 && mat > 90;
            //bool score1 = chinese > 90 || mat > 90;
            //System.Console.WriteLine("\"语文和数学成绩都大于90分\"这句话的结果为{0}",score);
            //System.Console.WriteLine("\"语文和数学成绩至少有一门大于90分\"这句话的结果为{0}",score1);
            //System.Console.ReadLine();


            //System.Console.Write("请输入一个年份，判断是否为闰年"); //ture为闰年，false不是闰年
            //int year = int.Parse(System.Console.ReadLine());
            //bool isRight = year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
            //System.Console.WriteLine(isRight);
            //System.Console.ReadLine();


            //int a = 10, b = 5;
            //bool isRight = ++a > 5 && ++b > 7;
            //System.Console.WriteLine("a = {0}  b = {1}",a,b);
            //System.Console.ReadLine();


            //int a = 10, b = 5;
            //bool isRight = ++a > 5 || ++b > 7;
            //System.Console.WriteLine("a = {0}  b = {1}", a, b);
            //System.Console.ReadLine();


            //System.Console.WriteLine("你今天数学考试考了多少分？");
            //int score=Convert.ToInt32(System.Console.ReadLine());
            //if (score > 90) 
            //        System.Console.WriteLine("奖励你100元");           
            //System.Console.ReadLine();


            //System.Console.WriteLine("请输入您的年龄");
            //int old = int.Parse(System.Console.ReadLine());
            //if (old >= 18)
            //{
            //    System.Console.WriteLine("您已成年");
            //}
            //else
            //    System.Console.WriteLine("您还未成年");
            //System.Console.WriteLine("程序结束");
            //System.Console.ReadLine();


            //System.Console.WriteLine("请输入您的音乐成绩");
            //int music = int.Parse(System.Console.ReadLine());
            //System.Console.WriteLine("请输入您的语文成绩");
            //int chinese = int.Parse(System.Console.ReadLine());
            //if (chinese > 90 && music > 80 ||
            //    chinese == 100 && music > 70)
            //{
            //    System.Console.WriteLine("奖励100元");
            //}
            //else
            //{
            //    System.Console.WriteLine("不给你钱");
            //}
            //System.Console.WriteLine("程序结束");
            //System.Console.ReadLine();


            //System.Console.WriteLine("请输入您的用户名：");
            //var userName = System.Console.ReadLine();
            //System.Console.WriteLine("请输入您的密码：");
            //var passWord = System.Console.ReadLine();
            //if ((userName == "admin") && (passWord == "mypass"))
            //    System.Console.WriteLine("登陆成功");
            //System.Console.WriteLine("程序结束");
            //System.Console.ReadLine();


            //int a = 3;
            //bool b = a > 4;
            //string a1 = Convert.ToString(b);
            //System.Console.WriteLine(b);
            //System.Console.ReadLine();


            //System.Console.Write("盖茨买的鸡蛋里有几颗坏蛋？");
            //int badEgg = Convert.ToInt32(System.Console.ReadLine());
            //if (badEgg <= 5)
            //{
            //    System.Console.WriteLine("我还是吃掉吧");
            //}
            //else 
            //{
            //    System.Console.WriteLine("我要去退货");
            //}
            //System.Console.ReadLine();


            //System.Console.WriteLine("请输入a的值：");
            //int a = Convert.ToInt32(System.Console.ReadLine());
            //System.Console.WriteLine("请输入b的值：");
            //int b = int.Parse(System.Console.ReadLine());


            //if (a % b == 0 || (a + b > 100))
            //{
            //    System.Console.WriteLine(a);
            //}
            //else 
            //{
            //    System.Console.WriteLine(b);
            //}
            //System.Console.ReadLine();


            //System.Console.WriteLine("请输入您的考试成绩");
            //int score = int.Parse(System.Console.ReadLine());
            //if (score >= 90) 
            //{
            //    System.Console.WriteLine("考试成绩评测为A");
            //}
            //if (score >= 80 && score < 90)
            //{
            //    System.Console.WriteLine("考试成绩评测为B");
            //}
            //if (score >= 70 && score < 80)
            //{
            //    System.Console.WriteLine("考试成绩评测为c");
            //}
            //if (score >= 60 && score <70)
            //{
            //    System.Console.WriteLine("考试成绩评测为D");
            //}
            //if (score < 60)
            //{
            //    System.Console.WriteLine("考试成绩评测为E");
            //}
            //System.Console.ReadLine();


            //System.Console.WriteLine("请输入您的考试成绩");
            //int score = int.Parse(System.Console.ReadLine());
            //if (score >= 90)
            //{
            //    System.Console.WriteLine("A");
            //}
            //else
            //{
            //    if (score >= 80)   //程序进入到这里说明程序<90
            //    {
            //        System.Console.WriteLine("B");
            //    }
            //    else
            //    {
            //        if (score >= 70)  //程序进入到这里说明程序<80
            //        {
            //            System.Console.WriteLine("C");
            //        }
            //        else
            //        {
            //            if (score >= 60)  //程序进入到这里说明程序<70
            //            {
            //                System.Console.WriteLine("D");
            //            }
            //            else
            //            {
            //                System.Console.WriteLine("E");  //程序进入到这里说明程序<60
            //            }
            //        }
            //    }
            //}
            //        System.Console.ReadLine();


            //int y = 1, x;
            //if (y == 0)
            //{
            //    x = 5;
            //}
            //else if (y > 0)
            //{
            //    x = 4;
            //}
            //else
            //{
            //    x = 3;
            //}
            //System.Console.WriteLine("x={0}", x);
            //System.Console.ReadLine();

            //int x = 5;
            //int y = x--;
            //System.Console.WriteLine("y={0}", y);
            //y = --x;
            //System.Console.WriteLine("y={0}", y);
            //System.Console.ReadLine();


            //System.Console.WriteLine("请输入您的密码");
            //var passWord = System.Console.ReadLine();
            //if (passWord == "88888888")
            //{
            //    System.Console.WriteLine("密码正确");
            //}
            //else
            //{
            //    System.Console.WriteLine("您输入的密码错误，请重新输入一次\a");
            //    var passWord1 = System.Console.ReadLine();
            //    if (passWord1 == "88888888")
            //    {
            //    System.Console.WriteLine("您输入的密码正确\a");
            //    }
            //    else
            //    {
            //    System.Console.WriteLine("您输入的密码有误，程序将自动退出\a");
            //    }
            //}
            //System.Console.ReadLine();

            //System.Console.WriteLine("请输入您的用户名");
            //string userName = System.Console.ReadLine();
            //System.Console.WriteLine("请输入您的密码");
            //string passWord = System.Console.ReadLine();
            //if (userName == "admin" && passWord == "88888888")
            //{
            //    System.Console.WriteLine("欢迎回来，吴鹏\a");
            //}
            //else if (userName != "admin")
            //{
            //    System.Console.WriteLine("您输入的用户名不存在，请重新输入");
            //}
            //else if (userName != "88888888")
            //    System.Console.WriteLine("您输入的密码错误，请重新输入");
            //System.Console.WriteLine("请输入您的用户名");
            //string userName1 = System.Console.ReadLine();
            //System.Console.WriteLine("请输入您的密码");
            //string passWord1 = System.Console.ReadLine();

            //if (userName1 == "admin" && passWord1 == "88888888")
            //{
            //    System.Console.WriteLine("欢迎回来，吴鹏\a");
            //}
            //else if (userName1 != "admin")
            //{
            //    System.Console.WriteLine("您输入的用户名出现了两次错误，程序将自动退出");
            //}
            //else if (passWord1 != "88888888")
            //{
            //    System.Console.WriteLine("您输入的密码出现了两次错误，程序将自动退出");
            //}

            //System.Console.ReadLine();


            //System.Console.WriteLine("请输入您的年龄");
            //int age = int.Parse(System.Console.ReadLine());
            //if (age >= 18)
            //{
            //    System.Console.WriteLine("您可以查阅此内容\a");
            //}
            //else if (age < 10) 
            //{
            //    System.Console.WriteLine("您不能查阅此内容");
            //}
            //else
            //{
            //    System.Console.WriteLine("你是否要查看此内容？\nYES or NO");
            //    string answer = System.Console.ReadLine();
            //    if (answer == "yes")
            //    {
            //        System.Console.WriteLine("您可以查看此内容\a");
            //    }
            //    else 
            //    {
            //        if (answer == "no")
            //        {
            //            System.Console.WriteLine("您不能查看此内容");
            //        }
            //        else 
            //        {
            //            System.Console.WriteLine("您输入的内容有误，程序将自动退出");
            //        }
            //    }
            //}
            //System.Console.ReadLine();

            //System.Console.WriteLine("请输入对张三的评级 \"A-E\"");
            //string input = System.Console.ReadLine();  //t
            //decimal salary = 5000;
            //bool flag = flase;
            //if (input == "A")
            //{
            //    salary += 500;
            //}
            //else if (input == "B")
            //{
            //    salary += 200;
            //}
            //else if (input == "C")
            //{
            //}
            //else if (input == "D")
            //{
            //    salary -= 200;
            //}
            //else if (input == "E")
            //{
            //    salary -= 500;
            //}
            //else
            //{
            //    System.Console.WriteLine("输入有误，程序将结束");
            //    flag = true;
            //}
            //if (flag == false)
            //{
            //    System.Console.WriteLine(salary);
            //}
            //System.Console.ReadLine();

            //System.Console.WriteLine("请输入对张三的评级 \"A-E\"");
            //string input = System.Console.ReadLine();
            //decimal salary = 5000;
            //if (input == "A")
            //{
            //    salary += 500;
            //}
            //else if (input == "B")
            //{
            //    salary += 200;
            //}
            //else if (input == "C")
            //{
            //}
            //else if (input == "D")
            //{
            //    salary -= 200;
            //}
            //else if (input == "E")
            //{
            //    salary -= 500;
            //}
            //else
            //{
            //    System.Console.WriteLine("输入有误，程序将结束");
            //}
            //System.Console.WriteLine(salary);
            //System.Console.ReadLine();



            //System.Console.WriteLine("请输入您对张三的评价 A-E");
            //string inPut = System.Console.ReadLine();
            //decimal salary = 5000m;
            //bool flag = true;
            //switch (inPut)
            //{
            //    case "A":
            //        salary += 500;
            //        break;
            //    case "B":
            //        salary += 200;
            //        break;
            //    case "C":
            //        break;
            //    case "D":
            //        salary -= 200;
            //        break;
            //    case "E":
            //        salary -= 500;
            //        break;
            //    default:
            //        System.Console.WriteLine("您输入的内容有误");
            //        flag = false;
            //        break;
            //}
            //if (flag == true)
            //{
            //    System.Console.WriteLine("张三的工资为{0}", salary);
            //}
            //System.Console.ReadLine();

            //已学过的数据类型：int char decimal long var string bool double 

            //已学过的运算符：+,-,*,/,%,++,--,+=,-=,*=,/=,%=,>,<,<=,>=,&&,||,！=,==,=


            //System.Console.Write("请输入一个年份，判断是否为闰年"); //ture为闰年，false不是闰年
            //int year = int.Parse(System.Console.ReadLine());
            //bool isRight = year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
            //System.Console.WriteLine(isRight);
            //System.Console.ReadLine();

            //System.Console.WriteLine("请输入一个年份");
            //int year = int.Parse(System.Console.ReadLine());
            //System.Console.WriteLine("请输入一个月份");
            //string month = System.Console.ReadLine();   //1357810 31天 闰年2月29天平年28天
            //bool flag = true;
            //int day=30;
            //if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
            //{
            //    switch (month)
            //    {
            //        case "1":
            //            day = 31;
            //            break;
            //        case "2":
            //            day = 29;
            //            break;
            //        case "3":
            //            day = 30;
            //            break;
            //        case "4":
            //            day = 30;
            //            break;
            //        case "5":
            //            day = 31;
            //            break;
            //        case "6":
            //            day = 30;
            //            break;
            //        case "7":
            //            day = 31;
            //            break;
            //        case "8":
            //            day = 31;
            //            break;
            //        case "9":
            //            day = 30;
            //            break;
            //        case "10":
            //            day = 31;
            //            break;
            //        case "11":
            //            day = 30;
            //            break;
            //        case "12":
            //            day = 31;
            //            break;
            //        default:
            //            System.Console.WriteLine("您输入的月份有误！");
            //            flag = false;
            //            break;
            //    }
            //    if (flag == true)
            //    {
            //        System.Console.WriteLine("{0}年{1}月有{2}天",year,month,day );
            //    }
            //}
            //else
            //{
            //    switch (month)
            //    {
            //        case "1":
            //            day = 31;
            //            break;
            //        case "2":
            //            day = 28;
            //            break;
            //        case "3":
            //            day = 30;
            //            break;
            //        case "4":
            //            day = 30;
            //            break;
            //        case "5":
            //            day = 31;
            //            break;
            //        case "6":
            //            day = 30;
            //            break;
            //        case "7":
            //            day = 31;
            //            break;
            //        case "8":
            //            day = 31;
            //            break;
            //        case "9":
            //            day = 30;
            //            break;
            //        case "10":
            //            day = 31;
            //            break;
            //        case "11":
            //            day = 30;
            //            break;
            //        case "12":
            //            day = 31;
            //            break;
            //        default:
            //            System.Console.WriteLine("您输入的月份有误！");
            //            flag = false;
            //            break;
            //    }
            //    if (flag == true)
            //    {
            //        System.Console.WriteLine("{0}年{1}月有{2}天",year,month,day );
            //    }
            //}
            //System.Console.ReadLine();

            //System.Console.WriteLine("请输入一个年份");
            //int year = int.Parse(System.Console.ReadLine());
            //System.Console.WriteLine("请输入一个月份");
            //string month = System.Console.ReadLine();
            //switch (month)
            //{
            //    case "1":
            //    case "3":
            //    case "5":
            //    case "7":
            //    case "8":
            //    case "10":
            //    case "12":
            //        System.Console.WriteLine("{0}年，{1}月，有31天", year, month);
            //        break;
            //    case "4":
            //    case "6":
            //    case "9":
            //    case "11":
            //        System.Console.WriteLine("{0}年{1}月，有30天", year, month);
            //        break;
            //    case "2":
            //        if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
            //        {
            //            System.Console.WriteLine("{0}年{1}月，有29天", year, month);
            //        }
            //        else
            //        {
            //            System.Console.WriteLine("{0}年{1}月，有28天", year, month);
            //        }
            //        break;


            //}
            //System.Console.ReadLine();

            //System.Console.WriteLine("请输入您的成绩");
            //int score = Convert.ToInt32(System.Console.ReadLine());
            //switch (score / 10)
            //{
            //    case 10:
            //        System.Console.WriteLine("A");
            //        break;
            //    case 9:
            //        System.Console.WriteLine("A");
            //        break;
            //    case 8:
            //        System.Console.WriteLine("B");
            //        break;
            //    case 7:
            //        System.Console.WriteLine("C");
            //        break;
            //    case 6:
            //        System.Console.WriteLine("D");
            //        break;
            //    default:
            //        System.Console.WriteLine("E");
            //        break;
            //}
            //System.Console.ReadLine();

            //int i = 1;
            //while (i <= 10)
            //{
            //    System.Console.WriteLine("欢迎您来到传智播客来学习");
            //    ++i;
            //}
            //System.Console.WriteLine(i);
            //System.Console.ReadLine();

            //System.Console.WriteLine("请输入您班级的人数");
            //int n = Convert.ToInt32(System.Console.ReadLine()); //n表示班级的人数
            //int i = 0;
            //int scoreAll = 0;
            //int score = 0;
            //while (i < n)
            //{
            //    System.Console.WriteLine("您正在第{0}个学生的成绩",i+1);
            //    score = int.Parse(System.Console.ReadLine());
            //    scoreAll = scoreAll + score;
            //    i++;
            //}
            //System.Console.WriteLine("根据您输入的结果，计算出学生的总成绩为{0}，学生的平均分为{1}",scoreAll,scoreAll/n);
            //System.Console.ReadLine();

            //System.Console.WriteLine("这道题你会做了吗？");
            //string answer = System.Console.ReadLine();
            //int i = 0;
            //if (answer == "y")
            //{
            //    System.Console.WriteLine("那你回家吧！");
            //}
            //else
            //{
            //    while (i < 5 && answer == "n")
            //    {
            //        System.Console.WriteLine("我就给你讲5遍，这是第{0}遍", i+1);
            //        System.Console.WriteLine("这道题你会了吗?");
            //        answer = System.Console.ReadLine();
            //        i++;
            //    }
            //}
            //System.Console.WriteLine("明天讲吧！");
            //System.Console.ReadLine();

            //double year = 2006;
            //double student = 80000;
            //while (student < 200000)
            //{
            //    student = student + (student * 0.25);
            //    year++;
            //}
            //System.Console.WriteLine("到{0}为止人数增加到200000", year);
            //System.Console.ReadLine();

            //System.Console.WriteLine("计算1-100之间的和");
            //int i = 1;
            //int sum = 0;
            //while (i <= 100)
            //{
            //    sum += i;
            //    i++;
            //}
            //System.Console.WriteLine(sum);
            //System.Console.Read();

            //string userName;
            //string passWord;
            //do
            //{
            //    System.Console.WriteLine("请输入您的用户名");
            //    userName = System.Console.ReadLine();
            //    System.Console.WriteLine("请输入您的密码");
            //    passWord = System.Console.ReadLine();
            //    if (userName != "admin" || passWord != "88888888")
            //    {
            //        System.Console.WriteLine("用户名或密码错误，请重新输入");
            //    }
            //}
            //while (userName != "admin" && passWord != "88888888");
            //System.Console.WriteLine("登陆成功！");
            //System.Console.ReadLine();


            //System.Console.WriteLine("请输入您的用户名：");
            //var userName = System.Console.ReadLine();
            //System.Console.WriteLine("请输入您的密码：");
            //var passWord = System.Console.ReadLine();
            //while (passWord != "88888888" && userName != "admin")
            //{
            //    System.Console.WriteLine("您输入有误，请重新输入");
            //    System.Console.WriteLine("请输入您的用户名：");
            //    userName = System.Console.ReadLine();
            //    System.Console.WriteLine("请输入您的密码：");
            //    passWord = System.Console.ReadLine();
            //}
            //System.Console.WriteLine("登陆成功！\a");
            //System.Console.ReadLine();


            //System.Console.WriteLine("请输入学生的姓名");
            //var stuName = System.Console.ReadLine();
            //while (stuName != "q") 
            //{
            //    System.Console.WriteLine("请输入学生的姓名");
            //    stuName = System.Console.ReadLine();
            //}
            //System.Console.WriteLine("程序结束");
            //System.Console.ReadLine();
            
            //string num = "0";
            //while (num != "q")
            //{
            //    try
            //    {
            //        System.Console.WriteLine("请输入一个数字");
            //        num = System.Console.ReadLine();
            //        int numInt = int.Parse(num);
            //        numInt *= 2;
            //        System.Console.WriteLine(numInt);
            //    }
            //    catch
            //    {
            //        if (num == "q")
            //        {
            //            System.Console.WriteLine("您刚刚输入了指令，程序结束");
            //        }
            //        else
            //        {
            //            System.Console.WriteLine("您输入的不是数字！");
            //        }
            //    }
            //}
            //    System.Console.ReadLine();


            //string answer;
            //do
            //{
            //    System.Console.WriteLine("张三唱了一遍歌");
            //    System.Console.WriteLine("老师，您是否满意 (y/n)");
            //    answer = System.Console.ReadLine();
            //    while (answer != "y" && answer != "n")
            //    {
            //        System.Console.WriteLine("您输入的不是y/n，请重新输入");
            //        answer = System.Console.ReadLine();
            //    }
            //}
            //while (answer != "y");
            //System.Console.WriteLine("你可以回家了");
            //System.Console.ReadLine();


            //string answer;
            //do
            //{
            //    System.Console.WriteLine("张三唱了一遍歌");
            //    System.Console.WriteLine("老师，您觉得怎么样 y/n");
            //    answer = System.Console.ReadLine();
            //}
            //while (answer != "y");
            //System.Console.WriteLine("你可以回家了");
            //System.Console.ReadLine();

            //int number;
            //string strNumber = "";
            //int max = 0;
            //bool flag = true;
            //do
            //{
            //    try
            //    {
            //        System.Console.WriteLine("请输入一个数字：");
            //        strNumber = System.Console.ReadLine();
            //        if (strNumber == "end")
            //        {
            //            System.Console.WriteLine("程序结束");
            //        }
            //        else
            //        {
            //            number = int.Parse(strNumber);
            //            if (number > max)  //求最大值的做法 
            //            {
            //                max = number;
            //            }
            //        }
            //    }
            //    catch
            //    {
            //        System.Console.WriteLine("您输入的有误，程序即将结束");
            //        strNumber = "end";
            //        flag = false;
            //    }
            //}
            //while (strNumber != "end");
            //if (flag == true)
            //{
            //    System.Console.WriteLine("您输如的最大值为{0}", max);
            //}
            //else if (flag == false)
            //{
            //}
            //System.Console.ReadLine();

            //int num = 0;
            //for (int i = 2; i <= 100; i += 2) 
            //{
            //    System.Console.WriteLine(i);
            //    num += i;
            //}
            //System.Console.WriteLine(num);
            //System.Console.ReadLine();


            //int i;
            //for (i = 100; i <= 999; i++)   //求100-999的水仙花数
            //{
            //    int a = i / 100;
            //    int b = (i % 100)/10;
            //    int c = (i % 100 ) % 10;
            //    if (i == a * a * a + b * b * b + c * c * c) 
            //    {
            //        System.Console.WriteLine(i);
            //    }
            //}
            //System.Console.ReadLine();

            //int i;                                        //这是我第一遍复杂的写法
            //for (i = 1; i < 10; i++)
            //{
            //    int num1 = 1 * i;
            //    System.Console.Write("1x{0}={1}\t", i, num1);
            //}
            //Console.WriteLine();
            //for (i = 1; i < 10; i++)
            //{
            //    int num2 = 2 * i;
            //    System.Console.Write("{0}x2={1}\t", i, num2);
            //}
            //Console.WriteLine();
            //for (i = 1; i < 10; i++)
            //{
            //    int num3 = 3 * i;
            //    System.Console.Write("{0}x3={1}\t", i, num3);
            //}
            //Console.WriteLine();
            //for (i = 1; i < 10; i++)
            //{
            //    int num4 = 4 * i;
            //    System.Console.Write("{0}x4={1}\t", i, num4);
            //}
            //Console.WriteLine();
            //for (i = 1; i < 10; i++)
            //{
            //    int num5 = 5 * i;
            //    System.Console.Write("{0}x5={1}\t", i, num5);
            //}
            //Console.WriteLine();
            //for (i = 1; i < 10; i++)
            //{
            //    int num6 = 6 * i;
            //    System.Console.Write("{0}x6={1}\t", i, num6);
            //}
            //Console.WriteLine();
            //for (i = 1; i < 10; i++)
            //{
            //    int num7 = 7 * i;
            //    System.Console.Write("{0}x7={1}\t", i, num7);
            //}
            //Console.WriteLine();
            //for (i = 1; i < 10; i++)
            //{
            //    int num8 = i * 8;
            //    System.Console.Write("{0}x8={1}\t", i, num8);
            //}
            //Console.WriteLine();
            //for (i = 1; i < 10; i++)
            //{
            //    int num9 = i * 9;
            //    System.Console.Write("{0}x9={1}\t", i, num9);
            //}
            //Console.WriteLine();
            //System.Console.ReadLine();

    
            //int i=0;
            //for (; ; i += 57) 
            //{
            //    Console.WriteLine(i);
            //}
            //Console.ReadLine();


            //for (int i = 1; i < 10; i++)  //9乘9算数表                       //这是正确的写法
            //{
            //    for (int n = 1; n < 10; n++)
            //    {
            //        Console.Write("{0}x{1}={2}\t", i, n, i * n);
            //    }
            //    Console.WriteLine();
            //    Console.WriteLine();
            //}
            //Console.ReadLine();


            //for (int i = 1; i < 10; i++)    //算术表，梯形写法
            //{
            //    for (int n = 1; n <= i; n++)
            //    {
            //        Console.Write("{0}x{1}={2}\t", i, n, i * n);
            //    }
            //    Console.WriteLine();
            //}
            //Console.ReadLine();


            //int num1 = 6;
            //for (int num = 0; num <= 6 && num >= 0; num++) 
            //{
            //    Console.WriteLine("{0}+{1}={2}",num,num1--,num + num1);
            //    Console.WriteLine();
            //}
            //Console.ReadLine();


            //bool flag = true;
            //while (flag == true)                     这是正确的写法
            //{
            //    try
            //    {
            //        Console.WriteLine("请输入一个数字");   //得出结论n+(i-n)=i
            //        int i = int.Parse(Console.ReadLine());  //假设n=6
            //        for (int n = 0; n <= i; n++)
            //        {
            //            System.Console.WriteLine("{0}+{1}={2}", n, (i - n), i);
            //        }
            //        Console.WriteLine("程序结束！按任意键退出");
            //        flag = false;
            //    }
            //    catch
            //    {
            //        Console.WriteLine("您输入的数字有误，请重新输入！");
            //    }
            //}
            //Console.ReadLine();


            //Console.WriteLine("请输入一个数字");                        这是我第一遍做的错误的写法
            //int i = int.Parse(Console.ReadLine());  //假设i=6
            //for (int n = 0; n <= i; n++)
            //{
            //    System.Console.WriteLine("{0}+{1}={2}",n,i,i);
            //    i--;
            //}
            //Console.ReadLine();

            //for (int i = 1; i <= 9; i++)
            //{
            //    for (int n = 1; n <= 9; n++)
            //    {
            //        Console.Write("{0}x{1}={2}\t", i, n, i * n);
            //    }
            //    Console.WriteLine();
            //    Console.WriteLine();
            //}
            //Console.ReadLine();


            //for (int i = 1; i <= 9; i++)
            //{
            //    for (int n = 1; n <= i; n++)
            //    {
            //        Console.Write("{0}x{1}={2}\t", n, i, i * n);
            //    }
            //    Console.WriteLine();
            //}
            //Console.WriteLine();
            //Console.WriteLine();
            //Console.WriteLine();
            //Console.WriteLine();
            //Console.WriteLine();
            //Console.WriteLine();
            //for (int i = 1; i <= 9; i++)
            //{
            //    for (int n = 1; n <= 9; n++)
            //    {
            //        Console.Write("{0}x{1}={2}\t", i, n, i * n);
            //    }
            //    Console.WriteLine();
            //    Console.WriteLine();
            //}
            //Console.ReadLine();

            //Console.ReadLine();


            //bool flag = true;
            //while (flag == true)
            //{
            //    try
            //    {
            //        Console.WriteLine("请输入一个数字");
            //        int n = int.Parse(Console.ReadLine()); //n =  6
            //        for (int i = 0; i <= n; i++)
            //        {
            //            Console.WriteLine("{0}+{1}={2}", i, (n - i), n);
            //        }
            //        flag = false;
            //    }
            //    catch
            //    {
            //        Console.WriteLine("您输入的有误，请重新输入！");
            //        flag = true;
            //    }
            //}
            //Console.ReadLine();

            //int i = 1;
            //int num = 0;
            //bool flag = true;
            //do
            //{
            //    Console.WriteLine("请输入第{0}个人的年龄", i);
            //    int old = int.Parse(Console.ReadLine());
            //    num = num + old;
            //    i++;
            //    if (old <= 0 || old > 100)
            //    {
            //        Console.WriteLine("您输入的有误，程序即将退出");
            //        flag = false;
            //        break;
            //    }
            //}
            //while (i <= 5);
            //if (flag == true)
            //{
            //    Console.WriteLine("平均年龄为{0}", num / 5);
            //}
            //Console.ReadLine();


            //Console.WriteLine("请输入您的用户名");
            //string userName = Console.ReadLine();
            //Console.WriteLine("请输入您的密码");
            //string passWord = Console.ReadLine();
            //while(userName != "admin" && passWord != "88888888")
            //{
            //    Console.WriteLine("用户名或密码错误，请重新输入");
            //    Console.WriteLine("请输入您的用户名");
            //    userName = Console.ReadLine();
            //    Console.WriteLine("请输入您的密码");
            //    passWord = Console.ReadLine();
            //    if (userName == "admin" && passWord == "88888888") 
            //    {
            //        break;
            //    }
            //}
            //Console.WriteLine("登陆成功！\a");
            //Console.ReadLine();


            //int sum = 0;
            //int n = 1;
            //for (int i = 1; i <= 100; i += n)
            //{
            //    n++;
            //    sum = i + n;
            //    Console.WriteLine("{0}+{1}={2}", i, n, sum);
            //    if (sum > 20)
            //    {
            //        Console.WriteLine("当+到{0}的时候，累加值>20", n);
            //        break;
            //    }
            //}
            //Console.ReadLine();

            //int i = 1;
            //int sum = 0;
            //while (i <= 100) 
            //{
            //    if (i % 7 == 0) 
            //    {
            //        i++;
            //        continue;
            //    }
            //    sum += i;
            //    i++;
            //}
            //Console.WriteLine(sum);
            //Console.ReadLine();














        }
    }
}
