using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace 提取页面中的所有招聘信息
{
    class Program:IEnumerable<string>
    {
        static void Main(string[] args)
        {
            WebClient web = new WebClient();
            byte[] buff = web.DownloadData(@"C:/Users/Administrator/Desktop/北京婚礼策划招聘_北京婚礼策划师招聘_北京招聘婚礼策划师助理-北京58同城.html");
            string html = Encoding.UTF8.GetString(buff);

            string regex = @"<a\shref=.+\starget=.+\sclass=""t""\s_t=""jingpin"">(?<information>.{1,})</a>";

            MatchCollection mcs = Regex.Matches(html, regex);

            foreach (Match item in mcs)
            {
                if (item.Success) 
                {
                    Console.WriteLine(item.Groups["information"]);
                }
            }
            Console.ReadLine();

        }

        public IEnumerator<string> GetEnumerator()
        {
            throw new NotImplementedException();
        }

        System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
        {
            throw new NotImplementedException();
        }
    }
}
