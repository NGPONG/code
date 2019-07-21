using BookShop.Model;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web;

namespace NGPONG.BookShop.Common.Helper
{
    public static class StaticPageHelper
    {
        public static void CreateStaticPage(string templatePageName, Book bookModel)
        {
            HttpContext context = HttpContext.Current;

            StringBuilder sb_htmlPage = new StringBuilder();
            using (FileStream fileRead = new FileStream(context.Request.MapPath($"/Template/{templatePageName}"), FileMode.OpenOrCreate, FileAccess.Read))
            {
                Byte[] buffer = new byte[1024 * 5];
                while (true)
                {
                    int count = fileRead.Read(buffer, 0, buffer.Length);
                    if (count == 0)
                    {
                        break;
                    }
                    sb_htmlPage.Append(Encoding.UTF8.GetString(buffer, 0, count));
                }
            }

            string dirPath = context.Request.MapPath($"/HtmlPage/{Convert.ToDateTime(bookModel.PublishDate).Year}/");
            if (!Directory.Exists(dirPath))
            {
                Directory.CreateDirectory(dirPath);
            }

            string htmlPage = sb_htmlPage.ToString().Replace("$title", bookModel.Title).Replace("$author", bookModel.Author).Replace("$unitprice", Convert.ToDecimal(bookModel.UnitPrice).ToString("F2")).Replace("$isbn", bookModel.ISBN).Replace("$content", bookModel.ContentDescription).Replace("$bookId", bookModel.Id.ToString());
            using (StreamWriter htmlWriter = new StreamWriter(dirPath + $"{bookModel.ISBN}.html"))
            {
                htmlWriter.Write(htmlPage);
            }
        }
    }
}
