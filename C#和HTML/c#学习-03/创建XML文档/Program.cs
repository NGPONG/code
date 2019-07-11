using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace 创建XML文档
{
    class Program
    {
        static void Main(string[] args)
        {
            //第一步：创建XML文档的对象
            XmlDocument doc = new XmlDocument();

            //第二步： 创建第一行的描述信息，并追加到doc文档中
            XmlDeclaration dec = doc.CreateXmlDeclaration("1.0", "utf-8", null);
            doc.AppendChild(dec);

            //第三步：创建根节点，并追加到doc文档中
            XmlElement books = doc.CreateElement("Books");
            doc.AppendChild(books);

            //第四步：给根节点books创建子节点，并添加进books根节点中
            XmlElement book1 = doc.CreateElement("Book1");
            books.AppendChild(book1);

            //第四步：创建book1的子节点，并添加入book1节点中
            XmlElement nameBook1 = doc.CreateElement("Name");
            nameBook1.InnerXml = "水浒传";//给name标签添加文本
            nameBook1.SetAttribute("标签属性名", "标签属性值");//给name标签添加属性
            book1.AppendChild(nameBook1);

            XmlElement priceBook1 = doc.CreateElement("Price");
            priceBook1.InnerXml = "10块钱 ";//给price标签添加文本
            priceBook1.SetAttribute("标签属性名", "标签属性值");//给price标签添加属性
            book1.AppendChild(priceBook1);

            XmlElement decBook1 = doc.CreateElement("Dec");
            decBook1.InnerXml = "无聊";//给dec标签添加文本
            decBook1.SetAttribute("标签属性名", "标签属性值");//给dec标签添加属性
            book1.AppendChild(decBook1);



            XmlElement book2 = doc.CreateElement("Book2");
            books.AppendChild(book2);
            XmlElement nameBook2 = doc.CreateElement("Name");
            nameBook2.InnerXml = "三国演义";
            nameBook2.SetAttribute("标签属性名", "标签属性值");
            book2.AppendChild(nameBook2);
            XmlElement priceBook2 = doc.CreateElement("Price");
            priceBook2.InnerXml = "5块钱";
            priceBook2.SetAttribute("标签属性名", "标签属性值");
            book2.AppendChild(priceBook2);
            XmlElement decBook2 = doc.CreateElement("Dec");
            decBook2.InnerXml = "关羽！！";
            decBook2.SetAttribute("标签属性名", "标签属性值");
            book2.AppendChild(decBook2);


            //第五步：保存XML文档，以下用的是相对路径
            doc.Save("books.xml");

        }
    }
}
