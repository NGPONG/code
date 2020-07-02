using System;
using System.Collections.Generic;
using System.Data;
using System.IO;
using System.Linq;
using System.Text;
using System.Web;

namespace TEST_15
{
    /// <summary>
    /// Test 的摘要说明
    /// </summary>
    public class Test : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "application/octet-stream";
            context.Response.AddHeader("content-disposition", "attachment;filename=test.xml");

            DataTable dataTable = new DataTable("Hello");
            dataTable.Columns.AddRange(new DataColumn[] { new DataColumn("name"), new DataColumn("address") });
            dataTable.Rows.Add("NGPONG1", "TEST1");
            dataTable.Rows.Add("NGPONG2", "TEST2");
            dataTable.Rows.Add("NGPONG3", "TEST3");

            MemoryStream stream = new MemoryStream();
            dataTable.WriteXml(stream);

            context.Response.BinaryWrite(stream.ToArray());
        }

        public bool IsReusable
        {
            get
            {
                return false;
            }
        }
    }
}