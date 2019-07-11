using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace 正则表达式
{
    class Program
    {
        static void Main(string[] args)
        {
            //string regex = @"(\w+)@(\w+)(\.\w+){1,2}";
            //MatchCollection mc = Regex.Matches("pengqi1997428@qq.com", regex);

            //foreach (Match item in mc)
            //{
            //    Console.WriteLine(item.Value);
            //}

            //Console.ReadLine();

            //string regex = @"\d{1,4}";
            //MatchCollection mcs = Regex.Matches("今天是2018年2月25日", regex);
            //foreach (Match item in mcs)
            //{
            //    Console.WriteLine(item.Value);
            //}
            //Console.ReadLine();



            ////练习一
            ////C:\Users\Administrator\Desktop\源码asdasd，提取出文件名

            //string path = @"C:\Users\Administrator\Desktop\源码asdasd";
            //string regex = @"(?<path>.+\\)(?<file>.+)";
            //Match mc = Regex.Match(path, regex);
            //Console.WriteLine("文件名为：{0}",mc.Groups["file"].Value);
            //Console.ReadLine();


            ////练习二
            ////June          26,          1951，提取出月份

            //string regex = @"(?<month>\w+)\s+(?<day>\d{1,2}),\s+(?<year>\d{4})";
            //string date = "June          26,          1951";
            //Match mc = Regex.Match(date, regex);
            //Console.WriteLine(mc.Groups["month"]);
            //Console.ReadLine();

            ////练习三
            ////pengqi19967428，提取域名和用户名
            //string regex = @"(?<name>\w+)@(?<address>\w+(\.\w+){1,2})";
            //string email = @"pengqi19967428@qq.com.cn";
            //Match mc = Regex.Match(email, regex);
            //if (mc.Success) 
            //{
            //    Console.WriteLine("用户名为{0}，域名为{1}", mc.Groups["name"], mc.Groups["address"]);
            //}

            //Console.ReadLine();

            //练习四
            //192.168.10.5[port=21,type=ftp]
            //192.168.10.5[port=21]

            //string regex = @"(?<ip>\d{3}(\.\d{1,3}){3})\[(?<port>\w+=\d{1,5})(,(?<type>\w+=\w{3}))?\]";
            //string address = @"192.168.10.5[port=21]";
            //Match mc = Regex.Match(address, regex);
            //if (mc.Groups["type"].Value == string.Empty)
            //{
            //    Console.WriteLine(mc.Groups["ip"]);
            //}
            //Console.ReadLine();
        }
    }
}
