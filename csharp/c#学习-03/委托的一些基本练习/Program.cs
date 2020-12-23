using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace 委托的一些基本练习
{
    //委托的声明
    //被委托所指向的方法的签名必须与声明委托的签名相同
    public delegate string DelGetStr(char cha);
    class Program
    {
        static void Main(string[] args)
        {
            string str = "ASASASAS";
            string str2 = "asdasdasdasd";
            string str3 = "我叫吴鹏";
            //DelGetStr del = strToLower;
            //del = strToUpper;
            //del = strSYH;
            //Console.WriteLine(ProcessStr(str, strToLower));
            //Console.WriteLine(ProcessStr(str2, strToUpper));
            //Console.WriteLine(ProcessStr(str3, strSYH));
            //Console.ReadLine();

            string strNew = ProcessStr(str, delegate(char cha)
            {
                return cha.ToString().ToLower();
            });
            Console.WriteLine(strNew);
            Console.ReadLine();
        }
        public static string ProcessStr(string str,DelGetStr del) 
        {
            char[] chars = str.ToCharArray();
            string strNew = null;
            for (int i = 0; i < chars.Length; i++)
            {
                strNew += del(chars[i]);
            }
            return strNew;
        }
        public static string strToUpper(char cha) 
        {
            string str = cha.ToString();
            return str.ToUpper();
        }

        public static string strToLower(char cha) 
        {
            string str = cha.ToString();
            return str.ToLower();
        }

        public static string strSYH(char cha) 
        {
            return "\"" + cha.ToString() + "\"";
        }
    }
}
