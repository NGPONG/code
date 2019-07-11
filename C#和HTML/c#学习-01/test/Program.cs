
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            //Student wupeng = new Student { Age = 18, Name = "吴鹏",Sex = '男'};
            //wupeng.SayHello();
            //wupeng.SayHI();
            //Teacher sukun = new Teacher { Age = 36, Sex = '女', Name = "苏坤", Worktime = 10 };
            //sukun.SayHello();
            //sukun.SayHI();
            //Console.ReadLine();

            //string str = null;
              
            //for (int i = 0; i < 1000000; i++) 
            //{
            //    str += i;
            //}
            //Console.WriteLine(str);
            //Console.ReadLine();

            //Console.WriteLine("请学员一输入喜欢的课程");
            //string str1 = Console.ReadLine();
            //Console.WriteLine("请学员二输入喜欢的课程");
            //string strB = Console.ReadLine();


            //if (str1.Equals(strB, StringComparison.OrdinalIgnoreCase))
            //{
            //    Console.WriteLine("你们喜欢的课程一样");
            //}
            //else 
            //{
            //    Console.WriteLine("你们喜欢的课程不一样");
            //}
            //Console.ReadLine();


            //string str = "      12   31           ";
            //char[] chs = {' ','1',' ','2','4'};
            //str = str.Trim();   //去掉字符串中前面和后面的空格，不包含中间的 也就是12 和 31中间的空格不去
            ////str = str.TrimStart();//去掉字符串中前面的空格，不包含中间的，也就是12 和31中间的空格不去
            ////str = str.TrimEnd();//去掉字符串后面的空格，不包含中间的，也就是12和31中间的空格不去
            //Console.WriteLine(str);
            //Console.ReadLine();


            //string str = "";
            //if (string.IsNullOrEmpty(str))
            //{
            //    Console.WriteLine("该字符串为null或者Empty");
            //}
            //else
            //{
            //    Console.WriteLine("里面有东西");
            //}
            //Console.ReadLine();


            //string[] strArry = { "张三", "李四", "王五", "赵六", "田七" };
            //string str = string.Join("|", strArry);
            //Console.WriteLine(str);
            //Console.ReadLine();


            //string path = @"C:\Users\Administrator\Desktop\bookName.txt";   ////第四题
            //string[] contents = File.ReadAllLines(path);
            //string contentstr = string.Join("|", contents);
            //string[] contentsArry = contentstr.Split(new char[] { ' ', '|' }, StringSplitOptions.RemoveEmptyEntries);

            //for (int i = 0; i < contentsArry.Length; i++)
            //{
            //    if (contentsArry[i].Length > 10)
            //    {
            //        contentsArry[i] = contentsArry[i].Substring(0, 8) + "……";
            //    }
            //}

            //int j = 1;
            //int n = 0;
            //string[] result = new string[contentsArry.Length / 2];
            //for (int i = 0; i < contentsArry.Length; i += 2)
            //{
            //    result[n] = string.Join("|", contentsArry[i], contentsArry[j]);
            //    j += 2;
            //    n++;
            //}

            //for (int i = 0; i < result.Length; i++)
            //{
            //    Console.WriteLine(result[i]);
            //}

            //Console.ReadLine();


            //string path = @"C:\Users\Administrator\Desktop\bookName.txt";   ////第四题
            //string[] contents = File.ReadAllLines(path);
            //for (int i = 0; i < contents.Length; i++)
            //{
            //    string[] str = contents[i].Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            //    str[0] = str[0].Length > 10 ? str[0].Substring(0, 8)+"***" : str[0];
            //    Console.WriteLine(string.Join("|", str));
            //}
            //Console.ReadLine();


            //string str = "abc";             //第一题
            //for (int i = str.Length - 1; i >= 0; i--) 
            //{
            //    Console.Write(str[i]);
            //}
            //Console.ReadLine();


            //string str = "Hello c sharp"; //第二题
            //char[] strArry = new char[str.Length];
            //int j = 0;
            //for (int i = str.Length - 1; i >= 0;i-- )
            //{
            //    strArry[j] = str[i];
            //    j++;
            //}

            //for (int i = 0; i < strArry.Length; i++) 
            //{
            //    Console.Write(strArry[i]);
            //}
            //Console.ReadLine(); 


            //string str = "pengqi1997428@outlook.com"; //第三题
            //string[] strArry = str.Split(new string[] { "@" }, StringSplitOptions.RemoveEmptyEntries);
            //Console.WriteLine("用户名为：{0}\n域名为：{1}",strArry[0],strArry[1]);
            //Console.ReadLine();

            //string str = "eqwerswreseeqwreese"; //19  18  ////第五题
            //int[] num = new int[str.Length];//18  17
            //for (int i = 0; i < str.Length; i++) 
            //{
            //    i = str.IndexOf('e', i);
            //    num[i] = i + 1;
            //}
            //Console.Write("e的位置为：");
            //for (int i = 0; i < num.Length; i++) 
            //{
            //    if (num[i] != 0) 
            //    {
            //        Console.Write("{0}  ",num[i]);
            //    }
            //}
            //Console.WriteLine();
            //Console.ReadLine();


            //string str = "老牛很邪恶"; //第六题
            //if (str.Contains("邪恶"))
            //{
            //    str = str.Replace("邪恶", "**");
            //    Console.WriteLine(str);
            //}
            //else 
            //{
            //    Console.WriteLine("正常输出");
            //}
            //Console.ReadLine();


            //string str = "{“诸葛亮”、“鸟叔”、“卡卡西”、“卡哇伊”}";  //第七题
            //Console.WriteLine("原来的语句为：{0}",str);
            //string[] strArry = str.Split(new string[] { "”","“", "{", "、","}" }, StringSplitOptions.RemoveEmptyEntries);
            //str = string.Join("|", strArry);
            //Console.WriteLine("修改后的语句：{0}",str);
            //strArry = str.Split('|');
            //str = string.Join(" ", strArry);
            //Console.WriteLine("再次修改后的语句为：{0}",str);
            //Console.ReadLine();

            //Student wupeng = new Student("吴鹏",21,123);
            //wupeng.SayHello();
            //wupeng.Study();
            //Console.ReadLine();

            //Student wupeng = new Student { ID = 123 };
            //Console.ReadLine();


            List<int> list = new List<int>();
            list.Add(1);
            list.Add(2);
            list.Add(3);
            Console.ReadLine();
            list.RemoveAt(0);
            Console.ReadLine();

        }

        public class Person 
        {
            private string _name;
            public string Name 
            {
                get { return _name; }
                set { _name = value; }
            }
            private int _age;
            public int Age 
            {
                get { return _age; }
                set { _age = value; }
            }

            public  void SayHello()
            {
                Console.WriteLine("我叫{0}",Name);
            }
            public Person() 
            {
            
            }
            
        }
        public class Student : Person
        {
            private int _id;
            public int ID 
            {
                get { return _id; }
                set { _id = value; }
            }
            public void Study() 
            {
                Console.WriteLine("{0}在学习，我{1}岁了,我的id为{2}",Name,this.Age,this._id);
            }


        }


    }
}
