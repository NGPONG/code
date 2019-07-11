using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace 删除XML文档中的节点
{
    class Program
    {
        static void Main(string[] args)
        {
            //第一步：创建XML文档的对象
            XmlDocument doc = new XmlDocument();

            //第二步：载入XML文档内容
            doc.Load("books.xml");

            //第三步：通过SelectSingleNode找到指定的节点 
            //              [ ]为精确查找
            XmlNode xn = doc.SelectSingleNode("Books/Book2/Name[@Count ='100000']");

            //第四步：通过该节点的对象调用RemoveAll的方法来删除该节点的内容
            xn.RemoveAll();

            doc.Save("New.xml");
            Console.ReadLine();
        }
    }
}
