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
            //第一步：创建一个新的XML文档的对象
            XmlDocument doc = new XmlDocument();
            //第二步：读取需要被追加内容的XML文档
            //当读取完成后，被追加内容的XML文档中的所有内容都会载入到我们新创的XML文档的对象
            doc.Load("books.xml");
            //读取根节点
            XmlElement books = doc.DocumentElement;
            //为根节点创建子节点，并对子节点进行赋值，以达到追加内容的目的
            XmlElement newBook = doc.CreateElement("new");
            books.AppendChild(newBook);
            doc.Save("new.xml");
        }
    }
}
