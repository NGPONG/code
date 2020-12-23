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
            //1.
            string str = "1壹-2贰-3叁--4肆--5伍-6陆--7柒--8捌--9玖--0零";
            string[] strs = str.Split(new char[] { '-' }, StringSplitOptions.RemoveEmptyEntries);
            Dictionary<string, string> dic = new Dictionary<string, string>();

            for (int i = 0; i < strs.Length; i++)
            {
                dic.Add(strs[i][0].ToString(), strs[i][1].ToString());
            }

            Console.WriteLine("请输入一段数字");
            string result = string.Empty;
            string strNum = Console.ReadLine();
            for (int i = 0; i < strNum.Length; i++)
            {
                result += dic[strNum[i].ToString()];
            }

            Console.WriteLine(result);
            Console.ReadLine();
        }
    }
}
