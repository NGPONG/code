using BookShop.Model;
using NGPONG.BookShop.BLL;
using NGPONG.BookShop.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.SessionState;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace NGPONG.BookShop.WebApplication.Member
{
    public partial class BookList : System.Web.UI.Page
    {
        protected int _pageSize = 0;
        protected int _currentPage = 0;

        protected void Page_Load(object sender, EventArgs e)
        {
            // first time
            if (string.IsNullOrEmpty(Context.Request.QueryString["PaginalNumber"]))
            {
                this._currentPage = 1;
            }
            else
            {
                if (!int.TryParse(Context.Request.QueryString["PaginalNumber"].ToString(), out this._currentPage))
                {
                    Response.Redirect("\\Html\\Error.html");
                }
            }

            var bookList = this.GetBookList();
            this._pageSize = Convert.ToInt32(string.IsNullOrEmpty(bookList[0].PageSize) ? "0" : bookList[0].PageSize);

            this.BookListRepeater.DataSource = bookList;
            this.BookListRepeater.DataBind();
        }
        
        protected List<Book> GetBookList()
        {
            BooksService service = new BooksService();
            return service.GetBooksList(this._currentPage);
        }
    }
}