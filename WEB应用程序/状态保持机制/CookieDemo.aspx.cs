using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace 状态保持机制
{
    public partial class CookieDemo : System.Web.UI.Page
    {
        protected string UserName { get; set; }

        protected void Page_Load(object sender, EventArgs e)
        {
            if (Request.Form["txtUserName"] != null)
            {
                HttpCookie cookie = new HttpCookie("userName", Request.Form["txtUserName"]);
                cookie.Expires = DateTime.Now.AddDays(30);
                Response.Cookies.Add(cookie);
            }

            this.UserName = Request.Cookies["userName"] == null ? string.Empty : Request.Cookies["userName"].Value.ToString();
        }
    }
}