using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 配置文件
{
    class Program
    {
        static void Main(string[] args)
        {
            // 获取配置文件中的应用程序配置信息节点的数据
            string value = ConfigurationManager.AppSettings["myName"];

            Console.WriteLine(value);

            //取AppSettings节点下 Key的值为SqlStr的value的值
            Console.WriteLine(ConfigurationManager.AppSettings["SqlStr"]);

            //取ConnectionStrings节点下 name的值为SqlStr2的connectionstring的值
            Console.WriteLine(ConfigurationManager.ConnectionStrings["SqlStr2"].ConnectionString);
            
            Console.ReadLine();
        }
    }
}
