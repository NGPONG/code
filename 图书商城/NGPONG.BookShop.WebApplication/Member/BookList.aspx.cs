using BookShop.Model;
using NGPONG.BookShop.BLL;
using NGPONG.BookShop.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace NGPONG.BookShop.WebApplication.Member
{
    public partial class BookList : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            this.BookListRepeater.DataSource = this.GetBookList();
            this.BookListRepeater.DataBind();
        }

        protected List<Book> GetBookList()
        {
            PageBar pageBar = new PageBar();
            pageBar.CurrentPage = Convert.ToInt32(base.Request.QueryString["CurrentPage"]);
            pageBar.PageSize = Convert.ToInt32(base.Request.QueryString["PageSize"]);

            BooksService service = new BooksService();
            return service.GetBooksList(pageBar);
        }
    }
}