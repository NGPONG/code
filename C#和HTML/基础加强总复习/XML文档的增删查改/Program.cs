using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
namespace XML文档的增删查改
{
    class Program
    {
        static void Main(string[] args)
        {
            //第一步：创建XML文档对象
            XmlDocument doc = new XmlDocument();

            //第二步：载入XML文档内容
            doc.Load("order.xml");

            //第三步：查找需要删除的节点，与该节点的根节点
            XmlNode xnRemove = doc.SelectSingleNode("Order/Items/OrderItem[@Name='手机']");
            XmlNode xnFather = doc.SelectSingleNode("Order/Items");

            //第四步：
            //RemoveAll()：移除当前节点的所有子节点，并且移除该节点的属性
            xnFather.RemoveAll();

            //RemoveChild()：移除指定根节点目录下的指定的子节点的所有内容
            xnFather.RemoveChild(xnRemove);

            //Attributes.RemoveNamedltem()：移除指定节点的某个属性
            xnRemove.Attributes.RemoveNamedItem("Name");

            doc.Save("orderNew2.xml");
            Console.WriteLine("Save Closed!");
            Console.ReadLine();
        }
    }
}
