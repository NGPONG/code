using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace 提取页面中的所有图片
{
    class Program
    {
        static void Main(string[] args)
        {
            //创建WebClient对象
            WebClient web = new WebClient();
            byte[] buff = web.DownloadData(@"http://price.pcauto.com.cn/sg2734/image.html");
            string html = Encoding.Default.GetString(buff);

            MatchCollection mcs = Regex.Matches(html, @"<img.+?(?<url>http.+\.jpg).+>");

            int i = 1;
            foreach (Match item in mcs)
            {
                i++;
                if (item.Success) 
                {
                    Console.WriteLine(item.Groups["url"].Value);
                    web.DownloadFile(item.Groups["url"].Value, @"C:\Users\Administrator\Desktop\new\" + i + ".jpg");
                }
            }
            Console.WriteLine("下载成功!!");
            Console.ReadLine();
            
            
        }
    }
}
