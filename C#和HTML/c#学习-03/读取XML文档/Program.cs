using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace 读取XML文档
{
    class Program
    {
        static void Main(string[] args)
        {
            //第一步：创建新的XML文档的对象
            XmlDocument doc = new XmlDocument();

            //第二步：读取XML文档文件的内容，并自动把内容复制到我们新创建的XML文档的对象中
            doc.Load(@"books.xml");

            //第三步：获取XML文档对象的根节点
            XmlElement books = doc.DocumentElement;

            //第四部：获取根节点中的所有子节点
            XmlNodeList xnl = books.ChildNodes;

            foreach (XmlNode item in xnl)
            {
                Console.WriteLine(item.InnerText);
            }
            Console.ReadLine();
        }
    }
}
