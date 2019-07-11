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
            MD5 md5 = MD5.Create();
            byte[] buff = md5.ComputeHash(Encoding.Default.GetBytes(str));

            StringBuilder sb = new StringBuilder();
            //循环ToString 解析出转换成md5的字节数组
            for (int i = 0; i < buff.Length; i++)
            {
                sb.Append(buff[i].ToString("x"));
            }
            Console.WriteLine(sb.ToString());
            Console.ReadLine();
        }
    }
}
