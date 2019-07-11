using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace 改变XML文档内容中节点属性的值
{
    class Program
    {
        static void Main(string[] args)
        {
            //第一步：创建XML文档的对象
            XmlDocument doc = new XmlDocument();

            //第二步：读取XML文档内容
            doc.Load("books.xml");

            //第三步：通过SelectSingleNode能够获取我们所制定目录下的某个节点
            XmlNode xn = doc.SelectSingleNode("Books/Book2/Name[@Count='100000']");

            //第四步：我们给该节点的Attributes的属性进行重新赋值
            xn.Attributes["Count"].Value = "被改变了啦！";
            xn.Attributes["Narture"].Value = "我也是哟！";

            doc.Save("books.xml");
        }
    }
}
