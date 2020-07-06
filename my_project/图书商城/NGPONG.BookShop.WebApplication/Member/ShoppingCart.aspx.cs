using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using NGPONG.BookShop.BLL;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace NGPONG.BookShop.WebApplication.Member
{
    public partial class ShoppingCart : System.Web.UI.Page
    {
        public bool IsNoneCart { get; set; }
        public decimal CharPrice { get; set; }
        protected void Page_Load(object sender, EventArgs e)
        {
            // 获取通过Cookie所存放的购物车内容
            var cookieRequestExpando = JsonConvert.DeserializeObject<JArray>(Request.Cookies["shoppingCart"]?.Value ?? string.Empty);

            if (Session["UserInfo"] != null)
            {
                // Cookie购物车还留有商品的话，要同步到数据库先
                if (cookieRequestExpando != null)
                {
                    CartService cartService = new CartService();

                    foreach (var jToken in cookieRequestExpando)
                    {
                        cartService.AddCart(new
                        {
                            UserId = (Session["UserInfo"] as Model.Users).Id,
                            BookId = jToken.Value<string>("bookId"),
                            Count = jToken.Value<int>("qty")
                        });
                    }

                    // 清除Cookie
                    HttpCookie cookie = new HttpCookie("shoppingCart");
                    cookie.Expires = DateTime.Now.AddDays(-1);
                    Response.Cookies.Add(cookie);
                }

                DataTable dtResult = new CartService().SelectCartByUserId((Session["UserInfo"] as Model.Users).Id);

                this.CharPrice = dtResult.AsEnumerable().Sum(x => Convert.ToDecimal(x["UnitPrice"]) * Convert.ToDecimal(x["Count"]));

                // init table
                this.repBookInfo.DataSource = dtResult;
                this.repBookInfo.DataBind();
            }
            else
            {
                // 还未添加任何商品至购物车
                if (cookieRequestExpando == null)
                {
                    this.IsNoneCart = true;
                    return;
                }

                string[] bookId = cookieRequestExpando.Select(x => $"'{x["bookId"].ToString()}'").ToArray();
                var bookList_Sql = new BooksService().GetBooksList(string.Join(",", bookId));

                var bookList_Cookie = cookieRequestExpando.ToList();

                // 获取每本书的Count信息
                var query = from cookie in bookList_Cookie
                            join sql in bookList_Sql on cookie["bookId"].ToString() equals sql.Id
                            select new
                            {
                                ISBN = sql.ISBN,
                                Title = sql.Title,
                                UnitPrice = Convert.ToDecimal(sql.UnitPrice),
                                Id = sql.Id,
                                Count = Convert.ToInt32(cookie["qty"].ToString())
                            };

                this.CharPrice = query.Sum(x => x.UnitPrice * x.Count);

                // init table
                this.repBookInfo.DataSource = query.ToList();
                this.repBookInfo.DataBind();
            }
        }
    }
}