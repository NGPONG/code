using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 吴鹏_面向对象
{
    class Program
    {
        static void Main(string[] args)
        {


            // Student zhangsan = new Student("张三",'男');
            ////zhangsan.Name = "张三";
            ////zhangsan.Sex = '男';

            //Student xiaolan = new Student("小兰",'女',16,95,85,100);
            ////xiaolan.Name = "小兰";
            ////xiaolan.Sex = '女';
            ////xiaolan.Age = 16;
            ////xiaolan.Chinese = 95;
            ////xiaolan.Math = 85;
            ////xiaolan.English = 100;

            //zhangsan.SayHello();
            //zhangsan.Score();
            //Console.WriteLine();
            //xiaolan.SayHello();
            //xiaolan.Score();

            //Console.ReadLine();


            //Ticket information;
            //information = new Ticket(120);
            //information.ShowTicket();

            //Console.ReadLine();

            //string str = "Hello World！";
            //for (int i = 0; i < str.Length; i++) 
            //{
            //    Console.Write(str[i]);
            //}
            //Console.ReadLine();

            //string str = "12345";
            //char[] test = str.ToCharArray();
            //test[1] = '6';
            //str = new string(test);
            //Console.WriteLine(str);
            //Console.ReadLine();


            //Console.WriteLine("请输入你心中想到的一个名字");
            //string str = Console.ReadLine();
            //Console.WriteLine(str.Length);
            //Console.ReadLine();


            //Console.WriteLine("请输入学员一喜欢的课程");
            //string str1 = Console.ReadLine();
            //Console.WriteLine("请输入学员二喜欢的课程");
            //string str2 = Console.ReadLine();
            //if (str1[1] == str2[1]) 
            //{
            //    Console.WriteLine("你们喜欢{0}课程",str1);
            //}
            //else if (str1 == str2)
            //{
            //    Console.WriteLine("你们喜欢{0}课程", str1);
            //}
            //else
            //{
            //    Console.WriteLine("学员一喜欢：{0}\n学员二喜欢：{1}", str1, str2);
            //}
            //Console.ReadLine();


            //Person zhangsan = new Person();
            //int a = zhangsan.Age;
            //Console.WriteLine(a);
            //Console.ReadLine();


            //string scoreA = "JAVA";
            //string scoreB = "java";

            //scoreA = scoreA.ToLower();
            //scoreB = scoreB.ToUpper();

            //Console.WriteLine(scoreB);
            //Console.ReadLine();


            //string scoreA = "JAVA";
            //string scoreB = "java";


            //if (scoreA.Equals(scoreB, StringComparison.OrdinalIgnoreCase))
            //{
            //    Console.WriteLine("一样");
            //}
            //else
            //{
            //    Console.WriteLine("不一样");
            //}
            //Console.ReadLine();


            //string str1 = "ABC";
            //str1 = str1.ToLower();
            //Console.WriteLine(str1);
            //Console.ReadLine();

            //string strA = "ABCDEFG";
            //string strB = "abcdefg";

            //if (strA.Equals(strB, StringComparison.OrdinalIgnoreCase))
            //{
            //    Console.WriteLine(true);
            //}
            //else 
            //{
            //    Console.WriteLine(false);
            //}
            //Console.ReadLine();

            //string strA = "ABCDEFG";
            //string strB = "abcdefg";

            //strA = strA.ToLower();
            //strB = strB.ToUpper();

            //Console.WriteLine(strA);
            //Console.WriteLine(strB);
            //Console.ReadLine();


            //Person test = new Person();
            //string str = test.ToString();
            //Console.WriteLine(str);
            //Console.ReadLine();


            //string str = "hello world";
            //char[] value = { ' ' };
            //string[] result = str.Split(value);
            //Console.WriteLine("输出的语句有{0}个单词", result.Length);
            //Console.WriteLine("他们分别为");
            //for (int i = 0; i < result.Length; i++)
            //{
            //    Console.WriteLine(result[i]);
            //}
            //Console.ReadLine();


            //string str = "how are you? i'am fun , thank you!";
            //char[] cha = { ' ', '?', '!',',' };
            //string[] result = str.Split(cha, StringSplitOptions.RemoveEmptyEntries);
            //Console.WriteLine("输出的语句由{0}个单词",result.Length);
            //Console.WriteLine("分别为");
            //for (int i = 0; i < result.Length; i++) 
            //{
            //    Console.WriteLine(result[i]);
            //}
            //Console.ReadLine();


            //string strA = "ABC";
            //char[] result = strA.ToCharArray();
            //result[1] = 'C';
            //strA = new string(result);
            //Console.WriteLine(strA);
            //Console.ReadLine();


            //string data = "2008-08-08";
            //for (int i = 0; i < data.Length; i++) 
            //{
            //    if (data[i] == '-') 
            //    {
            //        char[] result = data.ToCharArray();
            //        result[i] = '年';
            //        data = new string(result);
            //    }
            //    if (data[7] == '年') 
            //    {
            //        char[] result = data.ToCharArray();
            //        result[i] = '月';
            //        data = new string(result);
            //    }
            //}

            //Console.WriteLine(data);
            //Console.ReadLine();


            //string num = "2008 - 08 - 08";
            //Console.WriteLine(num);
            //char[] dataRead = { ' ', '-','/'};
            //string[] data = num.Split(dataRead, StringSplitOptions.RemoveEmptyEntries);
            //Console.WriteLine("{0}年{1}月{2}日",data[0],data[1],data[2]);
            //Console.ReadLine();



            //string num = "2017 - 12 - 7";
            //num = num.Replace('-', '/');
            //char[] numChar = { '/'};
            //string[] result = num.Split(numChar, StringSplitOptions.RemoveEmptyEntries);
            //Console.WriteLine("您输入的为{0}年{1}月{2}日",result[0],result[1],result[2]);
            //Console.ReadLine();


            //string[] ab = { "tmd", "sb", "cnm" };
            //Console.WriteLine("请输入一句话");
            //string statement = Console.ReadLine();
            //for (int i = 0; i < ab.Length; i++) 
            //{
            //    if (statement.Contains(ab[i])) 
            //    {
            //        statement = statement.Replace(ab[i], "***");
            //    }
            //}
            //Console.WriteLine(statement);
            //Console.ReadLine();


            //string str = "qweqwe12";
            //char[] result = str.ToCharArray();
            //char temp = ' ';
            //int j = result.Length;
            //for (int i = 0; i < result.Length - 3; i++)
            //{
            //    temp = result[i];
            //    result[i] = result[--j];
            //    result[j] = temp;
            //}
            //str = new string(result);
            //Console.WriteLine(str);
            //Console.ReadLine();


            //Console.WriteLine("请输入一句英语");
            //string str = Console.ReadLine();
            //char[] separator = {' '};
            //string[] result = str.Split(separator, StringSplitOptions.RemoveEmptyEntries);
            //for (int i = result.Length -1; i >= 0; i--) 
            //{
            //    if (i == 0)
            //    {
            //        Console.Write("{0}", result[i]);
            //    }
            //    else 
            //    {
            //        Console.Write("{0} ",result[i]);
            //    }
            //}
            //Console.ReadLine();


            //string test = "1234";
            //test = test.Replace()
            //Console.WriteLine(test);
            //Console.ReadLine();


            //char[] method = new char[] { '1', '3', '5' };
            //string str = "12345";
            //bool flag = true;
            //for (int i = 0; i < method.Length; i++) 
            //{
            //    if (str.Contains(method[i])) 
            //    {
            //        flag = false;
            //        break;
            //    }
            //}
            //if (flag == true)
            //{

            //}
            //else 
            //{
            
            //}


            //string str = "1234156";
            //int result = str.IndexOf('1',1);
            //Console.WriteLine(result);
            //Console.ReadLine();


            //Console.WriteLine("请输入您的邮箱地址");
            //string email = Console.ReadLine();
            //string[] mark = { "@" };
            //string[] result = email.Split(mark, StringSplitOptions.RemoveEmptyEntries);
            //Console.WriteLine("您的用户名为：{0}\n您的地址为：{1}",result[0],result[1]);
            //Console.ReadLine();


            //Console.WriteLine("请输入一段话，找到e的位置");
            //string str = Console.ReadLine();

            //if (str.Contains('e'))
            //{
            //    str = str.Replace('e', '*');
            //}
            //else 
            //{
            //    Console.WriteLine("该语句中不存在e");
            //}
            //Console.WriteLine(str);
            //Console.ReadLine();


            //string str = "122322341";
            //int result = str.IndexOf('3', 4);
            //Console.WriteLine(result);
            //Console.ReadLine();


            //string str = "qweseqwfrese";
            //int[] num = new int[99];
            //int j = 0;
            //bool flag = false;
            //for (int i = 0; i < str.Length; i++) 
            //{
            //    if (str.Contains('e') == false)
            //    {
            //        flag = true;
            //        break;
            //    }
            //    else 
            //    {
            //        flag = false;
            //        i = str.IndexOf('e', i);
            //        num[j++] = i;
            //    }
            //}
            //if (flag == true)
            //{
            //    Console.WriteLine("没有找到e");
            //}
            //else 
            //{
            //    for (int i = 0; i < num.Length; i++) 
            //    {
            //        if (num[i] == 0)
            //        {
            //            break;
            //        }
            //        else 
            //        {
            //            Console.Write("{0} ", num[i]);
            //        }
            //    }
            //}
            //Console.Write(" 为该语句中 e 的位置");
            //Console.ReadLine();


            //string str = "abcdee";
            //Console.WriteLine(str.Length);
            //int pos = 0;
            //do
            //{
            //    pos = str.IndexOf('e', pos) + 1;
            //    Console.WriteLine("e的位置为{0}", pos);
            //    if (pos >= str.Length) 
            //    {
            //        break;
            //    }
            //}
            //while (true);

            //Console.ReadLine();


            //string str = "abceeeeeee";
            //int pos = -1;
            //while (str.IndexOf('e',pos+1) != -1) 
            //{
            //    pos = str.IndexOf('e', pos + 1);
            //    Console.WriteLine("e的位置为{0}", pos+1);
            //}
            //Console.ReadLine();


            //string str = "abcfg";
            //for (int i = 0; i < str.Length; i++) 
            //{
            //    if (str.IndexOf('e', i) == -1) 
            //    {
            //        Console.WriteLine("没有e");
            //        break;
            //    }
            //    i = str.IndexOf('e', i);
            //    Console.WriteLine("e的位置为{0}",i+1);
            //}
            //Console.ReadLine();



            //string str = "Hello World!!";
            //string[] result = str.Split('!');
            //Console.ReadLine();


            //string str = "qweree";
            //for (int i = 0; i < str.Length; i++)
            //{
            //    if (str.Contains('e') == false)
            //    {
            //        Console.WriteLine("Empty");
            //        break;
            //    }
            //    else
            //    {
            //        i = str.IndexOf("e", i);
            //        Console.WriteLine("e的位置为{0}", i + 1);
            //    }
            //}
            //Console.ReadLine();


            string strA = "1234";
            string strB = "ABC";
            strA = strB;

            strA = "aaa";
            Console.WriteLine(strB);
            Console.ReadLine();



        }
        public void Test() 
        {

        }
    }
}
