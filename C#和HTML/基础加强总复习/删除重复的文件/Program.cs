using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 删除重复的文件
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] files = Directory.GetFiles(@"E:\CloudMusic");
            List<string> filesName = new List<string>();

            for (int i = 0; i < files.Length; i++)
            {
                filesName.Add(Path.GetFileNameWithoutExtension(files[i]));
            }

            for (int i = 0; i < filesName.Count; i++)
            {
                if (!filesName[i].Contains(" (3)")) 
                {
                    continue;
                }

                string strFile = filesName[i].Substring(0, filesName[i].Length - 4);

                for (int j = 0; j < filesName.Count; j++)
                {
                    if (filesName[j] == strFile) 
                    {
                        File.Delete(files[i]);
                    }
                }
            }

            Console.WriteLine("删除成功");
            Console.ReadLine();
        }
    }
}
