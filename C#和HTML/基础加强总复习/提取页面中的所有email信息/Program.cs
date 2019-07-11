using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace 提取页面中的所有email信息
{
    class Program
    {
        static void Main(string[] args)
        {
            //创建WebClient的对象
            WebClient web = new WebClient();
            //通过DownloadData()函数，下载指定页面，返回字节数组
            //通过DownloadString()函数，下载指定页面，以GBK编码形式返回字符串
            byte[] buff = web.DownloadData(@"C:/Users/Administrator/Desktop/大家留下email交友吧_email_天涯部落.html");
            string html = Encoding.UTF8.GetString(buff);

            MatchCollection mcs = Regex.Matches(html, @"[a-zA-Z0-9]+@[a-zA-Z0-9]+(\.[a-zA-Z]+){1,}");
            foreach (Match item in mcs)
            {
                if (item.Success) 
                {
                    Console.WriteLine(item.Value);
                }
            }
            
            Console.ReadLine();
        }
    }
}
