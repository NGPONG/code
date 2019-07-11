using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 字符串练习
{
    class Program
    {
        static void Main(string[] args)
        {
            //课上练习1：接收用户输入的字符串，将其中的字符以与输入相反的顺序输出。"abc"→"cba“.
            //string str = "abc";
            //string change = "";
            //for (int i = str.Length-1; i >= 0; i--)
            //{
            //    change += str[i];
            //}
            //Console.WriteLine(change);
            //Console.ReadLine();


            //课上练习2：接收用户输入的一句英文，将其中的单词以反序输出。      “I love you"→“I evol uoy"
            //string str = "I Love You";
            //string[] strs = str.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            //for (int i = 0; i < strs.Length/2; i++)
            //{
            //    string temp = "";
            //    temp = strs[i];
            //    strs[i] = strs[strs.Length - 1];
            //    strs[strs.Length - 1] = temp;
            //}
            //string strNew = string.Join(" ",strs);
            //Console.WriteLine(strNew);
            //Console.ReadLine();


            //课上练习3：”2012年12月21日”从日期字符串中把年月日分别取出来，打印到控制台
            //string str = "2018年2月15日";
            //string[] strs = str.Split(new char[] { '年', '月', '日' }, StringSplitOptions.RemoveEmptyEntries);
            //str = string.Join("-", strs);
            //Console.WriteLine(str);
            //Console.ReadLine();


            //课上练习4：把csv文件中的联系人姓名和电话显示出来。
            //string[] strFile = File.ReadAllLines(@"C:\Users\Administrator\Desktop\1.txt",Encoding.Default);
            //string[] strTel = new string[strFile.Length];

            //for (int i = 0; i < strFile.Length; i++)
            //{
            //    string[] strs = strFile[i].Split(new char[] { '"', ',', ';' }, StringSplitOptions.RemoveEmptyEntries);
            //    strTel[i] = "姓名：" + strs[0] + strs[1] + "\t" + "电话：" + strs[2];
            //}
            //File.WriteAllLines(@"C:\Users\Administrator\Desktop\Tel.txt", strTel);
            //Console.WriteLine("写入成功");
            //Console.ReadLine();


            //练习5：123-456---7---89-----123----2把类似的字符串中重复符号”-”去掉，既得到123-456-7-89-123-2
            //string str = "123-456---7---89-----123----2";
            //string[] strs = str.Split(new char[] { '-' }, StringSplitOptions.RemoveEmptyEntries);
            //str = string.Join("-", strs);
            //Console.WriteLine(str);
            //Console.ReadLine();


            //练习6：从文件路径中提取出文件名(包含后缀) 。比如从c:\aewqq\beqewq.txt中提取出b.txt这个文件名出来
            //string path = @"c:\aewqq\beqewq.txt";
            //int index = path.LastIndexOf("\\");
            //string str = path.Substring(index + 1);
            //Console.WriteLine(str);
            //Console.ReadLine();


            //练习7：“192.168.10.5[port=21,type=ftp]”，这个字符串表示IP地址为192.168.10.5的服务器的21端口提供的是ftp服务
            //其中如果“,type=ftp”部分被省略，则默认为http服务。

            //string str = "192.168.10.5[port=21,type=ftp]";
            //string ip = str.Substring(0, str.IndexOf('['));
            //string port = str.Substring(str.IndexOf('=') + 1, str.IndexOf(',') - (str.IndexOf('=')+1));
            //string type = "";
            //if (str.Contains("type=")) 
            //{
            //    type = str.Substring(str.LastIndexOf('=') + 1, (str.Length - 1) - (str.LastIndexOf('=') + 1));
            //}
            //else
            //{
            //    type = "http";
            //}

            //string result = "IP地址为" + ip + "的服务器的" + port + "端口提供的服务为" + type;
            //Console.WriteLine(result);
            //Console.ReadLine();


            //练习8：求员工工资文件中，员工的最高工资、最低工资、平均工资
            //string[] strFile = File.ReadAllLines(@"C:\Users\Administrator\Desktop\Salary.txt", Encoding.Default);
            //string[] strName = new string[strFile.Length];
            //string[] strSalary = new string[strFile.Length];

            //for (int i = 0; i < strFile.Length; i++)
            //{
            //    string[] strTemp = strFile[i].Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            //    strName[i] = strTemp[0];
            //    strSalary[i] = strTemp[1];
            //}

            //int max = int.Parse(strSalary[0]);
            //int maxIndex = 0;
            //int min = int.Parse(strSalary[0]);
            //int minIndex = 0;
            //int sum = 0;

            //for (int i = 0; i < strSalary.Length; i++)
            //{
            //    if (Convert.ToInt32(strSalary[i]) > max) 
            //    {
            //        max = int.Parse(strSalary[i]);
            //        maxIndex = i;
            //    }
            //    else if (int.Parse(strSalary[i]) < min)
            //    {
            //        min = int.Parse(strSalary[i]);
            //        minIndex = i;
            //    }
            //    sum += int.Parse(strSalary[i]);
            //}

            //Console.WriteLine("最高工资是：{0}，一个月有{1}元，最低工资是：{2}，一个月有{3}元，他们的平均工资为：{4}",strName[maxIndex], max, strName[minIndex], min, sum / strName.Length);
            //Console.ReadLine();


            //19. 有如下字符串：
            //     【"患者：“大夫，我咳嗽得很重。”     大夫：“你多大年记？”     患者：“七十五岁。”     大夫：“二十岁咳嗽吗”患者：“不咳嗽。”     大夫：“四十岁时咳嗽吗？”     患者：“也不咳嗽。”     大夫：“那现在不咳嗽，还要等到什么时咳嗽？”"】
            //       需求：请统计出该字符中“咳嗽”二字的出现次数，以及每次“咳嗽”出现的索引位置。

            //string str = "患者：“大夫，我咳嗽得很重。”     大夫：“你多大年记？”     患者：“七十五岁。”     大夫：“二十岁咳嗽吗”患者：“不咳嗽。”     大夫：“四十岁时咳嗽吗？”     患者：“也不咳嗽。”     大夫：“那现在不咳嗽，还要等到什么时咳嗽？”";
            //int index = 0;
            //List<int> list = new List<int>();
            //while (true)
            //{
            //    index = str.IndexOf("咳嗽", index);
            //    if (index == -1)
            //    {
            //        break;
            //    }
            //    else 
            //    {
            //        list.Add(index);
            //    }
            //    index+=2;
            //}
            //Console.WriteLine("出现了：{0}次，每次的索引位置为",list.Count);
            //foreach (var item in list)
            //{
            //    Console.WriteLine(item);
            //}

            //Console.ReadLine();


            //判断用户输入的是否是邮箱.
            //string str = "1917648573@qq.com";

            //if (str.Contains('@'))
            //{
            //    if (str.Contains(".com"))
            //    {
            //        Console.WriteLine("是邮箱");
            //    }
            //    else 
            //    {
            //        Console.WriteLine("不是邮箱");
            //    }
            //}
            //else 
            //{
            //    Console.WriteLine("不是邮箱");
            //}
            //Console.ReadLine();


            //{ "马龙", "迈克尔乔丹", "雷吉米勒", "蒂姆邓肯", "科比布莱恩特" },请输出最长的字符串。
            //string[] names = { "马龙", "迈克尔乔丹", "雷吉米勒", "蒂姆邓肯", "科比布莱恩特" };
            //int max = names[0].Length;
            //string maxName = names[0];
            //for (int i = 0; i < names.Length; i++)
            //{
            //    if (names[i].Length > max) 
            //    {
            //        max = names[i].Length;
            //        maxName = names[i];
            //    }
            //}
            //Console.WriteLine(maxName);
            //Console.ReadLine();

            //请将字符串数组{ "中国", "美国", "巴西", "澳大利亚", "加拿大" }中的内容反转。然后输出反转后的数组

            string[] countrys = { "中国", "美国", "巴西", "澳大利亚", "加拿大" };
            for (int i = 0; i < countrys.Length / 2; i++)
            {
                string temp = countrys[i];
                countrys[i] = countrys[countrys.Length - 1 - i];
                countrys[countrys.Length - 1 - i] = temp;
            }
            Console.ReadLine();
        }
    }
}
