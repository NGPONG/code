using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 字符串练习1
{
    class Program
    {
        static void Main(string[] args)
        {
            ////1.反序输出字符串： abc-cba
            //string str = "abc";
            //char[] chars = str.ToCharArray();

            ////数组里的元素反转的公式
            //for (int i = 0; i < chars.Length / 2; i++)
            //{
            //    char temp = chars[i];
            //    chars[i] = chars[chars.Length - 1 - i];
            //    chars[chars.Length - 1 - i] = temp;
            //}
            //str = new string(chars);
            //Console.WriteLine(str);
            //Console.ReadLine();


            //2. 将单词反序输出： I love you-I evol uoy
            //string str = "i love you";
            //string[] strArrary = str.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            //List<string> list = new List<string>();

            //for (int i = 0; i < strArrary.Length; i++)
            //{
            //    char[] charStr = strArrary[i].ToCharArray();
            //    string strNew = "";
            //    for (int j = charStr.Length-1; j >=0; j--)
            //    {
            //        strNew += charStr[j];
            //    }
            //    list.Add(strNew);
            //}
            //Console.WriteLine(string.Join(" ", list.ToArray()));
            //Console.ReadLine();

            //3. 2018年2月3日-2018 2 3
            //string str = "2018年2月3日";
            //str = str.Replace("年"," ");
            //str = str.Replace("月", " ");
            //str = str.Replace("日", " ");
            //Console.WriteLine(str);
            //Console.ReadLine();

            //4. 
            //string[] lines = File.ReadAllLines(@"C:\Users\Administrator\Desktop\tel.txt", Encoding.Default);
            //string[] strs = new string[lines.Length];
            //for (int i = 0; i < lines.Length; i++)
            //{
            //    string str = "";
            //    string[] strArrary = lines[i].Split(new char[] { ',', '"' }, StringSplitOptions.RemoveEmptyEntries);
            //    for (int j = 0; j < strArrary.Length; j++)
            //    {
            //        str += strArrary[j];
            //    }
            //    strs[i] = str;
            //}
            //string[] strNew = new string[strs.Length];
            //for (int i = 0; i < strs.Length; i++)
            //{
            //    strNew[i] += ("姓名：" + strs[i].Substring(0, 2) + "\t" + "电话：" + strs[i].Substring(2));
            //}

            //File.WriteAllLines(@"C:\Users\Administrator\Desktop\new.txt", strNew);
            //Console.WriteLine("写入成功！");
            //Console.ReadLine();
        }
    }
}
