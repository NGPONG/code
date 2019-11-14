using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Test_08
{
    class Program
    {
        List<string> strTags = new List<string>();

        static void Main(string[] args)
        {
            DataTable table = new DataTable();
            table.ReadXml(@"C:\Users\NGPONG\Desktop\新建文本文档.xml");


        }
    }
}
