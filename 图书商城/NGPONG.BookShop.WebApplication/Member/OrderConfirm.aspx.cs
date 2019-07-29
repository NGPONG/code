using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using NGPONG.BookShop.BLL;
using NGPONG.BookShop.Common.Unitis;
using NGPONG.BookShop.Model;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace NGPONG.BookShop.WebApplication.Member
{
    public partial class OrderConfirm : System.Web.UI.Page
    {
        #region Member
        protected Users UserInfo { get; set; }
        protected decimal TotalMoney { get; set; }
        protected bool IsCartEmpty { get; set; }
        #endregion
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["UserInfo"] == null)
            {
                WebCommon.RedirectLogin();
            }
            else
            {
                this.UserInfo = Session["UserInfo"] as Users;

                // 获取通过Cookie所存放的购物车内容
                var cookieRequestExpando = JsonConvert.DeserializeObject<JArray>(Request.Cookies["shoppingCart"]?.Value ?? string.Empty);

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

                DataTable dtResult = new CartService().SelectCartByUserId(this.UserInfo.Id);
                if (dtResult == null || dtResult.Rows.Count == 0)
                {
                    IsCartEmpty = true;
                    return;
                }
                else
                {
                    IsCartEmpty = false;
                }

                this.TotalMoney = dtResult.AsEnumerable().Sum(x => Convert.ToDecimal(x["UnitPrice"]) * Convert.ToDecimal(x["Count"]));

                // init table
                this.repBookInfo.DataSource = dtResult;
                this.repBookInfo.DataBind();
            }
        }
    }
}