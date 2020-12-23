using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Cookie验证页
{
    public partial class index : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Request.QueryString["AcceptCookie"] != null)
            {
                bool acceptCookie = Convert.ToBoolean(Request.QueryString["AcceptCookie"]);
                if (acceptCookie)
                {
                    Response.Write("您的网页已允许Cookie！");
                }
                else
                {
                    Response.Write("您的网页不允许Cookie，请开启！");
                }
            }
            else
            {
                HttpCookie cookie = new HttpCookie("CookieTest", "1");
                cookie.Expires = DateTime.Now.AddMinutes(5);
                Response.Cookies.Add(cookie);
                Response.Redirect("/CookieCheck.ashx?redirect=" + Request.RawUrl);
            }
        }
    }
}