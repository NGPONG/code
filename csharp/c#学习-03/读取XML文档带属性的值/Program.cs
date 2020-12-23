using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace 读取XML文档带属性的值
{
    class Program
    {
        static void Main(string[] args)
        {
            //第一步：创建XML文档
            XmlDocument doc = new XmlDocument();

            //第二步：加载XML文档
            doc.Load(@"Order.xml");

            //第三步：通过SelectNodes能够获取我们所指定节点目录下的所有的该节点的集合
            XmlNodeList xnl = doc.SelectNodes("Order/Items/OrderItem");

            //循环输出节点集合的每个元素的属性的值
            foreach (XmlNode item in xnl)
            {
                Console.WriteLine(item.Attributes["Name"].Value);
            }
            Console.ReadLine();

        }
    }
}
