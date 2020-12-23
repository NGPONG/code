using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace MD5加密
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = "pengqi1997428";
            string md5 = GetMD5(str);
            Console.WriteLine(md5);
            Console.ReadLine();
        }
        public static string GetMD5(string str) 
        {
            //创建MD5类的对象
            MD5 md5 = MD5.Create();
            //需转换的字符串转换成字节数组
            byte[] buffer = Encoding.Default.GetBytes(str);
            //字节数组转换成MD5并返回字节数组
            byte[] md5buffer = md5.ComputeHash(buffer);
            str = "";
            //通过循环把字节数组中的每个元素转换成字符串
            for (int i = 0; i < md5buffer.Length; i++)
            {
                str += md5buffer[i].ToString("x");
            }
            return str;
        }
    }
}
