using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 吴鹏面向对象04
{
    class Program
    {
        static void Main(string[] args)
        {
            //ArrayList list = new ArrayList();
            //Person per = new Person();
            //list.Add(1);
            //list.AddRange(new string[] { "a", "b", "c" });
            //list.Add(new Person());
            //list.AddRange(list);
            //for (int i = 0; i < list.Count; i++) 
            //{
            //    if (list[i] is Person)
            //    {
            //        ((Person)list[i]).PersonSayHello();
            //    }
            //    else 
            //    {
            //        Console.WriteLine(list[i]);
            //    }
            //}
            //    Console.ReadLine();

            //ArrayList list = new ArrayList();
            //list.Add(new Person());
            //((Person)list[0]).PersonSayHello();

            //ArrayList list = new ArrayList();
            //list.AddRange(new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 });
            //int sum = 0;
            //int max = (int)list[0];
            //int min = (int)list[0];
            //for (int i = 0; i < list.Count; i++)
            //{
            //    if ((int)list[i] > max) 
            //    {
            //        max = (int)list[i];
            //    }
            //    if ((int)list[i] < min) 
            //    {
            //        min = (int)list[i];
            //    }
            //    sum += (int)list[i];
            //}
            //int average = sum / list.Count;
            //Console.WriteLine("总和为{0}", sum);
            //Console.WriteLine("平均数为{0}", average);
            //Console.WriteLine("最大值为{0}",max);
            //Console.WriteLine("最小值为{0}",min);
            //Console.ReadLine();


            //ArrayList list = new ArrayList();
            //Random r = new Random();
            //for (int i = 0; i < 10; i++) 
            //{
            //    int rNumber = r.Next(0,10);
            //    if (list.Contains(rNumber))
            //    {
            //        do
            //        {
            //            rNumber = r.Next(0, 10);
            //        }
            //        while (list.Contains(rNumber));
            //        list.Add(rNumber);
            //    }
            //    else 
            //    {
            //        list.Add(rNumber);
            //    }
            //}
            //for (int i = 0; i < list.Count; i++) 
            //{
            //    Console.WriteLine(list[i]);
            //}
            //    Console.ReadLine();


            //Hashtable ht = new Hashtable();
            //ht.Add(1, "a");
            //ht.Add(2, true);
            //ht.Add(3, '男');
            //ht[true] = new Person();
            //Console.WriteLine(ht[1]);
            //foreach (var item in ht.Keys) 
            //{
            //    if (ht[item] is Person)
            //    {
            //        ((Person)ht[item]).PersonSayHello();
            //    }
            //    else 
            //    {
            //        Console.WriteLine(ht[item]);
            //    }
            //}

            //    const string xiaoxie = "abcdefghijklmnopqrstuvwxyz";   //大小写的转换用到了键值对集合
            //    const string daxie = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

            //    Console.WriteLine("请输入一段英语");
            //    string str = Console.ReadLine();
            //    Hashtable ht = new Hashtable();
            //    for (int i = 0; i < xiaoxie.Length; i++) 
            //    {
            //        ht.Add(xiaoxie[i], daxie[i]);
            //    }

            //    for (int i = 0; i < str.Length; i++) 
            //    {
            //        if (ht.Contains(str[i]))
            //        {
            //            Console.Write(ht[str[i]]);
            //        }
            //        else 
            //        {
            //            Console.Write(str[i]);
            //        }
            //    }
            //        Console.ReadLine();
            //


            //int number = str.LastIndexOf("\\");//获取文件名
            //string strNew = str.Substring(number + 1);
            //Console.WriteLine(strNew);
            //Console.ReadLine();

            //int number = str.LastIndexOf("\\");//获取文件名不包含拓展名
            //string strNew = str.Substring(number + 1);
            //number = strNew.IndexOf(".");
            //strNew = strNew.Substring(0, number);
            //Console.WriteLine(strNew);
            //Console.ReadLine();

            //int num = str.LastIndexOf(".");//获取文件拓展名
            //string strNew = str.Substring(num + 1);
            //Console.WriteLine(strNew);
            //Console.ReadLine();

            //int num = str.LastIndexOf("\\");//获取该文件的文件夹名字
            //string strNew = str.Substring(0, num + 1);
            //Console.WriteLine(strNew);
            //Console.ReadLine();

            //Console.WriteLine(str + @"\b.txt");//连接两个字符串作为路径
            //Console.ReadLine();
            //string str = @"C:\Users\Administrator\Desktop\bookName.txt";
            ////********************以下为Path类中常用的方法********************
            ////获取该文件名
            //Console.WriteLine(Path.GetFileName(str)); 
            ////获取该文件名，不包含拓展名
            //Console.WriteLine(Path.GetFileNameWithoutExtension(str));
            ////获取该文件的拓展名
            //Console.WriteLine(Path.GetExtension(str));
            ////获取该文件所在的文件夹的名称
            //Console.WriteLine(Path.GetDirectoryName(str));
            ////获取该文件的全路径
            //Console.WriteLine(Path.GetFullPath(str));
            ////把两个字符串连接成一个路径
            //Console.WriteLine(Path.Combine(str, "abc"));

            //string str = @"C:\Users\Administrator\Desktop\bookName.txt";

            //File.Create(@"C:\Users\Administrator\Desktop\text.txt"); //创建一个文件
            //Console.WriteLine("创建成功");

            //File.Delete(@"C:\Users\Administrator\Desktop\a.txt");//删除一个文件
            //Console.WriteLine("删除成功");

            //File.Copy(@"C:\Users\Administrator\Desktop\text.txt", @"C:\Users\Administrator\Desktop\newText.txt");//赋值一个文件
            //Console.WriteLine("复制成功");                                                                                                                       //前面是需要复制的文件路径和名字
            //Console.ReadLine();                                                                                                                                       //后面是复制成功的文件路径和名字

            //ArrayList list = new ArrayList();
            //list.Add(1);
            //Console.WriteLine(list[0]);
            //Console.ReadKey();

            //string str = Encoding.GetEncoding("GB2312").GetString(File.ReadAllBytes(@"C:\Users\Administrator\Desktop\bookName.txt"));
            //Console.WriteLine(str);
            //Console.ReadLine();
            //File.WriteAllBytes(@"C:\Users\Administrator\Desktop\text.txt", Encoding.UTF8.GetBytes("123123"));

            //Encoding.ut
            //Console.ReadLine();
            //Hashtable ht = new Hashtable();

            //string str = Encoding.Default.GetString(File.ReadAllBytes(@"C:\Users\Administrator\Desktop\bookName.txt"));
            //string[] str = File.ReadAllLines(@"C:\Users\Administrator\Desktop\bookName.txt", Encoding.Default);
            //string str = File.ReadAllText(@"C:\Users\Administrator\Desktop\bookName.txt", Encoding.Default);

            //File.WriteAllLines(@"C:\Users\Administrator\Desktop\new.txt", new string[] { "你好！" });
            //Console.WriteLine("ok");
            //Console.ReadLine();

            // string[] str = File.ReadAllLines(@"C:\Users\Administrator\Desktop\new.txt", Encoding.Default);
            // foreach (var item in str) 
            // {
            //     Console.WriteLine(item);
            // }
            // str[0] = "修改啦！";
            // foreach (var item in str) 
            // {
            //     Console.WriteLine(item);
            // }
            // Console.ReadLine();
            //File.ap

            //File.WriteAllBytes(@"C:\Users\Administrator\Desktop\new.txt", Encoding.Default.GetBytes("12345\nqwepojq\nasdq"));
            //Console.WriteLine("创建完成");
            //string str = File.ReadAllText(@"C:\Users\Administrator\Desktop\new.txt",Encoding.Default);
            //Console.WriteLine(str);
            //Console.ReadLine();


            //int i = 1;
            //object ob = i;      //装箱：值类型转化为引用类型
            //int n = (int)ob;    //拆箱：引用类型转化为值类型


            ////ArrayList list = new ArrayList();
            //Random r = new Random();
            //for (int i = 0; i < 10; i++) 
            //{
            //    int num = r.Next(0, 10);
            //    if (list.Contains(num))
            //    {
            //        i--;
            //    }
            //    else 
            //    {
            //        list.Add(num);
            //    }
            //}

            //foreach (var item in list) 
            //{
            //    Console.WriteLine(item);
            //}
            //Console.ReadLine();


            //List<int> list = new List<int>();
            //list.Add(1);
            //Console.WriteLine(list[0]);
            //Console.ReadLine();


            //Dictionary<int, string> dic = new Dictionary<int, string>();
            //dic.Add(1, "a");
            //dic.Add(2, "b");
            //dic.Add(3, "c");
            //dic.Add(4, "d");
            //foreach (KeyValuePair<int, string> item in dic) 
            //{
            //    Console.WriteLine("键：{0}-------值：{1}",item.Key,item.Value);
            //}
            //Console.ReadLine();

            //int[] num = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 };
            //List<int> list = new List<int>();
            //List<int> listA = new List<int>();
            //for (int i = 0; i < num.Length; i++) 
            //{
            //    if (num[i] % 2 == 0)
            //    {
            //        list.Add(num[i]);
            //    }
            //    else 
            //    {
            //        listA.Add(num[i]);
            //    }
            //}
            //list.AddRange(listA);
            //foreach (var item in list) 
            //{
            //    Console.WriteLine(item);
            //}
            //Console.ReadLine();

            //Console.WriteLine("请输入一个字符串");
            //string str = Console.ReadLine();
            //List<char> list = new List<char>();
            //list.AddRange(str);

            //char[] chs = new char[str.Length];
            //int i = 0;
            //foreach (var item in list) 
            //{
            //    chs[i] = item;
            //    i++;
            //}
            //Console.ReadLine();


            //string str = "Welcome to China";
            //string strNew = str.ToUpper();
            //List<char> list = new List<char>();
            //list.AddRange(strNew);
            //int[] num = new int[list.Count];
            ////int j = 0;
            ////foreach (var item in list) 
            ////{
            //for (int j = 0; j < list.Count; j++)
            //{
            //    for (int i = 0; i < list.Count; i++)
            //    {
            //        if (list[j] == list[i])
            //        {
            //            num[j] += 1;
            //        }
            //    }
            //}
            ////    j++;
            ////}
            //int n = 0;
            //Dictionary<char, int> dic = new Dictionary<char, int>();
            //foreach (var item in strNew)
            //{
            //    if (dic.ContainsKey(item))
            //    {
            //        n++;
            //        continue;
            //    }
            //    else if (item == ' ')
            //    {
            //        n++;
            //        continue;
            //    }
            //    else
            //    {
            //        dic.Add(item, num[n]);
            //    }
            //    n++;
            //}
            //foreach (KeyValuePair<char, int> kv in dic)
            //{
            //    Console.WriteLine("{0}----{1}次", kv.Key, kv.Value);
            //}
            //Console.ReadLine();

            //string str = "Welcome to China";
            //string strNew = str.ToLower();
            //Dictionary<char, int> dic = new Dictionary<char, int>();
            //for (int i = 0; i < strNew.Length; i++)
            //{
            //    if (strNew[i] == ' ')
            //    {
            //        continue;
            //    }
            //    if (!dic.ContainsKey(strNew[i]))
            //    {
            //        dic.Add(strNew[i], 1);
            //    }
            //    else
            //    {
            //        dic[strNew[i]]++;
            //    }
            //}
            //Console.WriteLine("请输入你想搜索的值，只能输入1个字符，不能是数字，只能是英文");
            //string strSerach = Console.ReadLine();
            //if (strSerach.Length > 1) 
            //{
            //    do
            //    {
            //        Console.WriteLine("输入有误，请重新输入");
            //        strSerach = Console.ReadLine();
            //    } 
            //    while (strSerach.Length >1);
            //}
            //else if (strSerach == null || (!dic.ContainsKey(((strSerach.ToLower()).ToCharArray())[0])))
            //{
            //    do//(!dic.ContainsKey(((strSerach.ToLower()).ToCharArray())[0])) || strSerach == null
            //    {
            //        Console.WriteLine("输入的字符不包含，请重新输入");
            //        strSerach = Console.ReadLine();
            //    }
            //    while (strSerach == null || (!dic.ContainsKey(((strSerach.ToLower()).ToCharArray())[0])));
            //}
            //else  
            //{
            //    Console.WriteLine("键：{0}-----值：{1}",strSerach,dic[((strSerach.ToLower()).ToCharArray())[0]]);
            //}
            //Console.ReadLine();

            //File用法
            //File.WriteAllBytes(@"C:\Users\Administrator\Desktop\new.txt", Encoding.Default.GetBytes("新的文件！！！"));
            //Console.WriteLine("创建成功！");
            //string str = Encoding.Default.GetString(File.ReadAllBytes(@"C:\Users\Administrator\Desktop\new.txt"));
            //Console.WriteLine(str);

            //File.WriteAllLines(@"C:\Users\Administrator\Desktop\new.txt", new string[] {"看我有没有把你覆盖掉"});
            //File.AppendAllLines(@"C:\Users\Administrator\Desktop\new.txt",);
            //Console.WriteLine("创建成功!");
            //Console.ReadLine();

            //File.Delete(@"C:\Users\Administrator\Desktop\new.txt");
            //Console.ReadLine();

            //FileStream fileRead = new FileStream(@"C:\Users\Administrator\Desktop\new.txt", FileMode.OpenOrCreate, FileAccess.Read);
            //byte[] byt = new byte[1024 * 1024 * 5];                     //每次读取的大小
            //int num = fileRead.Read(byt,0,byt.Length);               //获得读取的byte并返回成功读取到的字节
            //string str = Encoding.Default.GetString(byt,0,num); //把成功读取到的字节转化为字符串
            //Console.WriteLine(str);

            //FileStream fileWrite = new FileStream(@"C:\Users\Administrator\Desktop\new.txt", FileMode.Create, FileAccess.Write);
            //byte[] byt = Encoding.Default.GetBytes("最新的文本文件！");
            //fileWrite.Write(byt, 0, byt.Length);
            //fileWrite.Close();
            //fileWrite.Dispose();
            //Console.WriteLine("is ok");

            //using (FileStream fileWriteRead = new FileStream(@"C:\Users\Administrator\Desktop\new.txt", FileMode.Append, FileAccess.Write)) 
            //{
            //    byte[] byt = Encoding.Default.GetBytes("真真正正的最后一次了！！！！");
            //    fileWriteRead.Write(byt, 0, byt.Length);
            //    Console.WriteLine("创建成功！不用垃圾回收器了！");
            //}

            //using (FileStream fileRead = new FileStream(@"C:\Users\Administrator\Desktop\new.txt", FileMode.OpenOrCreate, FileAccess.Read)) 
            //{
            //    byte[] byt = new byte[1024 * 1024 * 5];
            //    int i = fileRead.Read(byt, 0, byt.Length);
            //    string str = Encoding.Default.GetString(byt, 0, i);
            //    Console.WriteLine("读取成功！");
            //    Console.ReadLine();
            //    Console.WriteLine(str);
            //}


            //string str = "Hello,World!";
            //Dictionary<char,int> dic = new Dictionary<char,int>();
            //for (int i = 0; i < str.Length; i++) 
            //{
            //    if (str[i] == ',' || str[i] == '!') 
            //    {
            //        continue;
            //    }
            //    if (!dic.ContainsKey(str[i]))
            //    {
            //        dic.Add(str[i], 1);
            //    }
            //    else 
            //    {
            //        dic[str[i]]++;
            //    }
            //}

            //foreach (KeyValuePair<char,int> item in dic) 
            //{
            //    Console.WriteLine("{0}----{1}",item.Key,item.Value);
            //}

            //    Console.ReadLine();

            //using (FileStream fileReadWrite = new FileStream(@"C:\Users\Administrator\Desktop\Text.avi", FileMode.OpenOrCreate, FileAccess.ReadWrite)) 
            //{


            //}

            //string source = @"C:\Users\Administrator\Desktop\Text.avi";
            //string target = @"C:\Users\Administrator\Desktop\Neww.avi";
            //copyMethod(source, target);
            //Console.WriteLine("复制成功！");
            //Console.ReadLine();


            //using (StreamReader sr = new StreamReader(@"C:\Users\Administrator\Desktop\bookName.txt",Encoding.Default)) 
            //{
            //    while (!sr.EndOfStream)  //判断是否读取到最后一行
            //    {                                      //因为默认只会读取一行，所以要写个循环
            //        Console.WriteLine(sr.ReadLine());
            //    }
            //}
            //Console.ReadLine();

            //using (StreamWriter sw = new StreamWriter(@"C:\Users\Administrator\Desktop\New.txt"))
            //{
            //    sw.Write("123123123");                                                                   //追加文本
            //}
            //Console.WriteLine("OK");
            //Console.ReadLine();

            //using (StreamWriter swNew = new StreamWriter(@"C:\Users\Administrator\Desktop\New.txt", true))
            //{                                                                                                           
            //    swNew.Write("追加的！");                                                                //不覆盖文本，在后面追加文本
            //}
            //Console.WriteLine("追加文本完成！");
            //Console.ReadLine();


            string source = @"C:\Users\Administrator\Desktop\01基础知识.avi";
            string target = @"C:\Users\Administrator\Desktop\newMovie.avi";

            using (FileStream fsRead = new FileStream(source, FileMode.Open, FileAccess.Read))
            {
                using (FileStream fsWrite = new FileStream(target, FileMode.Create, FileAccess.Write))
                {
                    byte[] byt = new byte[1024 * 1024 * 3];
                    do
                    {
                        int i = fsRead.Read(byt, 0, byt.Length);
                        if (i == 0)
                        {
                            break;
                        }
                        fsWrite.Write(byt, 0, i);
                    } while (true);
                }
            }
            Console.WriteLine("复制成功！");
            Console.ReadLine();

        }

        public static void copyMethod(string source, string target) //source 源文件目录  target目标文件目录
        {
            using (FileStream fsRead = new FileStream(source, FileMode.Open, FileAccess.Read))  //完成文件复制的方法
            {
                using (FileStream fsWrite = new FileStream(target, FileMode.Create, FileAccess.Write))
                {
                    byte[] byt = new byte[1024 * 1024 * 5];

                    do
                    {
                        int i = fsRead.Read(byt, 0, byt.Length);
                        if (i == 0) //i=0时 就没有字节可以读取，代表读取完毕 退出循环
                        {
                            break;
                        }
                        else
                        {
                            fsWrite.Write(byt, 0, i);
                        }
                    } while (true);
                }
            }
        }


    }
    public class Person
    {
        public void PersonSayHello()
        {
            Console.WriteLine("人类打招呼！");
        }
    }
}