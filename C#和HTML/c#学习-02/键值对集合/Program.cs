using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 键值对集合
{
    class Program
    {
        static void Main(string[] args)
        {
            //string str = "1一 2二 3三 4四 5五 6六 7七 8八 9九 0零";
            //Dictionary<char, char> dic = new Dictionary<char, char>();
            //string[] strs = str.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            //for (int i = 0; i < strs.Length; i++)
            //{
            //    char[] chars = strs[i].ToCharArray();
            //    dic.Add(chars[0], chars[1]);
            //}

            //Console.WriteLine("请输入一段数字");
            //string strNums = Console.ReadLine();
            //string strTel = "";
            //char[] charNums = strNums.ToCharArray();
            //for (int i = 0; i < charNums.Length; i++)
            //{
            //    if (dic.ContainsKey(charNums[i])) 
            //    {
            //        strTel += dic[charNums[i]];
            //    }
            //}
            //Console.WriteLine(strTel);
            //Console.ReadLine();


            Dictionary<char, int> dic = new Dictionary<char, int>();
            string str = "Welcome ,to ChinaWorld";
            string[] strChange = str.Split(new char[] { ' ', ',' }, StringSplitOptions.RemoveEmptyEntries);
            str = strChange[0] + strChange[1] + strChange[2];
            ////方法一：
            for (int i = 0; i < str.Length; i++)
            {
                if (dic.ContainsKey(char.ToLower(str[i]))||dic.ContainsKey(char.ToUpper(str[i])))
                {
                
                }
                else 
                {
                    dic.Add(str[i], 0);
                }
            }
            for (int i = 0; i < str.Length; i++)
            {
                if (dic.ContainsKey(char.ToUpper(str[i])))
                {
                    dic[char.ToUpper(str[i])]++;
                }
                else if (dic.ContainsKey(char.ToLower(str[i]))) 
                {
                    dic[char.ToLower(str[i])]++;
                }
            }
            foreach (KeyValuePair<char,int> item in dic)
            {
                Console.WriteLine("字母{0}，出现了{1}次",item.Key,item.Value);
            }
            Console.ReadLine();
            ////方法二：
            //for (int i = 0; i < str.Length; i++)
            //{
            //    if (!dic.ContainsKey(str[i]))
            //    {
            //        dic.Add(str[i], 1);
            //    }
            //    else 
            //    {
            //        dic[str[i]]++;
            //    }
            //}
            //Console.ReadLine();
        }
    }
}
