using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace 用代码创建一个XML文档
{
    class Program
    {
        static void Main(string[] args)
        {
            XmlDocument doc = new XmlDocument();
            XmlDeclaration dec = doc.CreateXmlDeclaration("1.0", "utf-8", null);
            doc.AppendChild(dec);

            XmlElement books = doc.CreateElement("Books");
            doc.AppendChild(books);

            #region book1
            XmlElement book1 = doc.CreateElement("Book");
            books.AppendChild(book1);

            XmlElement book1Name = doc.CreateElement("Name");
            book1Name.InnerXml = "水浒传";
            book1Name.SetAttribute("属性名", "属性值");
            book1.AppendChild(book1Name);

            XmlElement book1Price = doc.CreateElement("Price");
            book1Price.InnerXml = "10RMB";
            book1Price.SetAttribute("属性名", "属性值");
            book1.AppendChild(book1Price);

            XmlElement book1Dec = doc.CreateElement("Dec");
            book1Dec.InnerXml = "好看！";
            book1Dec.SetAttribute("属性名", "属性值");
            book1.AppendChild(book1Dec);
            #endregion

            XmlElement book2 = doc.CreateElement("Book");
            books.AppendChild(book2);

            XmlElement book2Name = doc.CreateElement("Name");
            book2Name.InnerXml = "西游记";
            book2Name.SetAttribute("属性名", "属性值");
            book2.AppendChild(book2Name);

            XmlElement book2Price = doc.CreateElement("Price");
            book2Price.InnerXml = "5RMB";
            book2Price.SetAttribute("属性名", "属性值");
            book2.AppendChild(book2Price);

            XmlElement book2Dec = doc.CreateElement("Dec");
            book2Dec.InnerXml = "还行~";
            book2Dec.SetAttribute("属性名", "属性值");
            book2.AppendChild(book2Dec);

            doc.Save("book.xml");

            Console.WriteLine("保存成功");
            Console.ReadLine();
            

        }
    }
}
