using BookShop.Model;
using NGPONG.BookShop.BLL;
using NGPONG.BookShop.Common.Helper;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace NGPONG.BookShop.WebApplication.AdminManager
{
    public partial class CreateStaticPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (IsPostBack)
            {
                Stopwatch sw = new Stopwatch();
                sw.Start();
                BooksService booksService = new BooksService();
                List<Book> boos = booksService.GetAllBooksList();
                for (int i = 0; i < boos.Count; i++)
                {
                    StaticPageHelper.CreateStaticPage("BookTemplate.html", boos[i]);
                }
                sw.Stop();

                base.Response.Write($"生成成功！耗时{sw.Elapsed.TotalSeconds}");
            }
        }
    }
}